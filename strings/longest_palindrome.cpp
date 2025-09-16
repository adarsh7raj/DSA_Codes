//brute force approach : 
class Solution {
    public:
        string longestPalindrome(string s) {
            int n=s.size();
    
             string ans="";
             vector<string>ans_str;
            for(int i=0;i<n;i++){
                string rev="";
               
            for(int j=i;j<n;j++){
              rev=rev+s[j];
              string temp=rev;
              reverse(temp.begin(),temp.end());
                if(temp==rev){
                 
                   ans=rev;
                }
            }
            ans_str.push_back(ans);
            }
            int largest=0;
            int longest=ans_str[0].size();
            
            for(int i=1;i<ans_str.size();i++){
               
                if(longest<ans_str[i].size()){
                     largest=i;
                     longest=ans_str[i].size();
                }
            }
            return ans_str[largest] ;
        }
    };


    // brute force approach  with recursion method :
    class Solution {
        public:
        bool solve(string s,int i ,int j){
                if(i>=j){
                    return true;
        
                }
                if(s[i]==s[j]){
                    return solve(s,i+1,j-1);
                }
                return false;
               }
            string longestPalindrome(string s) {
                int n = s.length();
                int start=0;
                int maxLen=0;
               for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                 if(solve(s,i,j)){
                    if(maxLen<(j-i+1)){
                        maxLen=j-i+1;
                        start=i;
                    }
                 }
                }
               }
              
        
                return s.substr(start, maxLen);
            }
        };

        //better approach O(n^2) using dp sc: O(n^2)

         class Solution {
        public:
      int  dp[1001][1001];
        bool solve(string s,int i ,int j){
                if(i>=j){
                    return true;
        
                }
                if(dp[i][j]!=-1){
                    return dp[i][j];
                }
                if(s[i]==s[j]){
                    return dp[i][j]= solve(s,i+1,j-1);
                }
                return dp[i][j]=false;
               }
            string longestPalindrome(string s) {
                int n = s.length();
                int start=0;
                int maxLen=0;
                memset(dp,-1,sizeof(dp));
               for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                 if(solve(s,i,j)){
                    if(maxLen<(j-i+1)){
                        maxLen=j-i+1;
                        start=i;
                    }
                 }
                }
               }
              
        
                return s.substr(start, maxLen);
            }
        };

        
        //better approach O(n^2)expanding around the center
        class Solution {
            public:
                string longestPalindrome(string s) {
                    int n = s.length();
                    int start = 0;
                    int maxLen = 0;
                    string res = "";
            
                    for (int i = 0; i < n; i++) {
                        // Odd-length palindrome
                        int left = i, right = i;
                        while (left >= 0 && right < n && s[left] == s[right]) {
                            if (maxLen < right - left + 1) {
                                maxLen = right - left + 1;
                                res = s.substr(left, right - left + 1);
                            }
                            left--;
                            right++;
                        }
            
                        // Even-length palindrome
                        left = i, right = i + 1;
                        while (left >= 0 && right < n && s[left] == s[right]) {
                            if (maxLen < right - left + 1) {
                                maxLen = right - left + 1;
                                res = s.substr(left, right - left + 1);
                            }
                            left--;
                            right++;
                        }
                    }
                    return res;
                }
            };
            

            //optimal algo: manchar's algo:O(n): learn about this algo

            class Solution {
                public:
                    string longestPalindrome(string s) {
                        // Step 1: Transform the string
                        string T = "^#";
                        for (char c : s) {
                            T += c;
                            T += '#';
                        }
                        T += '$';
                
                        int n = T.length();
                        vector<int> P(n, 0);
                        int C = 0, R = 0;  // Center and right boundary
                        int maxLen = 0, centerIndex = 0;
                
                        for (int i = 1; i < n - 1; i++) {
                            int mirror = 2 * C - i;
                
                            // Step 2: Initialize P[i] using previously computed values
                            if (i < R)
                                P[i] = min(R - i, P[mirror]);
                
                            // Step 3: Expand around center i
                            while (T[i + (1 + P[i])] == T[i - (1 + P[i])])
                                P[i]++;
                
                            // Step 4: Update center and right boundary
                            if (i + P[i] > R) {
                                C = i;
                                R = i + P[i];
                            }
                
                            // Step 5: Track max length
                            if (P[i] > maxLen) {
                                maxLen = P[i];
                                centerIndex = i;
                            }
                        }
                
                        // Step 6: Extract result
                        int start = (centerIndex - maxLen) / 2;
                        return s.substr(start, maxLen);
                    }
                };
                