// brute force approach : 
class Solution {
  public:
  bool is_sum_k=false;
  void solve(int sum,int i,vector<int>arr,int k){
     
      if(i>=arr.size()){
          return;
      }
       if(sum==k){
       is_sum_k=true;
       return;
      }
      solve(sum+arr[i],i+1,arr,k);
      solve(sum,i+1,arr,k);
  }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
         solve(0,0,arr,k);
         return is_sum_k;
    }
};




// slightly better approach :
#include <iostream>
#include <vector>
using namespace std;

// Function to check if subsequence with sum K exists
bool isSubsequenceSumK(int index, vector<int>& arr, int currentSum, int K) {
    // Base case: if currentSum equals K
    if (currentSum == K) return true;

    // If we've gone through all elements
    if (index == arr.size()) return false;

    // Include the current element
    if (isSubsequenceSumK(index + 1, arr, currentSum + arr[index], K))
        return true;

    // Exclude the current element
    if (isSubsequenceSumK(index + 1, arr, currentSum, K))
        return true;

    return false;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int K = 9;

    if (isSubsequenceSumK(0, arr, 0, K))
        cout << "Yes, a subsequence with sum " << K << " exists.\n";
    else
        cout << "No subsequence with sum " << K << " exists.\n";

    return 0;
}


// optimal approach :
// it is done by dp