
//TC: O(N)
//SC: O(1)
class Solution {
  public:
    int search(vector<int>& arr, int x) {
        // code here
        int result=-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==x){
                return i;
            }
        }
        return result;
    }
};