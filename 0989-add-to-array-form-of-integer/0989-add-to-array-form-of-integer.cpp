class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        vector<int> result;
        
        int i = n - 1;
        int carry = 0;
        
        while (i >= 0 || k > 0 || carry > 0) {
            int digit1 = (i >= 0) ? num[i] : 0;
            int digit2 = k % 10;
            
            int sum = digit1 + digit2 + carry;
            result.push_back(sum % 10);
            carry = sum / 10;
            
            if (i >= 0) i--;
            k /= 10;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};