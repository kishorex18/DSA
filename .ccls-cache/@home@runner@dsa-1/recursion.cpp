/*#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> permHelp(vector<int> nums,vector<int> arr)
{
    vector<vector<int>> ans;
  if(nums.empty())
  {

      ans.push_back(arr);
      return ans;
  }


  for(size_t i=0;i<nums.size();i++)
  {
      vector<int> newnums=nums;
      arr.push_back(nums[i]);
      newnums.erase(newnums.begin()+i);
      vector<vector<int>> temp=permHelp(newnums,arr);
      ans.insert(ans.end(),temp.begin(),temp.end());
       arr.pop_back();
  }
  return ans;
}
vector<vector<int>> permute(vector<int>& nums) {
  vector<int> arr;
  return permHelp(nums,arr);
}
int main()
{
    vector<int> nums={1,2,3};
    vector<vector<int>> ans=permute(nums);
    for(auto perm:ans)
        {
            for(auto num:perm)
                {
                    cout<<num<<" ";
                }
            cout<<endl;
        }

}*/