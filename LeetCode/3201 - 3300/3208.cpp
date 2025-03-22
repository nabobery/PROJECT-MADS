// 3208. Alternating Groups II

// Solution 1 using Sliding Window
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int res = 0, n = colors.size(), l = 0, group_sz = 1, r = 1;
            while(l < n){
                if(group_sz < k){
                    if(colors[(r-1) % n] != colors[r%n])
                        group_sz++;
                    else{
                        l = r;
                        group_sz = 1;
                    }
                }
                if(group_sz == k){
                    res++;
                    group_sz--;
                    l++;
                }
                r++;
            }
            return res;
        }
};