/*
Minimum Spanning Tree (MST)
Kruskal's algorithm
O(ElogE) or O(ElogV)

    ~LaKsHiTh_
*/

#include <bits/stdc++.h>

using namespace std;

struct edge{
    int src;
    int dest;
    int weight;
};

struct graph{
    int v;
    int e;
    edge* edges;
};

graph* createGraph(int v,int e){
    graph* g = new graph;
    g->v = v;
    g->e = e;
    g->edges = new edge[e];
    return g;
}

struct subset{
    int parent;
    int rank;
};

int find(subset subsets[],int i){
    if(subsets[i].parent!=i)
        subsets[i].parent = find(subsets,subsets[i].parent);
    return subsets[i].parent;
}

void Union(subset subsets[],int x,int y){
    int xroot = find(subsets,x);
    int yroot = find(subsets,y);
    if(subsets[xroot].rank<subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if(subsets[xroot].rank>subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else{
        subsets[xroot].parent = yroot;
        subsets[yroot].rank++;
    }
}

int comp(const void* a,const void* b){
    edge* A = (edge*)a;
    edge* B = (edge*)b;
    return A->weight < B->weight;
}

void kruskal(graph* g){
    int v = g->v;
    edge result[v];
    int e=0,i=0;
    qsort(g->edges,g->e,sizeof(g->edges[0]),comp);
    subset* subsets = new subset[v * sizeof(subset)];
    for(i=0;i<v;i++)
        subsets[i].parent=i,subsets[i].rank=0;
    while(e<v-1 && i< g->e){
        edge next = g->edges[i++];
        int x = find(subsets,next.src);
        int y = find(subsets,next.dest);
        if(x!=y){
            result[e++] = next;
            Union(subsets,x,y);
        }
    }
    return;
}