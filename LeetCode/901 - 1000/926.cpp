//926. Flip String to Monotone Increasing

class Solution {
public:
    // greedy solution where we want s to be in the form of 0.....01...1
    int minFlipsMonoIncr(string s) {
        int count0 = 0, count1 = 0;
        // count number of zeroes in the string
        for(char ch : s)
            if(ch == '0') count0++;
        // initialise minimum number of flips
        int result = s.size() - count0;
        for(char ch : s){
            // if s[i] = 0 then decrease count of 0's there in the right side of index i
            if(ch == '0'){
                count0--;
            }
                // if s[i] = 1 then increase the count of 1's there in the left side of index i
            else{
                // minimum number of flips in minimum of number of flips from 0 to 1 in the right + number of flips from 1 to 0 in the left and result
                result = min(result, count0+count1);
                count1++;
            }
        }
        return result;
    }
};


