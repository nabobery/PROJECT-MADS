#include <iostream>
#include <algorithm>
using namespace std;

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    string a,b, result = "";
    cin >> a >> b;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int i = 0, j = 0,count1 = 0,count2 = 0;
    while (i < n && j < m){
        if(a[i] < b[j]){
            count2 = 0;
            if(count1 < k){
                result += a[i];
                count1++;
                i++;
            }
            else if(count1 >= k){
                count1 = 0;
                result += b[j];
                count2 = 1;
                j++;
            }
        }
        else if(a[i] > b[j]){
            count1 = 0;
            if(count2 < k){
                result += b[j];
                count2++;
                j++;
            }
            else if(count2 >= k){
                count2 = 0;
                result += a[i];
                count1 = 1;
                i++;
            }
        }
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


