#include <bits/stdc++.h>
using namespace std;

int co=0;

bool isValid(int n,int r,int c)
{
  return(r>=0 && r<n && c>=0 && c<n);
}

bool isSafe(vector<vector<bool>> &board,int r,int c)
{
  if(isValid(board.size(),r-2,c-1))
  {
    if(board[r-2][c-1])
    {
      return false;
    }
  }
  if(isValid(board.size(),r-2,c+1))
    {
      if(board[r-2][c+1])
      {
        return false;
      }
    }
  if(isValid(board.size(),r-1,c-2))
    {
      if(board[r-1][c-2])
      {
        return false;
      }
    }
  if(isValid(board.size(),r-1,c+2))
    {
      if(board[r-1][c+2])
      {
        return false;
      }
    }
  return true;
}
void display(vector<vector<bool>> &board)
{
  int i,j;
  for(i=0;i<board.size();i++)
    {
      for(j=0;j<board[0].size();j++)
        {
          if(board[i][j])
          {
             cout<<"K ";
          }
          else
          {
             cout<<"X ";
          }
        }
      cout<<endl;
    }  
}

void nKnights(vector<vector<bool>> &board,int r,int c,int targets)
{
  if(targets==0)
  {
   //display(board);
  //cout<<endl;
    cout<<"All knights placed"<<endl;
    co++;
    return;
  }
  if (r == board.size()-1 && c==board.size()) {
      cout<<"Out of bound"<<endl;
      return;
  }

  
  if(c==board.size())
  {
     cout<<"r:"<<r<<"c:"<<c<<endl;
    cout<<"Out of column"<<endl;
  nKnights(board,r+1,0,targets);
   return; 
  }
  if(isSafe(board,r,c))
  {
    cout<<"r:"<<r<<"c:"<<c<<endl;
    cout<<"current is safe"<<endl;
    board[r][c]=true;
    nKnights(board,r,c+1,targets-1);
    board[r][c]=false;
  }
   cout<<"r:"<<r<<"c:"<<c<<endl;
  cout<<"no place move next col"<<endl;
  nKnights(board,r,c+1,targets);
 
}
int main()
{
vector<vector<bool>> board;
int i,j,n=3;
for(i=0;i<n;i++)
  {
    vector<bool> temp;
    for(j=0;j<n;j++)
    {
        temp.push_back(false);
    }
    board.push_back(temp);
  }
nKnights(board,0,0,board.size());
cout<<"count:"<<co<<endl;
  return 0;
}