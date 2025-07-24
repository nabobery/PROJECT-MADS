// 3307. Find the K-th Character in String Game II

// Solution 1: Using Simulation
// Time Complexity: O(n) where n is the number of operations
// Space Complexity: O(n) whee n is the number of operations
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        vector<int> requiredOperations = operations;
        while(pow(2, requiredOperations.size()-1) > k) requiredOperations.pop_back();
        int diff = 0;
        while(!requiredOperations.empty()){
            int sz = requiredOperations.size();
            int op = requiredOperations.back();
            if(op == 1 && k > pow(2, sz-1)){
                diff++; 
            }
            if(k > pow(2, sz-1)){
                k -= pow(2, sz-1);
            }
            requiredOperations.pop_back();
        }
        return ('a' + diff%26);
    }
};

