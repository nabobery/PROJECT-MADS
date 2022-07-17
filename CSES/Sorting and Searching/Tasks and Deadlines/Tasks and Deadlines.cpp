#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct task{
    int duration, deadline;
};

bool customCompare(task t1, task t2){
    return t1.duration < t2.duration;
}

void solve(){
    int n;
    cin >> n;
    long long int result = 0;
    vector<task> tasks(n);
    for(int i = 0; i < n;i++){
        cin >> tasks[i].duration >> tasks[i].deadline;
    }
    sort(tasks.begin(), tasks.end(), customCompare);
    long long int start = 0;
    for(int i = 0; i < n;i++){
        result += (tasks[i].deadline - tasks[i].duration - start);
        start += tasks[i].duration;
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}



