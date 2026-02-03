
class Solution {
  public:
    pair<int, int> get(int n) {
        // code here
       
        return n & (n - 1);
    }
};