#include <iostream>
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
int main()
{
  int i;
  bstree t;
  t.root=new bnode(1);
  for(i=2;i<10000;i++)
  {

      t.root=populatebst(i,t.root);


  }
 PostOrder(t.root);
  /*bnode* ans=search(7,t.root);
  if(ans==nullptr)
  {
    cout<<"ans not found"<<endl;
  }
  else
  {
    cout<<ans->value<<endl;
  }
*/
  cout<<"height:"<<t.root->height<<endl;
  return 0;

}
