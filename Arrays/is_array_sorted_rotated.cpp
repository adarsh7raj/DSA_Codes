
//TC:O(N)
//SC:O(1)

// the drop is greater thnan 1 then return false else true and we check in circular manner using mod operator
// and we always check the last element and  the first element ;
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
