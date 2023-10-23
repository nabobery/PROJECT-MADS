// Project Euler #10: Summation of primes

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool isPrime(int n){
    if(n == 1) return false;
    if(n <= 3) return true;
    if(n%2 == 0 || n %3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}


int main(){
    int t;
    cin >> t;
    vector<int> primes;
    for(int i = 2; i <= 1e6;i++){
        if(isPrime(i)){
            primes.push_back(i);
        }
    }
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        auto it = upper_bound(primes.begin(), primes.end(), n);
        cout<<accumulate(primes.begin(), it, 0LL)<<"\n";
        // long long int sum = 0;
        // for(auto i : primes){
        //     if(i > n) break;
        //     sum += i;
        // }
        // cout<<sum<<"\n";
    }
    return 0;
}
