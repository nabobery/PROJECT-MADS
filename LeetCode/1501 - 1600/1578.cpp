// 1578. Minimum Time to Make Rope Colorful

// Solution 1 Greedy  by maintaining the running sum and max value for repeated letters.
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int s = neededTime[0], mx = neededTime[0], n = colors.size(), result = 0;
        for(int i = 1; i < n;i++){
            int j = i;
            while(j < n && colors[j-1] == colors[j]){
                s += neededTime[j];
                mx = max(mx, neededTime[j]);
                j++;
            }
            if(s > mx) result += (s - mx);
            if(j < n) s = neededTime[j];
            mx = s;
            i = j;
        }
        return result;
    }
};

