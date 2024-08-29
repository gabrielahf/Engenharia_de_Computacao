#include <iostream>

using namespace std;

int main () {
    try {
        cout << "ANTES" << endl;
        throw 20;
        throw "ERRO DESCONHECIDO";
        cout << "DEPOIS" << endl;
    }
    catch (int e)  {
        cerr << "Ocorreu uma exceção de número " << e << "." << endl;
    }
    catch (...) {
        cerr << "Erro desconhecido..." << endl;
    }
    return 0;
}
