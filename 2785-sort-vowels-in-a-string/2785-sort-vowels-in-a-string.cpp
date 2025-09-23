class Solution {
public:
    string sortVowels(string s) {
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);
        
        // Identify vowels and count them
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                lower[s[i] - 'a']++;
                s[i] = '#';
            }
            else if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                upper[s[i] - 'A']++;
                s[i] = '#';
            }
        }
        
        // Collect all vowels in sorted order
        string vowels;
        
        // Add uppercase vowels first (A, E, I, O, U)
        for(int i = 0; i < 26; i++) {
            char c = 'A' + i;
            if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                while(upper[i] > 0) {
                    vowels += c;
                    upper[i]--;
                }
            }
        }
        
        // Add lowercase vowels (a, e, i, o, u)
        for(int i = 0; i < 26; i++) {
            char c = 'a' + i;
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                while(lower[i] > 0) {
                    vowels += c;
                    lower[i]--;
                }
            }
        }
        
        // Replace '#' with sorted vowels
        int vowelIndex = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '#') {
                s[i] = vowels[vowelIndex++];
            }
        }
        
        return s;
    }
};