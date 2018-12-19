#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s("0");
    while(s.size() < 1000) {
        string t;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '0') t.append("1");
            else t.append("0");
        }
        s = s+t;
    }
    int x, q;
    cin >> q;
    while(q--) {
        cin >> x;
        cout << s[x] << "\n";
    }
    return 0;
}
