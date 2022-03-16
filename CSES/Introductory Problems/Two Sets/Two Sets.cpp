// Introductory Problems : Two Sets
#include "iostream"
using namespace std;

int main(){
    int n;
    cin >> n;
    long long int temp = n;
    temp *= (temp + 1);
    if(n == 3){
        cout<<"YES\n";
        cout<<2<<"\n";
        cout<<1<<" "<<2<<"\n";
        cout<<1<<"\n";
        cout<<3<<"\n";
    }
    else if(temp % 4 != 0){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
        if(n % 2 == 0){
            cout<<n/2<<"\n";
            for(int i = 1; i <= n/2;i+=2){
                cout<<i<<" "<<n-i+1<<" ";
            }
            cout<<"\n"<<n/2<<"\n";
            for(int i = 2; i <= n/2; i+=2){
                cout<<i<<" "<<n-i+1<<" ";
            }
            cout<<"\n";
        }
        else{
            int tmp = n/4;
            int count = 0;
            cout<<n/2 + 1<<"\n";
            int i;
            for(i = 1; count < tmp;i+=2){
                cout<<i<<" ";
                count++;
            }
            int start = i - 1;
            for(i = start;i < n - 1;i+=2){
                cout<<i<<" ";
            }
            cout<<n<<" ";
            cout<<"\n"<<n/2<<"\n";
            count = 0;
            for(i = 2; count < tmp - 1;i+=2){
                cout<<i<<" ";
                count++;
            }
            start = i + 1;
            for(i = start;i < n - 1;i+=2){
                cout<<i<<" ";
            }
            cout<<n-1<<"\n";
        }
    }
    return 0;
}

