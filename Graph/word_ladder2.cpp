
//this will give MLE
// Time Complexity: O(N × L × 26 + S × L) → dominated by generating all transformations (N = words, L = word length, S = number of shortest sequences).

// Space Complexity: O(N × L + S × L) → for queue storing paths, set for unused words, and final sequences.

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        vector<vector<string>>ans;
        vector<string>usedOnLevel;
        usedOnLevel.push_back(beginWord);
        queue<vector<string>>q;
        q.push({beginWord});
        int level=0;
        unordered_set<string>st(wordList.begin(),wordList.end());
        
       
        while(!q.empty()){
           vector<string>vec=q.front();
           q.pop();
           if(vec.size()>level){
            level++;
            for(auto it:usedOnLevel){
          st.erase(it);
            }
            usedOnLevel.clear();
           }
          string word=vec.back();
           if(word==endWord){
        
            ans.push_back(vec);
           }
        
        
            for(int i=0;i<word.size();i++){
                char original=word[i];

                for(char ch ='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.count(word)){
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                       
                    }
                }
                word[i]=original;
            }
           
        }
  
        return ans;
    }
};


// optimal solution using dfs and backtracking
// TC :O((N + K) * L * 26) here N is the number of words in the word list, K is the number of shortest sequences found, and L is the length of each word. The BFS step takes O(N * L * 26) to generate all transformations and find the shortest path, while the DFS step takes O(K * L * 26) to backtrack through the paths and generate all sequences.
// SC : O(N + K * D) where N is the number of words in the word list, K is the number of shortest sequences found, and D is the maximum depth of the recursion (which can be at most the length of the longest sequence). The space complexity includes the queue for BFS, the map for storing distances, and the recursive stack for DFS.
class Solution {
public:
 unordered_map<string,int>mp;
 vector<vector<string>>ans;
 string begin_word;

 void dfs(string word , vector<string>&seq){
    if(word==begin_word){
        reverse(seq.begin(),seq.end());
        ans.push_back(seq);
        reverse(seq.begin(),seq.end());
        return ;
    }
    int steps=mp[word];
    for(int i=0;i<word.size();i++){
        char original=word[i];
        for( char ch='a';ch<='z';ch++){
            word[i]=ch;
            if(mp.count(word) && mp[word]+1==steps){
                seq.push_back(word);
                dfs(word,seq);
                seq.pop_back();
            }
        }
        word[i]=original;
    }
 }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

    unordered_set<string>st(wordList.begin(),wordList.end());
    queue<string>q;
    begin_word=beginWord;
    q.push(beginWord);
    st.erase(beginWord);
    mp[beginWord]=1;
    while(!q.empty()){

        string word=q.front();
        int steps=mp[word];
        if(word==endWord){
            break;
        }
        q.pop();
        for(int i=0;i<word.size();i++){
            char original=word[i];
            for(char ch='a'; ch<='z';ch++){
                word[i]=ch;
                if(st.count(word)){
                    q.push(word);
                    st.erase(word);
                    mp[word]=steps+1;
                }
            }
            word[i]=original;
        }

    }
   vector<string>seq;
   seq.push_back(endWord);
           if(mp.count(endWord)){

            dfs(endWord,seq);
           }
       return ans;
    }
};