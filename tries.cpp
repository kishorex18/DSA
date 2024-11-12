#include <bits/stdc++.h>
using namespace std;
class trieNode
{
  public:
  int isend=0;
  int count=0;
  trieNode* childNode[26];
  trieNode()
{
  for(int i=0;i<26;i++)
  {
    childNode[i]=nullptr;
  }
}
};
class trie
{
public:
  
  trieNode* root=new trieNode();
  bool getNode(char ch,trieNode* current)
  {
    return (current->childNode[ch-'a']!=nullptr);
  }
  void insert(string s)
  {
    trieNode* currentNode=root;
    for(auto ch:s)
    {
        if(getNode(ch,currentNode))
        {
          currentNode->childNode[ch-'a']->count++;
        }
      else
        {
          trieNode* node=new trieNode();
          currentNode->childNode[ch-'a']=node;
           currentNode->childNode[ch-'a']->count++;
        }
        currentNode=currentNode->childNode[ch-'a'];
    }
    currentNode->isend++;
  }
  bool search(string s)
  {
    trieNode* currentNode=root;
    for(auto ch:s)
    {
        if(getNode(ch,currentNode))
        {
          currentNode=currentNode->childNode[ch-'a'];
        }
        else
        {
          return false;
        }
    }
    return (currentNode->isend>0);
  }

int frequency(string s)
{
  trieNode* currentNode=root;
  
  for(auto ch:s)
  {
      if(getNode(ch,currentNode))
      {
        currentNode=currentNode->childNode[ch-'a'];
        
      }
      else
      {
        return 0;
      }
    
  }
  if(currentNode->isend>0)
  {
    return currentNode->isend;
  }
  return 0;
}
int prefix(string s)
{
  trieNode* currentNode=root;
  int m=INT_MAX;
  for(auto ch:s)
  {
      if(getNode(ch,currentNode))
      {
        m=min(m,currentNode->childNode[ch-'a']->count);
      }
      else
      {
        return 0;
      }
    currentNode=currentNode->childNode[ch-'a'];
  }
  return m;
}
};

int main()
{
  trie t;
  t.insert("apple");
  t.insert("app");
  t.insert("apps");
  t.insert("application");
  //t.deletestring("application");
  cout<<t.search("apple")<<endl;
  cout<<t.search("dad")<<endl;
  cout<<t.search("apple")<<endl;
  cout<<t.search("a")<<endl;
  cout<<t.frequency("d")<<endl;
  cout<<t.search("application")<<endl;
  cout<<t.prefix("app")<<endl;
}