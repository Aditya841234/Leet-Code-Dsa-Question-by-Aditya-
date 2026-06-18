class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
         int n = heights.size();
        vector<int>right(n);
        vector<int>left(n);
        stack<int>st;
       

        //this code is for the finding the right smallest elemnt 

        for(int i=0;i<n;i++){
           
            while(!st.empty() && heights[st.top()]>heights[i]){
                right[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()){
            right[st.top()]=n;
            st.pop();
        }


        //now we have to write the code for the left next smallest 

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>heights[i]){
                left[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()){
            left[st.top()]=-1;
            st.pop();
        }

        // now we taken out all the part right and left both 

      //now we are going to write the code for maximum output 
    int ans=0;
      for(int i =0;i<n;i++){
        ans= max(ans,heights[i]*(right[i]-left[i]-1));
      }
     
     return ans;
        
    }
};