//brute force O(n^2):
class Solution {
    public:
        int findContentChildren(vector<int>& g, vector<int>& s) {
            sort(g.begin(),g.end());
            sort(s.begin(),s.end());
            int count=0;
            for(int i=0;i<g.size();i++){
                int j=0;
                while(j<s.size()){
                  if(g[i]<=s[j]){
                    count++;
                    s[j]=-1;
                    break;
                  }
                  else{
                    j++;
                  }
                }
            }
            return count;
        }
    };

    //optimal O(nlogn):

    class Solution {
        public:
            int findContentChildren(vector<int>& g, vector<int>& s) {
                sort(g.begin(),g.end());
                sort(s.begin(),s.end());
                int count=0;
                    int i=0;
                    int j=0;
                    while(i<s.size() && j<g.size()){
                      if(s[i]>=g[j]){
                        count++;
                       i++;
                       j++;
                      }
                      else{
                        i++;
                      }
                    }
                
                return count;
            }
        };