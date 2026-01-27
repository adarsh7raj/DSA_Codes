// TC: O(N+M)
// SC: O(N+M)

class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<a.size();i++){
            mp[a[i]]++;
        }
        for(int i=0;i<b.size();i++){
            mp[b[i]]++;
        }
        for(auto it:mp){
            ans.push_back(it.first);
        }
        return ans;
    }
};

// as in this question it is said that the arrays are not sorted and we do not have to return the
//  union array in sorted order.
// we can use unordered_set or unordered_map to store the elements of both arrays and then return
// the elements of the set as a vector.

// If the arrays were sorted and we had to return the union array in sorted order
// Then we could have used the two pointer approach on two sorted arrays to solve this question
// in O(N+M) time and O(1) auxilary space.