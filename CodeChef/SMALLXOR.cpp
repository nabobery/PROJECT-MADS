#include <iostream>
#include <queue>

using namespace std;

int main() {
    int t,n,x,y,ai;
    cin >> t;
    while(t--){
        cin >> n >> x >> y;
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i = 0; i < n;i++){
            cin >> ai;
            q.push(ai);
        }
        while(y > 0){
            int temp = q.top();
            q.pop();
            if((temp^x) <= q.top()){
                if(y%2) q.push(temp^x);
                else q.push(temp);
                break;
            }
            q.push(temp^x);
            y--;
        }
        while(!q.empty()){
            cout<<q.top()<<" ";
            q.pop();
        }
        cout<<"\n";
    }
	return 0;
}
