#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int factorial(int n) {
    if(n == 0) return 1;
    int factorial = 1;
    for (int i = 2; i <= n; i++)
        factorial = factorial * i;
    return factorial;
}

int nCr(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

void solve(){
    string s1,s2;
    cin >> s1 >> s2;
    int count1 = 0,count2 = 0, n = s1.size(), unrecognized = 0;
    for(int i = 0; i < n;i++){
        if(s1[i] == '+') count1++;
        else count1--;
    }
    for(int i = 0; i < n;i++){
        if(s2[i] == '+') count2++;
        else if(s2[i] == '-') count2--;
        else unrecognized++;
    }
    bool flag = false;
    double result = 0;
    int temp = count1 - count2,counter = unrecognized;
    for(int i = unrecognized; i >= -unrecognized; i -= 2){
        if(temp == i){
            flag = true;
            break;
        }
        counter--;
    }
    if(flag){
        result = nCr(unrecognized,counter);
        result /= pow(2,unrecognized);
        cout << fixed << showpoint;
        cout<<setprecision(10)<<result<<"\n";
    }
    else{
        cout << fixed << showpoint;
        cout<<setprecision(10)<<result<<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}




