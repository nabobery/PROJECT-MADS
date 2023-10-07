// Project Euler #5: Smallest multiple

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

int gcd(int a, int b)
{
    return a == 0 ? b : gcd(b % a, a);
}

int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

int main(){
    int t;
    cin >> t;
    int ans[41];
    ans[0] = 0;
    ans[1] = 1;
    for(int i = 2; i <= 40; i++){
        ans[i] = lcm(ans[i-1], i);
    }
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout<<ans[n]<<"\n";
    }
    return 0;
}
