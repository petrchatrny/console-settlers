#include <iostream>
using namespace std;

void posloupnost2() {
    int pos = 1, count = 0, c, pre, delka = 0, poradi = 0;
    cin >> c;
    pre = c+1;
    while(c != 0) {
        if(c > pre) {
            pos++;
        } else {
            if(pos > 1) {
                count++;
                if(pos > delka) {
                    delka = pos;
                    poradi = count;
                }
                pos = 1;
            }
        }
        pre = c;
        cin >> c;
    }
    if(pos > 1) {
        count++;
        if(pos > delka) {
            delka = pos;
            poradi = count;
        }
    }
    cout << "Počet rostoucích posloupností: " << count << endl;
    cout << "Nejdelší posloupnost: " << delka << endl;
}

void fc3() {
    int count = 0, x;
    while(cin >> x) {
        count++;
    }
    cout << count;
}

void fc4() {
    char inp, prev;
    int count = 0;
    prev = '*';
    cin >> inp;
    while(inp != '.' || prev != '.') {
        if(inp >= 'A' && inp <= 'Z') {
            count++;
        }
        prev = inp;
        cin >> inp;
    }
    cout << "Počet velkých znaků: " << count << endl;
}

int main()
{
    fc4();
    return 0;
}
