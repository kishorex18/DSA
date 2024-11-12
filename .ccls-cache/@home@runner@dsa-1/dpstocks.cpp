/*#include <bits/stdc++.h>
using namespace std;
int stocks1(vector<int>& prices)
{
  int curmin,i,pro=INT_MIN;
  int n=prices.size();
  curmin=prices[0];
  for(i=1;i<n;i++)
    {
      pro=max(pro,prices[i]-curmin);
      if(prices[i]<curmin)
      {
        curmin=prices[i];
      }
    }
  if(pro<0)
  {
    pro=-1;
  }
  return pro;
}
int stocks2(vector<int>&prices)
{
  int n=prices.size();
  int k,j;
  vector<vector<int>> dp(n+1,vector<int>(2,-1));
  dp[n][0]=0;
  dp[n][1]=0;
  for(k=n-1;k>=0;k--)
    {
      for(j=0;j<2;j++)
        {
          if(j==0)
          {
            dp[k][j]=max(prices[k]+dp[k+1][1],dp[k+1][0]);
          }
          else
          {
             dp[k][j]=max(-prices[k]+dp[k+1][0],dp[k+1][1]);
          }
          cout<<dp[k][j]<<" ";
        }
      cout<<endl;
    }
  return dp[0][1];
    
}
int stocks5(vector<int>&prices)
{
  int n=prices.size();
  int k,j;
  vector<vector<int>> dp(n+2,vector<int>(2,0));
  dp[n][0]=0;
  dp[n][1]=0;
  for(k=n-2;k>=0;k--)
    {
      for(j=0;j<2;j++)
        {
          if(j==0)
          {
            dp[k][j]=max(prices[k]+dp[k+1][1],dp[k+1][0]);
          }
          else
          {
             dp[k][j]=max(-prices[k]+dp[k+2][0],dp[k+1][1]);
          }
          cout<<dp[k][j]<<" ";
        }
      cout<<endl;
    }
  return dp[0][1];

}
int stocks3(vector<int>prices,int i,int b,int c)
{
  
  if(c==0)
  {
    return 0;
  }
  if(i==prices.size())
  {
    return 0;
  }
  if(b==1)
  {
    return max(-prices[i]+stocks3(prices,i+1,0,c),stocks3(prices,i+1,1,c));
  }
  else
  {
    return max(prices[i]+stocks3(prices,i+1,1,c-1),stocks3(prices,i+1,0,c));
  }
}
int main()
{
  vector<int> prices={4,5,1,6,7,2,3};

  
  cout<<stocks5(prices)<<endl;
}
*/