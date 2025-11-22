// 2154. Keep Multiplying Found Values by Two

// Solution 1. Simulation
// Time Complexity: O(1000) ~ O(n)
// Space Complexity: O(1000) ~ O(n)
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        bool seen[1001] = {false};
        for (int num : nums) {
            seen[num] = true;
        }
        while (original <= 1000 && seen[original]) {
            original *= 2;
        }
        
        return original;
    }
};

// Solution 2. Simulation with Unordered Set
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> seen(nums.begin(), nums.end());
        while (seen.count(original)) {
            original *= 2;
        }
        
        return original;
    }
};