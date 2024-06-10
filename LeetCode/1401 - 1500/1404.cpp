// 1404. Number of Steps to Reduce a Number in Binary Representation to One

// Solution 1 Naive Simulation
// Time complexity: O(n* k), n is the length of s, k is the number of steps
// Space complexity: O(1)
class Solution {
public:
    bool reachedEnd(string s){
        bool b = s.back() == '1';
        for(int i = 0; i < s.size()-1;i++){
            if(s[i] == '1'){
                b = false;
                break;
            }
        }
        return b;
    }

    void addOne(string& s){
        int carry = 1, n = s.size();
        for(int i = n-1; i >= 0;i--){
            int su = carry + s[i] - '0';
            if(su == 2){
                s[i] = '0';
                carry = 1;
            }
            else{
                s[i] = su + '0';
                carry = 0;
            }
            if(carry == 0) break;
        }
        if(carry == 1) s = '1' + s;
    }

    void rightShift(string& s){
        int n = s.size();
        for(int i = n-1; i > 0;i--) s[i] = s[i-1];
        s[0] = '0';
    }

    int numSteps(string s) {
        int res = 0;
        while(!reachedEnd(s)){
            if(s.back() == '1') addOne(s);
            else rightShift(s);
            res++;
        }
        return res;
    }
};


// Solution 2 Bit Manipulation and Math
// Time complexity: O(n), n is the length of s
// Space complexity: O(1)
class Solution {
public:
    int numSteps(string s) {
        int res = 0, carry = 0;
        for(int i = s.size()-1; i > 0;i--){
            // for right shift every bit
            res++;
            // for add one to odd number
            if(s[i] - '0' + carry == 1){
                carry = 1;
                res++;
            }
        }
        return res + carry;
    }
};