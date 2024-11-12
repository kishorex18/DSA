#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> &board)
{
  int i,j;
  for(i=0;i<board.size();i++)
    {
      for(j=0;j<board[0].size();j++)
        {
          cout<<board[i][j]<<" ";
        }
      cout<<endl;
    }  
}

bool isSafe(vector<vector<int>> &board,int r,int c,int num)
{
  int i,j;
  int gsize=sqrt(board.size());
  int rstart=r-r%gsize;
  int cstart=c-c%gsize;
  int rend=rstart+gsize;
   int cend=cstart+gsize;
  for(i=0;i<board.size();i++)
    {
      if(board[r][i]==num)
      {
        return false;
      }
      if(board[i][c]==num)
      {
        return false;
      }
    }
  for(i=rstart;i<rend;i++)
    {
      for(j=cstart;j<cend;j++)
        {
          if(board[i][j]==num)
          {
            return false;
          }
        }
    }
  return true;
}

bool solve(vector<vector<int>> &board)
{
  bool empty=false;
  int row=-1;
  int col=-1;
  int i,j;
  for(i=0;i<board.size();i++)
    {
      for(j=0;j<board.size();j++)
        {
          if(board[i][j]==0)
          {
            row=i;
            col=j;
            empty=true;
            break;
          }
            
        }
      if(empty)
      {
        break;
      }
    }
  if(!empty)
  {
    display(board);
    return true;
  }
  for(i=1;i<=9;i++)
    {
      if(isSafe(board,row,col,i))
      {
        board[row][col]=i;
        
        if(solve(board))
        {
          return true;
        }
      }
      board[row][col]=0;
    }

  return false;
}
int main()
{
  vector<vector<int>> board={ {0, 8, 7, 6, 5, 4, 3, 2, 1},
  {2, 0, 0, 0, 0, 0, 0, 0, 0},
  {3, 0, 0, 0, 0, 0, 0, 0, 0},
  {4, 0, 0, 0, 0, 0, 0, 0, 0},
  {5, 0, 0, 0, 0, 0, 0, 0, 0},
  {6, 0, 0, 0, 0, 0, 0, 0, 0},
  {7, 6, 0, 0, 0, 0, 0, 0, 0},
  {8, 0, 0, 0, 0, 0, 0, 0, 0},
  {9, 0, 0, 0, 0, 0, 0, 0, 0}};
  int i,j;
  for(i=0;i<9;i++)
    {
       vector<int> temp;
      for(j=0;j<9;j++)
        {
         temp.push_back(0);
        }
      board.push_back(temp);
    }
  
  cout<<solve(board)<<endl;
}