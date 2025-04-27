// 2179. Count Good Triplets in an Array

// Solution 1: Using Binary Index Tree (Fenwick Tree)
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
    public:

        // Binary Indexed Tree (Fenwick Tree) implementation
        // Used to store prefix sums and perform range queries
        class BIT {
            vector<int> bit;
            int n;
        public:
            // Constructor to initialize the BIT with size n
            // BIT(size) initializes a BIT of size n with all values set to 0
            BIT(int size) : n(size), bit(size + 1, 0) {}
            // Update the BIT with value val at index i
            void update(int i, int val) {
                // 1 indexed BIT
                // add val to the index i and all its parents
                // i & -i gives the LSB of i
                for (++i; i <= n; i += i & -i)
                    bit[i] += val;
            }
            // Query the sum of elements from 0 to i
            int query(int i) {
                int res = 0;
                // 1 indedxed BIT
                // subtract LSB of i from i to get the parent index
                // i & -i gives the LSB of i
                for (++i; i > 0; i -= i & -i)
                    res += bit[i];
                return res;
            }
            // Query the sum of elements from l to r
            int rangeQuery(int l, int r) {
                return query(r) - query(l - 1);
            }
        };
    
        long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
            int n = nums1.size();
            vector<int> pos(n);
            // Storing the position of each element in nums2
            // pos[i] = index of nums2[i] in nums2
            // nums2[i] -> i
            for (int i = 0; i < n; ++i)
                pos[nums2[i]] = i;
            
            // Mapping nums1 elements to their positions in nums2
            // mappedNums[i] = index of nums1[i] in nums2
            // pos1 -> pos2
            vector<int> mappedNums(n);
            for (int i = 0; i < n; ++i)
                mappedNums[i] = pos[nums1[i]];

            // 2 BITs to store the left and right counts
            BIT bitLeft(n), bitRight(n);
            
            // leftCount[i] = number of elements in nums1 that are present in nums2 before nums2[i]
            // rightCount[i] = number of elements in nums1 that are present in nums2 after nums2[i]
            vector<int> leftCount(n), rightCount(n);
            
            // Count the number of elements in nums1 that are present in nums2 before nums2[i]
            for (int i = 0; i < n; ++i) {
                leftCount[i] = bitLeft.query(mappedNums[i] - 1);
                bitLeft.update(mappedNums[i], 1);
            }
            
            // Count the number of elements in nums1 that are present in nums2 after nums2[i]
            for (int i = n - 1; i >= 0; --i) {
                rightCount[i] = bitRight.query(n - 1) - bitRight.query(mappedNums[i]);
                bitRight.update(mappedNums[i], 1);
            }
    
            long long res = 0;
            for (int i = 0; i < n; ++i)
                res += (long long)leftCount[i] * rightCount[i];
    
            return res;
        }
    };

// Solution 2: Using PBDS (Policy Based Data Structure)
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

class Solution {
    public:
        long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
            int n = nums1.size();
            vector<int> pos(n);
            
            // Store the the postion of each element in nums1
            // nums1[i] -> i
            for (int i = 0; i < n; ++i)
                pos[nums1[i]] = i;
            
            // Store the index of elements in nums1 that are present in nums2 until now
            ordered_set os;

            long long res = 0;

            for(int i = 0; i < n;i++){
                int pos1 = pos[nums2[i]];
                // Count the number of elements in os that are less than pos1
                // This gives the number of elements in nums1 that are present in nums2 until now (left of nums2[i])
                long long leftCount = os.order_of_key(pos1);
                // Count the number of elements in os that are greater than pos1
                // This gives the number of elements in nums1 that are present in nums2 after nums2[i] (right of nums2[i])
                // n-1-pos1 gives the number of elements in nums1 that are present after pos1
                // os.size() gives the number of elements in nums1 that are present in nums2 until now (left of nums2[i])
                // So, (n-1-pos1) - (os.size() - os.order_of_key(pos1)) gives the number of elements in nums1 that are present after pos1 and are present in nums2 after nums2[i]
                long long rightCount = (n - 1 - pos1) - (os.size() - os.order_of_key(pos1));
                // Update the result with the product of leftCount and rightCount
                res += leftCount * rightCount;

                // Insert the current element in os
                os.insert(pos1);
            }
            return res;
        }
};
