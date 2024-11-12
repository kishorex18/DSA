/*#include <bits/stdc++.h>
using namespace std;
void swap(string& s1,string& s2,int i)
{
  int temp=s1[i];
  s1[i]=s2[i];
  s2[i]=temp;
  return;
}

void minswap(string& s1,string& s2,int ind)
{
  int ans;
  if(ind==s1.size())
  {
    ans=abs(stoi(s1)-stoi(s2));
    cout<<"s1:"<<s1<<" s2:"<<s2<<" ans:"<<ans<<endl;
    
    return;
  }
  ans=abs(stoi(s1)-stoi(s2));
  cout<<"s1:"<<s1<<" s2:"<<s2<<" ans:"<<ans<<endl;
  swap(s1[ind],s2[ind]);
  minswap(s1,s2,ind+1);
  swap(s2[ind],s1[ind]);
  minswap(s1,s2,ind+1);
  
}



int main()
{
  string s1="12345";
  string s2="34683";
  minswap(s1,s2,0);
 
  return 0;
}*/