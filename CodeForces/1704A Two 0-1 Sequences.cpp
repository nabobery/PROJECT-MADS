#include <iostream>
using namespace std;

void solve()
{
    int n, m;
    string s1, s2;
    cin >> n >> m >> s1 >> s2;
    if (n == m)
    {
        if (s1 == s2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else
    {
        bool flag = true;
        int i = n - 1, j;
        for (j = m - 1; j > 0; j--)
        {
            if (s1[i] != s2[j]) {
                flag = false;
                break;
            }
            i--;
        }
        if (!flag)
            cout << "NO\n";
        else
        {
            char ch = s2[0];
            i = n-m;
            while (i >= 0)
            {
                if (ch == s1[i])
                {
                    flag = false;
                    break;
                }
                i--;
            }
            if (!flag)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
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



