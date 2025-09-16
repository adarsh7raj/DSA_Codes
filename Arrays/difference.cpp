int main(){
   int result=differenc(arr); 
}

int difference(vector<int>&arr){
    sort(arr.begin(),arr.end(),[](int a,int b){
        return a<b;
    });
    int n=arr.size();
    map<int,vector<int>>subs;
    for(int i=0;i<n;i++){
        int max_dif=INT_MIN;
     for(int j=i+1;j<n;j++){
        int diff=arr[j]-arr[i];
        if(subs.count(diff)){
            subs[diff].push_back(arr[j]);
        }
        else{
            vector<int,int>diff_arr;
            diff_arr.push_back(i);
            diff_arr.push_back(j);
            subs[diff]=diff_arr;
        }
   

     }
    }
}