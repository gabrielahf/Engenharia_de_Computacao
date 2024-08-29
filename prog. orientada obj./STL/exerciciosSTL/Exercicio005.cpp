/*Uma pilha (stack) é um tipo abstrato de dados que tem associadas as seguintes operações:
    push() – coloca um novo elemento no topo da pilha
    pop() – retira um elemento do topo da pilha
    top() – devolve o elemento no topo da pilha (sem a alterar!)
    clear() – esvazia a pilha

    a. Defina uma classe genérica em C++ que implemente uma pilha com todas as operações
    mencionadas e utiliza como estrutura de armazenamento um array. (Sugestão: utilize a classe vector da STL.)

    b. Defina uma classe genérica em C++ que implementa uma pilha com todas as operações
    mencionadas e utiliza como estrutura de armazenamento uma lista ligada. (Sugestão:Utilize a classe list da STL) */

#include <iostream>
#include <stack>
#include <template>
#include <vector>
#include <list>

using namespace std;

template <typename T>
class Pilha{
    private:
        vector <int> numero;
    public:
    Pilha(T &n) : numero(n){ numero = nullptr;}
    ~Pilha(){if(numero != nullptr) delete numero;}
    void setPilha(T &n){ numero = n;}
    T getPilha(){return numero;}
    bool comparacao( Pilha &n1, Pilha &n2){return n1.numero < n2.numero;}
    
}

int main(){
    vector<Pilha> lista;

    lista.push_back(Pilha(5));
    lista.push_back(Pilha(3));
    lista.push_back(Pilha(4));
    lista.push_back(Pilha(6));
    lista.push_back(Pilha(2));
    lista.pop_back(Pilha(5));
    lista.top(Pilha(5));
    lista.clear(Pilha);
    
    sort(lista.begin(), lista.end(), Pilha::comparacao);
}