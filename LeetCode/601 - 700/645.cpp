// 645. Set Mismatch

// Solution 1 using Sort
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int dup = -1, missing = 1, n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i-1]) {
                dup = nums[i];
            } else if (nums[i] > nums[i-1] + 1) {
                missing = nums[i-1] + 1;
            }
        }
        return {dup, nums[n-1] != n ? n : missing};
    }
};

// Solution 2 using visited array
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size(), rep = 0, mis = 0;
        vector<bool> vis(n+1, false);
        for(int i : nums){
            if(vis[i]) rep = i;
            vis[i] = true;
            mis += i;
        }
        mis = (n*(n+1))/2 - mis + rep;
        return {rep, mis};
    }
};

// Solution 3 using unordered_set
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> s;
        int dup = -1, n = nums.size(),  sum = (n*(n+1))/2;
        for (int i : nums) {
            if (s.count(i)) dup = i;
            sum -= i;
            s.insert(i);
        }
        return {dup, sum + dup};
    }
};

// Solution 4 using XOR
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size(), xor1 = 0, xor2 = 0;
        for (int i = 0; i < n; i++) {
            xor1 ^= nums[i];
            xor2 ^= (i+1);
        }
        int xor3 = xor1 ^ xor2;
        int rightmostbit = xor3 & ~(xor3 - 1);
        int num1 = 0, num2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] & rightmostbit) num1 ^= nums[i];
            else num2 ^= nums[i];
        }
        for (int i = 1; i <= n; i++) {
            if (i & rightmostbit) num1 ^= i;
            else num2 ^= i;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] == num1) return {num1, num2};
        }
        return {num2, num1};
    }
};