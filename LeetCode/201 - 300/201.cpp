// 201. Bitwise AND of Numbers Range

// Solution 1 by finding the common prefix of l and r
// Time complexity: O(32) = O(1)
// Space complexity: O(32) = O(1)
class Solution {
public:
    string toBinary(int n) {
        string result;
        while (n) {
            result += to_string(n % 2);
            n /= 2;
        }
        reverse(result.begin(), result.end());
        return result;
    }
    int rangeBitwiseAnd(int left, int right) {
        if(left == right) return right;
        string l = toBinary(left), r = toBinary(right);
        if(l.size() != r.size()) return 0;
        int res = 0, n = l.size();
        for(int i = 0;i < n;i++){
            if(l[i] != r[i]) break;
            else
                if(l[i] == '1') res += pow(2, n-i-1);
        }
        return res;
    }
};

// Cleaned up solution 1 without reversing the string
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == right) return right;
        string l = toBinary(left), r = toBinary(right);
        if(l.size() != r.size()) return 0;
        int res = 0, n = l.size();
        for(int i = n-1;i >= 0;i--){
            if(l[i] != r[i]) break;
            else
                if(l[i] == '1') res += pow(2, i);
        }
        return res;
    }
    string toBinary(int n) {
        string result;
        while (n) {
            result += to_string(n % 2);
            n /= 2;
        }
        return result;
    }
};