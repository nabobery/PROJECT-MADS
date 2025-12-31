// 3074. Apple Redistribution into Boxes

// Solution 1: Using Greedy Approach and Sorting
// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(1) 
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int res = 0, reqCapacity = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end());
        for(int i = capacity.size()-1; i >= 0;i--){
            reqCapacity -= capacity[i];
            res++;
            if(reqCapacity <= 0 ) break; 
        }
        return res;
    }
};