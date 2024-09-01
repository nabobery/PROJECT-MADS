// 1653. Minimum Deletions to Make String Balanced

// Solution 1: Using Prefix and Suffix Sum
// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> prefix(n+1, 0), suffix(n+1, 0);
        // prefix[i] = number of 'b' in s[0..i-1]
        for(int i = 0; i < n;i++){
            prefix[i+1] += prefix[i];
            if(s[i] == 'b') prefix[i+1]++; 
        }
        // suffix[i] = number of 'a' in s[i..n-1]
        for(int i = n-1; i >= 0; i--){
            suffix[i] += suffix[i+1];
            if(s[i] == 'a') suffix[i]++;
        }
        int res = n+1;
        // for each i, we need to find the minimum number of deletions to make s[0..n-1] balanced
        // so that we can get the minimum number of deletions to have all a's on the left and all b's on the right
        for(int i = 0; i < n;i++)
            // if splitting at i, we need to delete prefix[i] 'b' and suffix[i] 'a'
            res = min(res, prefix[i] + suffix[i+1]);
        return res;
    }
};

// Solution 2: Using Optimized Prefix and Suffix Sum
// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(), prefix = 0, suffix = 0;
        for(int i = 0; i < n;i++)
            if(s[i] == 'a') suffix++;
        int res = n+1;
        for(int i = 0; i < n;i++){
            if(s[i] == 'a') suffix--;
            res = min(res, prefix + suffix);
            if(s[i] == 'b') prefix++;
        }
        return res;
    }
};