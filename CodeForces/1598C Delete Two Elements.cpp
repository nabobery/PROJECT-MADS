#include <iostream>
#include <map>
using namespace  std;

void solve(){
    int n,x;
    cin >> n;
    long long int sum = 0, result = 0;
    map<int,int> mp;
    for(int i = 0; i < n;i++){
        cin >> x;
        mp[x]++;
        sum += x;
    }
    if(!((sum % n == 0) || ((sum*2) % n == 0))) cout<<"0\n";
    else{
        double k = (double)sum/n;
        for(auto itr : mp){
            if(itr.first >= k) break;
            result += (long long int) itr.second * mp[(int)2*k - itr.first];
        }
        if(k - (int) k == 0){
            auto it = mp.find((int)k);
            if(it != mp.end()){
                result += ((long long int) it->second * (it->second-1))/2;
            }
        }
        cout<<result<<"\n";
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

