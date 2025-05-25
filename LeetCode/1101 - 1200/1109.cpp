// 1109. Corporate Flight Bookings

// Solution 1 using Prefix Sum and Difference Array
// Time Complexity: O(n + m) where n is the number of flights and m is the number of bookings
// Space Complexity: O(n) for the result array
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n), prefix(n+1);
        for(auto& booking: bookings){
            prefix[booking[0]-1] += booking[2];
            prefix[booking[1]] -= booking[2];
        }
        int curr = 0;
        for(int i = 0; i < n;i++){
            curr += prefix[i];
            res[i] = curr;
        }
        return res;
    }
};