


class Solution {
   public:
   int getSecondLargest(vector<int>arr) {
        // code here
        
        int firstHigh=-1;
        int secondHigh=-1;
        
        for(int i=0;i<arr.size();i++){
            if(firstHigh==arr[i]){
                continue;
            }
            if(firstHigh<arr[i]){
                int temp=firstHigh;
                
                firstHigh=arr[i];
                secondHigh=temp;
            }
            else{
                secondHigh=max(arr[i],secondHigh);
            }
        }
      
        return secondHigh;
    }
};