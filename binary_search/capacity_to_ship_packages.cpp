
// TC: O(n log m) , SC: O(1)
class Solution {
public:
bool isPossible(vector<int>weights,int days,int weight_cap){
    int sum=0;
    for(int i=0;i<weights.size();i++){
        sum+=weights[i];
      if(sum>weight_cap){
        days--;
        sum=weights[i];
      }
    }
    if(sum>0){
        days--;
    }
    if(days<0){
        return false;
    }
    return true;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
        }
        int l=*max_element(weights.begin(),weights.end());
        int r=sum;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(weights,days,mid)){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};


// cleaner version
class Solution {
public:
    bool canShip(const vector<int>& weights, int days, int capacity) {
        int currentLoad = 0;
        int requiredDays = 1;

        for (int w : weights) {
            if (currentLoad + w > capacity) {
                requiredDays++;
                currentLoad = 0;
            }
            currentLoad += w;
        }

        return requiredDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = 0;

        for (int w : weights) {
            right += w;
        }

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (canShip(weights, days, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
