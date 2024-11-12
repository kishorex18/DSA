#include <bits/stdc++.h>
using namespace std;

class ListNode
{
  public:
  int val;
  ListNode* next;
  ListNode(int x)
 {
    val=x;
 }
};

class llist
{
  public:
  ListNode* head=new ListNode(-1);
  ListNode* current=head;
  void pushback(int v)
  {
    ListNode* temp=new ListNode(v);
    current->next=temp;
    current=temp;
  }
  int len(ListNode* n)
  {
   int i=0;
    while(n!=nullptr)
      {
        i++;
        n=n->next;
      }
    return i;
  }
};
void display(ListNode* head)
{
  if(head==nullptr)
  {
    cout<<"END"<<endl;
    return;
  }
  cout<<head->val<<"->";
  display(head->next);
}

ListNode* insert(ListNode* node,int val,int index)
{
  if(index==0)
  {
    cout<<"base condtion"<<endl;
    ListNode* n=new ListNode(val);
    cout<<n->val<<endl;
    n->next=node;
    cout<<node->val<<endl;
    return n;
  }
   cout<<"before"<<node->val<<endl;
  if(node->next!=nullptr)
  {
  node->next=insert(node->next,val,index-1);
  }
  cout<<"after"<<node->val<<endl;
  return node;
}
ListNode* removeDuplicate(ListNode* head)
{
  ListNode* ans=new ListNode(-1);
  ListNode* mover=ans;
  ListNode* current=head;
  ListNode* pre=new ListNode(-1);
  ListNode* next=head->next;
  while(current!=nullptr)
  {
    
    if(next==nullptr)
    {
      if(pre->val!=current->val)
      {
        int val=current->val;
        ListNode* temp=new ListNode(val);
        mover->next=temp;
        mover=temp;
        
      }
      break;
    }
    cout<<"P:"<<pre->val<<" C:"<<current->val<<" N:"<<next->val<<endl;
    if(pre->val!=-1 && next->val!=current->val && pre->val!=current->val)
    {
      int val=current->val;
      ListNode* temp=new ListNode(val);
      mover->next=temp;
      mover=temp;

    }
    
    pre=current;
    current=next;
    next=next->next;
  }
  return ans->next;
}
ListNode* rotate(ListNode* head,int n,int len)
{
  if(n%len!=0)
  {
  int roatations=n%len;
  ListNode* tail=head;
  ListNode* newHead=head;
   ListNode* newEnd;
  int i=1;
  while(tail->next!=nullptr)
  {
    if(i==len-roatations)
      {
        newEnd=tail;
      }
    tail=tail->next;
    i++;
  }
  newHead=newEnd->next;
  tail->next=head;
  newEnd->next=nullptr;

  return newHead;
  }
  return head;
}
ListNode* removeNthFromEndHelper(ListNode* head, int& k) {
  if (head == nullptr) {
    return head;
  }

  head->next = removeNthFromEndHelper(head->next, k); // Recursive call
  k = k - 1;  
  cout << k << endl; // Debugging line

  if (k == 0) {
    return head->next; // Skip the node to remove
  }

  return head; // Return the current node
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
  return removeNthFromEndHelper(head, n); // Pass n as a reference
}

ListNode* reverse(ListNode* head)
{
  ListNode* pre=nullptr;
  ListNode* c=head;
  while(c!=nullptr)
    {
      ListNode* temp=c->next;
      c->next=pre;
      pre=c;
      c=temp;
    }
  return pre;
}
ListNode* reverseStart(ListNode* head,int s,int e)
{
  int i;
  ListNode* npre;
  ListNode* pre=nullptr;
  ListNode* n=head;
  ListNode* start;
  ListNode* end=nullptr;
  for(i=1;i<=e;i++)
  {
   
    if(i==s)
    {
      npre=pre;
      start=n;
    }
      if(e==i)
      {
        end=n;
        break;
      }
    pre=n;
    n=n->next;
  }
 
  ListNode* nend=end->next;
  end->next=nullptr;
  ListNode* nstart=reverse(start);
  start->next=nend;
  if(npre!=nullptr)
  {
    npre->next=nstart;
    return head;
  }
  else
  {
    return nstart;
  }
}
ListNode* reverseKNodes(ListNode* head,int k)
{
  int i=1;
  ListNode* n=head;
  ListNode* pre=nullptr;
  ListNode* start,*end,*nstart,*nend;
  ListNode* newHead=head;
   ListNode* npre=nullptr;
  if(k==1 || head==nullptr || head->next==nullptr)
  {
    return head;
  }
  while(n!=nullptr)
  {
      
     // cout<<"i:"<<i<<endl;
     // cout<<"c:"<<n->val<<endl;
    ListNode* temp=n->next;
  
      if(i%k==1)
      {
       // cout<<"First Pass:"<<endl;
        start=n;
        npre=pre;
        //cout<<"S:"<<start->val<<endl;
        if(npre!=nullptr)
        {
        //cout<<"npre:"<<npre->val<<endl;
        }
        pre=start;
      }
      if(i%k==0)
      { 
         pre=start;
        //cout<<"Second Pass:"<<endl;
        end=n;
        //cout<<"E:"<<end->val<<endl;
        nend=end->next;
      // cout<<"NE:"<<nend->val<<endl;
        end->next=nullptr;
       // cout<<"S:"<<start->val<<endl;
        nstart=reverse(start);
       // cout<<"NS:"<<nstart->val<<endl;
        start->next=nend;
        //cout<<"startnext:"<<start->next->val<<endl;
        if(npre!=nullptr)
        {
         // cout<<"Npre:"<<npre->val<<endl;
          npre->next=n;
          //cout<<"Nprenext:"<<npre->next->val<<endl;
        }
        else
        {
          newHead=nstart;
          head=newHead;
          //cout<<"Head:"<<head->val<<endl;
        }
       
      }
    
    n=temp;
    i++;
  }
  return head;
}

int main()
{
  llist ll;
  for(int i=1;i<=9;i++)
    {
      ll.pushback(i);
    }
  display(ll.head->next);
  //int len=ll.len(ll.head->next);
  //display(rotate(ll.head->next,4,len));
  
  //display(removeNthFromEnd(ll.head->next,4));
//display(reverseKNodes(ll.head->next,1));
  
}