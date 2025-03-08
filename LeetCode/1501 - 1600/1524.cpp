// 1524. Number of Sub-arrays With Odd Sum


// Solution 1: Prefix Sum and Counting
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
    public:
        int mod = 1e9 + 7;
        int numOfSubarrays(vector<int>& arr) {
            int n = arr.size(), even = 1, odd = 0, prefix = 0;
            long res = 0;
            for(int i = 0; i < n;i++){
                prefix += arr[i];
                if(prefix%2){
                    odd++;
                    res = (res + even)% mod;
                }
                else{
                    even++;
                    res = (res + odd)% mod;
                }
            }
            return res;
        }
};