#include <iostream>
#include <algorithm>
using namespace std;

void solve(){
    string s;
    cin >> s;
    int result = 1000, flips, n = s.size(), zeroes = 0, ones;
    for(int i = 0; i < n;i++){
        if(s[i] == '0') zeroes++;
    }
    ones = n - zeroes;
    int currzeroes = 0, currones = 0;
    // 0....01.....1
    // flips is sum of ones left of the index and zeroes in the right of the index(number of flips to make such that the string is in the given form), we need to find the min.
    /* Example: 100101 000111 flips = 2
     * i = 0 011111 flips = 4
     * i = 1 001111 flips = 3
     * i = 2 000111 flips = 2
     * i = 3 000011 flips = 3
     * i = 4 000001 flips = 2
     * i = 5 000000 flips = 3
     */
    // flips = ones till now + (zeroes - (zeroes covered till now))
    // 1.....10.....0
    // flips = zeroes till now + (ones - (ones covered till now))
    for(int i = 0; i < n;i++){
        if(s[i] == '1') currones++;
        else currzeroes++;
        flips = currones + (zeroes - (i + 1 - currones));
        result = min(flips,result);
        flips = currzeroes + (ones - (i+1 - currzeroes));
        result = min(flips,result);
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
