// brute force O(nlogn):

class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int,int>mp;
            vector<pair<int,int>>ans;
            vector<int>result;
            for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            }
            for(auto it:mp){
                pair<int,int>pr={it.first,it.second};
           ans.push_back(pr);
            }
            sort(ans.begin(),ans.end(),[](pair<int,int>&a,pair<int,int>&b){
                return a.second>b.second;
            });
    
            for(int i=0;i<k;i++){
                result.push_back(ans[i].first);
            }
            return result;
        }
    };

    //using min_heap : O(nlogk):

    
class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> freq;
    
            // Step 1: Count frequency of each number
            for (int num : nums) {
                freq[num]++;
            }
    
            // Step 2: Define a lambda comparator for the min-heap (based on frequency)
            auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
                return a.second > b.second; // min-heap: smaller frequency at top
            };
    
            // Step 3: Declare min-heap with lambda comparator
            priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);
    
            // Step 4: Push elements to heap and maintain size k
            for (auto& [num, count] : freq) {
                minHeap.push({num, count});
                if (minHeap.size() > k) {
                    minHeap.pop();
                }
            }
    
            // Step 5: Extract top k frequent elements
            vector<int> result;
            while (!minHeap.empty()) {
                result.push_back(minHeap.top().first);
                minHeap.pop();
            }
    
            return result;
        }
    };
    

    // using bucket sort : O(N):

    
class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            int n=nums.size();
            vector<int>ans;
            unordered_map<int, int> mp;
           
             for(int i=0;i<n;i++){
    mp[nums[i]]++;
             }

              vector<vector<int>>bucket(n+1);
              // bucket[i] = elements having frequency i
              // i is the frequency
             for(auto it:mp){
                
                bucket[it.second].push_back(it.first);
             }
             // start from the back of the bucket because we want the most frequent elements
     for(int i=n;i>0;i--){
      int j=0;
     
     if(bucket[i].size()==0){
        continue;
     }
    
     while(bucket[i].size()>j && k >0){
        ans.push_back(bucket[i][j]);
        j++;
        k--;
    
     }
     }
     return ans;
        }
    };