// 2064. Minimized Maximum of Products Distributed to Any Store

// Solution 1: Greedy an Binary Search
// Time complexity: O(nlogn)
// Space complexity: O(1)
class Solution {
public:
    // helper function to check if mid as maximum products(store) is possible
    // We can distribute products to stores in such a way that each store gets at most k products
    // returns true if it is possible to distribute products to stores in such a way that each store gets at most k products
    bool helper(int n, int k, vector<int>& quantities){
        int stores = 0;
        for(auto i : quantities) stores += (i+k-1)/k;
        return stores <= n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        // to binary search on the minimum value of maximum products(store)
        // low = 1, high = max(quantities)
        int l = 1, h = *std::max_element(quantities.begin(), quantities.end());
        int res = h;
        while(l <= h){
            int mid = (l+h)/2;
            // check if mid as maximum products(store) is possible
            if(helper(n, mid, quantities)){
                res = mid;
                h = mid-1;
            }
            else
                l = mid+1;
        }
        return res;
    }
};