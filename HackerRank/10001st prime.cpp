// Project Euler #7: 10001st prime
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
    for(int i = 2; i < 2*1e5;i++){
        if(isPrime(i)) primes.push_back(i);
    }
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout<<primes[n-1]<<"\n";
    }
    return 0;
}

