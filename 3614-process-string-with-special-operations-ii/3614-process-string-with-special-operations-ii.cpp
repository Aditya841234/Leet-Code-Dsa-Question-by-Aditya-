class Solution {
public:

    vector<long long> len;
    string s;


    char solve(int idx, long long k, bool rev) {

        if(idx < 0)
            return '.';


        char ch = s[idx];


        // Normal character append
        if(ch != '*' && ch != '#' && ch != '%') {

            // Current string = previous + ch
            // If reversed, ch is at index 0
            if(rev) {

                if(k == 0)
                    return ch;

                k--;
            }
            else {

                if(k == len[idx] - 1)
                    return ch;
            }

            return solve(idx - 1, k, rev);
        }


        // Delete last character
        if(ch == '*') {

            // If current view is reversed,
            // deleted character was at the front
            if(rev)
                k++;

            return solve(idx - 1, k, rev);
        }


        // Duplicate string
        if(ch == '#') {

            long long half = len[idx] / 2;

            if(k >= half)
                k -= half;

            return solve(idx - 1, k, rev);
        }


        // Reverse string
        if(ch == '%') {

            return solve(idx - 1, k, !rev);
        }


        return '.';
    }


    char processStr(string str, long long k) {

        s = str;

        len.resize(s.size());

        long long size = 0;


        // Calculate length after each operation
        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '*') {

                if(size > 0)
                    size--;
            }
            else if(s[i] == '#') {

                size *= 2;
            }
            else if(s[i] != '%') {

                size++;
            }

            len[i] = size;
        }


        if(k >= size)
            return '.';


        return solve(s.size()-1, k, false);
    }
};