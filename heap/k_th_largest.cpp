// optimal solution : using MaxHeap O(nlogn):

class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            int n=nums.size();
            priority_queue<int>pr;
            for(int i=0;i<n;i++){
                pr.push(nums[i]);
            }
            for(int i=1;i<k;i++){
                pr.pop();
            }
            return pr.top();
        }
    };

    //using minHeap : O(nlogk):
    class Solution {
        public:
            int findKthLargest(vector<int>& nums, int k) {
                priority_queue<int, vector<int>, greater<int>> minHeap;  // Min-heap
                
                for (int num : nums) {
                    minHeap.push(num);  // Add each number to the heap
                    if (minHeap.size() > k) {
                        minHeap.pop();  // Pop the smallest element if the heap size exceeds k
                    }
                }
                
                return minHeap.top();  // The k-th largest element is at the top of the min-heap
            }
        };
        