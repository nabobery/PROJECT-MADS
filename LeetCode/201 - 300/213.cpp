// 213. House Robber II

// O(n) Time and O(n) Space Solution
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(n,0),dp2(n,0);
        dp1[0] = 0, dp1[1] = nums[0];
        dp2[0] = 0, dp2[1] = nums[1];
        for(int i = 2; i < n;i++){
            dp1[i] =  max(dp1[i-2] + nums[i-1], dp1[i-1]);
            dp2[i] =  max(dp2[i-2] + nums[i], dp2[i-1]);
        }
        return max(dp1[n-1], dp2[n-1]);
    }
};

// O(n) Time and O(1) Space Solution
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int t10 = 0,  t11 = nums[0], t20 = 0, t21 = nums[1],temp;
        for(int i = 2; i < n;i++){
            temp = t11;
            t11 =  max(t10 + nums[i-1], t11);
            t10 = temp;
            temp = t21;
            t21 =  max(t20 + nums[i], t21);
            t20 = temp;
        }
        return max(t11, t21);
    }
};