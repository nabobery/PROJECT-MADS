// 1052. Grumpy Bookstore Owner

// Solution 1 using Sliding Window
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size(), res = 0, curr = 0;
        for(int i = 0; i < n;i++)
            curr += (!grumpy[i]  ? customers[i] : 0);
        for(int i = 0; i < minutes;i++) curr += (grumpy[i]  ? customers[i] : 0);
        res = curr;
        for(int i = minutes; i < n;i++){
            curr -= (grumpy[i-minutes]  ? customers[i-minutes] : 0);
            curr += (grumpy[i]  ? customers[i] : 0);
            res = max(res, curr);
        }
        return res;
    }
};

// Cleaner version of Solution 1 
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size(), res = 0, curr = 0;
        for(int i = 0; i < n;i++){
            curr += (!grumpy[i]  ? customers[i] : 0);
            if(i < minutes) curr += (grumpy[i]  ? customers[i] : 0);
        }
        res = curr;
        for(int i = minutes; i < n;i++){
            curr -= (grumpy[i-minutes]  ? customers[i-minutes] : 0);
            curr += (grumpy[i]  ? customers[i] : 0);
            res = max(res, curr);
        }
        return res;
    }
};