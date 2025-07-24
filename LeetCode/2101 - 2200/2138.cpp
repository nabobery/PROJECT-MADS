// 2138. Divide a String Into Groups of Size k

// Solution 1: Simple and Straight Forward
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        int n = s.size();
        string curr;
        for(int i = 0; i < n;i++){
            curr += s[i];
            if(curr.size() == k){
                res.push_back(curr);
                curr = "";
            }
        }
        if(!curr.empty() && curr.size() < k){
            while(curr.size() < k) curr += fill;
            res.push_back(curr);
        }
        return res;
    }
};