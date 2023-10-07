// Project Euler #8: Largest product in a series

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
        int k;
        cin >> n >> k;
        string num;
        cin >> num;
        multiset<char> vis;
        int ans = 0, curr = 1;
        for(int i = 0; i < k;i++){
            vis.insert(num[i]);
            curr *= (num[i] - '0');
        }
        ans = curr;
        for(int i = k; i < n;i++){
            vis.erase(vis.find(num[i-k]));
            vis.insert(num[i]);
            if(!vis.count('0')){
                curr = 1;
                for(auto it : vis) curr *= (it - '0');
                ans = max(curr, ans);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
