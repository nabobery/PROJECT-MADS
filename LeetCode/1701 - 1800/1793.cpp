// 1793. Maximum Score of a Good Subarray

// Solution 1 using 2 Pointers and Greedy Approach
// Time Complexity = O(N)
// Space Complexity = O(1)

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int l = k, r = k, mi = nums[k], res = nums[k];
        while(l >= 0 && r <= nums.size()-1){
            if(l == 0 && r == nums.size()-1) break;
            if(l > 0 && r < nums.size()-1){
                if(nums[l-1] > nums[r+1]){
                    l--;
                    mi = min(mi, nums[l]);
                    res = max(res, mi*(r-l+1));
                }
                else{
                    r++;
                    mi = min(mi, nums[r]);
                    res = max(res, mi*(r-l+1));
                }
            }
            else if(l > 0){
                l--;
                mi = min(mi, nums[l]);
                res = max(res, mi*(r-l+1));
            }
            else{
                r++;
                mi = min(mi, nums[r]);
                res = max(res, mi*(r-l+1));
            }
        }
        return res;
    }
};

// A neater Solution 1
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int l = k, r = k, mi = nums[k], res = nums[k];
        while(l > 0 || r < nums.size()-1){
            if(l == 0) r++;
            else if(r == nums.size()-1) l--;
            else if(nums[l-1] > nums[r+1]) l--;
            else r++;
            mi = min(mi, min(nums[l], nums[r]));
            res = max(res, mi*(r-l+1));
        }
        return res;
    }
};

// Solution 2 using Binary Search
// Time Complexity = O(NlogN)
// Space Complexity = O(N)
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        // get the prefix of left array based on right array
        int res = helper(nums, k);
        reverse(nums.begin(), nums.end());
        // get the prefix of right array based on left array and return max
        return max(res, helper(nums, nums.size()-1-k));
    }

    int helper(vector<int>& nums, int k){
        int n = nums.size(), res = 0;
        vector<int> left(k, 0), right;
        int mi = INT_MAX;
        // get the prefix of left array by finding the minimum value from k to 0
        for(int i = k-1; i >= 0; i--){
            mi = min(mi, nums[i]);
            left[i] = mi;
        }
        mi = INT_MAX;
        // get the prefix of right array by finding the minimum value from k to n
        for(int i = k; i < n; i++){
            mi = min(mi, nums[i]);
            right.push_back(mi);
        }
        // find the maximum prefix that can be obtained from the left array based on the right array
        for(int j = 0; j < right.size(); j++){
            // the minimum value of the right array should be the minimum value of the left array too
            mi = right[j];
            // find the index of the first element in the left array that is greater than or equal to mi
            int i = lower_bound(left.begin(), left.end(), mi) - left.begin();
            // update the maximum score
            res = max(res, mi*(k+j+1-i));
        }
        // return the maximum score
        return res;
    }
};

// Solution 3 using Stack
// Time Complexity = O(N)
// Space Complexity = O(N)
// The basic idea is to find the subaarray that has nums[i] as the minimum value and get the optimal answer
// We do this by finding the first element that is smaller than nums[i] from the left and first element that is smaller than nums[i] from the right
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] > nums[i]){
                left[st.back()] = i;
                st.pop();
            }
            st.push(i);
        }
        // clear the stack
        st.clear();
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                right[st.back()] = i;
                st.pop();
            }
            st.push(i);
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            if(left[i] < k && k < right[i]){
                res = max(res, nums[i]*(right[i]-left[i]-1));
            }
        }
        // return the maximum score
        return res;
    }
};
