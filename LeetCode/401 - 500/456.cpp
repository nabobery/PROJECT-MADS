// 456. 132 Pattern

// my naive solution using multisets and binary search
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;
        multiset<int> s1, s2;
        for(auto i : nums) s2.insert(i);
        for(int j = 0; j < n;j++){
            s2.erase(s2.find(nums[j]));
            if(!s1.empty() && ! s2.empty()){
                int nums_i = *s1.begin();
                if(s2.upper_bound(nums_i) != s2.end()){
                    int nums_k = *s2.upper_bound(nums_i);
                    if(nums_i < nums[j] && nums_k < nums[j])
                        return true;
                }
            }
            s1.insert(nums[j]);
        }
        return false;
    }
};

// Solution 2: using stack
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        // if size < 3, return false
        if(n < 3) return false;
        // we use a stack to store the numbers that are larger than nums_k which are candidates of nums_j
        stack<int> s;
        // nums_k is the largest number in the stack
        int nums_k = INT_MIN;
        // we traverse from the end of the array
        for(int i = n - 1; i >= 0; i--){
            // if nums[i] < nums_k, we find the 132 pattern
            if(nums[i] < nums_k) return true;
            else{
                // if nums[i] > nums_k, we need to update nums_k
                // we pop the numbers in the stack that are smaller than nums[i]
                // and update nums_k to the largest number in the stack
                while(!s.empty() && nums[i] > s.top()){
                    nums_k = s.top();
                    s.pop();
                }
            }
            // we push nums[i] into the stack
            s.push(nums[i]);
        }
        return false;
    }
};

