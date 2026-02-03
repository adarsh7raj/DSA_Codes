//TC: O(1) , SC: O(1)
class Solution {
  public:
    int replaceBit(int n, int k) {
        // code here.
      
        return  n & ~(1<<k);
    }
};

