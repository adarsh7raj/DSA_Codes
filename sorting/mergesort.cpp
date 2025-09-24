void mergeSort(long long *arr, int low, int high) {
    if (low >= high) return; // Base case

    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void merge(long long *arr, int low, int mid, int high) {
    int left = low, right = mid + 1;
    vector<long long> temp;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
        
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy merged elements back to original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}