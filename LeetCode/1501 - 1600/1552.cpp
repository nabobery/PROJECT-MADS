// 1552. Magnetic Force Between Two Balls

// Solution 1 using Binary Search 
// Time complexity: O(nlogn)
// Space complexity: O(1)
class Solution {
public:
    bool check(vector<int>& position, int m, int mid) {
        int count = 1, last = position[0];
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - last >= mid) {
                count++;
                last = position[i];
            }
        }
        return count >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        int l = 0, r = 1e9;
        sort(position.begin(), position.end());
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(position,m, mid)) 
                l = mid + 1;
            else 
                r = mid - 1;
        }
        return r;
    }
};

// Cleaner version of the above code without using an additional function
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int l = 0, r = position[n - 1] - position[0];
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int count = 1, last = position[0];
            for (int i = 1; i < n; i++) {
                if (position[i] - last >= mid) {
                    count++;
                    last = position[i];
                }
            }
            if (count >= m) 
                l = mid + 1;
            else 
                r = mid - 1;
        }
        return r;
    }
};
