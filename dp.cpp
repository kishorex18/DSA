/*#include <bits/stdc++.h>
using namespace std;

int frogjumps(vector<int>&nums,vector<int>&dp,int ind)
{
  if(ind==0 || ind<0)
  {
    cout<<"Base"<<endl;
    return 0;
  }
  if(dp[ind]!=-1)
  {
    cout<<"stored"<<endl;
    return dp[ind];
  }
  int oneJump=frogjumps(nums,dp,ind-1)+abs(nums[ind-1]-nums[ind]);
  cout<<"Onejump"<<endl;
  cout<<"nums1:"<<nums[ind]<<" nums2:"<<nums[ind-1]<<endl;
  int twoJump=INT_MAX;
  if(ind>1)
  {
    cout<<"Twojump"<<endl;
    twoJump=frogjumps(nums,dp,ind-2)+abs(nums[ind-2]-nums[ind]);
    cout<<"nums1:"<<nums[ind]<<" nums2:"<<nums[ind-2]<<endl;
  }
  dp[ind]=min(oneJump,twoJump);
  return dp[ind];
}
int frogKjumps(vector<int>&nums,vector<int>&dp,int ind,int k)
{
  if(ind==0 || ind<0)
  {
    cout<<"Base"<<endl;
    return 0;
  }
  if(dp[ind]!=-1)
  {
    cout<<"stored"<<endl;
    return dp[ind];
  }
  int Min=INT_MAX;
  for(int i=1;i<=k;i++)
  {
      if(ind>=i)
      {
      int temp=frogKjumps(nums,dp,ind-k,k)+abs(nums[ind]-nums[ind-k]);
      Min=min(Min,temp);
      }
      else
      {
        break;
      }
  }
  dp[ind]=Min;
  return dp[ind];
}
int training(vector<vector<int>>& data,vector<vector<int>>& dp,int day,int last)
{

 
   
  if(dp[day][last]!=0)

  {
    
    return dp[day][last];
  }
  if(day==0)
  {
     
    int i,maxi=0;
    for(i=0;i<3;i++)
      {
        if(i!=last)
        {
           
          maxi=max(maxi,data[0][i]);
        }
      }
     cout<<"maxi:"<<maxi<<endl;
     dp[0][last]=maxi;
     return dp[0][last];
  }

   
 
 
    
  int i,maxi=0;
  
  for(i=0;i<3;i++)
  {
      
      if(i!=last)
      {

        cout<<"i:"<<i<<endl;
        cout<<"ele:"<<data[day][i]<<endl;
        int perm=data[day][i]+training(data,dp,day-1,i);
        maxi=max(maxi,perm);
       
      }
   }
  dp[day][last]=maxi;
  return dp[day][last];
  
}
int tabtraining(vector<vector<int>> &nums)
{
  vector<int> dp(4,0);
  dp[0]=max(nums[0][1],nums[0][2]);
  dp[1]=max(nums[0][0],nums[0][2]);
  dp[2]=max(nums[0][0],nums[0][1]);
  dp[3]=max(nums[0][0],nums[0][1]);
  dp[3]=max(dp[3],nums[0][3]);
  int day,last,task;
  for(day=1;day<nums.size();day++)
    {
      vector<int> temp(4,0);
      for(last=0;last<4;last++)
        {
            
          
          for(task=0;task<3;task++)
            {
              if(last!=task)
              {
                temp[last]=max(dp[last],dp[task]+nums[day][task]);
              }
            }
        }
      dp=temp;
    }
  return dp[3];
}
int uniquepaths(vector<vector<int>>&dp,int i,int j)
{
  if(i==0 && j==0)
  {
    return 1;
  }
  if(i<0 || j<0)
  {
    return 0;
  }
  if(dp[i][j]!=0)
  {
    cout<<"Visited"<<endl;
    return dp[i][j];
  }
  int up,left;
  up=0;
  left=0;
  if(i>0)
  {
    up=uniquepaths(dp,i-1,j);
  }
  if(j>0)
  {
    left=uniquepaths(dp,i,j-1);
  }
  return dp[i][j]=up+left;
}
int tabuniquepaths(int r,int c)
{
   vector<vector<int>> dp (r,vector<int>(c,0));
   int i,j;
   for(i=0;i<r;i++)
     {
       for(j=0;j<c;j++)
         {
           int up=0;
           int left=0;
           if(i==0 && j==0)
           {
             dp[i][j]=1;
             continue;
           }
           if(i>0)
             up=dp[i-1][j];
           if(j>0)
             left=dp[i][j-1];
           dp[i][j]=up+left;
         }
     }
  return dp[r-1][c-1];
}
int tabminsumpaths(vector<vector<int>> &nums)
{
  vector<int>dp(nums[0].size(),0);
  int i,j,sum=0;
  for(i=0;i<dp.size();i++)
    {
      sum+=nums[0][i];
      dp[i]=sum;
      cout<<"dp[i]:"<<dp[i]<<endl;
    }
  for(i=1;i<nums.size();i++)
    {
      vector<int>temp(dp.size(),0);
      for(j=0;j<dp.size();j++)
        {
          if(j>0)
          {
            temp[j]=min(temp[j-1],dp[j]);
            
          }
          else
          {
            temp[j]=dp[j];
          }
          temp[j]+=nums[i][j];
          cout<<"temp[j]:"<<temp[j]<<endl;
        }
      dp=temp;
    }
  return dp[dp.size()-1];
}
int triangle(vector<vector<int>>nums)
{
  int n=nums.size();
  vector<int>dp(n,-1);
  int i,j;
  for(i=0;i<n;i++)
    {
      dp[i]=nums[n-1][i];
    }
  for(i=n-2;i>=0;i--)
    {
      vector<int>temp(i+1,-1);
      for(j=i;j>=0;j--)
        {
          int down=dp[j];
          int dia=dp[j+1];
          temp[j]=nums[i][j]+min(down,dia);
        }
      dp=temp;
    }
  return dp[0];
}
int minsumpaths(vector<vector<int>> &nums,vector<vector<int>>&dp,int r,int c)
{
  if(r==0 && c==0)
  {
    return nums[0][0];
  }
  if(r<0 || c<0)
  {
    return INT_MAX;
  }
  if(dp[r][c]!=0)
  {
    return dp[r][c];
  }
  int up=(r>0)?nums[r][c]+minsumpaths(nums,dp,r-1,c):INT_MAX;
  int left=(c>0)?nums[r][c]+minsumpaths(nums,dp,r,c-1):INT_MAX;
  return dp[r][c]=min(up,left);
}
int main()
{
  vector<vector<int>> nums={{10,20,10},{10,20,10},{10,30,10}};
  vector<vector<int>> num={{1},{2,3},{4,5,6},{8,7,9,10}};
  vector<vector<int>> dp (3,vector<int>(3,0));
  int i,j;
  for(i=0;i<nums.size();i++)
    {
      vector<int> temp;
      for(j=0;j<4;j++)
        {
          temp.push_back(0);
        }
      dp.push_back(temp);
    }

  cout<<training(nums,dp,3,3)<<endl;
  for(i=0;i<nums.size();i++)
    {
      
      for(j=0;j<4;j++)
        {
          cout<<dp[i][j]<<" ";
        }
      cout<<endl;
    }

 //cout<<minsumpaths(nums,dp,2,2);
 //cout<<tabminsumpaths(nums)<<endl;
  cout<<triangle(num)<<endl;
}*/