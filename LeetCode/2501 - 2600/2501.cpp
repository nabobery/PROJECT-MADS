// 2501. Longest Square Streak in an Array

// Solution 1 using Unordered Set and using only sqaure numbers
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    bool isSquare(double num){
        double root = sqrt(num);
        return ceil(root) == floor(root);
    }
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> squares, s(nums.begin(), nums.end());
        unordered_map<int,int> mp;
        for(int num : nums)
            if(isSquare(num)) squares.insert(num);
        if(squares.empty()) return -1;
        for(auto it : squares){
            int root = sqrt(it), streak = 0;
            while(squares.count(root)){
                streak++;
                root = sqrt(root);
            }
            if(s.count(root)) streak++;
            if(streak) mp[it] = streak+1;
        }
        int res = -1;
        for(auto it : mp)
            res = max(res, it.second);
        return res;
    }
};