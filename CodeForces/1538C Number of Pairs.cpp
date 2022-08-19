#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    int n, l, r, x;
    cin >> n >> l >> r;
    int arr[n];
    long long int result = 0;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    for (int i = 0; i < n - 1; i++)
    {
        // all pairs with i such that sum <= r
        result += upper_bound(arr + i + 1, arr + n, r - arr[i]) - arr;
        // all pairs with i such that sum < l
        result -= lower_bound(arr + i + 1, arr + n, l - arr[i]) - arr;
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
