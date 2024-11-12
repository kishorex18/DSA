/*#include <bits/stdc++.h>

using namespace std;

class rstack {
public:
  stack<int> first, second;

  rstack(stack<int> s1, stack<int> s2) {
    first = s1;
    second = s2;
  }

  void push(int num) {
    while (first.size() != 0) {
      second.push(first.top());
      first.pop();
    }
    second.push(num);
    while (second.size() != 0) {
      first.push(second.top());
      second.pop(); 
    }
  }

  void pop() {
    first.pop();
  }

  int front() {
    return first.top();
  }
};

class pstack {
  public:
  stack<int> first, second;
  pstack(stack<int> s1, stack<int> s2) {
    first = s1;
    second = s2;
  }

  void push(int num) {
    first.push(num);
  }

  void pop() {
    while(first.size()!=0)
    {
        second.push(first.top());
        first.pop();
    }
    if(second.size()!=0)
    {
    second.pop();
    }
    else
    {
      cout<<"No elements"<<endl;
    }
    while(second.size()!=0)
    {
        first.push(second.top());
        second.pop();
    }
  }

  int front() {
    int ans=-1;
    while(first.size()!=0)
      {
          second.push(first.top());
          first.pop();
      }
      if(second.size()!=0)
      {
        ans=second.top();
      }
      while(second.size()!=0)
      {
          first.push(second.top());
          second.pop();
      }
    return ans;
  }
};
int pre(char s)
{
  if(s=='^')
  {
    return 3;
  }
  if(s=='*' || s=='/')
  {
    return 2;
  }
  if(s=='+' || s=='-')
  {
      return 1;
  }
  return 0;
}
bool isOperator(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
string postfix(string s)
{
  stack <char> st;
  string ans="";
  int i;
  for(i=0;i<s.size();i++)
  {
      if(s[i]=='(')
      {
         cout<<"it is open"<<endl;
        st.push(s[i]);
         cout<<"ans;"<<ans<<endl;
        continue;
      }
      if(s[i]==')')
      {
        cout<<"it is close"<<endl;
        while(st.size()!=0 && st.top()!='(')
        {
            cout<<"sttop"<<st.top()<<endl;
            ans+=st.top();
            st.pop();
        }
         cout<<"sttop"<<st.top()<<endl;
        st.pop();
        cout<<"ans;"<<ans<<endl;
        continue;
      }
      if(isOperator(s[i]))
      {
        if(st.size()==0)
        {
          cout<<"it is empty"<<endl;
          cout<<s[i]<<endl;
          st.push(s[i]);
           cout<<"ans;"<<ans<<endl;
          continue;
        }
        else
        {
          if(pre(s[i])>pre(st.top()))
          {
            cout<<"it is in correct order"<<endl;
            cout<<s[i]<<endl;
            st.push(s[i]);
             cout<<"ans;"<<ans<<endl;
            continue;
          }
          else
          {
            cout<<"it is not in correct order"<<endl;
            while(pre(s[i])<=pre(st.top()))
            {
                cout<<"sttop"<<st.top()<<endl;
                ans+=st.top();
                st.pop();
            }
             cout<<"ans;"<<ans<<endl;
             cout<<s[i]<<endl;
            st.push(s[i]);
            continue;
          }
        }
      }
      else
      {
        cout<<"it is operand"<<endl;
        ans+=s[i];
         cout<<"ans;"<<ans<<endl;
      }
  }
 while(st.size()!=0)
   {
     ans+=st.top();
     st.pop();
   }
  return ans;
}
vector<int> nge(vector<int> arr)
{
  stack<int> st;
  vector<int> ans;
  int i,n=arr.size();
  for(i=n-1;i>=0;i--)
    {
      if(st.size()==0)
      {
        ans.push_back(-1);
        st.push(arr[i]);
      }
      else if(st.top()>arr[i])
      {
        ans.push_back(st.top());
         st.push(arr[i]);
      }
      else if(st.top()<=arr[i])
      {
        while(st.size()!=0 && st.top()<=arr[i])
        {
            st.pop();
        }
        if(st.size()!=0)
        {
          ans.push_back(st.top());
        }
        else
        {
          ans.push_back(-1);
        }
        st.push(arr[i]);
      }
    }
  return ans;
}
vector<int> pse(vector<int> arr)
{
  stack<int> st;
  vector<int> ans;
  int i,n=arr.size();
  for(i=0;i<n;i++)
    {
      if(st.size()==0)
      {
        ans.push_back(-1);
        st.push(i);
      }
      else if(arr[st.top()]<arr[i])
      {
        ans.push_back(st.top());
         st.push(i);
      }
      else if(arr[st.top()]>=arr[i])
      {
        while(st.size()!=0 && arr[st.top()]>=arr[i])
        {
            st.pop();
        }
        if(st.size()!=0)
        {
          ans.push_back(st.top());
        }
        else
        {
          ans.push_back(-1);
        }
        st.push(i);
      }
    }
  return ans;
}
int largerectangle(vector<int> arr)
{
  vector <int> temp=pse(arr);
  int i=0;
  int maxi=INT_MIN;
  for(i=0;i<arr.size();i++)
    {
      if(temp[i]==-1)
      {
        maxi=max(maxi,(i+1)*arr[i]);
      }
      else
      {
        maxi=max(maxi,((i-temp[i])+1)*arr[temp[i]]);
      }
    }
  return maxi;
}
int main() {

  vector <int> arr={1,2,2,5,6,3,2};
  vector <int> ans=pse(arr);
  int i;
  for(i=0;i<ans.size();i++)
    {
      cout<<ans[i]<<endl;
    }
  cout<<"max:"<<largerectangle(arr)<<endl;
  return 0;
}*/