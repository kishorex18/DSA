/*#include <iostream>
using namespace std;

class node
{
  public:
    int data;
    node* left;
    node* right;
    int height;
  node(int v)
  {
    data=v;
    left=nullptr;
    right=nullptr;
  }
};
int height(node* n)
{
  if(n==nullptr)
  {
    return 0;
  }
  return 1+max(height(n->left),height(n->right));
}
class tree
{
  public:
   node* root;
   bool balance;
};

void populate(node* n)
{
  bool left,right;
  cout<<"Do you want to populate left of:";
  cout<<n->data<<endl;
  cin>>left;
  if(left)
  {
    int v;
    cout<<"Enter the value:"<<endl;
    cin>>v;
    n->left=new node(v);
    n->left->height=height(n->left);
    populate(n->left);
  }
  cout<<"Do you want to populate right of:";
  cout<<n->data<<endl;
  cin>>right;

  if(right)
  {
    int v;
    cout<<"Enter the value:"<<endl;
    cin>>v;
    n->right=new node(v);
    n->right->height=height(n->right);
    populate(n->right);
  }
}
node* populateSorted(int s,int e,int* arr)
{
    node* n=nullptr;
    if(s>e)
    {
        return n;
    }
    int mid=(s+e)/2;
    n=new node(*(arr+mid));
    n->left=populateSorted(s,mid-1,arr);
    n->right=populateSorted(mid+1,e,arr);
    n->height=height(n);
    return n;
}
int diameter(node* n,int m)
{
  if(n==nullptr)
    return 0;
  return max(m,1+height(n->left)+height(n->right));
}
int main()
{
  tree t;
  int i;
  int arr[100];
  for(i=0;i<100;i++)
  {
      arr[i]=i+1;
  }
  t.root=populateSorted(0, 99, arr);
  cout<<diameter(t.root,0)<<endl;
  return 0;
}*/