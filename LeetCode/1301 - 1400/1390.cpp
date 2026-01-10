// 1390. Four Divisors

// Solution 1: Precompute primes using Sieve of Eratosthenes and check each number for exactly four divisors
// There are two cases where a number has exactly four divisors:
// 1. It is the product of two distinct primes (p * q), which gives divisors: 1, p, q, pq
// 2. It is the cube of a prime (p^3), which gives divisors: 1, p, p^2, p^3
// Time Complexity: O(N * sqrt(M)) where N is the number of elements in nums and M is the maximum number in nums
// Space Complexity: O(M) for storing primes
class Solution {
public:
    set<int> primes;
    void preComputePrimes(int N){
        vector<bool> isPrime(N + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= N; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= N; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        for(int i = 2; i < N;i++){
            if(isPrime[i]) primes.insert(i);
        }
    }
    int sumOf4Divisors(int num){
        for(auto& p: primes){
            if(num% p == 0){
                long q = num/p;
                if((primes.count(q) && p != q) || (q == 1LL *p*p)) return (p+q+1+num);
                else return -1;
            }
        }
        return -1;
    }
    int sumFourDivisors(vector<int>& nums) {
        preComputePrimes(1e5);
        int res= 0;
        for(int& num: nums){
            int curr = sumOf4Divisors(num);
            if(curr != -1) res += curr;
        }
        return res;
    }
};

// Solution 2: Directly count divisors for each number
// Time Complexity: O(N * sqrt(M)) where N is the number of elements in nums and M is the maximum number in nums
// Space Complexity: O(1)
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            int sum = 0, count = 0;
            for (int i = 1; i * i <= num; ++i) {
                if (num % i == 0) {
                    if (i * i == num) {
                        count++;
                        sum += i;
                    } else {
                        count += 2;
                        sum += (i + num / i);
                    }
                    if (count > 4)
                        break;
                }
            }
            if (count == 4) {
                totalSum += sum;
            }
        }
        return totalSum;
    }
};