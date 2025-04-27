// 1399. Count Largest Group

// Solution 1: Using Brute Force (straightforward)
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
    public:
        int sumToGroup[37];
        int countLargestGroup(int n) {
            memset(sumToGroup, 0, sizeof(sumToGroup));
            int mx = 0, res = 0;
            for(int i = 1; i <= n;i++){
                int sum = 0, temp = i;
                while(temp > 0){
                    sum += (temp % 10);
                    temp /= 10;
                }
                sumToGroup[sum]++;
                mx = max(sumToGroup[sum], mx);
            }
            for(auto& i : sumToGroup) if(i == mx) res++;
            return res;
        }
};