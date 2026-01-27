// TC: O(N)
// SC: O(N)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    vector<int>temp;
    int n=nums.size();
    int last=nums[0];
    temp.push_back(nums[0]);
    for(int i=1;i<n;i++){
        if(last!=nums[i]){
            temp.push_back(nums[i]);
            last=nums[i];
        }
    }
   for(int i=0;i<temp.size();i++){
    nums[i]=temp[i];
   }
    return temp.size();
  
    }
};

// optimal solution
// TC: O(N)
// SC: O(1)

class Solution {
public:
   
    int removeDuplicates(vector<int>& arr) {

        int forward=1, back=1,curr=arr[0];
     for (int i = 1; i < arr.size(); i++) {
    if (curr != arr[back]) {
        arr[forward] = arr[i];
        forward++;
        curr = arr[i];
    }
    back++;
}
return forward;


    }
};