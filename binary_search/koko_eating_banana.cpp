//TC: O(n log m) , SC: O(1)

class Solution {
public:
bool isPossible(vector<int>& piles,int h,int k){
    for(int i=0;i<piles.size();i++){
      int hours=ceil ((double)piles[i]/k);
      h-=hours;
    }
    if(h<0){
        return false;
    }
    return true;
}
    int minEatingSpeed(vector<int>& piles, int h) {
      int n=piles.size();
     // sort(piles.begin(),piles.end());
      int l=1;
      int r=INT_MAX;
      while(l<=r){
        int mid=l+(r-l)/2;

        if(isPossible(piles,h,mid)){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
      }
      return l;
    }
};