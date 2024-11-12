/*#include <bits/stdc++.h>
using namespace std;

int lcs(string s1,string s2,int i,int j,vector<vector<int>> &dp)
{
  if(i<0 || j<0)
  {
    return 0;
  }
  if(dp[i][j]!=-1)
  {
    //cout<<"repeated"<<endl;
    return dp[i][j];
  }
  int eq,neq;
  eq=0;
  neq=0;
  if(s1[i]==s2[j])
  {
    //cout<<"if"<<endl;
    return dp[i][j]=1+lcs(s1,s2,i-1,j-1,dp);
  }
  else
  {
    //cout<<"else"<<endl;
    return dp[i][j]=max(lcs(s1,s2,i-1,j,dp),lcs(s1,s2,i,j-1,dp));
  }
  
}
int lcstab(string s1,string s2)
{
  int n,m,i,j;
  n=s1.size();
  m=s2.size();
  vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
  for(i=0;i<=n;i++)
    {
      dp[i][0]=0;
    }
  for(j=0;j<=m;j++)
    {
      dp[0][j]=0;
    }
  for(i=1;i<=n;i++)
    {
      for(j=1;j<=m;j++)
        {
          if(s1[i-1]==s2[j-1])
          {
            dp[i][j]=1+dp[i-1][j-1];
          }
          else
          {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
          }
         
        }
      
    }

  return dp[n][m];
}
int lcsubstringtab(string s1,string s2)
{
  int n,m,i,j;
  n=s1.size();
  m=s2.size();
  vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
  for(i=0;i<=n;i++)
    {
      dp[i][0]=0;
    }
  for(j=0;j<=m;j++)
    {
      dp[0][j]=0;
    }
  int maxi=0;
  for(i=1;i<=n;i++)
    {
      for(j=1;j<=m;j++)
        {
          if(s1[i-1]==s2[j-1])
          {
            dp[i][j]=1+dp[i-1][j-1];
          }
          else
          {
            dp[i][j]=0;
          }
          maxi=max(maxi,dp[i][j]);
          cout<<dp[i][j]<<" ";
        }
      cout<<endl;
    }

  return maxi;
}
string lcstabdisplay(string s1,string s2)
{
  int n,m,i,j;
  n=s1.size();
  m=s2.size();
  vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
  for(i=0;i<=n;i++)
    {
      dp[i][0]=0;
    }
  for(j=0;j<=m;j++)
    {
      dp[0][j]=0;
    }
  for(i=1;i<=n;i++)
    {
      for(j=1;j<=m;j++)
        {
          if(s1[i-1]==s2[j-1])
          {
            dp[i][j]=1+dp[i-1][j-1];
          }
          else
          {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
          }
          cout<<dp[i][j]<<" ";
        }
      cout<<endl;
    }
  string ans="";
  
        while(i>0 && j>0)
        {
          if(s1[i-1]==s2[j-1])
          {
            ans=s1[i-1]+ans;
            i--;
            j--;
          }
          else
          {
            if(dp[i-1][j]<dp[i][j-1])
            {
              j--;
            }
            else
            {
              i--;
            }
          }
        }
   return ans;
}
int lps(string s1)
{
  string r=s1;
  reverse(r.begin(),r.end());
  return lcstab(s1,r);
}

int distinct(string s1,string s2,int i,int j,vector<vector<int>> &dp)
{
  if(j<0)
  {
    return 1;
  }
  if(i<0)
  {
    return 0;
  }
  if(dp[i][j]!=-1)
  {
    //cout<<"repeated"<<endl;
    return dp[i][j];
  }
  int eq,neq;
  eq=0;
  neq=0;
  if(s1[i]==s2[j])
  {
    //cout<<"if"<<endl;
    dp[i][j]=distinct(s1,s2,i-1,j-1,dp)+distinct(s1,s2,i-1,j,dp);
  }
  else
  {
    //cout<<"else"<<endl;
    dp[i][j]=distinct(s1,s2,i-1,j,dp);
  }
  return dp[s1.size()-1][s2.size()-1];
}
int distincttab(string s1,string s2)
{
 
  int n,m,i,j;
  n=s1.size();
  m=s2.size();
  vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
  for(i=0;i<=n;i++)
    {
      dp[i][0]=1;
    }
  for(j=1;j<=m;j++)
    {
      dp[0][j]=0;
    }
  
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=m;j++)
   {
      if(s1[i-1]==s2[j-1])
    {
      //cout<<"if"<<endl;
      dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
    }
    else
    {
      //cout<<"else"<<endl;
      dp[i][j]=dp[i-1][j];
    }
      }
  }
  
  return dp[n][m];
}

int main()
{
  string s1,s2;
  s1="alafreajoan";
  s2="ala";
  vector<vector<int>>dp(s1.size(),vector<int>(s2.size(),-1));
  cout<<lcs(s1,s2,s1.size()-1,s2.size()-1,dp)<<endl;
  cout<<lcsubstringtab(s1,s2)<<endl;
  cout<<lps(s1)<<endl;
  cout<<distincttab(s1,s2)<<endl;
}
*/