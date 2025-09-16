//brute force is simple O(n^2):

class Solution {
    public:
    int subarraySum(vextor<int>& arr,int k){
        int n=arr.size();
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum=sum+arr[j];
                if(sum==k){
                    count++;
                }
            }
        }
        return count;
    }
}


// optimal approach : O(n):

class Solution {
    public:
        int subarraySum(vector<int>& arr,int k) {
            int n = arr.size();
            map<int,int>m;
            int sum=0;
            int count=0;
            for(int i=0;i<n;i++){
                sum=sum+arr[i];
                if(sum==k){
                    count++;
    
                }
                int rem=sum-k;
                if(m.count(rem)){
                    count=count+m[rem];
                }
                m[sum]++;
            }
            return count;
        }
    };
    