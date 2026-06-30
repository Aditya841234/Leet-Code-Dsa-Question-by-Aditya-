class Solution {
public:
    int numberOfSubstrings(string s) {
       int n = s.length();

       int result = 0;

       vector<int> fc(3,0); //0-a,1-b,2-c that is shoe the index of the count element 

       int i = 0;
       int j = 0;

       while(j<n){
        char ch = s[j];
        fc[ch-'a']++;

        while(fc[0]>0 && fc[1] > 0 && fc[2] > 0){
            result += (n-j);

            fc[s[i] - 'a']--;
            i++;
        }

        j++;
       }

      return result;
    }
};