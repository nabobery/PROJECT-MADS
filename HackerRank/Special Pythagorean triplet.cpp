// Project Euler #9: Special Pythagorean triplet

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
        if(n%2) cout<<"-1\n";
        else{
            int result = -1;
            // c = x^2 + y^2
            // a = x^2 - y^2
            // b = 2xy
            // a+b+c = n = 2x^2 + 2xy
            // traverse for b 
            for (int i = 1; i <= n / 3; i++) {
                // calculate a
                // n-i = 2x^2
                // n-2*i = 2x^2 -2xy
                // n*(n-2*i) = 4x^2(x^2 - y^2)
                // a = 4x^2(x^2-y^2)/ 2*2x^2 = x^2 - y^2
                int j = (n*(n - 2*i))/(2*(n - i)); 
                int k = n - i - j;
                // check for a^2 + b^2 = c^2
                if (i * i + j * j == k * k) 
                {
                    int temp = i*j*k;
                    result = max(result, temp);
                }
            }
            cout<<result<<"\n";
        }
    }
    return 0;
}
