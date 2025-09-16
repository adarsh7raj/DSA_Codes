
class Trie {
public:
struct TrieNode{
    bool is_word_end;
    TrieNode * children[26];
};
TrieNode * root;
TrieNode * CreateTrie(){
    TrieNode * temp=new TrieNode();
    for(int i=0;i<26;i++){
        temp->children[i]=NULL;
    }
    temp->is_word_end=false;
    return temp;
}
    Trie() {
        root=CreateTrie();
    }
    
    void insert(string word) {
        TrieNode* crawler=root;
        for( auto ch : word){
            int index=ch-'a';
            if(crawler->children[index]==NULL){
      crawler->children[index]=CreateTrie();
            }
        crawler=crawler->children[index];
        }
        crawler->is_word_end=true;
    }
    
    bool search(string word) {
          TrieNode* crawler=root;
        for( auto ch : word){
            int index=ch-'a';
            if(crawler->children[index]==NULL){
   return false;
            }
        crawler=crawler->children[index];
        }
      if(crawler!=NULL && crawler->is_word_end==true){
        return true;
      }
      return false;
    }
    
    bool startsWith(string prefix) {
         TrieNode* crawler=root;
         int count=0;
        for( auto ch : prefix){
            
            int index=ch-'a';
            if(crawler->children[index]==NULL){
   return false;
            }
        crawler=crawler->children[index];
        count++;
        }
    if(prefix.length()==count){
        return true;
    }
      return false;
    }
};
