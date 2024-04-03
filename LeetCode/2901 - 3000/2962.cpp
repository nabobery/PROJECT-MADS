// 2962. Count Subarrays Where Max Element Appears at Least K Times

// Solution 1 using Priority Queue
// Time complexity: O(nlogn)
// Space complexity: O(n)
// The idea is to first find the maximum element in the array and then iterate through the array and maintain a priority queue of indices of the maximum element.
// The priority queue will store the indices of the maximum element in increasing order.
// When we have atleast k indices of the maximum element, we can calculate the number of subarrays that satisfy the condition.
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int mx = 0;
        for (int num : nums)
            mx = max(mx, num);
        long long res = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            // If the current element is the maximum element, push its index to the priority queue
            if (nums[i] == mx)
                pq.push(i);
            // If the size of the priority queue is equal to k, 
            // which is equal to pq.top() + 1 (because there are pq.top() elements before the 1st maximum element in the window such that the maximum element appears at least k times)
            if (pq.size() == k)
            {
                res++;
                res += pq.top();
            }
            // If the size of the priority queue is greater than k (k+1)
            // we pop the smallest index from the priority queue and move thw window rightwards
            // The number of subarrays is pq.top() + 1 (because there are pq.top() elements before the 1st maximum element in the window)
            else if (pq.size() > k)
            {
                res++;
                pq.pop();
                res += pq.top();
            }
        }
        return res;
    }
};


// Solution 2 using Two Pointers and Sliding Window
// Time complexity: O(n)
// Space complexity: O(1)
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int mx = 0;
        for (int num : nums) mx = max(mx, num);
        long long res = 0;
        int l = 0, r = 0, cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == mx)
                cnt++;
            while (cnt == k)
            {
                res += nums.size() - i;
                if (nums[l++] == mx)
                    cnt--;
            }
        }
        return res;
    }
};

// Solution 2 v2
// Time complexity: O(n)
// Space complexity: O(1)
class Solution{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int mx = *max_element(nums.begin(), nums.end());
        long long res = 0, l = 0;
        for(int r = 0; r < nums.size(); r++){
            if(nums[r] == mx) k--;
            while(k == 0)
                if(nums[l++] == mx) k++;
            res += l;
        }
        return res;
    }
};