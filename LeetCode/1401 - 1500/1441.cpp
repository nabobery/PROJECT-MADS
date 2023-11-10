// 1441. Build an Array With Stack Operations

// Solution 1 Using Simulation
// Time complexity: O(n)
// Space complexity: O()
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int p = 1;
        for(auto num : target){
            if(num == p){
                res.push_back("Push");
                p++;
            }
            else{
                while(p < num){
                    res.push_back("Push");
                    res.push_back("Pop");
                    p++;
                }
                res.push_back("Push");
                p++;
            }
        }
        return res;
    }
};

// Cleaner Solution 1

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int p = 1;
        for(auto num : target){
            while(p < num){
                res.push_back("Push");
                res.push_back("Pop");
                p++;
            }
            res.push_back("Push");
            p++;
        }
        return res;
    }
};

