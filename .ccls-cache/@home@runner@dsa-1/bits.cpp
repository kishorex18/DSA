/*#include <bits/stdc++.h>
using namespace std;
int b2d(string s)
{
  int p=1;
  int ans=0;
  int i;
  for(i=s.size()-1;i>=0;i--)
    {
      if(s[i]=='1')
      {
        ans+=p;
      }
      p=p<<1;
    }
  return ans;
}
string d2b(int n)
{
  string ans="";
  while(n>1)
    {
      if((n&1)==1)
        ans='1'+ans;
      else
        ans='0'+ans;
      n=n>>1;
    }
  if(n==1)
    ans='1'+ans;
  else
    ans='0'+ans;
  return ans;
}
vector<int> swap(int a,int b)
{
  a=a^b;
  b=a^b;//(a^b)^b=a
  a=a^b;//(a^b)^a=b
  vector<int> ans;
  ans.push_back(a);
  ans.push_back(b);
  return ans;
}

bool checkithBit(int n,int i)
{
  return 1&(n>>i);
}

int setithBit(int n,int i)
{
  return n|(1<<i);
}

int clearithBit(int n,int i)
{
  return n&~(1<<i);
}

int toggleithBit(int n,int i)
{
  return n^(1<<i);
}

int removelastsetBit(int n)
{
  return n&(n-1);
}

int checkpower2(int n)
{
  if((n&(n-1))==0)
  { 
    return 1;
    
  }
  else
  {
    return 0;
  }
}
int countbits(int n)
{
  int count=0;
  while(n>1)
    {
      count+=n&1;
      n=n>>1;
    }
  if(n==1)count+=1;
  return count;
}
vector<vector<int>> powerset(vector<int> arr)
{
  int subsets=1<<arr.size();
  int i,j;
 
  vector<vector<int>> ans;
  for(i=0;i<subsets;i++)
    {
      
      vector<int> list;
      for(j=0;j<arr.size();j++)
        {
         
          if(i & (1<<j))
          {
            list.push_back(arr[j]);
          }
        }
      ans.push_back(list);
    }
  return ans;
}

int minflip(int num,int tar)
{
  return countbits(num^tar);
}
int main()
{
 
  cout<<maxans<<endl;
  return 0;
}*/