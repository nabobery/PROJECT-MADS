#include <iostream>
#include <string>
using namespace  std;

void solve(){
    string x, result;
    cin >> x;
    int temp, ind;
    bool flag = false;
    for(int i = 0; i < x.size() - 1;i++){
        temp = x[i] - '0' + x[i+1] - '0';
        if(temp >= 10){
            flag = true;
            ind = i;
        }
    }
    if(!flag){
        temp = x[0] - '0' + x[1] - '0';
        result = to_string(temp);
        result += x.substr(2);
    }
    else{
        temp = x[ind] - '0' + x[ind + 1] - '0';
        result =  x.substr(0,ind);
        result += to_string(temp);
        result += x.substr(ind + 2);
    }
    cout<<result<<"\n";
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
