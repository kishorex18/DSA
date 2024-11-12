/*#include <bits/stdc++.h>
using namespace std;
int minmoves(vector<int>arr)
{
  map <int,int> mp;
  int i,j;
  for(i=0;i<arr.size();i++)
    {
      mp.insert(i+1,arr[i]);
    }
  int minmove=0;
  int cur=1;
  int flag=0;
  for(i=0;i<arr.size();i++)
    {
     
      for(j=1;j<5;j++)
        {
          int m;
          if(mp[i+j]!=1)
          {
           cur=max(cur,mp[i+j]);
           m=0;
          }
          else
          {
            cur=max(cur,cur+j);
            m=1;
          }
          minmove=minmove+m;
          if(cur==arr.size()+1)
          {
            return minmove;
          }
        }
    }
  return minmove;
}
int main()
{
  
}*/