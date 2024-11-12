#include <bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
void swap(int*a,int*b)
{
  int temp=*a;
  *a=*b;
  *b=temp;
}
class Maxheap
{
  public:
  vector <int> ht;
  void downheap(int i)
  {
    int left=2*i+1;
    int right=2*i+2;
    int lar=i;
    int size=ht.size();
    if(left<size && ht[left]>ht[lar])
    {
      lar=left;
    }
    if(right<size && ht[right]>ht[lar])
    {
      lar=right;
    }
    if(lar!=i)
    {
      swap(&ht[lar],&ht[i]);
      downheap(lar);
    }
  }
  void upheap(int i)
  {
    if(i==0)
    {
      return;
    }
      int parent=(i-1)/2;
      if(ht[i]>ht[parent])
      {
        swap(&ht[i],&ht[parent]);
        upheap(parent);
      }
  
  }
  void insert(int v)
  {
    if(ht.size()==0)
    {
      ht.push_back(v);
    }
    else
    {
      ht.push_back(v);
      upheap(ht.size()-1);
    }
  }
  int peek()
  {
    if(ht.size()==0)
    {
      return -1;
    }
    else
    {
      return ht[0];
    }
  }
  void deleteNode()
  {
    if(ht.size()==0)
    {
     
      return;
    }
    else
    {
      swap(&ht[0], &ht[ht.size()-1]);
      ht.pop_back();
      // Heapify from the root
      downheap(0);
     
    }
  }
};
class Minheap
{
  public:
  vector <int> ht;
  void downheap(int i)
  {
    int left=2*i+1;
    int right=2*i+2;
    int lar=i;
    int size=ht.size();
    if(left<size && ht[left]<ht[lar])
    {
      lar=left;
    }
    if(right<size && ht[right]<ht[lar])
    {
      lar=right;
    }
    if(lar!=i)
    {
      swap(&ht[lar],&ht[i]);
      downheap(lar);
    }
  }
  void upheap(int i)
  {
    if(i==0)
    {
      return;
    }
      int parent=(i-1)/2;
      if(ht[i]<ht[parent])
      {
        swap(&ht[i],&ht[parent]);
        upheap(parent);
      }

  }
  void insert(int v)
  {
    if(ht.size()==0)
    {
      ht.push_back(v);
    }
    else
    {
      ht.push_back(v);
      upheap(ht.size()-1);
    }
  }
  int peek()
  {
    if(ht.size()==0)
    {
      return -1;
    }
    else
    {
      return ht[0];
    }
  }
  void deleteNode()
  {
    if(ht.size()==0)
    {

      return;
    }
    else
    {
     // cout<<ht[0]<<endl;
      swap(&ht[0], &ht[ht.size()-1]);
      ht.pop_back();
      // Heapify from the root
      downheap(0);

    }
  }
};
class MinheapNode
{
  public:
  vector <ListNode*> ht;
  void downheap(int i)
  {
    int left=2*i+1;
    int right=2*i+2;
    int lar=i;
    int size=ht.size();
    if(left<size && ht[left]->val<ht[lar]->val)
    {
      lar=left;
    }
    if(right<size && ht[right]->val<ht[lar]->val)
    {
      lar=right;
    }
    if(lar!=i)
    {
      swap(&ht[lar]->val,&ht[i]->val);
      downheap(lar);
    }
  }
  void upheap(int i)
  {
    if(i==0)
    {
      return;
    }
      int parent=(i-1)/2;
      if(ht[i]->val<ht[parent]->val)
      {
        swap(&ht[i]->val,&ht[parent]->val);
        upheap(parent);
      }

  }
  void insert(ListNode* v)
  {
    if(ht.size()==0)
    {
      ht.push_back(v);
    }
    else
    {
      ht.push_back(v);
      upheap(ht.size()-1);
    }
  }
  int peek()
  {
    if(ht.size()==0)
    {
      return -1;
    }
    else
    {
      return ht[0]->val;
    }
  }
  void deleteNode()
  {
    if(ht.size()==0)
    {

      return;
    }
    else
    {
      swap(&ht[0]->val, &ht[ht.size()-1]->val);
      ht.pop_back();
      // Heapify from the root
      downheap(0);

    }
  }
};
class MinheapIpo
{
  public:
  vector <vector<int>> ht;

  void downheap(int i)
  {
    int left=2*i+1;
    int right=2*i+2;
    int lar=i;
    int size=ht.size();
    if(left<size && ht[left][0]<ht[lar][0])
    {
      lar=left;
    }
    if(right<size && ht[right][0]<ht[lar][0])
    {
      lar=right;
    }
    if(lar!=i)
    {
      swap(&ht[lar][0],&ht[i][0]);
       swap(&ht[lar][1],&ht[i][1]);
      downheap(lar);
    }
  }
  void upheap(int i)
  {
    if(i==0)
    {
      return;
    }
      int parent=(i-1)/2;
      if(ht[i][0]<ht[parent][0])
      {
        swap(&ht[i][0],&ht[parent][0]);
         swap(&ht[i][1],&ht[parent][1]);
        upheap(parent);
      }

  }
  void insert(vector<int> v)
  {
    if(ht.size()==0)
    {
      ht.push_back(v);
    }
    else
    {
      ht.push_back(v);
      upheap(ht.size()-1);
    }
  }
  int peek()
  {
    if(ht.size()==0)
    {
      return -1;
    }
    else
    {
      return ht[0][1];
    }
  }
  void deleteNode()
  {
    if(ht.size()==0)
    {
      
      return;
    }
    else
    {
      swap(&ht[0][0], &ht[ht.size()-1][0]);
      swap(&ht[0][1], &ht[ht.size()-1][1]);
      ht.pop_back();
      // Heapify from the root
      downheap(0);

    }
  }
};

int main()
{
  MinheapNode h;
  int i;
  for(i=0;i<6;i++)
  {
      ListNode* temp=new ListNode(i);
      h.insert(temp);
  }

  
 //vector <int> ans=h.ht;
 while(h.ht.size()!=0)
  {
    
      cout<<h.peek()<<endl;
      h.deleteNode();
    cout<<endl;
  }
  
}
