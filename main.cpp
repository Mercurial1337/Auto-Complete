#include <iostream>
#include <vector>

using namespace std;

struct Trie
{

   struct Node
   {
      static const int sz = 26;
      int child[sz]{};
      int f = 0;
      bool end=false;
      int freq_of_search=0;

   };

   vector<Node> trie;

   Trie() 
   {
       trie.emplace_back(); 
   }


   void insert(string &s)
   {
      int idx = 0, siz = s.size();
      for (int i = 0; i < siz; i++)
      {
         int nxt = s[i] - 'a';
         if (trie[idx].child[nxt] == 0)
         {
            trie[idx].child[nxt] = trie.size();
            trie.emplace_back();
         }
         idx = trie[idx].child[nxt];
         trie[idx].f++;
         if(i==siz-1){
             trie[idx].end=true;
         }
      }
   }


   void del(string &s)
   {
      int idx = 0, siz = s.size();
      for (int i = 0; i < siz; i++)
      {
         int nxt = s[i] - 'a';
         idx = trie[idx].child[nxt];
         trie[idx].f--;
         if(i==siz-1){
            trie[idx].end=false;
        }
      }
   }

   vector<string> search(string &s)
   {
      vector<string>ret;
      int idx = 0, siz = s.size(),lastnode=-1;
      for (int i = 0; i < siz; i++)
      {
         int nxt = s[i] - 'a';
         if (!trie[trie[idx].child[nxt]].f)
            return ret;
         idx = trie[idx].child[nxt];
         lastnode=idx;
      }
      if(!trie[lastnode].end)return ret;
      trie[lastnode].freq_of_search++;
      //dfs / bfs from lastnode

      return ret;
   }
};

int main()
{
   
}