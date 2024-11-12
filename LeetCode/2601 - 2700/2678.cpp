// 2678. Number of Senior Citizens

// Solution 1: Simple and straight forward
// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        for(string citizen: details)
            if(stoi(citizen.substr(11,2)) > 60) res++;
        return res;
    }
};