#include <bits/stdc++.h>
using namespace std;

bool subsum(vector<int>nums,int ind,int target,vector<vector<int>> &dp)
{
  cout<<"ind:"<<ind<<" tar:"<<target<<endl;
  if(target==0)
  {
    return 1;
  }
  if(ind<0)
  {
    return 0;
  }
  if(dp[ind][target]!=-1)
  {
    return dp[ind][target];
  }
  if(ind==0 && target==nums[0])
  {
    return 1;
  }
  
  bool pick=0;
  if(nums[ind]<=target)
  {
  pick=subsum(nums,ind-1,target-nums[ind],dp);
  }
  bool notpick=subsum(nums,ind-1,target,dp);
  return dp[ind][target]=pick||notpick;
}
bool equalsubsethelper(vector<int> nums,vector<vector<int>> dp,int& tot)
{
  if(tot%2!=0)
    return 0;
  else
    return subsum(nums,nums.size()-1,tot/2,dp);
}
bool equalsubset(vector<int> nums,vector<vector<int>> dp)
{
  int total=0;
  for(int i=0;i<nums.size();i++)
    {
      total+=nums[i];
    }
  return equalsubsethelper(nums,dp,total);
}
int sum(vector<int> nums)
{
  int i,tot=0;
  for(i=0;i<nums.size();i++)
    {
      tot+=nums[i];
    }
  return tot;
}
int subsetmindif(vector<int> nums)
{
  int ind,tar;
  int target=sum(nums);
  vector<vector<bool>>dp(nums.size(),vector<bool>(target+1,0));
  for(ind=0;ind<nums.size();ind++)
    {
      dp[ind][0]=1;
    }
  dp[0][nums[0]]=1;
  vector<bool> pre(target+1,0);
  pre[0]=1;
  if(nums[0]<=target)
    pre[nums[0]]=1;
  for(ind=1;ind<nums.size();ind++)
    {
      vector<bool> cur(target+1);
      for(tar=0;tar<target+1;tar++)
        {
          bool notpick,pick=0;
          notpick=pre[tar];
          if(tar>=nums[ind])
            pick=pre[tar-nums[ind]];
          cur[tar]=pick||notpick;
        }
      pre=cur;
    }
  int mini=INT_MAX;
  for(ind=0;ind<=target/2;ind++)
    {
      if(pre[ind]==1)
      {
      mini=min(mini,abs(ind-(target-ind)));
      cout<<"s1:"<<ind<<endl;
      cout<<"s2:"<<target-ind<<endl;
      cout<<"mini"<<mini<<endl;
      }
    }
  return mini;
}
bool subsetWithDiff(vector<int> nums,int diff)
{
  int ind,tar;
  int target=sum(nums);
  vector<bool> pre(target+1,0);
  pre[0]=1;
  if(nums[0]<=target)
    pre[nums[0]]=1;
  for(ind=1;ind<nums.size();ind++)
    {
      vector<bool> cur(target+1);
      for(tar=0;tar<target+1;tar++)
        {
          bool notpick,pick=0;
          notpick=pre[tar];
          if(tar>=nums[ind])
            pick=pre[tar-nums[ind]];
          cur[tar]=pick||notpick;
        }
      pre=cur;
    }
  return ((target-diff)%2==0) && (pre[(target-diff)]);
}
int knapsack(vector<int>nums,vector<int>weights,int ind,int weight,vector<vector<int>>dp)
{
  if(weight==0)
    return 0;
  if(ind<0)
    return 0;
  if(ind==0 && weights[0]<=weight)
    return nums[0];
  if(dp[ind][weight]!=-1) return dp[ind][weight];
  int notpick,pick=0;
  notpick=knapsack(nums,weights,ind-1,weight,dp);
  if(weights[ind]<=weight)
    pick=nums[ind]+knapsack(nums,weights,ind-1,weight-weights[ind],dp);
  return dp[ind][weight]=max(pick,notpick);
}
int knapsacktab(vector<int>nums,vector<int>weights,int weight)
{
  int w,ind;
  vector<vector<int>>dp(nums.size(),vector<int>(weight+1,0));
  for(w=0;w<=weight;w++)
    {
      if(weight>=weights[0])
        dp[0][weight]=nums[0];
    }
  vector<int> pre(weight+1,0);
  if(weight>=weights[0])
    pre[0]=nums[0];
  for(ind=1;ind<nums.size();ind++)
    {
      vector<int> cur(weight+1,0);
      for(w=0;w<=weight;w++)
        {
            int notpick,pick=0;
            notpick=pre[weight];
            if(weight>=weights[ind])
              pick=nums[ind]+pre[weight-weights[ind]];
            cur[weight]=max(pick,notpick);
        }
      pre=cur;
    }
  return pre[weight];
}
int coinchange(vector<int>&denom,int ind,int target,vector<vector<int>> dp)
{
  
  if(ind<0)
  {
    return 0;
  }
 
  if(ind==0)
  {
    if(target%denom[0]==0)
    {
      return target/denom[0];
    }
    else
    {
      return 1e9;
    }
  }
  if(dp[ind][target]!=-1)
  {
    return dp[ind][target];
  }
  int take=1e9;
  if(target>=denom[ind])
  {
  take=1+coinchange(denom,ind,target-denom[ind],dp);
  }
  int notTake=coinchange(denom,ind-1,target,dp);
  
  
  return dp[ind][target]=min(take,notTake);
  
}
int coinchangeways(vector<int>&denom,int ind,int target,vector<vector<int>> dp)
{

  if(ind<0)
  {
    return 0;
  }

  if(ind==0)
  {
    if(target%denom[0]==0)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
  if(dp[ind][target]!=-1)
  {
    return dp[ind][target];
  }
  int take=0;
  
  int notTake=coinchange(denom,ind-1,target,dp);
  if(target>=denom[ind])
    {
    take=coinchange(denom,ind,target-denom[ind],dp);
    }

  return dp[ind][target]=take+notTake;

}
int main()
{
  vector<int> nums={2,3,5,5,10,2,2,2,2};
  //int target=sum(nums);
  //vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
  //cout<<equalsubset(nums,dp);
  //cout<<subsetmindif(nums);
  int target=10;
  int n=nums.size();
  vector<vector<int>>dp(n,vector<int>(target+1,-1));
  cout<<coinchangeways(nums,n-1,target,dp);
}