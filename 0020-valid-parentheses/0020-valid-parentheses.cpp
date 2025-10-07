class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[' ){
                stck.push(s[i]);
            }
            else{
                if( stck.size() == 0) {
                    return false;
                }
                
                if((stck.top()=='(' && s[i]==')') || 
                (stck.top()=='{' && s[i]=='}') || (stck.top()=='[' && s[i]==']') )
                {
                    stck.pop();
                }
                else
                 return false;
            }
        }
        return stck.size()==0;
    }
};