// 902. Numbers At Most N Given Digit Set
// Not efficient
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string number = to_string(n);
        int result = 0;
        for(int i = 1; i < number.size();i++){
            result += pow(digits.size(),i);
        }
        int i = 0;
        while(i < number.size()){
            int j = 0;
            while(j < digits.size() && digits[j][0] < number[i]){
                result += pow(digits.size(), number.size() - 1 - i);
                j++;
            }
            if(j == digits.size() || digits[j][0] > number[i]){
                return result;
            }
            i++;
        }
        result++;
        return result;
    }
};

// not space efficent but fast
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string number = to_string(n);
        int l = number.length();
        vector<int> dp(l+1,0);
        dp[l] = 1;
        for(int i = l - 1; i >=0; i--){
            int ni = number[i] - '0';
            for(string d : digits){
                if(stoi(d) < ni)
                    dp[i] += pow(digits.size(), l -1 -i);
                else if(stoi(d) == ni)
                    dp[i] += dp[i + 1];
            }
        }
        for(int i = 1; i < l; i++){
            dp[0] += pow(digits.size(), i);
        }
        return dp[0];
    }
};