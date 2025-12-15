class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
       int n = prices.size();
       long long total = 1;
       int current_count = 1;

       for(int i=1; i<n; i++){
         if(prices[i]==prices[i-1]-1){
            current_count++;
         }
         else{
            current_count = 1;
         }
         total += current_count;
       } 
       return total;
    }
};