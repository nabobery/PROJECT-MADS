#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t;
	string s;
	cin >> t;
	for(int i = 0; i < t;i++){
	    int result = 0;
	    cin >> s;
	    int n = s.size();
	    if(n < 3){
	        cout<<-1<<"\n";
	        continue;
	    }
	    char start = s[0], end = s[n-1];
	    int p = 1;
	    for(int j = 1; j < n - 1;j++){
	        if(s[j] != start && s[j] != end){
	            p = j;
	            while(s[j] != start && s[j] != end && j < n-1){
	                j++;
	            }
	            result = max(j-p,result);
	        }
	    }
	    if(result == 0) cout<<-1<<"\n";
	    else cout<<result<<"\n";
	}
	return 0;
}
