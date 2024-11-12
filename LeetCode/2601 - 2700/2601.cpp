// 2601. Prime Subtraction Operation

// Solution 1 by generating prime numbers and doing binary search
// Time complexity: O(nlogn)
// Space complexity: O(n)
// The idea is to pre compute all primes upto 100 using Sieve of Eratosthenes
// Then iterate over the array from right to left and check if the current element is less than the next element then continue
// Otherwise, find the upper bound of the difference between the current element and the next element in the primes array because we want a prime such that curr - prime < next
class Solution {
public:
    vector<int> primes;
    vector<int> generatePrimes(int n) {
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i < n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        return primes;
    }
    bool primeSubOperation(vector<int>& nums) {
        generatePrimes(1000);
        for (int i = nums.size()-2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) continue;
            auto it = upper_bound(primes.begin(), primes.end(), nums[i] - nums[i+1]);
            if(it == primes.end() || nums[i] <= *it) return false;
            nums[i] -= *it;
        }
        return true;
    }
};