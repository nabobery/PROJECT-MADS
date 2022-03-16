// 189. Rotate Array
// my naive solution O(n) time and O(n) space solution
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if(k == 0) return;
        vector <int> temp = nums;
        for(int i = 0; i < n;i++){
            nums[(i+k)%n] = temp[i];
        }
    }
};

// using array reversal O(n) time and O(1) space solution
/* Example : [1,2,3,4,5] k = 2
 * first we reverse the array  [5,4,3,2,1]
 * then reverse the two sub arrays based on k % n [4,5] and [1,2,3]
 * which gives [4,5,1,2,3]
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(), nums.begin() + k%n);
        reverse(nums.begin() + k%n, nums.end());
    }
};

// O(n) time and O(1) space solution using swap
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(), start = 0;
        for (; k %= n; n -= k, start += k) {
            for (int i = 0; i < k; i++) {
                swap(nums[start + i], nums[start + n - k + i]);
            }
        }
    }
};

// O(n) time and O(1) space solution  is on the idea of placing each element in its original position while keeping track of the element originally in that position.


