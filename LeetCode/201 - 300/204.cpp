// 204. Count Primes

// Solution using Sieve of Eratosthenes
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        vector<bool> marked(n, false);
        marked[0] = true;
        int result = 0;
        for(int i = 2; i < n;i++){
            if(!marked[i-1]){
                result++;
                for(int j = 2*i;j <= n;j += i){
                    marked[j-1] = true;
                }
            }
        }
        return result;
        
    }
};