#include <iostream>

using namespace std;

int main() {
    int x = 0, y = 1, y_t, x_s, x_t;
    int r = 1000, l = 2,m;
    string str;
    while (l < r) {
        m = (l + r) / 2;
        if (m == l) {
            cout << "? 0 " << m + 1 << endl;
            cin >> str;
            if (str == "YES") {
                l = m + 1;
            }
            break;
        }
        cout << "? 0 " << m << endl;
        cin >> str;
        if (str == "YES") {
            l = m;
        } else {
            r = m - 1;
        }
    }
    y_t = l;
    y = 0, l = 1, r = 1000;
    while (l < r) {
        m = (l + r) / 2;
        if (m == l) {
            cout << "? "<< m + 1 <<" 0"<< endl;
            cin >> str;
            if (str == "YES") {
                l = m + 1;
            }
            break;
        }
        cout << "? " << m <<" 0"<< endl;
        cin >> str;
        if (str == "YES") {
            l = m;
        } else {
            r = m - 1;
        }
    }
    x_s = l;
    y = 2*x_s, l = x_s + 1, r = 1000;
    while (l < r) {
        m = (l + r) / 2;
        if (m == l) {
            cout << "? "<< m + 1 <<" "<< 2*x_s << endl;
            cin >> str;
            if (str == "YES") {
                l = m + 1;
            }
            break;
        }
        cout << "? " << m <<" "<< 2*x_s << endl;
        cin >> str;
        if (str == "YES") {
            l = m;
        } else {
            r = m - 1;
        }
    }
    x_t = l;
    int area = 4*x_s*x_s;
    area += x_t*(y_t - 2*x_s);
    cout<<"! "<< area <<endl;
	return 0;
}
