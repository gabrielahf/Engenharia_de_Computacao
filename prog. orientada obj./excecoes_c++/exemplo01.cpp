#include <iostream>

using namespace std;

int fatorial(int n) {
    if (n < 0) throw "fatorial de número negativo!";
    if (n == 0 || n == 1)
        return 1;
    return n * fatorial(n-1);
}

int divisao(int a, int b) {
    if (b == 0) throw "divisão por zero!";
    return a / b;
}

int main() {
    try {
        cout << fatorial(4) << endl;
        cout << divisao (4,0) << endl;
        cout << fatorial(-1) << endl;
        cout << fatorial(0) << endl;
    }
    catch (const char *e) {
        cerr << "\nERRO: " << e << endl;
    }
    return 0;
}
