

//TC: O(N)
//SC: O(N)

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int count=0;
        int n=arr.size();
        vector<int>temp;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                count++;
            }
            else{
                temp.push_back(arr[i]);
            }
        }
        while(count>0){
            temp.push_back(0);
            count--;
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=temp[i];
        }
        
    }
};

// Optimal Solution
// TC: O(N)
// SC: O(1)

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        
        int n=arr.size();
        vector<int>temp;
        int k=0;
        for(int i=0;i<arr.size();i++){
         while( i<arr.size()  && arr[i]==0){
             
             i++;
         }
         if(i<arr.size()){
         swap(arr[i],arr[k]);
         k++;
         }
    
        }
    }
};