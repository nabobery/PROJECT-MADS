// 1512. Number of Good Pairs

// Solution 1 using array
// O(n) time complexity, O(100)= O(1) space complexity
class Solution {
public:
    int count[100];
    int numIdenticalPairs(vector<int>& nums) {
        memset(count, 0, sizeof(count));
        for(auto i : nums) count[i-1]++;
        int res = 0;
        for(auto i : count){
            if(i >= 2) res += (i*(i-1)/2);
        }
        return res;
    }
};

// Solution 2 using unordered_map
// O(n) time complexity, O(n) space complexity 
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> count;
        for(auto i : nums) count[i-1]++;
        int res = 0;
        for(auto it : count){
            if(it.second >= 2) res += (it.second*(it.second-1)/2);
        }
        return res;
    }
};