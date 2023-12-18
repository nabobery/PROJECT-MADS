// 1464. Maximum Product of Two Elements in an Array

// Solution 1 - Easy and Simple (maintaining max and second max)
// Time Complexity = O(N)
// Space Complexity = O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx1 = -1, mx2 = -1;
        for(int num : nums){
            if(num >= mx1){
                mx2 = mx1;
                mx1 = num;
            }
            else if(num > mx2) mx2 = num;
        }
        return (mx1-1)*(mx2-1);
    }
};

