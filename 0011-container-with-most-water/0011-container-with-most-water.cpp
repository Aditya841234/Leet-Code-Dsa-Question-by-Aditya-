class Solution {
public:
    int maxArea(vector<int>& height) {
      int max_area = 0;
      int left =0;
      int right = height.size()-1;
      while(left<right){
        //we need to find the height of left
        int h = min(height[left],height[right]);

        int w = right-left;

        max_area = max(max_area,h*w);

        if(height[left] < height[right]){
            left++;
        }
        else
         right--;
      }

      return max_area;  
    }
};