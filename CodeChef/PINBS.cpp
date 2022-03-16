#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	string s;
	for(int i = 0; i < t;i++){
	    cin >> s;
	    bool flag = false;
	    for(int j = 0; j < s.size() - 1;j++){
	        if((s[j] == '1' && s[j+1] == '1') || (s[j] == '1' && s[j+1] == '0')){
	            cout<<"YES\n";
	            flag = true;
	            break;
	        }
	    }
	    if(!flag || s.size() == 1){
	        cout<<"NO\n";
	    }
	}
	return 0;
}
