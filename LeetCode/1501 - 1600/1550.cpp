// 1550. Three Consecutive Odds

// Straight forward Solution 1
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i <= n-3;i++)
            if(arr[i]%2 && arr[i+1]%2 && arr[i+2]%2) return true;
        return false;
    }
};
