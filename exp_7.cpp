
#include <iostream>

using namespace std;

class TrieNode{
  public:
  char data;
  TrieNode * children[26];
  bool isTerminal;
  
  TrieNode(char ch){
      data = ch;
      for(int i = 0;i<26;i++){
          children[i] = NULL;
          isTerminal = false;
      }
  }
};

class Trie{
  public:
  TrieNode*root;
  
  Trie(){
      root = new TrieNode('\0');
  }
  
  //INSERTION
  void insertUtil(TrieNode*root,string word){
      if(word.length() == 0){
          root->isTerminal = true;
          return;
      }
      
      int index = word[0] - 'A';
      TrieNode * child;
      
      if(root->children[index] != NULL){
          child = root->children[index];
      }else{
          child = new TrieNode(word[0]);
          root->children[index] = child;
      }
      insertUtil(child,word.substr(1));
  }
  
  void insertWord(string word){
      insertUtil(root,word);
  }
  
//   SEARCHING
  bool searchUtil(TrieNode*root,string word){
      if(word.length() == 0){
          return root->isTerminal;
      }
      int index = word[0] - 'A';
      TrieNode * child;
      
      if(root->children[index] != NULL){
          child = root->children[index];
      }else{
          return false;
      }
      return searchUtil(child,word.substr(1));
  }
  
  bool searchWord(string word){
      return searchUtil(root,word);
  }
  
  
};
int main()
{
    Trie * t = new Trie();
    t->insertWord("ARM");
    t->insertWord("TIME");
    t->insertWord("DO");
    
    if(t->searchWord("TARA")){
        cout<<"the word you entered is present"<<endl;
    }else{
        cout<<"the word you entered is not present"<<endl;
    }
    
    

    return 0;
}
