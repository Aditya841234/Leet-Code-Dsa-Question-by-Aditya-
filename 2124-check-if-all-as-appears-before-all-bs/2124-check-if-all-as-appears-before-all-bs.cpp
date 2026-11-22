class Solution {
public:
    bool checkString(string s) {
        int i = 0;
        int n = s.length();
        
        // Move past all leading 'a's
        while (i < n && s[i] == 'a') {
            i++;
        }
        
        // Move past all subsequent 'b's
        while (i < n && s[i] == 'b') {
            i++;
        }
        
        // If we reached the end of the string, no 'a' appeared after a 'b'
        return i == n;
    }
};