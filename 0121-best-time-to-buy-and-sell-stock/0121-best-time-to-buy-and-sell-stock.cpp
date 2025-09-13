class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;// ini
        int maxProfit = 0;
        
        int size = prices.size();

        //finding maximum profit

        for(int i =0; i<size; i++){
            if(prices[i]<minPrice){
                minPrice = prices[i];
            }
            else if(prices[i]-minPrice > maxProfit){
                maxProfit=  prices[i]-minPrice;
            }
        }
       return maxProfit;
    }
};