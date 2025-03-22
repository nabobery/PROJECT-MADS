// 2594. Minimum Time to Repair Cars

// Solution 1: Using Binary Search
// Time Complexity: O(nlog(r*cars^2))
// Space Complexity: O(1)
class Solution {
    public:
        bool check(vector<int>& ranks, int& cars, long long& time){
            long carsRepaired = 0;
            for(int& rank : ranks){
                carsRepaired += int(sqrt(time/rank));
                if(carsRepaired >= cars) return true;
            } 
            return false;
        }
        long long repairCars(vector<int>& ranks, int cars) {
            long long l = 1, r = pow(cars, 2), mid;
            r *= *max_element(ranks.begin(), ranks.end());
            while(l <= r){
                mid = (l+r) /2;
                if(check(ranks, cars, mid)) r = mid-1;
                else l = mid+1;
            }
            return l;
        }
};
    
    