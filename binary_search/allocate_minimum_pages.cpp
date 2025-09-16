//optimal solution :O(nlogn):

int  isPossible(vector<int>& arr, int total_students, int x) {
    int student_count = 1;
    int total_pages = 0;

    for (int i = 0; i < arr.size(); i++) {
      //  if (arr[i] > x) return false;

       if(arr[i]+total_pages<x){
 total_pages+=arr[i];
       }
       else{
student_count++;
total_pages=arr[i];
       }
       
       }
    }

    return total_students;


int findPages(vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) return -1;  // Not enough books

    int sum = 0;
    int largest = INT_MIN;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        largest = max(largest, arr[i]);
    }

    int low = largest;
    int high = sum;                                    
    

    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(arr, k, mid)<=k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return low;
}
