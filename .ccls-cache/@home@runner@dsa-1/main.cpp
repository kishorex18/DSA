#include <iostream>
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

class tree
{
  public:
   node* root;
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
    populate(n->right);
  }
}
void preOrder(node* n)
{
  if(n==nullptr)
    return;
  cout<<n->data<<endl;
  preOrder(n->left);
  preOrder(n->right);
  
}
void postOrder(node* n)
{
  if(n==nullptr)
    return;
  postOrder(n->left);
  postOrder(n->right);
  cout<<n->data<<endl;

}
void inOrder(node* n)
{
  if(n==nullptr)
    return;
  inOrder(n->left);
  cout<<n->data<<endl;
  inOrder(n->right);
 

}
int main() {

  tree t;
  t.root=new node(1);
  populate(t.root);
  cout<<"Preorder"<<endl;
  preOrder(t.root);
  cout<<"postorder"<<endl;
  postOrder(t.root);
  cout<<"inorder"<<endl;
  inOrder(t.root);
}