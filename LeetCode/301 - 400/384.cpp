// 384. Shuffle an Array


// Solution using Fisher-Yates Algorithm
class Solution {
public:
    vector<int> orig;
    Solution(vector<int>& nums) {
        orig = nums; 
    }
    
    vector<int> reset() {
        return orig;
    }
    
    vector<int> shuffle() {
        if(orig.size() == 1) return orig;
        vector<int> temp = orig;
        int i = rand() % temp.size(), j = i;
        while(i == j) j = rand() % temp.size();
        swap(temp[i], temp[j]);
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */