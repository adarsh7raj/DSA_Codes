// brute force approach : O(N*M):
class Solution {
public:
int FindIndex(vector<int>nums2,int target){
    for(int i=0;i<nums2.size();i++){
        if(nums2[i]==target){
            return i;
        }
    }
 return 0;
}
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>result(nums1.size(),-1);
        for(int i=0;i<nums1.size();i++){
            int value=FindIndex(nums2,nums1[i]);
            for(int j=value;j<nums2.size();j++){
                if(nums2[value]<nums2[j]){
                  result[i]=nums2[j];
                  break;
                }
            }
        }
        return result;
    }
};

//optimal TC :O(3n):

class Solution {
public:

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> ngeMap; // Map from num to its next greater element
    stack<int> st;

    // Traverse nums2 from right to left
    for (int i = nums2.size() - 1; i >= 0; --i) {
        int curr = nums2[i];

        // Maintain decreasing stack: pop all elements <= current
        while (!st.empty() && st.top() <= curr) {
            st.pop();
        }

        // If stack is empty => no greater element to the right
        if(st.empty()){
            ngeMap[curr]=-1;
        }
        else{
            ngeMap[curr]=st.top();
           
        }
         st.push(curr);

    }

    // Result array for nums1 using the map
    vector<int> result;
    for (int num : nums1) {
        result.push_back(ngeMap[num]);
    }

    return result;
}
};

    stack<int>st;
    for(int i=0;i<arr.size();i++){
        if(stack.top()<=arr[i]){
            stack.push();

        }
        else{
            stack.pop();
        }
    }