// 905. Sort Array By Parity

// Solution 1 using 2 pointers and memory
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> res(nums.size());
        int p1 = 0, p2 = nums.size()-1;
        for(auto i : nums){
            if(i&1) res[p2--] = i;
            else res[p1++] = i;
        }
        return res;
    }
};

// Solution 2 using 2 pointers and no memory
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int p1 = 0, p2 = nums.size()-1;
        while(p1 < p2){
            if(nums[p1]&1){
                swap(nums[p1], nums[p2]);
                p2--;
            }
            else p1++;
        }
        return nums;
    }
};

// Solution 3 using sort function
// Time complexity: O(nlogn)
// Space complexity: O(1)
class Solution {
public:
    bool static comparator(int a, int b){
        return (a&1) < (b&1);
    }
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comparator);
        return nums;
    }
};