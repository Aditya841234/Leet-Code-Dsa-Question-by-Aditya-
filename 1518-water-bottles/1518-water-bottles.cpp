class Solution {
public:
    int numWaterBottles(int numBot, int numEx) {
       if(numEx>numBot) return n;//when bottle is less than the exchange
       int empty=0, consumed =0; //
       while(numBot){
         consumed += numBot;
         empty += numBot;
         numBot = empty/numEx ;
         empty %= numEx;
       } 
       return consumed;
    }
};