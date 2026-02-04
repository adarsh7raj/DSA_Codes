


// brute force approach
//TC: O(logn) , SC: O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1){
            return true;
        }
        if(n<=0){
            return false;
        }
        while(n>1){
            if(n%2==1){
                return false;
            }
            n=n/2;
        }
        return true;
    }
};


// optimal approach
//TC: O(1) , SC: O(1)

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0){
            return false;
        }
       return n&(n-1)?false:true;
    }
};