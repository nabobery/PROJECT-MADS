// 995. Minimum Number of K Consecutive Bit Flips

// Greedy and Naive Solution 1 (TLE)
// Time complexity: O(n*k)
// Space complexity: O(1)
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        for(int i = 0; i < n;i++){
            if(nums[i]) continue;
            else{
                if(i+k > n) return -1;
                for(int j = i; j < i+k;j++) nums[j] = 1 - nums[j];
                res++;
            }
        }
        return res;
    }
};

// Greedy Solution 2 using Bit Manipulation and prefix xor 
// Time complexity: O(n)
// Space complexity: O(n)
// The basic idea is to keep track if a flip should be done at the current index or not using flip which tells if the current index will be flipped to one or not
// diff is used to keep track whether the flip ends at the current index or not which is used to update the flip value
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        vector<int> diff(n+1);
        int flip = 0;
        for(int i = 0; i < n;i++){
            flip ^= diff[i];
            if(nums[i] == flip){
                if(i+k > n) return -1;
                res++;
                flip ^= 1;
                diff[i+k] ^= 1;
            }
        }
        return res;
    }
};

// Greedy Solution 3 using Bit Manipulation and deque
// Time Complexity: O(n)
// Space Complexity: O(k)
// The basic idea is to keep track of the indices where the flip is needed using a deque

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        deque<int> dq;
        for(int i = 0; i < n;i++){
            // If the front of the deque is equal to i-k then pop the front because the flip is done at that index
            if(!dq.empty() && dq.front() + k == i) dq.pop_front();
            // If the size of the deque is even and the current number is 0 then we need to flip
            // If the size of the deque is odd and the current number is 1 then we need to flip
            if(dq.size() % 2 == nums[i]){
                if(i+k > n) return -1;
                res++;
                dq.push_back(i);
            }
        }
        return res;
    }
};

// Greedy Solution 4 using Bit Manipulation
// Time Complexity: O(n)
// Space Complexity: O(1)
// The basic idea is to keep track of the number of flips done at the current index using a variable flip
// If the flip is odd then the current number is flipped
// If the flip is even then the current number is not flipped
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        int flip = 0;
        for(int i = 0; i < n;i++){
            // if we're out of the window and the number is 2 then decrement the flip
            if(i >= k && nums[i - k] == 2) flip--;
            if((flip%2) == nums[i]){
                if(i+k > n) return -1;
                res++;
                flip++;
                // mark the number as 2 to keep track of the number of flips done at the current index
                nums[i] = 2;
            }
        }
        return res;
    }
};