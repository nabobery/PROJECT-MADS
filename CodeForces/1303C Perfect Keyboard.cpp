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

int mod = 1e9 + 7;

bool visited[26];

void solve()
{
    string s;
    cin >> s;
    // to maintain what characters were visited
    memset(visited, false, sizeof(visited));
    visited[s[0] - 'a'] = true;
    // for maintaining current keyboard layout
    string layout = "";
    layout += s[0];
    // maintains the position of most recent character in the layout
    int pos = 0;
    for (int i = 1; i < s.size(); i++)
    {
        // if character already in layout
        if (visited[s[i] - 'a'])
        {
            // check if it's adjacent to prev char on both sides based on layout size and update pos
            if (pos > 0 && layout[pos - 1] == s[i])
                pos--;
            else if (pos < layout.size() - 1 && layout[pos + 1] == s[i])
                pos++;
            // if not then no layout is possible for the string
            else
            {
                cout << "NO\n";
                return;
            }
        }
        // if character not in layout
        else
        {
            // add it at the start if current position is 0
            if (pos == 0)
                layout = s[i] + layout;
            // add it to size if current position is layout size
            else if (pos == layout.size() - 1)
            {
                layout += s[i];
                pos++;
            }
            // if not possible to add anywhere means current layout not possible
            else
            {
                cout << "NO\n";
                return;
            }
        }
        // mark as visited
        visited[s[i] - 'a'] = true;
    }
    // for all character which were not there in string, just add them to the end of the current layout
    for (int i = 0; i < 26; i++)
    {
        if (!visited[i])
            layout += (i + 'a');
    }
    cout << "YES\n"
         << layout << "\n";
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