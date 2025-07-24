// 2099. Find Subsequence of Length K With the Largest Sum

// Solution 1: Using Sorting and Ranking
// Time Complexity: O(n log n), where n is the size of the input array.
// Space Complexity: O(n), for storing pairs and ranks.
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size(), p = 0;
        vector<pair<int,int>> pairs(n);
        for(int i = 0; i < n;i++) pairs[i] = {i, nums[i]};
        sort(pairs.begin(), pairs.end(), [](pair<int,int>& a, pair<int, int>& b){
            return a.second > b.second;
        });
        vector<int> rank(n), res(k);
        for(int i = 0; i < n;i++) rank[pairs[i].first] = i;
        for(int i = 0; i < n;i++){
            if(rank[i] < k) res[p++] = nums[i];
        }
        return res;
    }
};

// Solution 2: Using Priority Queue of pairs and then use sorting based on indices for subsequence
// Time Complexity: O(n log n), where n is the size of the input array.
// Space Complexity: O(n), for storing pairs 
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        // Using a min-heap to keep track of the k largest elements
        for(int i = 0; i < n; i++) {
            minHeap.push({nums[i], i});
            if(minHeap.size() > k) minHeap.pop();
        }
        vector<int> res;
        // get the k largest element's indices
        while(!minHeap.empty()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        // Sort the indices to maintain the order of the subsequence
        sort(res.begin(), res.end());
        vector<int> subsequence;    
        for(int i : res) {
            subsequence.push_back(nums[i]);
        }       
        return subsequence;
    }
};
