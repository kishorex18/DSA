#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<bool>> &board,int row,int col)
{
  //vertical
  int i;
  for(i=1;i<=row;i++)
    {
      if(board[row-i][col])
      {
        return false;
      }
    }
  int right=board.size()-col-1;
  int maxLeft=min(row,col);
  int maxRight=min(row,right);
  for(i=1;i<=maxLeft;i++)
    {
      if(board[row-i][col-i])
      {
        return false;
      }
    }
  for(i=1;i<=maxRight;i++)
    {
      if(board[row-i][col+i])
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
             cout<<"Q ";
          }
          else
          {
             cout<<"X ";
          }
        }
      cout<<endl;
    }  
}
int nqueens(vector<vector<bool>> &board,int row)
{
  if(row==board.size())
  {
    //display(board);
    //cout<<endl;
    return 1;
  }
  int i,count=0;
  for(i=0;i<board.size();i++)
  {
      if(isSafe(board,row,i))
      {
        board[row][i]=true;
        count+=nqueens(board,row+1);
      }
       board[row][i]=false;
  }
  return count;
}

int main()
{
  vector<vector<bool>> board;
  int i,j,n=12;
  for(i=0;i<n;i++)
    {
      vector<bool> temp;
      for(j=0;j<n;j++)
      {
          temp.push_back(false);
      }
      board.push_back(temp);
    }
  int c=nqueens(board,0);
  cout<<"count:"<<c<<endl;
}
