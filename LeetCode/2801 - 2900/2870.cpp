// 2870. Minimum Number of Operations to Make Array Empty

// Solution 1 Simple and Intuitive using math and count table
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> cnt;
        for(int num : nums) cnt[num]++;
        int result = 0;
        for(auto it : cnt){
            if(it.second%3 != 1){
                if(it.second%3 != 0) result++;
                result += it.second/3;
            }
            else{
                if(it.second < 4) return -1;
                result += (it.second-4)/3 + 2;
            }

        }
        return result;
    }
};

// Cleaned up version of solution 1
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> cnt;
        for(int num : nums) cnt[num]++;
        int result = 0;
        for(auto it : cnt){
            if(it.second == 1) return -1;
            result += ceil((double)(it.second) / 3);
        }
        return result;
    }
};