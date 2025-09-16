// brute force approach :


//You are given a read only array of n integers from 1 to n.

//Each integer appears exactly once except A which appears twice and B which is missing.Return A and B.



// brute force approach 1:
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    vector<int> ans(2,0);
    int repeated=-1;
    int missing=-1;
    int count=0;
    for(int i=1;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(A[j]==i){
                count++;
            }
        }
        if(count==2){
            ans[0]=i;
            break;
        }
        else if(count==0){
            ans[1]=i;
            break;
        }
    }
    return ans;

}

// brute force approach 2 :
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    
    // Make a copy of A since A is const and cannot be modified
    vector<int> B = A;
    std::sort(B.begin(), B.end());
    
    vector<int> arr(2, 0);
    if(A[0]!=1){
        arr[1]=1;
    }
    if(n==2){
        arr[0]=A[0];
        if(A[1]==1){
            arr[1]=2;
            return arr;
        }
        arr[1]=1;
        return arr;
    }
    if(A[n-1]!=n){
        arr[1]=n;
    }
    for (int i = 0; i < n - 1; i++) {
        if (B[i] == B[i + 1]) {
            arr[0] = B[i];  // Repeated number
        }
        if (B[i + 1] - B[i] > 1) {
            arr[1] = B[i] + 1;  // Missing number
        }
    }

    return arr;
}
// better solution this method uses hashing :

vector<int> Solution::repeatedNumber(const vector<int> &A) {

    int n=A.size();
    vector<int> frequency(n+1,0);
    int repeated=-1;
    int missing=-1;
    vector<int> ans(2,0);
    for(int i=0;i<n;i++){
    frequency[A[i]]++;

    }
    for(int i=1;i<=n;i++){
        if(frequency[i]==2){
            ans[0]=i;
        }
        else if(frequency[i]==0){
            ans[1]=i;
        }
    }
  return ans;
 
}
//optimal solution TC:O(n) SC:O(1);
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long n = A.size();
    long sum1=0;
    long sum2=0;
    long long value1;
    long long value2;
    for( int i=0;i<n;i++){
        sum1=sum1+A[i];
        sum2=sum2+(long long)A[i]*(long long)A[i];
    }
 
    long long s1=n*(n+1);
    s1=s1/2;
    long long s2=n*(n+1)*(2*n+1);
    s2=s2/6;
    value1=sum1-s1;
    value2=(sum2-s2)/value1;
    long long x=(value1+value2)/2;
    long long  y=(value2-value1)/2;
    return {(int)x,(int)y};
}
    
    

//optimal solution using XOR:
vector<int> Solution::repeatedNumber(const vector<int> &A) {
int n=A.size();
int xor=0;
for(int i=0;i<n;i++){
    xor=xor^A[i];
    xor=xor^(i+1);
}
int bitno=0;
while(true){
    if((xor&(1<<bitno))!=0){
        break;
    }
    bitno++;
}
int one=0;
int zero=0;
for(int i=0;i<n;i++){
    if((A[i]&(1<<bitno))!=0){
    one=one^A[i];
    }
    else{
        zero=zero^A[i];
    }
}
for(int i=1;i<=n;i++){
    if((i&(1<<bitno))!=0){
        one=one^(i);
        }
        else{
            zero=zero^(i);
        }
}
int count=0;
for(int i=0;i<n;i++){
    if(A[i]==zero){
        count++;
    }
}
if(count==0){
    return {zero,one};
}
return {one,zero};
}

//Brute force TC:O(n)
// You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.

// Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.

class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
           vector<int> arr;
           vector<int> ans(2,0);
           for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                arr.push_back(grid[i][j]);
            }
           }  
           sort(arr.begin(),arr.end());
           int n=arr.size();
           if(arr[n-1]!=n){
            ans[1]=n;
           }
           if(arr[0]!=1){
            ans[1]=1;
           }
            for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] == arr[i + 1]) {
                ans[0] = arr[i];  // Repeated number
            }
            if (arr[i + 1] - arr[i] > 1) {
                ans[1] = arr[i] + 1;  // Missing number
            }
        }
        return ans;
        }
    };