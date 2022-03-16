#include <iostream>
using namespace std;

int main() {
	int t, x,p1,p2;
	string result;
	cin >> t;
	for(int i = 0; i < t;i++){
	    cin >> x >> result;
	    p1 = 0, p2 = 0;
	    for(int j = 0; j < 14;j++){
	        if(result[j] == 'C') p1 += 2;
	        else if (result[j] == 'N') p2 += 2;
	        else{
	            p1++;
	            p2++;
	        }
	    }
	    if(p1 > p2) cout<<60*x<<"\n";
	    else if(p1 == p2) cout<<55*x<<"\n";
	    else cout<<40*x<<"\n";
	}
	return 0;
}
