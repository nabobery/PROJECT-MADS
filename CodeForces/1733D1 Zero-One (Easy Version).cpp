#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast")

void solve(){
    int n,x,y;
    long long int counter = 0;
    cin >> n >> x >> y;
    string a,b,c = "";
    cin >> a >> b;
    // ci = ai xor bi
    for(int i = 0; i < n;i++){
        if(a[i] != b[i]){
            c += '1';
            counter++;
        }
        else c += '0';
    }
    // we need to make c of all zeroes with min cost
    // we can't get the string b using odd number of flips
    if(counter % 2) cout<<"-1\n";
    else{
        if(counter == 2){
            bool flag = false;
            for(int i = 1; i < n;i++)
                if(c[i] == '1' && c[i-1] == '1'){
                    flag = true;
                    break;
                }
            // if both 1's are adjacent, then we can just do the operation and use a dummy bit to do 2 flips which costs 2*y or we can use a single x operation
            if(flag){
                if(x > 2*y) cout<<2*y<<"\n";
                else cout<<x<<"\n";
            }
            else cout<<y<<"\n";
        }
            // we can just select ith and (i + d/2)th bit and flip As x >= y, counter/2*y is the min cost
        else{
            cout<<(counter/2)*y<<"\n";
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


