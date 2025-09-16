// slightly different approach TC :  (n) SC: O(1):

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        // Step 1: Find index of the highest bar
        int maxIndex = 0;
        for (int i = 1; i < n; ++i) {
            if (height[i] > height[maxIndex]) {
                maxIndex = i;
            }
        }

        int water = 0;
        int leftMax = 0;

        // Step 2: Traverse from left to maxIndex , treat this maximum as rightMax
        for (int i = 0; i < maxIndex; ++i) {
            if (height[i] >= leftMax)
                leftMax = height[i];
            else
                water += leftMax - height[i];
        }

        int rightMax = 0;

        // Step 3: Traverse from right to maxIndex , treat this maximum as leftMax
        for (int i = n - 1; i > maxIndex; --i) {
            if (height[i] >= rightMax)
                rightMax = height[i];
            else
                water += rightMax - height[i];
        }

        return water;
    }
};

// TC : O(n) and SC : O(1):

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax)
                    leftMax = height[left];
                else
                    water += leftMax - height[left];
                ++left;
            } else {
                if (height[right] >= rightMax)
                    rightMax = height[right];
                else
                    water += rightMax - height[right];
                --right;
            }
        }

        return water;
    }
};
 
// TC : O(n) SC : O(n):

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> leftMax(n), rightMax(n);
        leftMax[0] = height[0];
        for (int i = 1; i < n; ++i) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        int water = 0;
        for (int i = 0; i < n; ++i) {
            water += min(leftMax[i], rightMax[i]) - height[i];
        }

        return water;
    }
};
