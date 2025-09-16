//

int nthRoot(int n, int m) {
    double result = pow(m, 1.0 / n);
    int rounded = round(result);
    if (pow(rounded, n) == m){ 
        return rounded
        
    };
    else {
        return -1;
    }
}

//optimal solution:  TC:O(logn) ,SC:O(1)
int nthRoot(int n, int m) {
    if (n == 1) return m;

    int left = 1;
    int right = m;

    while (left <= right) {
        int mid = (left + right) / 2;
        long long power = pow(mid, n); // Use long long to prevent overflow

        if (power == m) return mid;
        else if (power > m) right = mid - 1;
        else left = mid + 1;
    }

    return -1;
}

