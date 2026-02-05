
//TC:O(n)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int Xor=0;
        for(auto it :nums){
            Xor^=it;
        }
       long ux=(long) Xor;
         int pos = 0;
        while ((Xor & 1) == 0) {
            Xor>>= 1;
            pos++;
        }
        int mask=1<<pos;// instead of finding position we can directly find the rightmost set bit 
        //by doing Xor & -Xor
        int A=0;
        int B=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] & mask){
              A=A^nums[i];
            }
            else{
                B=B^nums[i];
            }
        }
        return {A,B};
    }
};

