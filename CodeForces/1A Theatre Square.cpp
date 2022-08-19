#include<iostream>
using namespace std;

void solve()
{
    int n,m,a;
    cin >> n >> m >> a;
    long long int result = (n/a + (n%a != 0));
    result *= (m/a + (m%a != 0));
    cout<<result<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}
