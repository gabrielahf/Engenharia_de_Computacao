#include <iostream>
#include <exception>

using namespace std;

class minhaExcecao : public exception {
    virtual const char* what() const throw() {
        return "Minha exceção aconteceu!";
    }
};

int main () {
    try {
        cout << "ANTES" << endl;
        throw minhaExcecao();
        cout << "DEPOIS" << endl;
    }
    catch (exception &e) {
        cerr << e.what() << endl;
    }
    return 0;
}

