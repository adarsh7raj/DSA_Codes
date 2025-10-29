// brute force approach : 


class Solution {
public:
void generateSubsequences(int index, vector<int>& arr, vector<int>& subseq, vector<vector<int>>& result) {
    if (index == arr.size()) {
        result.push_back(subseq);
        return;
    }

    // Include current element
    subseq.push_back(arr[index]);
    generateSubsequences(index + 1, arr, subseq, result);

    // Exclude current element
    subseq.pop_back();
    generateSubsequences(index + 1, arr, subseq, result);
}
    int longestArithSeqLength(vector<int>& nums) {
    vector<int> subseq;
    vector<vector<int>> result;
    int maxLen=0;
    generateSubsequences(0, nums, subseq, result);
    for(int i=0;i<result.size();i++){
        if (result[i].size() < 2) {
    maxLen = max(maxLen, (int)result[i].size());
    continue;
}
         int cd=result[i][1]-result[i][0];
    
         bool  not_ap=false;
        for(int j=0;j<result[i].size()-1;j++){
           
            if(result[i][j+1]-result[i][j]!=cd){
                not_ap=true;
     break;
            }

        }
        if(!not_ap){
            int n=result[i].size();
   maxLen=max(maxLen,n);
        }
       
    }
    return maxLen;
    }
};


// optimal approach : using dp and hashing :
// This approach might fail for some cases because of integer overflow in calculating the difference.(cd becomes -ve or +ve infinity)

class Solution {
public:
    int lengthOfLongestAP(int A[], int n) {
        int ans = 0;
        unordered_map<int, int> dp[n + 1];
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = A[i] - A[j];
                int cnt = 1;

                // If an AP with this diff ending at index j exists
                if (dp[j].count(diff))
                    cnt = dp[j][diff];

                // Extend that AP by 1 (current element A[i])
                dp[i][diff] = 1 + cnt;

                // Update maximum length
                ans = max(ans, dp[i][diff]);
            }
        }

        return ans;
    }
};


// optimal approach :
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        
        if(n <= 2)
            return n;
        
        vector<vector<int>> t(n, vector<int>(1001,0));
        //t[i][j] = Max AP length till ith index (0 to i) having common difference j

        int result = 0;
        
        for (int i = 1; i<n; i++) {
            
            for (int j=0; j<i; j++) {
                
                int diff    = nums[i] - nums[j] + 500; //to avoid negative diff
                
                t[i][diff] = t[j][diff] > 0 ? t[j][diff] + 1 : 2;
                
                result      = max(result, t[i][diff]);
            }
        }

        return result;
    }
};