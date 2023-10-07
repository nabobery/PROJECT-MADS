// Project Euler #2: Even Fibonacci numbers

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

#define ll long long int


int main(){
    int t;
    cin >> t;
    ll limit = 4*1e16;
    vector<ll> fibs;
    ll f_0 = 1, f_1 = 2;
    fibs.push_back(f_1);
    while(f_1 < limit){
        ll temp = f_1;
        f_1 += f_0;
        if(f_1%2 == 0) 
            fibs.push_back(f_1);
        f_0 = temp;
    }
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        ll s = 0;
        for(auto i : fibs){
            if(i >= n) break;
            s += i;
        }
        cout<<s<<"\n";
    }
    return 0;
}
