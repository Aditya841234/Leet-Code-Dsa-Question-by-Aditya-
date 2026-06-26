class Solution {
public:
    bool rotateString(string s, string goal) {
       if (s.length() != goal.length()) {
            return false;
        }
        
        // Concatenate s with itself
        string doubled = s + s;
        
        // Check if goal exists within the doubled string
        return doubled.find(goal) != string::npos; 
    }
};