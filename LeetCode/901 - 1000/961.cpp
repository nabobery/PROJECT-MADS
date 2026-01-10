// 961. N-Repeated Element in Size 2N Array

// Solution 1: Naive and Straightforward
// The Array is of Size 2N and Contains N+1 Unique Elements 
// One Element is Repeated N Times -> Find that Element
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> s;
        for(int num: nums){
            if(s.count(num)) return num;
            s.insert(num);
        }
        return -1;
    }
};