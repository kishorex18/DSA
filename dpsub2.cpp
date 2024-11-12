#include <bits/stdc++.h>
using namespace std;
int lis(vector<int> arr,int cur,int pre,vector<vector<int>>dp)
{
  cout<<"cur:"<<cur<<" pre"<<pre<<endl;
  if(cur==arr.size())
  {
    cout<<"End of list"<<endl;
    return 0;
  }
  if(dp[cur][pre]!=-1)
  {
    return dp[cur][pre];
  }
  if(cur==pre)
  {
    cout<<"one element"<<endl;
    return dp[cur][pre]=1+lis(arr,cur+1,cur,dp);
  }
  if(arr[cur]>arr[pre])
  {
     cout<<"increasing"<<endl;
     return dp[cur][pre]=1+lis(arr,cur+1,cur,dp);
  }
  else
  {
    cout<<"not take"<<endl;
    return dp[cur][pre]=lis(arr,cur+1,pre,dp);
  }
}
int listab(vector<int> arr)
{
  int i,j;
   vector<vector<int>>dp(arr.size()+1,vector<int>(arr.size()+1,0));
  for(i=arr.size()-1;i>=0;i--)
    {
      for(j=i-1;j>=-1;j--)
        {
          int take=0;
          int notTake=dp[i+1][j+1];
          if(j==-1|| arr[j]<arr[i])
          {
            
            take=1+dp[i+1][i+1];
          }
          dp[i][j+1]=max(take,notTake);
        }
    }
  return dp[0][0];
}
int listab2(vector<int> arr)
{
  int i,j,maxi=1;
  int maxind=0;
 vector<int> ans;
  vector<int> hash(arr.size(),1);
  for(i=0;i<arr.size();i++)
    {
      hash[i]=i;
    }
  vector<int> dp(arr.size(),1);
  for(i=0;i<arr.size();i++)
    {
      for(j=0;j<i;j++)
        {
          if(arr[i]>arr[j])
          {
            if(dp[i]<dp[j]+1)
            {
              dp[i]=dp[j]+1;
              hash[i]=j;
            }
  
          }
         
        }
      if(maxi<dp[i])
      {
        maxi=dp[i];
        maxind=i;
      }
    }
  ans.push_back(arr[maxind]);
  while(hash[maxind]!=maxind)
    {
      maxind=hash[maxind];
      ans.push_back(arr[maxind]);
    }
  for(i=0;i<ans.size();i++)
    {
      cout<<ans[i]<<endl;
    }
  return maxi;
}
int main()
{
 vector<int> coins={1,3,5};
 int amount=11;
  
  vector<vector<int>>dp(coins.size(),vector<int>(amount+1,0));
  int i,j,n=coins.size();
  for(i=0;i<=amount;i++)
  {
      if(amount%coins[0]==0)
      {
          dp[0][i]=j/coins[0];
      }
      else
      {
          dp[0][i]=1e9;
      }
  }
  for(i=1;i<n;i++)
  {
      for(j=0;j<amount+1;j++)
      {

          int notTake=dp[i-1][j];
           int take=1e9;
          if(j>=coins[i])
          {
              take=1+dp[i][j-coins[i]];
          }
          dp[i][j]=min(take,notTake);
      }
  }
  
}