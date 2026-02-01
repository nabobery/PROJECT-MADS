// 3315. Construct the Minimum Bitwise Array II

// Solution 1: Bit Manipulation using Bitset
// Time Complexity: O(N * log M)
// Space Complexity: O(M)
// where N is the size of the input array and M is the maximum possible value in the array
// so, we know that each prime number greater than 2 is odd and can be represented as (2*n + 1)
// thus, in binary representation, it will have trailing 1s
// so, we know that to get the minimum number x such that (x | (x + 1)) = prime and x and x + 1 differ only in the trailing block of 1s (because x + 1 flips all trailing 1s to 0s and the first 0 to 1)
// and as we need the minimum x, we can just turn off the highest bit in the trailing block of 1s in the binary representation of the prime number which will give us the required x
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for(int i = 0; i < n;i++){
            // if the prime is 2, return -1 because that's the only number that cannot be formed
            if(nums[i] == 2) res[i] = -1;
            // else if all other primes are odd are of the form 2*n + 1
            else{
                // Use bitset to manipulate bits
                // convert number to bitset
                bitset<32> b(nums[i]);
                int k = 0;
                // find the first 0 bit from the right to find highest bit set in trailing block of 1s in the right
                while(k < 32 && b[k] == 1) k++;
                // set that bit to 0
                b[k-1] = 0;
                // that's the minimum number that can be used  to form the given prime 
                // (x | (x +1)) = prime
                res[i] = (int)b.to_ulong();          
            }
        }
        return res;
    }
};

// Solution 2: Direct Mathematical Approach
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for(int i = 0; i < n;i++){
            int num = nums[i];
            if(num == 2) res[i] = -1;
            else{
                // we make use of the fact that x+1 flips all trailing 1s to 0s and the first 0 to 1
                // so to get x, we just need to turn off the highest bit in the trailing
                // to get that we can use the expression (num + 1) & -(num + 1) to get the lowest set bit in num + 1
                // then we right shift it by 1 to get the highest bit in the trailing block of x 
                int bitToRemove = ((num + 1) & -(num + 1)) >> 1;
                res[i] = num - bitToRemove;         
            }
        }
        return res;
    }
};