#include <iostream>
using namespace std;

int reset(int n){
    if(n < 3){
        return 1;
    }
    int curr = 2;
    int count = 1;
    while(curr != 1){
        curr = (curr*2) % (n-1);
        count++;
    }
    return count;
}

int transform(int k, int n){
    if(n < 3){
        return 1;
    }
    int result = 1;
    for(int j =0; j < k;++j){
        result = (result*2)%(n-1);
    }
    return result;
}

int main() {
	int t, n,k,r;
	cin >> t;
	long long int temp;
	for(int i = 0; i < t;i++){
	    cin >> n >> k;
	    r = reset(n);
	    k = transform(k % r, n);
	    cout << 1 << " ";
	    for(int j = 1; j < n-1;j++){
	        temp = k;
            temp = (temp * j) % (n - 1);
            temp++;
            cout << temp << " ";
	    }
	    cout<<n<<"\n";
	    
	}
	return 0;
}
