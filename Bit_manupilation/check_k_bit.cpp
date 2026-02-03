

// brute force approach : O(logn)


class Solution {
  public:
    bool checkKthBit(int n, int k) {
        //  code here
        string binary="";
        while(n>=1){
            if(n%2==0){
                binary+='0';
            }
            else{
                binary+='1';
            }
            n=n/2;
        }
        reverse(binary.begin(),binary.end());
        int len=binary.size()-k-1;
        if( binary.size()<=k){
            return false;
        }
        if(binary[len]=='0' ){
            return false;
        }
        return true;
    }
};


// optimal solution : TC: O(1) , SC: O(1)

class Solution {
  public:
    bool checkKthBit(int n, int k) {
        //  code here
       return n>>k & 1;
    }
};