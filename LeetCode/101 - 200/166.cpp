// 166. Fraction to Recurring Decimal

// Solution 1: Using Math (Long Division method using HashMap to store the remainder and its corresponding index in the result string)
// Time Complexity: O(n) where n is the number of digits in the result
// Space Complexity: O(n) for the hashmap to store the remainders
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(!numerator) return "0";
        string res;
        long abs_num = abs(long(numerator)), abs_denom = abs(long(denominator));
        long quotient = abs_num/abs_denom, remainder = abs_num % abs_denom;
        bool differentParity = ((numerator ^ denominator) < 0);
        if(differentParity) res += "-";
        res += to_string(quotient);
        if(remainder != 0){
            res += ".";
            unordered_map<int, int> repeatedRemainder;
            bool isRecurring = false;
            repeatedRemainder[remainder] = 0;
            string fraction;
            while(remainder > 0){
                int cnt = 0;
                while(remainder < abs_denom){
                    remainder *= 10;
                    cnt++;
                }
                quotient = remainder/abs_denom;
                remainder %= denominator;
                if(cnt > 1) fraction += string(cnt-1, '0');
                fraction += to_string(quotient);
                if(repeatedRemainder.count(remainder)){
                    isRecurring = true;
                    break;
                }
                repeatedRemainder[remainder] = fraction.size();
            }
            if(!isRecurring) res += fraction;
            else{
                res += fraction.substr(0, repeatedRemainder[remainder]);
                res += "(";
                res += fraction.substr(repeatedRemainder[remainder]);
                res += ")";
            }
        }
        return res;
    }
};

// Cleaner Solution 1
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // Handle the zero numerator case.
        if (numerator == 0) {
            return "0";
        }

        string result;

        // 1. Determine the sign.
        // The XOR operator is a concise way to check if signs are different.
        if ((numerator > 0) ^ (denominator > 0)) {
            result += "-";
        }

        // 2. Use long long to prevent overflow with INT_MIN.
        // abs(INT_MIN) overflows, so we cast to a larger type first.
        long long num = abs(static_cast<long long>(numerator));
        long long den = abs(static_cast<long long>(denominator));

        // 3. Append the integer part.
        result += to_string(num / den);
        long long remainder = num % den;

        // If there's no remainder, we are done.
        if (remainder == 0) {
            return result;
        }

        // 4. Handle the fractional part.
        result += ".";
        
        // Use a map to store remainders and the index where they appeared.
        // Key: remainder, Value: index in the result string.
        unordered_map<long long, int> remainderMap;

        while (remainder != 0) {
            // If we've seen this remainder before, we've found the repeating cycle.
            if (remainderMap.count(remainder)) {
                // Insert the opening parenthesis at the start of the repeating sequence.
                result.insert(remainderMap[remainder], "(");
                result += ")";
                break;
            }
            
            // Store the current remainder and the current length of the string.
            // This marks the position where the cycle might start.
            remainderMap[remainder] = result.length();

            // Simulate long division: bring down a '0'.
            remainder *= 10;
            
            // Append the next digit of the fraction.
            result += to_string(remainder / den);
            
            // Update the remainder.
            remainder %= den;
        }
        
        return result;
    }
};