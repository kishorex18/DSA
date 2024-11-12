//This code has sum segment tree data structure it can answer queries,create trees for any array,insert elements within the range

/*#include <iostream>
using namespace std;

class node
{
   public:
    int s;
    int e;
    int value;
    node* left;
    node* right;
    node(int a,int b,int v=0)
  {
      s=a;
      e=b;
      value=v;
  }
};

class segTree
{
  public:
    node* root;
};

//populating tree
node* populate(int s,int e,int* arr)
{
  if(s>e)
  {
    return nullptr;
  }
  if(s==e)
  {
    node* leaf=new node(s,e,*(arr+s));
    return leaf;
  }
  int mid=(s+e)/2;
  node* n=new node(s,e);
  n->left=populate(s,mid,arr);
  n->right=populate(mid+1,e,arr);
  int lv,rv;
  lv=(n->left!=nullptr)?n->left->value:0;
  rv=(n->right!=nullptr)?n->right->value:0;
  n->value=max(lv,rv);
  return n;
}

int find(int s,int e,node* n)
{
  if(n==nullptr)
  {
    return 0;
  }
  int cs=n->s;
  int ce=n->e;
  if(cs>=s && ce<=e)
  {
    return n->value;
  }
  else if(e<cs)
  {
    return 0;
  }
  else
  {
    return max(find(s,e,n->left),find(s,e,n->right));
  }
}
int insert(int v,int i,node* n)
{
  if(n->s<=i && n->e>=i)
  {
    if(n->s==n->e && n->s==i)
    {
      n->value=v;
      return n->value;
    }
    else
    {
      n->value=insert(v,i,n->left)+insert(v,i,n->right);
      return n->value;
    }
  }
  return n->value;
}
void PostOrder(node* n)
{
  if(n==nullptr)
  {
    return;
  }
 
  PostOrder(n->left);
  PostOrder(n->right);
  cout<<"Range:"<<n->s<<" "<<n->e<<endl;
  cout<<"Value:"<<n->value<<endl;
 
}

int main()
{
  segTree t;
  int i;
  int arr[10];
  for(i=1;i<=10;i++)
  {
      arr[i-1]=i;
  }
  t.root=populate(0,9,arr);
  PostOrder(t.root);
  cout<<"Ans:"<<find(0,9,t.root)<<endl;
  cout<<"Ans:"<<insert(100,11,t.root);
}*/