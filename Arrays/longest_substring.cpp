// better force approach : O(n)

  }
    };class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int longest=1;
            int n=s.size();
            int k=0;
            if(n==0){
                return 0;
            }
            for(int i=0;i<n;i++){
                int count=1;
              int j=i;
        
           while(j>k){
           
            if(s[i]!=s[j-1]){
             count++;
             longest=max(longest,count);
                j--;
            }
            else{
            
             k=j;  
                break;
            }
           }
            }
            return longest;
      
    //optimal solution : O(n):

    class Solution {
        public:
            int lengthOfLongestSubstring(string s) {
                unordered_map<char, int> lastSeen;
                int left = 0;
                int maxLen = 0;
        
                for (int right = 0; right < s.length(); right++) {
                    char curr = s[right];
        
                    // If the character is already seen and its index is inside the current window
                    if (lastSeen.count(curr) && lastSeen[curr] >= left) {
                        left = lastSeen[curr] + 1;  // move left pointer right past the last occurrence
                    }
        
                    lastSeen[curr] = right;  // update last seen index
                    maxLen = max(maxLen, right - left + 1);
                }
        
                return maxLen;
            }
        };
        