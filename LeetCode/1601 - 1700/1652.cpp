// 1652. Defuse the Bomb

// Solution 1 by simple condition checking
// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size(), sum;
        vector <int> temp = code;
        if(k > 0){
            for(int i = 0; i < n; i++){
                sum = 0;
                for(int j = i + 1; j <= i + k; j++){
                    sum += temp[j % n];
                }
                code[i] = sum;
            }
        }
        else if(k < 0){
            for(int i = 0; i < n; i++){
                sum = 0;
                for(int j = i + n - 1; j > i + n + k - 1 ; j--){
                    sum += temp[j % n];
                }
                code[i] = sum;
            }
        }
        else {
            for(int i = 0; i < n; i++){
                code[i % n] = 0;
            }
        }
        return code;
    }
};

// Solution 2 by Prefix Sum
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);
        if(k == 0) return res;
        vector<int> prefix(n+1, 0);
        for(int i = 0; i < n;i++) prefix[i+1] = prefix[i] + code[i];
        for(int i = 0; i < n;i++){
            if(k > 0) res[i] = prefix[min(i+k+1, n)] - prefix[i+1] + prefix[max((i+k-n+1), 0)] - prefix[0];
            else res[i] = prefix[i] - prefix[max(i+k, 0)] + prefix[n] - prefix[min(n+i+k, n)];
        }
        return res;
    }
};