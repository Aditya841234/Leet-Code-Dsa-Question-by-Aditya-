int Num(char c){
    if( c == 'I')
    return 1;
    else if(c == 'V')
    return 5;
    else if(c == 'X')
    return 10;
    else if(c == 'L')
    return 50;
    else if(c == 'C')
    return 100;
    else if(c == 'D')
    return 500;
    else
     return 1000;
}

class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();

        int Ans = 0;
        int index =0;
        while(index < n-1){
           if(Num(s[index]) < Num(s[index+1])){
              Ans -= Num(s[index]);
           }
           else{
             Ans += Num(s[index]);
           }
           index++;
        }
         Ans += Num(s[index]);

        return Ans;
    }
};