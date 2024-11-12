/*#include <bits/stdc++.h>
using namespace std;
void printMat(int mat[3][3])
{
  for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
        {
          cout<<mat[i][j]<<" ";
        }
      cout<<endl;
    }
  
}
int countPaths(int r,int c)
{
   if(r==1 || c==1)
   {
     return 1;
   }
   int right=countPaths(r,c-1);
   int down=countPaths(r-1,c);
  return right+down;
};
void printPaths(string p,int r,int c)
{
  if(r==1 && c==1)
  {
    cout<<p<<endl;
    return;
  }
  if(r>1)
  {
    printPaths(p+"D",r-1,c);
  }
  if(c>1)
  {
    printPaths(p+"R",r,c-1);
  }
  
}
vector<string> printPathsarr(string p,int r,int c)
{
  if(r==1 && c==1)
  {
   vector <string> ans;
    ans.push_back(p);
    return ans;
  }
  vector <string> res;
  if(r>1)
  {
    vector<string> temp = printPathsarr(p+"D",r-1,c);
    res.insert(res.end(), temp.begin(), temp.end());
  }
  if(c>1)
  {
    vector<string> temp = printPathsarr(p+"R",r,c-1);
    res.insert(res.end(), temp.begin(), temp.end());
  }
  return res;
}
vector<string> printPathsarr2(string p,int r,int c)
{
  if(r==1 && c==1)
  {
   vector <string> ans;
    ans.push_back(p);
    return ans;
  }
  vector <string> res;
  if(r>1 && c>1)
  {
    vector<string> temp = printPathsarr2(p+"D",r-1,c-1);
    res.insert(res.end(), temp.begin(), temp.end());
  }
  if(r>1)
  {
    vector<string> temp = printPathsarr2(p+"S",r-1,c);
    res.insert(res.end(), temp.begin(), temp.end());
  }
  if(c>1)
  {
    vector<string> temp = printPathsarr2(p+"E",r,c-1);
    res.insert(res.end(), temp.begin(), temp.end());
  }
  return res;
}
void backtrack(string p,int r,int c,bool maze[3][3])
{
   
   if(r==2 && c==2)
    {
      //cout<<"final"<<endl;
      cout<<p<<endl;
      maze[r][c]=false;
      return;
    }
   if(maze[r][c])
   {
    // cout<<"visted"<<endl;
     return;
   }
   maze[r][c]=true;
    if(r>0)
    {
       //cout<<"up"<<endl;
      backtrack(p+"U",r-1,c,maze);
    }
    if(c>0)
    {
      //cout<<"left"<<endl;
      backtrack(p+"L",r,c-1,maze);
    }
    if(r<2)
    {
      //cout<<"down"<<endl;
       backtrack(p+"D",r+1,c,maze);
    }
  if(c<2)
    {
        //cout<<"right"<<endl;
       backtrack(p+"R",r,c+1,maze);
    }
  maze[r][c]=false;

}
void printMaze(string path,int p[3][3],int r,int c,bool maze[3][3],int level)
{
  if(r==2 && c==2)
    {
      //cout<<"final"<<endl;
       p[r][c]=level;
       cout<<path<<endl;
      printMat(p);
      cout<<endl;
      maze[r][c]=false;
      return;
    }
   if(maze[r][c])
   {
    //cout<<"visted"<<endl;
     return;
   }
   maze[r][c]=true;
    p[r][c]=level;
  //cout<<level<<endl;
    if(r>0)
    {
       //cout<<"up"<<endl;
       //cout<<level<<endl;
      printMaze(path+"U",p,r-1,c,maze,level+1);
    }
    if(c>0)
    {
      //cout<<"left"<<endl;
      //cout<<level<<endl;
      printMaze(path+"L",p,r,c-1,maze,level+1);
    }
    if(r<2)
    {
     // cout<<"down"<<endl;
      //cout<<level<<endl;
       printMaze(path+"D",p,r+1,c,maze,level+1);
    }
  if(c<2)
    {
        //cout<<"right"<<endl;
        //cout<<level<<endl;
       printMaze(path+"R",p,r,c+1,maze,level+1);
    }
  maze[r][c]=false;
  p[r][c]=0;
}

int main()
{
  bool maze[3][3]={{0,0,0},{0,0,0},{0,0,0}};
  //backtrack("",0,0,maze);
  int up[3][3]={{0,0,0},{0,0,0},{0,0,0}};
  printMaze("",up,0,0,maze,1);
  return 0;
}*/
