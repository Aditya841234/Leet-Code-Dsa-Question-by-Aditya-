class Solution {
public:
    int countOdds(int low, int high) {
      int ans = low;
      int count = 0;
       while(ans<=high){
           if(ans%2==0){
               ans = ans + 1;
            } 
            else{
                 ans = ans +2;
                 count++;
            }
       }
       return count;
    }
};