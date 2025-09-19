
// TC : O(n^2) in worst case
// SC : O(1)
// Insertion Sort Algorithm

void insertion_sort(int arr[], int n) {
    // Intuition:
    // Think of how you sort playing cards in your hand.
    // You pick one card at a time and insert it into its correct position among the already sorted cards.
    // Here, the left side of the array becomes sorted step by step,
    // while the right side is still unsorted.

    for (int i = 0; i <= n - 1; i++) {  
        // i represents the index of the "current element" we want to place
        // correctly in the sorted part of the array (0 to i-1).

        int j = i;  // Start from the current index
        while (j > 0 && arr[j - 1] > arr[j]) {
            // While the current element (arr[j]) is smaller than the one before it (arr[j-1]),
            // keep swapping it backwards until it reaches its correct position.

            swap(arr[j], arr[j - 1]);
            j--; // Move one step left
        }
        // At the end of this while loop, the subarray arr[0..i] is sorted.
    }
}

// Algorithm (Step-by-step):
// 1. Start with the second element (index 1), because a single element (index 0) is already "sorted".
// 2. Compare the current element with the elements before it.
// 3. Shift (swap) the current element left until it is in the correct position relative to the sorted part.
// 4. Repeat for all elements until the array is fully sorted.

int main() {
    int arr[5] = {5, 4, 3, 2, 1};
    int n = 5;

    insertion_sort(arr, n);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}