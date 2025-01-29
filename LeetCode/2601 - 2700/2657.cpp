// 2657. Find the Prefix Common Array of Two Arrays

// Solution 1 using Unordered Sets
// Time Complexity: O(n^2)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), cnt;
        vector<int> res(n);
        unordered_set<int> s1, s2;
        for(int i = 0; i < n;i++){
            s1.insert(A[i]);
            s2.insert(B[i]);
            cnt = 0;
            for(auto it : s1)
                if(s2.count(it)) cnt++;
            res[i] = cnt;
        }
        return res;
    }
};

// Solution 2 using Boolean Array
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> res(n);
        vector<bool> s1(n+1, false), s2(n+1, false); 
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            s1[A[i]] = true;
            s2[B[i]] = true;
            if (s1[A[i]] && s2[A[i]]) {
                cnt++;
                s1[A[i]] = false; 
                s2[A[i]] = false;
            }
            if (s1[B[i]] && s2[B[i]]) {
                cnt++;
                s1[B[i]] = false;
                s2[B[i]] = false;
            }
            res[i] = cnt;
        }

        return res;
    }
};