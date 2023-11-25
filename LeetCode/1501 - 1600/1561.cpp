// 1561. Maximum Number of Coins You Can Get

// Solution 1 using Sort 
// Time Complexity: O(nlogn)
// Space Complexity: O(logn)
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int res = 0;
        for(int r = piles.size()/3; r < piles.size();r += 2) res += piles[r];
        return res; 
    }
};

