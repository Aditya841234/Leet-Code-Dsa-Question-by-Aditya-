class Solution {
public:
    string clearDigits(string s) {
        string ans="";
        stack<char>st;
        int j=s.size()-1;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='1' ||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
                if(!st.empty())
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
       return ans;
    }
};