// 2037. Minimum Number of Moves to Seat Everyone

// Solution 1 using Greedy Approach by sorting the arrays
// Time Complexity: O(nlogn)
// Space Complexity: O(1)

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int res = 0, n = students.size();
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        for(int i = 0; i < n;i++) res += abs(seats[i] - students[i]);
        return res;
    }
};
