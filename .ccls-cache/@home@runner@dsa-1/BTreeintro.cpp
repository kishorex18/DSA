/*#include <bits/stdc++.h>
#include <iostream>
#include <vector>
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
  int left,right;
  cout<<"Do you want to populate left of:";
  cout<<n->data<<endl;
  cin>>left;
  if(left>=0)
  {

    n->left=new node(left);
    populate(n->left);
  }
  cout<<"Do you want to populate right of:";
  cout<<n->data<<endl;
  cin>>right;
  
  if(right>=0)
  {
    
    n->right=new node(right);
    populate(n->right);
  }
}
void htree(node* n)
{
  if(n==nullptr)
    return;
  htree(n->left);
  htree(n->right);
  n->height=height(n)-1;
}
void preOrder(node* n)
{
  if(n==nullptr)
    return;
  cout<<n->data<<endl;
  cout<<"height:"<<n->height<<endl;
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
bool balanced(node* n)
{
  if(n==nullptr)
  {
    return 1;
  }
  if(n->left==nullptr && n->right==nullptr)
  {
    return 1;
  }
  int lh=(n->left!=nullptr)?n->left->height:0;
  int rh=(n->right!=nullptr)?n->right->height:0;
  if(abs(lh-rh)<=1)
    return 1 && balanced(n->left) && balanced(n->right);
  else
    return 0;
}
bool rightMost(node* n)
{
  if(n==nullptr)
    return true;
  if(n->left==nullptr && n->right==nullptr)
    return true;
  if(n->left==nullptr && n->right==nullptr)
    return false;
  if(n->left->data== n->right->data)
    return true;
  return rightMost(n->left)&&rightMost(n->right);
  
}
void leftMost(node* n)
{
  if(n==nullptr)
    return ;
  leftMost(n->left);
  cout<<n->data<<endl;
}
vector <int> levelOrder(node* root)
{
  vector <int> ans;
  if(root==nullptr)
  {
    return ans;
  }
  queue <node*> q;
  q.push(root);
  while(!q.empty())
  {
    int levelSize=q.size();
    for(int i=0;i< levelSize;i++)
    {
        node* current=q.front();
        if(current->left!=nullptr)
        {
          q.push(current->left);
        }
      if(current->right!=nullptr)
        {
          q.push(current->right);
        }
        ans.push_back(current->data);
        q.pop();
    }
  }
  return ans;
}
int sum;
int sumNumbers(node* root) {
    
     if(root->left==nullptr && root->right==nullptr)
     {
        
        return sum+root->data;
     }
  
     sum=(sum+root->data)*10;
     
    int s=sumNumbers(root->left)+sumNumbers(root->right);
  return s;
}
bool isValidBST(node* root) {
    if(root->left==nullptr && root->right==nullptr)
    {
        cout<<"1"<<endl;
        return true;
    }
    if(root->left==nullptr || root->right==nullptr)
    {
        if(root->left!=nullptr)
        {
            if(root->data>root->left->data)
            {
                cout<<"2"<<endl;
                return isValidBST(root->left);
            }
            else
            { 
                cout<<"2a"<<endl;
                return false;
            }
        }
        else
        {
            if(root->data<root->right->data)
            {
                cout<<"3"<<endl;
                return isValidBST(root->right);
            }
            else
            {   
                 cout<<"3a"<<endl;
                return false;
            }
        }
    }
  else
    {
    int low=root->left->data;
    int high=root->right->data;
    if(root->data>low && root->data<high)
    {

        cout<<"4"<<endl;
        return isValidBST(root->left)&&isValidBST(root->right);
    }
    else
    {
         cout<<low<<" "<<high<<endl;
         cout<<"4a"<<endl;
        return false;
    }
    }
}
void inorder(node* root,int& min,int& msd)
{
    if(root==nullptr)
    {
        return;
    }
    inorder(root->left,min,msd);
    cout<<"msd:"<<msd<<endl;
    cout<<"min:"<<min<<endl;
    msd=(msd>abs(min-root->data) && min>=0)?abs(min-root->data):msd;
    min=root->data;
    cout<<"min:"<<min<<endl;
    inorder(root->right,min,msd);
}
int main() {

  tree t;
  int value;
  cout<<"Enter the root value:";
  cin>>value;
  t.root=new node(value);
  populate(t.root);
  //htree(t.root);
  //cout<<"Preorder"<<endl;
  //preOrder(t.root);
  //cout<<"postorder"<<endl;
//postOrder(t.root);
  //cout<<"inorder"<<endl;
  //inOrder(t.root);
  //t.balance=balanced(t.root);
 //cout<<"Balance:"<<t.balance<<endl;
  int msd=INT_MAX;
  int min=-100;
  inorder(t.root,min,msd);
  
  

}*/