
//TC:O(N)
//SC:O(1)
class Solution {
public:
    bool check(vector<int>& arr) {
     int drop=0;
     int n=arr.size();

     
     for(int i=0;i<n;i++){

         if(arr[i]>arr[(i+1)%n]){
           drop++;
         }
     }
     if(drop>1){
        return false;
     }
           return true;
}
};
