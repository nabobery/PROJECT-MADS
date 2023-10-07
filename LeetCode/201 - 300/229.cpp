// 229. Majority Element II

// Solution 1 using hash map
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        n /= 3;
        unordered_map<int,int> mp;
        for(auto i : nums) mp[i]++;
        vector<int> res;
        for(auto it : mp){
            if(it.second > n){
                res.push_back(it.first);
            }
        }
        return res;
    }
};

// Solution 2 using Boyer-Moore Majority Vote algorithm
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0, num1 = 0, num2 = 1;
        for(auto i : nums){
            if(i == num1) cnt1++;
            else if(i == num2) cnt2++;
            else if(cnt1 == 0){
                num1 = i;
                cnt1 = 1;
            }
            else if(cnt2 == 0){
                num2 = i;
                cnt2 = 1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for(auto i : nums){
            if(i == num1) cnt1++;
            else if(i == num2) cnt2++;
        }
        vector<int> res;
        if(cnt1 > n/3) res.push_back(num1);
        if(cnt2 > n/3) res.push_back(num2);
        return res;
    }
};