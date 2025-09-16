// better approach : O(nlogn)
class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            int n=nums.size();
            vector<int> ans;
            map<int,int> m;
            for(int i =0;i<n;i++){
                m[nums[i]]++;

            }
            for(auto i:m){
                if(i.second>(n/3)){
                    ans.push_back(i.first);
                }
            }
            return ans;
        }
        };
    

//optimal approach : O(2n)
class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            int n=nums.size();
            int count1=0;
            int count2=0;
            int element1=INT_MIN;
            int element2=INT_MIN;
            vector<int> ans;
            for(int i=0;i<n;i++){
                if(count1==0&&element2!=nums[i]){
                    count1=1;
                    element1=nums[i];
                }
                else if(count2==0&&element1!=nums[i]){
                    count2=1;
                    element2=nums[i];
                }
                else if(nums[i]==element1){
                    count1++;
                }
                else if(nums[i]==element2){
                    count2++;
                }
                else{
                    count1--;
                    count2--;
                }
            }
      count1=0;
      count2=0;
      for(int i=0;i<n;i++){
        if(nums[i]==element1){
            count1++;
        }
        if(nums[i]==element2){
            count2++;
        }

      }
      if(count1>(n/3)){
        ans.push_back(element1);
      }
      if(count2>(n/3)){
        ans.push_back(element2);
      }
      return ans;
        }
};