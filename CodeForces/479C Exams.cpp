#include <iostream>
#include <algorithm>
using namespace std;

struct element{
    int a, b;
};

bool comparator(element p, element q){
    if(p.a != q.a) return (p.a < q.a);
    return (p.b < q.b);
}

void solve(){
    int n;
    cin >> n;
    element elements[n];
    for(int i = 0; i < n;i++) cin >> elements[i].a >> elements[i].b;
    sort(elements, elements + n, comparator);
    int result = min(elements[0].a, elements[0].b);
    for(int i = 1; i < n;i++){
        int t1 = min(elements[i].a, elements[i].b);
        int t2 = max(elements[i].a,elements[i].b);
        if(t1 > result) result = t1;
        else if(result > t1) result = t2;
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}




