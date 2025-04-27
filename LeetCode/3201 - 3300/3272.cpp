// 3272. Find the Count of Good Integers

// Solution 1: Using Enumeration and Permutations and Combinations
// Time Complexity : O(nlogn * 10^m)
// Space Complexity : O(n*10^m)
// where n is the number of digits and m is the number of digits in 1st half of the number 
class Solution {
    public:
        long long countGoodIntegers(int n, int k) {
            long long res = 0;
            // precompute factorials
            vector<long long> fact(n+1, 1);
            // start is the starting number for first half of the number
            int start = pow(10, (n-1)/2);
            // isOdd = 1 if n is odd, 0 if n is even
            int isOdd = n & 1;
            // to store distinct good integers
            // first get all unique good integers of same count (as they can be rearranged)
            unordered_set<string> goodIntegers;
            for(int i = start; i < start*10;i++){
                // first half of the number
                string s = to_string(i);
                // if n is odd, we skip the last digit of the 1st half 
                // else we also take the last digit of the 1st half
                // so that we get digit of size n (n+1)/2 + (n-1)/2 digits
                s += string(s.rbegin() + isOdd, s.rend());
                long long num = stoll(s);
                // check if the number is good integer (divisible by k)
                if(num % k == 0){
                    // sort it to only consider unique good integers
                    sort(s.begin(), s.end());
                    goodIntegers.insert(s);
                }    
            }
            // calculate factorials
            for(int i = 2; i <= n;i++)
                fact[i] = fact[i-1] *i;
            // for each good integer, calculate the number of permutations and combinations
            // Number of good integers = (n-1)!/(n1! * n2! * n3! * ... * nk!) * (n - cnt[0])
            // where n is the number of digits, cnt[i] is the count of digit i in the good integer 
            for(string s : goodIntegers){
                vector<int> cnt(10 , 0);
                for(char &ch : s) cnt[ch - '0']++;
                long long curr = fact[n-1] * (n - cnt[0]);
                for(int& i : cnt) curr /= fact[i];
                res += curr;
            }
            return res;
        }
    };