#include <iostream>
#include <vector>
using namespace  std;

void solve(){
    int n, q,x;
    cin >> n >> q;
    long long int sum = 0;
    vector<int> vec, last(n,-1);
    for(int i = 0; i < n;i++){
        cin >> x;
        vec.push_back(x);
        sum += x;
    }
    int t, k, last_2 = -1, val, temp;
    for(int i = 0; i < q;i++){
        cin >> t;
        if(t == 1){
            cin >> k >> x;
            if(last_2 > last[k-1]) temp = val;
            else temp = vec[k-1];
            sum -= temp;
            vec[k-1] = x;
            last[k-1] = i;
            sum += vec[k-1];
        }
        else if(t == 2){
            last_2 = i;
            cin >> x;
            val = x;
            sum = x;
            sum *= n;
        }
        cout<<sum<<"\n";
    }

}

int main() {
    solve();
    return 0;
}


