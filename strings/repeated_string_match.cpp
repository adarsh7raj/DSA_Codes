
    //optimal solution : O(n):
    class Solution {
        public:
            int repeatedStringMatch(string a, string b) {
                const int n = ceil((double)b.length() / a.length());
                string s;
        
                for (int i = 0; i < n; ++i) {
                    s += a;
                }
        
                if (s.find(b) != string::npos) { // this will take O(n*m) we  can use KML algo for TC O(n+m)
                    return n;
                }
        
                if ((s + a).find(b) != string::npos) {
                    return n + 1;
                }
        
                return -1;
            }
        };
        // optimal approach :
        //we can use KMP algo to find if string is present in other string or not 