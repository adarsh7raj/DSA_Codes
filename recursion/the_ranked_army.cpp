

#include <iostream>
using namespace std;

int countWays(int pos, int prev, int N, int r, int end) {
    
    // Base case → reached last position
    if(pos == N) {
        return (prev == end); // only count if last digit == end
    }

    int ways = 0;

    for(int digit = 1; digit <= r; digit++) {
        
        // no two consecutive same
        if(digit != prev){
             ways += countWays(pos + 1, digit, N, r, end);
        } 

       
    }

    return ways;
}

int main() {
    int N, r, end;
    cin >> N >> r >> end;

    // start is fixed = 1
    int result = countWays(1, 1, N, r, end);

    cout << result;
}