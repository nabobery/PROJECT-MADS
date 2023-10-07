// Project Euler #3: Largest prime factor

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
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        ll i = 2, p = -1;
        while(i*i <= n){
            while(n%i == 0){
                n = n/i;
                p = i;
            }
            i++;
        }
        if(n > 1) p = n;
        cout<<p<<"\n";
    
    }
    return 0;
}
