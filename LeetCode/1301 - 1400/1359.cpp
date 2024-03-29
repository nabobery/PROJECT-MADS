// 1359. Count All Valid Pickup and Delivery Options
// Using Probability O(N) time solution
// the number of total permutations of those pairs is (2*n)!
// the number of pairs possible would be (P1,D1), (P2,D2)...... there'll be n pairs
// We want Pi always before Di, so we can fix Pi and Di will be always after Pi
// the probability of Pi being before Di is 1/2
// so the probability of Pi being before Di for all n pairs is 1/2^n
// probability is 1/2^n, probability = |favourable outcomes|/|total outcomes|
// number of favourable outcomes = (2*n)!/(2^n)
class Solution {
public:
    int countOrders(int n) {
        if(n == 1) return 1;
        long long int mod = 1000000007;
        long long int result = 1;
        for(int i = 1; i <= 2*n;i++){
            result *= i;
            if(i % 2 == 0)
                result /= 2;
            result %= mod;
        }
        return (int) (result % mod);
    }
};


// Different way of calculating the (2*n)!/(2^n)
class Solution {
public:
    int countOrders(int n) {
        int mod = 1000000007;
        long long int result = 1;
        for(int i = 1; i <= n;i++){
            result *= i;
            result *= (2*i - 1);
            result %= mod;
        }
        return result;
    }
};
