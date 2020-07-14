#include <bits/stdc++.h>
#define pi pair<int,int>
#define f first
#define s second
#define ld long double
#define shit cout << "shit" << "\t";
#define fuck return;
#define what_is(x) cout << #x << " is " << x << "\n";


using namespace std;

inline void io_setup(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int n;
int l,r,y;

struct node{
  int l;
  int r;
  int v;
  node* left;
  node* right;
  bool isEnd;
};

pi getBounds(int x,int h,int v){
  ld right = (ld)y/((ld)h/(ld)v)+(ld)x;
  ld left = (ld)y/((ld)h/(ld)v)*-1+(ld)x;
  return {(int)floor(left)+1,(int)ceil(right)-1};
}

node* newNode(int l,int r,int v=0){
  struct node* root = new node;
  root->l=l;
  root->r=r;
  root->v=v;
  root->left = nullptr;
  root->right = nullptr;
  root->isEnd = true;
  return root;
}

void update(node* root,pi range){
  if(root->l==range.f&&root->r==range.s){
    root->v++;
    return;
  }
  int mid = (root->l+root->r)/2;
  if(root->left==nullptr)root->left=newNode(root->l,mid,root->v);
  if(root->right==nullptr)root->right=newNode(mid+1,root->r,root->v);
  if(range.s<=mid){
    root->isEnd = false;
    update(root->left,range);
  }else if(range.f>mid){
    root->isEnd = false;
    update(root->right,range);
  }else{
    root->isEnd = false;
    update(root->left,{range.f,mid});
    update(root->right,{mid+1,range.s});
  }
  return;
}

int sum[1000011];

void getAns(node* root){
  if(root->isEnd){
    sum[root->v+1]+=(root->r)-(root->l)+1;
    return;
  }
  if(root->left!=nullptr)
  getAns(root->left);
  if(root->right!=nullptr)
  getAns(root->right);
}

int main(){
  io_setup();
  cin >> n;
  cin >> l >> r >> y;
  node* root = newNode(l,r);
  for(int i=0;i<n;i++){
    int x,h,v;
    cin >> x >> h >> v;
    pi range = getBounds(x,h,v);
    update(root,range);
  }
  getAns(root);
  for(int i=1;i<=n+1;i++)sum[i]+=sum[i-1];
  for(int i=1;i<=n+1;i++)cout << sum[i] << "\n";
}
