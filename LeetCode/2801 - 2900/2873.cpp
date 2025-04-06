// 2873. Maximum Value of an Ordered Triplet I

// Solution 1: Using 3 nested loops
// Time Complexity: O(n^3), where n is the number of elements in the array
// Space Complexity: O(1)
class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long res = 0;
            int n = nums.size();
            for(int i = 0; i < n-2;i++){
                for(int j = i+1; j < n-1;j++){
                    for(int k = j+1; k < n;k++){
                        long long curr = nums[i] - nums[j];
                        curr *= nums[k];
                        res = max(res, curr);
                    }
                }
            }
            return res;
        }
};

// Solution 2: Using 2 nested loops and a multiset
// Time Complexity: O(n^2logn), where n is the number of elements in the array
// Space Complexity: O(n), where n is the number of elements in the array
class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long res = 0;
            int n = nums.size();
            multiset<int> s(nums.begin(), nums.end());
            for(int i = 0; i < n-2;i++){
                s.erase(s.find(nums[i]));
                multiset<int> temp = s;
                for(int j = i+1; j < n-1;j++){
                    temp.erase(temp.find(nums[j]));
                    long long curr = nums[i] - nums[j];
                    curr *= *temp.rbegin();
                    res = max(res, curr);
                }
            }
            return res;
        }
};