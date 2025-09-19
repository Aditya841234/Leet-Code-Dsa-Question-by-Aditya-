class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       if(strs.empty()){
          return " "; 
         
       } 

       sort(strs.begin(), strs.end());

        string first = strs[0];
        string last = strs.back();

        string answer = "";

        int i =0;
        while( i < first.size() && i < last.size()){

            if(first[i] == last[i]){
                answer += first[i];
                i++;
            }
            else{
                break;
            }
        }
        return answer;
    }
};