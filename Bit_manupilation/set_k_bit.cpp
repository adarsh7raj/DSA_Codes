//TC: O(1) , SC: O(1)

class Solution {
  public:
    int setKthBit(int n, int k) {
        // Code here
        return 1<<k | n;
    }
};
