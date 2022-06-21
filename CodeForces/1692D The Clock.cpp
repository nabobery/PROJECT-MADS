#include <iostream>
#include <set>
#include <string>
using namespace std;

string arr[16] = {"00:00", "01:10", "02:20", "03:30", "04:40", "05:50", "10:01", "11:11", "12:21", "13:31", "14:41", "15:51", "20:02", "21:12", "22:22", "23:32"};

string time(int h, int m){
    string hours,minutes;
    hours = to_string(h);
    minutes = to_string(m);
    if(h < 10) hours = '0' + hours;
    if(m < 10) minutes = '0' + minutes;
    return (hours + ":" + minutes);
}

bool check(string t){
    for(auto s : arr){
        if(t == s) return true;
    }
    return false;
}

void solve(){
    string s;
    int x;
    cin >> s >> x;
    int h = stoi(s.substr(0,2));
    int m = stoi(s.substr(3,2));
    int result = check(s);
    set<string> times;
    times.insert(s);
    while(true){
        int temp = (m + x);
        h += temp/60;
        m = temp%60;
        if(h >= 24) h -= 24;
        string t = time(h,m);
        if(times.count(t)) break;
        if(check(t)) result++;
        times.insert(t);
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




