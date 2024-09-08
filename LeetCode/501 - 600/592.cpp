// 592. Fraction Addition and Subtraction

// Solution 1 using Math and String Parsing
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }
    int denom_lcm(vector<int>& denom){
        int res = 1;
        for(auto i : denom) res = lcm(res, i);
        return res;
    }
    string fractionAddition(string expression) {
        vector<int> numerators, denominators;
        int n = expression.size();
        for(int i = 0; i < n;i++){
            int j = i;
            while(j < n && expression[j] != '/') j++;
            string num = expression.substr(i, j-i);
            j++;
            int k = j;
            while(k < n && (expression[k] != '-' && expression[k] != '+')) k++;
            string denom = expression.substr(j, k-j);
            i = k-1;
            numerators.push_back(stoi(num));
            denominators.push_back(stoi(denom));
        }
        int denom = denom_lcm(denominators), num = 0;
        for(int i = 0; i < numerators.size();i++){
            num += numerators[i] * (denom / denominators[i]);
        }
        if(num == 0) denom = 1;
        else if (gcd(denom, abs(num)) != 1){
            int lc = gcd(abs(num), denom);
            denom /= lc;
            num /= lc;
        }
        string res = to_string(num) + "/" + to_string(denom);
        return res;
    }
};
