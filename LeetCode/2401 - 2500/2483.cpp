// 2483. Minimum Penalty for a Shop

// Solution 1: Using Prefix Sum
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> prefix(n+1, 0);
        for(int i = 0; i < n;i++){
            prefix[0] += (customers[i] == 'Y');
        }
        for(int i = 1; i < n;i++){
            prefix[i] = prefix[i-1] + (customers[i-1] == 'Y' ? -1 : 1);
        }
        prefix[n] = prefix[n-1] + (customers[n-1] == 'Y' ? -1 : 1);
        int mi = n, res;
        for(auto p : prefix) mi = min(p, mi);
        for(int i = 0; i < prefix.size();i++){
            if(mi == prefix[i]){
                res = i;
                break;
            }
        }
        return res;
    }
};

// Solution 2: Using Prefix Sum but in O(1) space with 2 Pass
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size(),prefix = 0;
        for(int i = 0; i < n;i++) 
            prefix += (customers[i] == 'Y');
        int mi = prefix, res = 0;
        for(int i = 0; i < n;i++){
            prefix += (customers[i] == 'Y' ? -1 : 1);
            if(mi > prefix){
                mi = prefix;
                res = i+1;
            }
        }
        return res;
    }
};

// Solution 3: Using Prefix Sum but in O(1) space with one pass
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size(),prefix = 0, mi = 0, res = 0;
        for(int i = 0; i < n;i++){
            prefix += (customers[i] == 'Y' ? -1 : 1);
            if(mi > prefix){
                mi = prefix;
                res = i+1;
            }
        }
        return res;
    }
};