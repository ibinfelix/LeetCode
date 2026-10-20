#include <cstdlib>
#include <iostream>

//LC50
using namespace std;
double myPow(double x, int n){
    if(n == 0) return 1;
    if (n < 0) {
        x = 1/x;
        n = -n;
    }
    double product = myPow(x, n/2);
    if(n % 2 == 0) return product * product;
    else return product * product * x;
}

int main() {
    double x;
    int n;
    cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter exponent (n): ";
    cin >> n;

    cout << x << "^" << n << " = " << myPow(x, n) << endl;

    return 0;
}