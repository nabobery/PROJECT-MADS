// Project Euler #6: Sum square difference

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
        // n*(n+1)*(3n+2)*(n-1)/12
        long long int ans = n;
        ans *= n+1;
        ans *= (3*n + 2);
        ans *= (n-1);
        ans /= 12;
        cout<<ans<<"\n";
    }
    return 0;
}
