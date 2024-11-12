#include <iostream>
using namespace std;

class node
{
  public:
  int value,height;
  node* left;
  node* right;
  bool balance;
  node(int data)
  {
    value=data;
    left=nullptr;
    right=nullptr;
  };
};
class tree
{
  public:
  node* root;
};
void populate(int v,node* n)
{
  if(n->value<=v && n->right!=nullptr)
  {
    populate(v,n->right);
  }
  else
  {
    node* c=new node(v);
    n->right=c;
    return;
  }
  if(n->value>=v && n->left!=nullptr)
  {
      populate(v,n->left);
  }
  else
  {
    node* c=new node(v);
    n->left=c;
    return;
  }
}
void postOrder(node* n)
{
  if(n==nullptr)
  {
    return;
  }
  postOrder(n->left);
  postOrder(n->right);
  cout<<n->value<<endl;
}
int main()
{
  int i;
  tree t;
  t.root=new node(1);
  for(i=0;i<5;i++)
  {
      int v;
      cin>>v;
      populate(v,t.root);

  }
  postOrder(t.root);

  return 0;
}