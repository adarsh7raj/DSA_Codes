//brute force : O(2n)

class Solution {
    public:
        string reverseWords(string s) {
            int n=s.size();
            std::istringstream iss(s);
            vector<string> arr;
            int j=0;
         
            string word;
          while(iss>>word){
            arr.push_back(word);
          }
          reverse(arr.begin(),arr.end());
          string ans=arr[0];
          for(int i=1;i<arr.size();i++){
            cout<<arr[i];
          ans=ans+' '+arr[i];
          }
            return ans;
        }
    };

    //another approach: O(n):

// reverse the whole string and then reverse each word in the reversed string
  class Solution {
public:
    string reverseWords(string s) {
        //story
        //1. reverse whole string
        
        reverse(s.begin(), s.end());
        
        int i = 0;
        //hero honge hamare l and r jo revrese karenge words ko
        int l = 0, r = 0;
        
        int n = s.length();
        // take three pointers i,l,r , i for travesing the string
        // l and r for reversing the words
        while(i < n) {
            while(i < n && s[i] != ' ') { //i ko agar char dikha to r ko dega and i++ and r++
                s[r] = s[i];
                i++;
                r++;
            }
            
            if(l < r) { //l     r
                reverse(s.begin()+l, s.begin()+r);
                
                s[r] = ' ';
                r++;
                
                l = r;
            }
            
            i++; //y eto badhta rahega
        }
        
        s = s.substr(0 , r-1);
        
        return s;
        
    }
};