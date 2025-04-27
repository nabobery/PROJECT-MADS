// 781. Rabbits in Forest

// Solution 1: Greedy Approach and Math
// Time Complexity: O(n)
// Space Complexity: O(1)
// 1. Count the number of rabbits with the same answer
// 2. For each unique answer, calculate the number of rabbits needed
// 3. The number of rabbits needed is (number of rabbits with the same answer)/(answer + 1) + (number of rabbits with the same answer)%(answer + 1) != 0
// 4. Multiply the number of rabbits needed by (answer + 1) to get the total number of rabbits
class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            unordered_map<int, int> mp;
            for(int&answer : answers) mp[answer]++;
            int res = 0;
            for(auto& it : mp){
                res += (it.second/(it.first+1) + (it.second%(it.first+1) != 0))*(it.first+1);
            }
            return res;
        }
};