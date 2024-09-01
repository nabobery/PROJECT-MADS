// 2191. Sort the Jumbled Numbers

// Solution 1 by sorting with custom comparator using mapping
// Time complexity: O(nlogn)
// Space complexity: O(n)
unordered_map<int, int> mp;
class Solution {
public:
    static int mapped_number(int num) {
        if(num == 0) return mp[num];
        int mapped_num = 0;
        int factor = 1;
        while (num > 0) {
            int digit = num % 10;
            mapped_num += mp[digit] * factor;
            factor *= 10;
            num /= 10;
        }
        return mapped_num;
    }

    static bool compare(pair<int, int>& a, pair<int, int>& b) {
        int mapped_a = mapped_number(a.first);
        int mapped_b = mapped_number(b.first);
        if (mapped_a != mapped_b) {
            return mapped_a < mapped_b;
        }
        return a.second < b.second;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        mp.clear();
        int n = nums.size();
        vector<pair<int, int>> numbers(n);
        for (int i = 0; i < n; ++i) {
            numbers[i] = { nums[i], i };
        }
        for (int i = 0; i <= 9; ++i) {
            mp[i] = mapping[i];
        }
        sort(numbers.begin(), numbers.end(), compare);
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = numbers[i].first;
        }
        return res;
    }
};

// Optimised Solution 1
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    int mapped_number(int num) {
        if (num == 0) return mp[num];
        int mapped_num = 0;
        int factor = 1;
        while (num > 0) {
            int digit = num % 10;
            mapped_num += mp[digit] * factor;
            factor *= 10;
            num /= 10;
        }
        return mapped_num;
    }

    static bool compare(pair<int, int>& a, pair<int, int>& b) {
        if (a.first != b.first) 
            return a.first < b.first;
        return a.second < b.second;
    }
    unordered_map<int, int> mp;
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> numbers(n);
        for (int i = 0; i <= 9; ++i) 
            mp[i] = mapping[i];
        for (int i = 0; i < n; ++i) 
            numbers[i] = { mapped_number(nums[i]), i };
        sort(numbers.begin(), numbers.end(), compare);
        vector<int> res(n);
        for (int i = 0; i < n; ++i) 
            res[i] = nums[numbers[i].second];
        return res;
    }
};
