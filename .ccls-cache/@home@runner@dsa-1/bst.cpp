// it has populate functions for both sorted array and avl trees,search function,bft,height,balance functions
/*#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class bnode {
public:
    int value, height;
    bnode* left;
    bnode* right;
    bool balance;
    bnode(int data) {
        value = data;
        left = nullptr;
        right = nullptr;
        height = 1; // Initialize height to 1 for leaf nodes
    }
};
class bstree
{
  public:
    bnode* root;
};
int height(bnode* n) {
    if (n == nullptr)
        return 0;
    return 1+max(height(n->left),height(n->right));
}

bnode* rightRotate(bnode* n) {
    bnode* c = n->left;
    bnode* t = c->right;
    c->right = n;
    n->left = t;

    // Update heights
    n->height = height(n);
    c->height =height(c);

    return c;
}

bnode* leftRotate(bnode* n) {
    bnode* p = n->right;
    bnode* t = p->left;
    p->left = n;
    n->right = t;

    // Update heights
    n->height = height(n);
    p->height = height(p);

    return p;
}

bnode* rotate(bnode* n) {
    if (n == nullptr)
        return n;

    n->height = height(n);

    int balance = height(n->left) - height(n->right);

    // Left heavy
    if (balance > 1) {
        if (height(n->left->left) >= height(n->left->right)) {
            return rightRotate(n);
        } else {
            n->left = leftRotate(n->left);
            return rightRotate(n);
        }
    }

    // Right heavy
    if (balance < -1) {
        if (height(n->right->left) <= height(n->right->right)) {
            return leftRotate(n);
        } else {
            n->right = rightRotate(n->right);
            return leftRotate(n);
        }
    }

    return n;
}

bnode* populatebst(int v, bnode* n) {
    if (n == nullptr) {
        n = new bnode(v);
        return n;
    }

    if (v < n->value) {
        n->left = populatebst(v, n->left);
    } else if (v > n->value) {
        n->right = populatebst(v, n->right);
    } else {
        return n; // No duplicates allowed in BST
    }

    // Update height of current node
    n->height = height(n);

    // Perform rotation if necessary
    return rotate(n);
}
bnode* populateSorted(int s,int e,int* arr)
{
    bnode* n=nullptr;
    if(s>e)
    {
        return n;
    }
    int mid=(s+e)/2;
    n=new bnode(*(arr+mid));
    n->left=populateSorted(s,mid-1,arr);
    n->right=populateSorted(mid+1,e,arr);
    n->height=height(n);
    return n;
}
void PostOrder(bnode* n)
{
  if(n==nullptr)
  {
    return;
  }
  
  PostOrder(n->left);
  PostOrder(n->right);
    cout<<"Value:"<<n->value<<endl;
  if(n->left!=nullptr && n->right!=nullptr)
  {
    int lh=n->left->height;
    int rh=n->right->height;
    cout<<"Balance:"<<lh-rh<<endl;
  }

}

bnode* search(int v,bnode* n)
{
  if(n==nullptr)
    return nullptr;
  else if(n->value==v)
    return n;
  else if(v>n->value)
    return search(v,n->right);
  else 
    return search(v,n->left);

}
vector <int> levelOrder(bnode* root)
{
  vector <int> ans;
  if(root==nullptr)
  {
    return ans;
  }
  queue <bnode*> q;
  q.push(root);
  while(!q.empty())
  {
    int levelSize=q.size();
    for(int i=0;i< levelSize;i++)
    {
        bnode* current=q.front();
        if(current->left!=nullptr)
        {
          q.push(current->left);
        }
      if(current->right!=nullptr)
        {
          q.push(current->right);
        }
        ans.push_back(current->value);
        q.pop();
    }
  }
  return ans;
}

int main()
{
  int i;
  bstree t1,t2;
  int arr[100];
  for(i=0;i<100;i++)
  {
    arr[i]=i+1;
  }
  t1.root=populateSorted(0,99,arr);
  t2.root=new bnode(1);
  for(i=2;i<=100;i++)
  {

      t2.root=populatebst(i,t2.root);


  }
  PostOrder(t2.root);
  vector <int> ans=levelOrder(t1.root);
  for(auto it=ans.begin();it!=ans.end();it++)
       cout<<*(it)<<" ";
 //PostOrder(t.root);
  bnode* ans=search(9000,t.root);
  if(ans==nullptr)
  {
    cout<<"ans not found"<<endl;
  }
  else
  {
    cout<<ans->value<<endl;
  }

  cout<<"height:"<<t.root->height<<endl;
  return 0;
  
}*/
