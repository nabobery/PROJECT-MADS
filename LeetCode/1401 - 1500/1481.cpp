// 1481. Least Number of Unique Integers after K Removals

// Solution 1 using HashMap and PriorityQueue
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(int num : arr) mp[num]++;
        priority_queue <int, vector<int>, greater<int> > pq; 
        for(auto& it : mp) pq.push(it.second);
        while(!pq.empty()){
            if(pq.top() <= k){
                k -= pq.top();
                pq.pop();
            }
            else break;
        }
        return pq.size();
    }
};

// Solution 2 using HashMap and Sorting
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(int num : arr) mp[num]++;
        vector<int> freq;
        for(auto& it : mp) freq.push_back(it.second);
        sort(freq.begin(), freq.end());
        int i = 0;
        while(i < freq.size() && k > 0){
            if(freq[i] <= k){
                k -= freq[i];
                i++;
            }
            else break;
        }
        return freq.size() - i;
    }
};