class Solution {
public:
vector<int> nextPermutation(vector<int>& nums,int k,int count) {
    if(count==k){
        return nums;
    }
            int index = -1;
            int n = nums.size();

            for (int i = n - 2; i >= 0; i--) {
                if (nums[i] < nums[i + 1]) {
                    index = i;
                    break;
                }
            }

            // if (index == -1) {
            //     reverse(nums.begin(), nums.end());
            //     return nums;
            // }
    
            
            for (int j = n - 1; j > index; j--) {
                if (nums[j] > nums[index]) {
                    swap(nums[index], nums[j]);
                    break;
                }
            }
    
            // Step 4: Reverse the suffix after the swapped element
            reverse(nums.begin() + index + 1, nums.end());
            
           return  nextPermutation(nums,k,count+1);
        }
  
    string getPermutation(int n, int k) {
        int number=0;
        int count=1;
        for(int i=0;i<n;i++){
            number=number+(n-i)*pow(10,i);
        }
        vector<int> starting_sequence;
         string sequence=to_string(number);
       for(char ch:sequence){
        starting_sequence.push_back(ch-'0');
       }
  vector<int>ans= nextPermutation(starting_sequence,k,count);
  string result="";
  for(int i=0;i<n;i++){
    result=result+to_string(ans[i]);
  }
  return result;
    }
};