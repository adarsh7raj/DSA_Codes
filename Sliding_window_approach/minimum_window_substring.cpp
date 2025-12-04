
// minimum_window_substring.cpp
//TC:O(n*m) SC:O(m) where n=length of s and m=length of t

// This solution will give TLE for large inputs
class Solution {
public:
bool it_contains(unordered_map<char,int>& check,unordered_map<char,int>& curr){

if(curr.size()<check.size()){
    return false;
}
for(auto it : check){
    if(it.second>curr[it.first]){
        return false;
    }
}
return true;

}
    string minWindow(string s, string t) {
     int n=s.size();
     string result="";
     int mini=INT_MAX;
     vector<string>ans;
     unordered_map<char,int>check;
for(auto c:t){
    check[c]++;
}

     unordered_map<char,int>curr;
     int l=0;
     int r=0;
while(r<n){
    curr[s[r]]++;

    while(it_contains(check,curr)){
        if(mini>r-l+1){
            result=s.substr(l,r-l+1);
            mini=r-l+1;
        }
    
     curr[s[l]]--;
     l++; 
    }
    r++;
}
      
    return result;
    }
};

//optimal solution : 
// TC : O(2n) and SC: O(m) where n=length of s and m=length of t
class Solution {
public:

    string minWindow(string s, string t) {
     int CurrWindowSize=0;
     int MinWindowSize=INT_MAX;
     int start_idx=0;
     int l=0;
     int r=0;
     int n=s.size();
     int count=t.size();
     unordered_map<char,int>check;
     for(auto c:t){
        check[c]++;
        
      }


     while(r<n){
     if(check[s[r]]>0){
        count--;
     }
     check[s[r]]--;

     while(count==0){
        CurrWindowSize=r-l+1;
        if(MinWindowSize>CurrWindowSize){
            MinWindowSize=CurrWindowSize;
            start_idx=l;
        }
        check[s[l]]++;
        if(check[s[l]]>0){
            count++;
        }
        l++;
     }
     r++;
     }        
                    
    return MinWindowSize==INT_MAX ? "":s.substr(start_idx,MinWindowSize);
    }
};