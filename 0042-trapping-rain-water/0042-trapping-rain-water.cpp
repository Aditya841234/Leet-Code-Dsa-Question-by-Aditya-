class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        
        int maxHeight = height[0];
        int index = 0;
        for (int i = 1; i < n; i++) {
            if (height[i] > maxHeight) {
                maxHeight = height[i];
                index = i;
            }
        }
        
        int water = 0;
        int maxLeft = height[0];
        for (int i = 1; i < index; i++) {
            if (height[i] < maxLeft) {
                water += maxLeft - height[i];
            } else {
                maxLeft = height[i];
            }
        }
        
        int maxRight = height[n-1];
        for (int i = n-2; i > index; i--) {
            if (height[i] < maxRight) {
                water += maxRight - height[i];
            } else {
                maxRight = height[i];
            }
        }
        
        return water;
    }
};