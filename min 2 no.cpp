#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int mn = (a < b) ? a : b;
    cout << mn << endl;

    return 0;
}
