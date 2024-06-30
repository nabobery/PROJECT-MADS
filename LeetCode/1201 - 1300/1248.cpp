// 1248. Count Number of Nice Subarrays

// My Naive Solution 1 using Sliding Window and prefix sum
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        for(int& num : nums) num = num%2;
        vector<int> prefix(n+1, 0);
        for(int i = 1; i <= n;i++) prefix[i] = prefix[i-1] + nums[i-1];
        int l = 0;
        for(int r = 1; r <= n;r++){
            if(prefix[r] - prefix[l] == k){
                int temp = l;
                while(prefix[r] - prefix[temp] == k){
                    res++;
                    temp++;
                }
            }
            else if(prefix[r] - prefix[l] > k){
                while(prefix[r] - prefix[l] > k) l++;
                int temp = l;
                while(prefix[r] - prefix[temp] == k){
                    res++;
                    temp++;
                }
            }
        }
        return res;
    }
};

// Solution 2 using Unordered Map and prefix sum ( A better approach than Solution 1 as we're storing the prefix sum to number of sub arrays with that prefix sum mapping)
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        for(int& num : nums) num = num%2;
        unordered_map<int, int> prefix;
        prefix[0] = 1;
        int sum = 0;
        for(int i = 0; i < n;i++){
            sum += nums[i];
            if(prefix.find(sum - k) != prefix.end()) res += prefix[sum - k];
            prefix[sum]++;
        }
        return res;
    }
};

// Solution 3 using Queue
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res = 0, n = nums.size(), l = -1, gap = -1;
        queue<int> q;
        for(int i = 0; i < n;i++){
            if(nums[i]%2) q.push(i);
            if(q.size() > k){
                l = q.front();
                q.pop();
            }
            if(q.size() == k){
                gap = q.front() - l;
                res += gap;
            }
        }
        return res;
    }
};

// Solution 4 using Sliding Window = Sum of at most k odd numbers - Sum of at most k-1 odd numbers
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
    
    int atMost(vector<int>& nums, int k){
        int res = 0, n = nums.size(), l = 0, odd = 0;
        for(int r = 0; r < n;r++){
            if(nums[r]%2) odd++;
            while(odd > k){
                if(nums[l]%2) odd--;
                l++;
            }
            res += r - l + 1;
        }
        return res;
    }
};
