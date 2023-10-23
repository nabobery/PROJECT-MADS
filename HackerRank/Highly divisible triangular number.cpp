// Project Euler #12: Highly divisible triangular number

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long int

// Returns count of divisors of n in O(sqrt(n))
int divCount(ll n) 
{ 
    int  cnt = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0) {
            // if i*i == n, then only one divisor
            if (n / i == i)
                cnt++;
            // Otherwise two divisors
            else 
                cnt = cnt + 2;
        }
    }
    return cnt; 
} 

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t, n, l = 1000, num = 0;
    // precompute the numbers having divisors from 1 to 1001
    vector<int> nums;
    nums.push_back(0);
    for(ll i = 1; nums.size() < l;i++){
        // num is the ith triangular number which is the sum of first i natural numbers
        num += i;
        int div = divCount(num);
        // fill gaps in the vector as we need only the first triangular number with more than n divisors
        while(nums.size() <= div)
            nums.push_back(num);
    }
    cin >> t;
    while(t--){
        cin >> n;
        cout<<nums[n+1]<<"\n";
    }   
    return 0;
}
