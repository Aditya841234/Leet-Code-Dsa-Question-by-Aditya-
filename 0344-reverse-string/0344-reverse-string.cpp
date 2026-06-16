class Solution {
public:
    void reverseString(vector<char>& s) {
    //    int n = s.size();
    //    int start=0,end=n-1;
    //    while(start<end){
    //     swap(s[start],s[end]);
    //     start++;
    //     end--;
    //    }


    // we can use also stack for solving this problem 

    stack<char>st;
    for(int i=0;i<s.size();i++){
        st.push(s[i]);
    }
      
    //for retreiving the data 
    int i =0;

    while(!st.empty()){
        s[i]=st.top();
        i++;
        st.pop();
    }
    
    }
};