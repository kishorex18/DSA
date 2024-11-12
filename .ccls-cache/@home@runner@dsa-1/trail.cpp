#include <iostream>
using namespace std;

class bnode
{
public:
    int value, height;
    bnode *left;
    bnode *right;
    bool balance;
    bnode(int data)
    {
        value = data;
        left = nullptr;
        right = nullptr;
    };
};

class bstree
{
public:
    bnode *root;
};

int height(bnode *n)
{
    if (n == nullptr)
        return 0;
    return 1 + max(height(n->left), height(n->right));
}

bnode *rightRotate(bnode *n)
{
    bnode *c = n->left;
    bnode *t = c->right;
    c->right = n;
    n->left = t;
    return c;
}

bnode *leftRotate(bnode *n)
{
    bnode *p = n->right;
    bnode *t = p->left;
    p->left = n;
    n->right = t;
    return p;
}

bnode *rotate(bnode *n)
{
    int lh = n->left ? n->left->height : 0; 
    int rh = n->right ? n->right->height : 0; 

    if (abs(lh - rh) > 1)
    {
        if (lh - rh > 1)
        { // left heavy
            if (n->left) { // Check if n->left is not null
                int llh = n->left->left ? n->left->left->height : 0; 
                int lrh = n->left->right ? n->left->right->height : 0; 
                if (llh - lrh > 0)
                {
                    // left left heavy
                    return rightRotate(n);
                }
                else
                {
                    n->left = leftRotate(n->left);
                    return rightRotate(n);
                }
            }
        }
        else
        {
            // right heavy
            if (n->right) { // Check if n->right is not null
                int rlh = n->right->left ? n->right->left->height : 0; 
                int rrh = n->right->right ? n->right->right->height : 0; 
                if (rlh - rrh < 0)
                {
                    // right right heavy
                    return leftRotate(n);
                }
                else
                {
                    n->right = rightRotate(n->right);
                    return leftRotate(n);
                }
            }
        }
    }
    return n;
}

bnode *populatebst(int v, bnode *n, bnode *root)
{
    if (n == nullptr)
    {
        n = new bnode(v);
        return n;
    }

    if (n->value < v)
    {
        n->right = populatebst(v, n->right, root);
    }
    else if (n->value > v)
    {
        n->left = populatebst(v, n->left, root);
    }

    // Update the height after insertion
    n->height = 1 + max(height(n->left), height(n->right));
    // If we inserted at the root, update the root pointer in 'bstree'
    if (n == root)
    {
        return n;
    }
    return rotate(n);
}

void PostOrder(bnode *n)
{
    if (n == nullptr)
    {
        return;
    }

    PostOrder(n->left);
    PostOrder(n->right);
    cout << "Value:" << n->value << endl;
    cout << n->height << endl;
}

bnode *search(int v, bnode *n)
{
    if (n == nullptr)
        return nullptr;
    else if (n->value == v)
        return n;
    else if (v > n->value)
        return search(v, n->right);
    else
        return search(v, n->left);
}

int main()
{
    int i;
    bstree t;
    t.root = new bnode(1);

    for (i = 2; i < 10; i++)
    {
        t.root = populatebst(i, t.root, t.root); // Update the root pointer
        cout << t.root->value << endl;
    }

    PostOrder(t.root);
    bnode *ans = search(7, t.root);
    if (ans == nullptr)
    {
        cout << "ans not found" << endl;
    }
    else
    {
        cout << ans->value << endl;
    }

    return 0;
}