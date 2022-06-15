#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t,X,b,c;
    cin >> t;
    while(t--){
        long long int result = 0;
        cin >> X >> b;
        long long int x[b], y[b];
        for(int i = 0; i < b;i++){
            cin >> x[i] >> y[i];
        }
        cin >> c;
        if(c){
            long long int p[c], q[c], r[c];
            for(int i = 0; i < c; i++){
                cin >> p[i] >> q[i] >> r[i];
            }
            int p1 = b -1, p2 = c -1;
            bool flag = false;
            X = max(p[p2],x[p1]);
            while(p1 >= 0 || p2 >= 0){
                if(p2 >= 0 && X == p[p2]){
                    if(result >= q[p2] && result < (q[p2] + r[p2])){
                        result = q[p2];
                        flag = true;
                    }
                    else if(result >= (q[p2] + r[p2])){
                        result -= r[p2];
                    }
                    p2--;
                }
                if(p1 >= 0 && X == x[p1]){
                    result += y[p1];
                    p1--;
                }
                if(p1 >= 0 && p2 >= 0) X = max(p[p2],x[p1]);
                else if(p2 < 0 && p1 >= 0) X = x[p1];
                else if(p1 < 0 && p2 >= 0) X = p[p2];
            }
            if(!flag) result += 1;
        }
        else{
            for(int i = 0; i < b;i++){
                result += y[i];
            }
            result += 1;
        }
        cout<<result<<"\n";
    }
	return 0;
}
