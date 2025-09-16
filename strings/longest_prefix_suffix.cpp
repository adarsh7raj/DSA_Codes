// Function to compute the LPS (Longest Prefix Suffix) array for a given string
// LPS[i] = the length of the longest proper prefix of substring(0..i)
//          which is also a suffix of substring(0..i)
vector<int> computeLPS(const string& needle) {
    int n = needle.size();
    vector<int> lps(n, 0); // Initialize LPS array with 0s
    
    int len = 0; // length of the current longest prefix-suffix match
    int i = 1;   // start from index 1 (since lps[0] is always 0)

    // Build the LPS array
    while (i < n) {
        if (needle[i] == needle[len]) {
            // ✅ Case 1: Characters match
            // We can extend the current prefix-suffix match
            len++;
            lps[i] = len;  // Store the length of the longest prefix-suffix for position i
            i++;
        } else {
            // ❌ Case 2: Mismatch occurs
            if (len != 0) {
                // Instead of starting over, fall back to the
                // length of the previous longest prefix-suffix
                len = lps[len - 1];
                // (Notice: we don’t increment i here, we retry with the new len)
            } else {
                // If no prefix-suffix can be reused, set lps[i] = 0
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}
