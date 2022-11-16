#include <iostream>
using namespace std;
#include "BigReal.h"
#include <iomanip>
int main() {
cout << boolalpha;
BigReal p1{"1.5"}, p2{"1.4"};

    while (cin >> p1 >> p2){
        cout << "p1 + p2 = " << (p1 + p2) << endl;
        cout << "p1 - p2 = " << (p1 - p2) << endl;
        cout << "p1 < p2 " << (p1 < p2) << endl;
        cout << "p1 > p2 " << (p1 > p2) << endl;
        cout << "p1 == p2 " << (p1 == p2) << endl;
        cout << "Size of p1 " << p1.size() << endl;
        cout << "Size of p2 " << p2.size() << endl;
        cout << "Sign of p1 " << p1.get_sign() << endl;
        cout << "Sign of p2 " << p2.get_sign() << endl;
    }


}
