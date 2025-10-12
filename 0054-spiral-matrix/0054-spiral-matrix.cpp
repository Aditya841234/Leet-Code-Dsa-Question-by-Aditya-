#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) return result;
        
        int m = matrix.size();    // number of rows
        int n = matrix[0].size(); // number of columns
        
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;
        
        while (top <= bottom && left <= right) {
            // Traverse from left to right along top row
            for (int j = left; j <= right; j++) {
                result.push_back(matrix[top][j]);
            }
            top++;
            
            // Traverse from top to bottom along right column
            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;
            
            // Traverse from right to left along bottom row
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    result.push_back(matrix[bottom][j]);
                }
                bottom--;
            }
            
            // Traverse from bottom to top along left column
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        
        return result
    }
};