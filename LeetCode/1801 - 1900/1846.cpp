// 1846. Maximum Element After Decreasing and Rearranging

// Solution 1 Greedy Approach with Sorting
// Time Complexity O(nlogn)
// Space Complexity O(1)
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        int res = 1;
        for(int i = 1; i < arr.size();i++){
            if(abs(arr[i] - arr[i-1]) > 1) 
                arr[i] = arr[i-1]+1;
            res = max(res, arr[i]);
        }
        return res;
    }
};

// Solution 2 Greedy Approach without Sorting
// Time Complexity O(n)
// Space Complexity O(n)
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> count(n+1, 0);
        for(int i = 0; i < n; i++){
            count[min(arr[i], n)]++;
        }
        int miss = 0;
        for(int i = 1; i <= n; i++){
            if(count[i] == 0) miss++;
            else miss -= min(count[i]-1, miss);
        }
        return n-miss;  
    }  
};

// A cleaner version of Solution 2
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size(), res = 1;
        vector<int> count(n+1, 0);
        for(int i = 0; i < n; i++){
            count[min(arr[i], n)]++;
        }
        for(int i = 2; i <= n;i++){
            res = min(res+count[i], i);
        } 
        return res;
    }  
};