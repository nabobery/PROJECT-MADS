// 703. Kth Largest Element in a Stream

// Solution 1 using set
// Time complexity: O(nlogk)
// Space complexity: O(k)

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

class KthLargest {
public:
    int k;
    multiset<int> s;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        s.insert(nums.begin(), nums.end());
    }
    
    int add(int val) {
        s.insert(val);
        auto it = s.rbegin();
        for(int i = 0; i < k-1;i++) it++;
        return *it;
    }
};

// Solution 2 using priority_queue
// Time complexity: O(nlogk)
// Space complexity: O(k)

class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num : nums) {
            pq.push(num);
            if(pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k) pq.pop();
        return pq.top();
    }
};