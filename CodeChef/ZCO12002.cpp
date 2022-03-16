#include <bits/stdc++.h>
using namespace std;

int main() {
	int n , x, y;
	cin >> n >> x >> y;
	int contests [n][2];
	vector<int> V(x), W(y);
	for(int i = 0; i < n;i++)
	    cin >> contests[i][0] >> contests[i][1];
	for(int i = 0; i < x;i++)
	    cin >> V[i];
	for(int i = 0; i < y;i++)
	    cin >> W[i];
	sort(V.begin(),V.end());
	sort(W.begin(),W.end());
	int result = 1000000;
	for(int i = 0; i < n;i++){
	    vector<int>::iterator start = upper_bound(V.begin(),V.end(), contests[i][0]);
	    vector<int>::iterator end = lower_bound(W.begin(),W.end(), contests[i][1]);
	    if(start != V.begin() && end != W.end()){
	        result = min(result, (W[end-W.begin()] - V[start - V.begin() -1] + 1));
	    }
	    
	}
	cout<<result<<"\n";
	return 0;
}
