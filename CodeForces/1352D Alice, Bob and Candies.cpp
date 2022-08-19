#include<iostream>
using namespace std;

void solve()
{
    int n,a = 0,b = 0,preva, prevb = 0, result = 0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n;i++) cin >> arr[i];
    int l = 0, r = n-1;
    while(l <= r){
        int temp = 0;
        while(temp <= prevb && l <= r){
            temp += arr[l];
            a +=  arr[l];
            l++;
        }
        result++;
        preva = temp;
        if(l > r) break;
        temp = 0;
        while(temp <= preva && l <= r){
            temp += arr[r];
            b += arr[r];
            r--;
        }
        result++;
        prevb = temp;
    }
    cout<<result<<" "<<a<<" "<<b<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
