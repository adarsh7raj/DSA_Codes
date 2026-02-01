// brute force approach
//TC: O(sqrt(n))
//SC: O(1)

class Solution {
public:
    int mySqrt(int x) {
      long long ans=1;
      long long  i=1;
      for(;i<=x;i++){
    ans=i*i;
    if(ans>=x){
        break;
    }
      } 
      if(ans==x){
        return i;
      } 
  return i-1;
    }
};

// optimal approach: TC: O(logn)
//SC: O(1)

class Solution {
public:
    int mySqrt(int x) {
     long  l=1;
     long r=x;
     while(l<=r){
        long long  mid=l+(r-l)/2;
        if(mid*mid==x){
            return mid;
        }
        else if(mid*mid>x){
    r=mid-1;
        }
        else{
            l=mid+1;
        }
     }
     return r;
    }

};