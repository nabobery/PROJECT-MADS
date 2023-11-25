// 1630. Arithmetic Subarrays

// Solution 1 using Priority queue
// Time complexity: O(m*nlogn)
// Space complexity: O(n)
class Solution {
public:
    bool helper(priority_queue <int, vector<int>, greater<int>> pq){
        if(pq.size() < 3) return true;
        bool b = true;
        int p = pq.top();
        pq.pop();
        int diff = pq.top() - p;
        p = pq.top();
        pq.pop();
        while(!pq.empty()){
            if(diff != pq.top() - p){
                b = false;
                break;
            }
            else{
                p = pq.top();
                pq.pop();
            }
        }
        return b;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        for(int i = 0; i < l.size();i++){
            priority_queue <int, vector<int>, greater<int>> pq(nums.begin()+l[i], nums.begin()+r[i]+1);
            res.push_back(helper(pq));
        }
        return res;
    }
};

// Solution 2 without using priority queue/Sorting
// Time complexity: O(m*n)
// Space complexity: O(n)
class Solution {
public:
    bool helper(vector<int> arr){
        if(arr.size() < 3) return true;
        int min_elem = INT_MAX, max_elem = INT_MIN;
        unordered_set<int> s;
        for(int i = 0; i < arr.size(); i++){
            min_elem = min(min_elem, arr[i]);
            max_elem = max(max_elem, arr[i]);
            s.insert(arr[i]);
        }
        if((max_elem - min_elem)%(arr.size()-1) != 0) return false;
        int diff = (max_elem - min_elem)/(arr.size()-1);
        for(int i = 0; i < arr.size(); i++){
            if(s.find(min_elem + i*diff) == s.end()) return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        for(int i = 0; i < l.size();i++){
            res.push_back(helper(vector<int>(nums.begin()+l[i], nums.begin()+r[i]+1)));
        }
        return res;
    }
};