#include <bits/stdc++.h>
#define ll long long

ll delta = 10000000000000000;

int C = 0;

using namespace std; 

inline ll Max(ll a,ll b){return a<b?b:a;}
inline ll Min(ll a,ll b){return a<b?a:b;}

struct Interval { 
    ll low, high; 
}; 

struct Node 
{ 
    Interval *i; 
    ll max;
    ll min;
    Node *left, *right; 
}; 

Node * newNode(Interval i) 
{ 
    Node *temp = new Node; 
    temp->i = new Interval(i); 
    temp->max = i.high; 
    temp->min = i.low;
    temp->left = temp->right = NULL; 
    return temp; 
}; 

Node *insert(Node *root, Interval i) 
{ 
    if (root == NULL) 
        return newNode(i); 

    ll l = root->i->low; 

    if (i.low < l) 
        root->left = insert(root->left, i); 

    else
        root->right = insert(root->right, i); 

    if (root->max < i.high) 
        root->max = i.high; 
    if(root->min > i.low)
      root->min = i.low;

    return root; 
} 

bool doOVerlap(Interval i1, Interval i2) { 
    if (i1.low <= i2.high && i2.low <= i1.high) 
        return true; 
    return false; 
}

ll overlapSearch(Node *root, Interval i) {
  C++;
  ll Count = 0;
    if (root == NULL) return Count; 

    if (doOVerlap(*(root->i), i)) 
        Count++; 

    if (root->left != NULL && root->left->max >= i.high && root->left->min <= i.low) 
        Count+= overlapSearch(root->left, i); 
    if(root->right != NULL && root->right->max >= i.high && root->right->min <= i.low)
        Count+= overlapSearch(root->right, i); 
 return Count;
} 

int main() 
{ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,m;
  vector<ll> N;
  cin >> n >> m;
  for(int i=0;i<n;i++){
    ll a;
    cin >> a;
    N.push_back(a);
  }
  Node* root = NULL;
  for(int i=0;i<m;i++){
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    b = c;
    if(a>b)swap(a,b);
    a++;
    b--;
    if(a>b)continue;
    root = insert(root,{a,b});
  }
  ll total = 0;
  for(ll x:N)
    total += overlapSearch(root,{x,x});
  cout << total << "\n";
} 
/*
 4 9
-5 -3 2 3
-2 5 5 -6
-5 -2 -3 -5
-2 3 -6 1
-1 -3 4 2
2 5 2 1
4 5 4 -5
-2 -4 5 3
1 2 -2 1
-7 0 7 0
 */
