// Project Euler #1: Multiples of 3 and 5

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


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        long long int s = 0;
        int n_3 = (n-1)/3, n_5 = (n-1)/5, n_15 = (n-1)/15;
        long long int temp = 3*n_3;
        temp *= (n_3 + 1);
        temp /= 2;
        s += temp;
        temp = 5*n_5;
        temp *= (n_5 + 1);
        temp /= 2;
        s += temp;
        temp = 15*n_15;
        temp *= (n_15 + 1);
        temp /= 2;
        s -= temp;
        cout<<s<<"\n";
    }
    return 0;
}
