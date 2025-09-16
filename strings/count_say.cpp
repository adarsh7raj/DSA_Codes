// using recursion : TC(2^n)
class Solution {
    public:
    
    string Rle_encoding(int n, string code, int count) {
        int i = 0;
        string ans = "";
    
        while (i < code.size()) {
            int j = i + 1;
            int freq = 1;
    
            // Count how many times code[i] repeats
            while (j < code.size() && code[j] == code[i]) {
                freq++;
                j++;
            }
    
            ans += to_string(freq) + code[i];
            i = j;
        }
    
        if (count == n - 1) {
            return ans;
        } else {
            return Rle_encoding(n, ans, count + 1);
        }
    }
    
        string countAndSay(int n) {
            if(n==1){
                return "1";
            }
         string ans=   Rle_encoding(n,"1",1);
         return ans;
        }
    };

    
    //using iterative approach :  TC(2^n)

    
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        
        string result = "1";

        for (int i = 1; i < n; i++) {
            string current = "";
            int j = 0;
            
            while (j < result.size()) {
                int count = 1;
                while (j + 1 < result.size() && result[j] == result[j + 1]) {
                    count++;
                    j++;
                }
                current += to_string(count) + result[j];
                j++;
            }

            result = current;
        }

        return result;
    }
};
