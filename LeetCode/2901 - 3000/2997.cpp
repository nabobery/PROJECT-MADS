// 2997. Minimum Number of Operations to Make Array XOR Equal to K

// Solution 1 using bitsets and Bit Manipulation
// Time complexity: O(nlogn)
// Space complexity: O(32)
// The idea is to count the number of set bits in the binary representation of the numbers in the array and add them up
// Then we compare the bits of the sum with the bits of k and see if xor of all of the bits is set or not and increment the result accordingly
class Solution {
public:
    int cnt[32] = {0};
    int minOperations(vector<int>& nums, int k) {
        bitset<32> b(0);
        for(int& num : nums){
            b  = bitset<32>(num);
            for(int i = 0; i < 32;i++)
                if(b[i]) cnt[i]++;
        }
        int res = 0;
        b = bitset<32>(k);
        for(int i = 0; i < 32;i++)
            if(cnt[i]%2 != b[i]) res++;
        return res;
    }
};

// Solution 2 without using bitsets
// Time complexity: O(nlogn)
// Space complexity: O(32)
class Solution {
public:
    int cnt[32] = {0};
    int minOperations(vector<int>& nums, int k) {
        for(int& num : nums)
            for(int i = 0; i < 32;i++)
                if(num & (1 << i)) cnt[i]++;
        int res = 0;
        for(int i = 0; i < 32;i++)
            if(cnt[i]%2 != ((k >> i) & 1)) res++;
        return res;
    }
};

// Solution 3 by just xor-ing all the numbers in the array and then counting the number of set bits in the xor of the numbers and k
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x = 0;
        for(int& num : nums) x ^= num;
        int res = 0;
        while(x || k){
            if((x & 1) != (k & 1)) res++;
            x >>= 1;
            k >>= 1;
        }
        return res;
    }
};

// using built-in function __builtin_popcount
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x = 0;
        for(int& num : nums) x ^= num;
        return __builtin_popcount(x^k);
    }
};