//TC: O(n*m*26) SC: O(n*m)
// we will use bfs to find the shortest path from begin word to end word. We will       

class Solution {
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);

        while(!q.empty()){
            string word=q.front().first;
            int count=q.front().second;
            q.pop();
            if(word==endWord){
                return count;
            }

            for(int i=0;i<word.size();i++){
                char original=word[i];

                for(char ch ='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.count(word)){
                        q.push({word,count+1});
                        st.erase(word);
                    }
                }
                word[i]=original;
            }
        
        }

        return 0;

    }
};