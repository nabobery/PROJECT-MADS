// 2528. Maximize the Minimum Powered City

// Solution 1 using Binary Search, Greedy and Line Sweep Algorithm
// Time Complexity: O(n log (maxP)), where n is the number of cities and maxP is the maximum initial power of any city
// Space Complexity: O(n)
class Solution {
public:
    int n;
    // function to check if it is possible to achieve at least mid power for each city
    bool isPossible(long long mid, vector<long long> prefix, int k, int r){
        long long curr = 0;
        for(int i = 0; i < n;i++){
            // accumulate the current power
            curr += prefix[i];
            // if current power is less than mid, we need to add more power
            if(curr < mid){
                long long diff =mid-curr;
                // if the required power exceeds the available power, return false
                if(diff > k) return false;
                // add the required power to the current city from the station at position i+r to maximize the effect
                // update the prefix array and current power and remaining power stations k
                prefix[i] += diff;
                curr += diff;
                prefix[min(i+2*r +1, n)] -= diff;
                k -= diff;
            }
        }
        return true;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        n = stations.size();
        vector<long long> prefix(n+1, 0);
        // line sweep to calculate the initial power of each city
        for(int i = 0; i < n;i++){
            prefix[max(i-r, 0)] += stations[i];
            prefix[min(i+r+1, n)] -= stations[i]; 
        }
        // binary search to find the maximum minimum power
        long long l = 0, h = 1e12, res, mid;
        while(l <= h){
            mid = (l+h)/2;
            // check if it is possible to achieve at least mid power for each city
            if(isPossible(mid, prefix, k, r)){
                // if possible, try for a higher minimum power
                l = mid+1;
                res = mid;
            }
            // if not possible, try for a lower minimum power
            else h = mid-1;
        }
        return res;
    }
};