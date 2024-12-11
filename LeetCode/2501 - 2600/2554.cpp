// 2554. Maximum Number of Integers to Choose From a Range I

// Solution 1: Using Set
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int> s(banned.begin(), banned.end());
        int currS = 0, res = 0;
        for(int i = 1; i <= n;i++){
            if(s.count(i)) continue;
            currS += i;
            if(currS > maxSum) break;
            res++;
        }
        return res;
    }
};

// Solution 2: Using Hashed Set
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> s(banned.begin(), banned.end());
        int currS = 0, res = 0;
        for(int i = 1; i <= n;i++){
            if(s.count(i)) continue;
            currS += i;
            if(currS > maxSum) break;
            res++;
        }
        return res;
    }
};