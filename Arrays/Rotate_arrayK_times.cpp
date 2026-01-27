// TC: O(n*k)
// SC: O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>temp; 
        int n=nums.size();
        k=k%n;
      
        int idx=n-1;
      for(int i=0;i<k;i++){
       nums.insert(nums.begin(), nums[idx]);
       nums.pop_back();
                                             
      }            
        
    }
};


// TC: O(N)
// SC: O(N)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>temp; 
        int n=nums.size();
        k=k%n;
        int idx=n-k;
      for(int i=0;i<n;i++){
       temp.push_back(nums[idx % n]);
       idx++;
      }
        for(int i=0;i<n;i++){
            nums[i]=temp[i];
        }
    }
};

// optimal solution

// TC: O(N) 
//SC:O(1)
// first reverse the whole array
// then reverse first k elements
// then reverse the remaining n-k elements
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      
        int n=nums.size();
        k=k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
                                             
      }            
        
    
};