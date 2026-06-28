class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();

        // Sort the array to arrange elements in increasing order
        sort(arr.begin(), arr.end());

        // The first element must be 1
        arr[0] = 1;

        // Make sure adjacent difference is at most 1
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1] + 1) {
                arr[i] = arr[i - 1] + 1;
            }
        }

        // The maximum element will be the last element
        return arr[n - 1];
    }
};