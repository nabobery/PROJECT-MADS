// 2523. Closest Prime Numbers in Range

// Solution 1: using Sieve of Eratosthenes and greedily checking adjacent primes
// Time complexity: O(nloglogn)
// Space complexity: O(n)
vector<int> primes;
class Solution {
public:
    void findPrimes(){
        int n = 1e6;
        vector<bool> prime(n + 1, true);
        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        for (int p = 2; p <= n; p++)
            if(prime[p]) primes.push_back(p);
    }
    vector<int> closestPrimes(int left, int right) {
        if(primes.empty()) findPrimes();
        vector<int> res(2, -1);
        int diff = INT_MAX;
        auto it = std::lower_bound(primes.begin(), primes.end(), left);
        int index = it - primes.begin(), prev = primes[index];  
        for(int i = index+1; i < primes.size();i++){
            if(primes[i] > right) break;
            if(primes[i] - prev < diff){
                diff = primes[i] - prev;
                res[0] = prev;
                res[1] = primes[i];
            }
            prev = primes[i];
        }
        return res;
    }
};