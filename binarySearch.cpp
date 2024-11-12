#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& nums,int target)
{
  int start,end;
  start=0;
  end=nums.size()-1;
  while(start<=end)
    {
      int mid=start + (end-start)/2;
      if(nums[mid]==target)
      {
        return mid;
      }
      else if(target<nums[mid])
      {
        end=mid-1;
      }
      else
      {
        start=mid+1;
      }
    }
  return -1;
    
}

int ceiling(vector<int>& nums,int target)
{
  int start,end;
  start=0;
  end=nums.size()-1;
  while(start<=end)
    {
      int mid=start + (end-start)/2;
      if(nums[mid]==target)
      {
        return mid;
      }
      else if(target<nums[mid])
      {
        end=mid-1;
      }
      else
      {
        start=mid+1;
      }
    }
  return start;

}
int floor(vector<int>& nums,int target)
{
  int start,end;
  start=0;
  end=nums.size()-1;
  while(start<=end)
    {
      int mid=start + (end-start)/2;
      if(nums[mid]==target)
      {
        return mid;
      }
      else if(target<nums[mid])
      {
        end=mid-1;
      }
      else
      {
        start=mid+1;
      }
    }
  return end;

}
vector<int> fandlocc(vector<int> nums,int target)
{
  vector<int> ans={-1,-1};
  int start,end,s,e;
  start=0;
  end=nums.size()-1;
  while(start<=end)
    {
      int mid=start + (end-start)/2;
      if(nums[mid]==target)
      {
        s=mid;
        end=mid-1;
      }
      else if(target<nums[mid])
      {
        end=mid-1;
      }
      else
      {
        start=mid+1;
      }
    }
    start=0;
    end=nums.size()-1;
    while(start<=end)
      {
        int mid=start + (end-start)/2;
        if(nums[mid]==target)
        {
          e=mid;
          start=mid+1;
        }
        else if(target<nums[mid])
        {
          end=mid-1;
        }
        else
        {
          start=mid+1;
        }
      }
  ans[0]=s;
  ans[1]=e;
  return ans;
}
int main()
{
  vector<int> nums={1,2,3,4,6,7,8,9,20,21,28};
  int target=19;
  cout<<ceiling(nums,target);
}