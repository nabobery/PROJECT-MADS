// 3479. Fruits Into Baskets III

// Solution 1: Naive Brute Force (TLE)
// Time Complexity: O(n^2)
// Space Complexity: O(n)
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int res = 0, n = fruits.size();
        vector<bool> used(n, false);

        for (int i = 0; i < n; i++) {
            bool placed = false;
            for (int j = 0; j < n; j++) {
                if (!used[j] && baskets[j] >= fruits[i]) {
                    used[j] = true;
                    placed = true;
                    break;
                }
            }
            if (!placed) res++;
        }

        return res;
    }
};

// Solution 2: Using Segment Tree for Efficient Range Queries
// Time Complexity: O(n log n)
// Space Complexity: O(n)
class Solution {
    vector<int> st;
    int n;
    
    void build(int node, int l, int r, vector<int>& A) {
        if (l == r) {
            st[node] = A[l];
        } else {
            int mid = (l + r) / 2;
            build(node * 2,     l,    mid, A);
            build(node * 2 + 1, mid+1, r,   A);
            st[node] = max(st[node * 2], st[node * 2 + 1]);
        }
    }
    
    int findFirst(int node, int l, int r, int x) {
        if (l == r) return l;
        int mid = (l + r) / 2;
        if (st[node * 2] >= x)
            return findFirst(node * 2,     l,    mid, x);
        else
            return findFirst(node * 2 + 1, mid+1, r,   x);
    }
    
    void update(int node, int l, int r, int pos, int newVal) {
        if (l == r) {
            st[node] = newVal;
        } else {
            int mid = (l + r) / 2;
            if (pos <= mid)
                update(node * 2,     l,    mid, pos, newVal);
            else
                update(node * 2 + 1, mid+1, r,   pos, newVal);
            st[node] = max(st[node * 2], st[node * 2 + 1]);
        }
    }
    
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        n = baskets.size();
        st.assign(4 * n, 0);
        build(1, 0, n - 1, baskets);
        
        int res = 0;
        for (int w : fruits) {
            if (st[1] < w) {
                res++;
            } else {
                int idx = findFirst(1, 0, n - 1, w);
                update(1, 0, n - 1, idx, INT_MIN);
            }
        }
        return res;
    }
};
