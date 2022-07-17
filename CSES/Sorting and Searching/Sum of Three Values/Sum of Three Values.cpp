#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct element{
    int elem,index;
};

bool customCompare(element e1, element e2){
    return e1.elem < e2.elem;
}

void solve(){
    int n, x;
    cin >> n >> x;
    vector<element> elements(n);
    for(int i = 0; i < n;i++){
        cin >> elements[i].elem;
        elements[i].index = i+1;
    }
    bool flag = false;
    sort(elements.begin(),elements.end(), customCompare);
    for(int i = 0; i < n-1;i++){
        for(int j = i+1; j < n;j++){
            int l = j+1, h = n-1;
            while(l <= h){
                int mid = (l+h)/2;
                if(elements[mid].elem == (x-elements[i].elem - elements[j].elem)){
                    if(i != j && j != mid){
                        flag = true;
                        cout<<elements[i].index<<" "<<elements[j].index<<" "<<elements[mid].index<<"\n";
                    }
                    break;
                }
                else if(elements[mid].elem > (x-elements[i].elem - elements[j].elem)){
                    h = mid-1;
                }
                else l = mid+1;
            }
            if(flag) break;
        }
        if(flag) break;
    }
    if(!flag) cout<<"IMPOSSIBLE\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}



