// 2011. Final Value of Variable After Performing Operations

// Solution 1: Straightforward Simulation
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;
        for(auto& op: operations){
            if(op.find("+") != string::npos) res++;
            else res--;
        }
        return res;
    }
};