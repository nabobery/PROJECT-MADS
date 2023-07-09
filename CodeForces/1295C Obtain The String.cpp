#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

void solve()
{
    string s, t;
    cin >> s >> t;
    vector<vector<int>> pos(26, vector<int>());
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        pos[s[i] - 'a'].push_back(i);
    }
    int curr = -1, result = 1;
    for (int i = 0; i < t.size(); i++)
    {
        if (pos[t[i] - 'a'].empty())
        {
            cout << "-1\n";
            return;
        }
        int temp = upper_bound(pos[t[i] - 'a'].begin(), pos[t[i] - 'a'].end(), curr) - pos[t[i] - 'a'].begin();
        if (temp != pos[t[i] - 'a'].size())
        {
            curr = pos[t[i] - 'a'][temp];
        }
        else
        {
            curr = -1;
            i--;
            result++;
        }
    }
    cout << result << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}