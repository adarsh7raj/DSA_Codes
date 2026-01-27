
//TC: O(log N)
//SC: O(1)
        int mini=INT_MAX;
        int l=0;
        int r=arr.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid]>target){
                mini=min(mini,mid);
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return mini==INT_MAX ? arr.size():mini;