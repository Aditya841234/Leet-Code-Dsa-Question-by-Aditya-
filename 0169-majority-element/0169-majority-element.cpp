class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityElement = 0;
        int count =0;
        for(int i =0; i< nums.size(); i++){
            if(count==0){
                count = count +1;
                majorityElement = nums[i];
            }
            else{
                if(majorityElement == nums[i]){
                    count++;
                }
                else
                  count--;
            }
        }
        return majorityElement;
    }
};