// 1780. Check if Number is a Sum of Powers of Three

// Solution 1: By calculating if n can be made using powers of 3 (subset sum)
// Time Complexity: O(2^15)
// Space Complexity: O(1)

class Solution {
    public:
    
        void helper(int ind, vector<int>& nums, int curr, int& target, bool& res){
            if(curr > target) return;
            if(ind == nums.size()){
                if(curr == target) res = true;
                return;
            }
            helper(ind+1, nums, curr + nums[ind], target, res);
            helper(ind+1, nums, curr, target, res);
        }
        bool checkPowersOfThree(int n) {
            bool res = false;
            vector<int> nums;
            for(int i = 0; i < 15;i++) nums.push_back(pow(3, i));
            helper(0, nums, 0, n, res);
            return res;
        }
};

// Solution 2 by checking if there're only 1's and 0's present in ternary expression
// Time Complexity: O(log3 n)
// Space Complexity: O(1)

class Solution{
    public:
        bool checkPowersOfThree(int n){
            while(n > 0){
                if(n % 3 == 2) return false;
                n /= 3;
            }
            return true;
        }
};