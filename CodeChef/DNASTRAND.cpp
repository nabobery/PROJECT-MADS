#include <iostream>

using namespace std;

int main() {
    int t,n;
    string s;
    cin >> t;
    while(t--){
        cin >> n >> s;
        for(int i = 0; i < n;i++){
            if(s[i] == 'T') s[i] = 'A';
            else if(s[i] == 'A') s[i] = 'T';
            else if(s[i] == 'C') s[i] = 'G';
            else s[i] = 'C';
        }
        cout<<s<<"\n";
    }
	return 0;
}
