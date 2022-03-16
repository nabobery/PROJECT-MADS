#include <iostream>
#include <queue>
using namespace std;

int main() {
	int t, z, n, temp;
	cin >> t;
	for(int i = 0; i < t;i++){
	    cin >> n >> z;
	    priority_queue<int> q;
	    for(int j = 0; j < n;j++){
	        cin >> temp;
	        q.push(temp);
	    } 
	    temp = z;
	    int result = 0;
	    while(!q.empty() && temp >= 0){
	        int curr = q.top();
	        q.pop();
	        temp -= curr;
	        result++;
	        curr /= 2;
	        if(curr > 0) q.push(curr);
	    }
	    if(q.empty() && temp > 0) cout<<"Evacuate\n";
	    else cout<<result<<"\n";
	}
	return 0;
}
