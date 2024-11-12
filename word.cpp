#include <bits/stdc++.h>
using namespace std;

bool isValid(int r,int c,vector<vector<char>>& board)
{
  return (r>=0 && r<board.size() && c>=0 && c<board[0].size());
}

bool checkBool(vector<vector<bool>> & check)
{
  int i,j;
  for(i=0;i<check.size();i++)
  {
      for(j=0;j<check[0].size();j++)
      {
          if(check[i][j])
          {
              return true;
          }
      }
  }
  return false;
}

void existHelper(vector<vector<bool>>& check,vector<vector<char>>& board,string p,string word,int r,int c,bool& f)
{
     
    
    
  
  if(board[r][c]==word[p.size()])
  {
      p=p+board[r][c];
      check[r][c]=false;
      if(p==word)
       {
          cout<<"p:"<<p<<endl;
          f=true;
          check[r][c]=true;
          return;
        }
  }
  
  else
  {
      //cout<<"I am excuted"<<endl;
      cout<<"p:"<<p<<endl;
      cout<<"Char:"<<board[r][c]<<endl;
      check[r][c]=true;
      return;
  }
  
    cout<<"p:"<<p<<endl;
    cout<<"Char:"<<board[r][c]<<endl;
 
  cout<<"r:"<<r<<" "<<"c:"<<c<<endl;
  if(isValid(r+1,c,board) && check[r+1][c])
  {
      cout<<"Down"<<endl;
      existHelper(check,board,p,word,r+1,c,f);
      
    
      
  }
   if(isValid(r-1,c,board) && check[r-1][c])
  {
      cout<<"Up"<<endl;
       existHelper(check,board,p,word,r-1,c,f);
      
   
     
  }
    if(isValid(r,c-1,board) && check[r][c-1])
      {
          cout<<"Left"<<endl;
          existHelper(check,board,p,word,r,c-1,f);
         


      }
   if(isValid(r,c+1,board) && check[r][c+1])
  {
      cout<<"Right"<<endl;
      existHelper(check,board,p,word,r,c+1,f);
      
     
      
  }
  

   cout<<"No next"<<endl;
    check[r][c]=true;
  return;
}


bool exist(vector<vector<char>>& board, string word) {
  int i,j;
  vector <vector<bool>> check;
  for(i=0;i<board.size();i++)
  {
      vector<bool> temp;
      for(j=0;j<board[0].size();j++)
      {
          temp.push_back(true);
      }
      check.push_back(temp);
  }
    for(i=0;i<board.size();i++)
  {

      for(j=0;j<board[0].size();j++)
      {

          if(board[i][j]==word[0])
          {
              cout<<"found"<<endl;
              bool f=0;
              string p="";
              existHelper(check,board,p,word,i,j,f);
              if(f)
              {
                  return true;
              }
              
          }
      }

  }
  return false;
}

int main()
{
    vector<vector<char>> board = {{'A'}};
    cout<<exist(board,"A");
}