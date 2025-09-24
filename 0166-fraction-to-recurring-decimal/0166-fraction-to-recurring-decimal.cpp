class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        
        string result;
        
        // Handle sign
        if ((numerator < 0) ^ (denominator < 0)) {
            result += '-';
        }
        
        // Convert to long long to avoid overflow
        long long num = abs(static_cast<long long>(numerator));
        long long den = abs(static_cast<long long>(denominator));
        
        // Integer part
        result += to_string(num / den);
        long long remainder = num % den;
        
        if (remainder == 0) {
            return result;
        }
        
        // Fractional part
        result += '.';
        unordered_map<long long, int> remainderMap;
        
        while (remainder != 0) {
            // If remainder repeats, we found a cycle
            if (remainderMap.find(remainder) != remainderMap.end()) {
                int pos = remainderMap[remainder];
                result.insert(pos, "(");
                result += ')';
                return result;
            }
            
            // Store current remainder position
            remainderMap[remainder] = result.length();
            
            // Perform division
            remainder *= 10
            result += to_string(remainder / den);
            remainder %= den;
        }
        
        return result;
    }
};
