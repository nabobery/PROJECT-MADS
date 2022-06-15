#include <iostream>
#include <set>

using namespace std;

int main() {
    int t,n;
    string a, b;
    cin >> t;
    while(t--){
        cin >> n >> a >> b;
        set <char> s;
        for(int i = 0; i < n;i++){
            if(a[i] != b[i]){
                s.insert(b[i]);
            }
        }
        cout<<s.size()<<"\n";
    }
	return 0;
}
