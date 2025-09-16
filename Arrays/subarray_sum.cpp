//optimal approach O(n)time (Kadane algo)

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int max_sum = INT_MIN;
            int sum = 0;
            int n = nums.size();
    
            for (int i = 0; i < n; i++) {
                sum += nums[i];
                max_sum = max(max_sum, sum);
                
                if (sum < 0) {
                    sum = 0;     // because -ve sum will always decrease the value
                }
            }
    
            return max_sum;
        }
    };

    
    // brute force appraoch
  

    //  maximum subarray : 

    class Solution {
        public:
            int maxSubArray(vector<int>& nums) {
                int max_sum = INT_MIN, sum = 0;
                int start = 0, end = 0, temp_start = 0; // Track subarray indices
                
                for (int i = 0; i < nums.size(); i++) {
                    sum += nums[i];
        
                    if (sum > max_sum) {
                        max_sum = sum;
                        start = temp_start;  // Update start index of the best subarray
                        end = i;              // Update end index
                    }
        
                    if (sum < 0) {
                        sum = 0;
                        temp_start = i + 1; // Reset start index for a new subarray
                    }
                }
        
                // Print the subarray
                cout << "Max Subarray: [";
                for (int i = start; i <= end; i++) {
                    cout << nums[i] << (i < end ? ", " : "");
                }
                cout << "]" << endl;
        
                return max_sum;
            }
        };
        