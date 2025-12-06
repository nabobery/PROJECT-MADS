// 2141. Maximum Running Time of N Computers

// Solution 1: Binary Search
// Time Complexity: O(N log(sum(batteries)))
// Space Complexity: O(1)
class Solution {
public:
    bool check(long long mid, vector<int>& batteries, int n){
        long long s = 0;
        for(auto& battery: batteries) s += min((long long)battery, mid);
        return s >= n*mid; 
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long res, low = 1, high = accumulate(batteries.begin(), batteries.end(), 0LL) / n, mid;
        while (low <= high) {
            mid = (low + high)/2;
            if(check(mid, batteries, n)){
                low = mid+1;
                res = mid;
            }
            else high = mid-1;
        }
        return res;
    }
};