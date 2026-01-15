class Solution {
public:
vector<int> computeLPS(string & needle) {
    int n = needle.size();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;

    while (i < n) {
        if (needle[i] == needle[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}
    string longestPrefix(string s) {
      vector<int>LPS=computeLPS(s);
      return s.substr(0,LPS[LPS.size()-1]);  
    }
};