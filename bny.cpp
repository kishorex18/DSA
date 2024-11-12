/*#include <bits/stdc++.h>
using namespace std;

int balancingelements(vector<int>& arr)
{
  int esum,osum,ep,op,i,n,c=0;
  n=arr.size();
  esum=0;
  osum=0;
  ep=0;
  op=0;
  for(i=0;i<n;i++)
    {
      if(i%2==0)
      {
        esum+=arr[i];
      }
      else
      {
        osum+=arr[i];
      }
    }
  for(i=0;i<n;i++)
    {
     
      if(i%2==0)
      {
       
        esum-=arr[i];
        
      }
      else
      {
        
        osum-=arr[i];
         
      }
      
      if(osum+ep==esum+op)
      {
        
        c++;
      }
      if(i%2==0)
      {
        
        ep+=arr[i];
      }
      else
      {
       
        op+=arr[i];
      }
    }
  return c;
}
int Load(vector<int>& arr,vector<int> &a,int i,int c)
{
  cout<<"c:"<<c<<endl;
  if(c==0)
  {
    cout<<"All included"<<endl;
    return 0;
  }
  if(i<0)
  {
    cout<<"Out of bound"<<endl;
    return 10000000;
  }
  if(c<0)
  {
    cout<<"Out of bound"<<endl;
    return 10000000;
  }
  cout<<"i:"<<i<<endl;
  int pick,notpick;
  if(a[i])
  {
  pick=arr[i]+Load(arr,a,i-1,c-1);
  notpick=Load(arr,a,i-1,c);
    return min(pick,notpick);
  }
  else
  {
    notpick=Load(arr,a,i-1,c);
    return notpick;
  }
}
int main()
{
  vector<int> arr={10,20,40,13,12,17};
  vector<int> a={1,0,0,1,0,1};
  cout<<Load(arr,a,5,3)<<endl;
  return 0;
}*/