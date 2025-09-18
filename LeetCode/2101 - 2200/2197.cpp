// 2197. Replace Non-Coprime Numbers in Array

// Solution 1: Using Bruteforce and Straight Forward Approach using Stack and Math functions
// Time Complexity: O(n*log(max(lcm_nums[i])))
// Space Complexity: O(n)
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> stk;
        vector<int> res;
        int n = nums.size();
        for(int i = 0; i < n;i++){
            int num = nums[i];
            if(!stk.empty() && gcd(num, stk.top()) > 1){
                while(!stk.empty() && gcd(num, stk.top()) > 1){
                    num = lcm(num, stk.top());
                    stk.pop();
                }
            }
            stk.push(num);
        }
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};