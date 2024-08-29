#include <iostream>
#include <sstream>

using namespace std;

class ListaOrdenada {
    private:
            class Nodo{
                public:
                string nome; // dado
                Nodo *prev, *next; //referencias
                Nodo (string n) {
                    nome = n;
                    prev = next = nullptr;
                    cout << "+ Nodo ("<< nome << ") criado..." << endl;
                }
                ~Nodo(){
                    cout << "- Nodo ("<< nome << ") destruido..." << endl;
                }
            }
};
Nodo *head;
public:
    ListaOrdenada() {
        head = nullptr;
         cout << "+ ListaOrdenada ("<< nome << ") criado..." << endl;
    }
    ~ListaOrdenada() {
        while ( head != nullptr) {
            Nodo *aux = head;
            head = head -> next;
            delete aux;
        }
         cout << "- ListaOrdenada ("<< nome << ") destruido..." << endl;
    }

    void add (string n) {
        Nodo *novo = new Nodo(n);
        if ( head == nullptr)
            head = novo;
            else {
                Nodo *aux = head, *ant = nullptr;
                while (aux != nullptr && n > aux -> nome ) {// enquanto nao chegou ao final da lista
                ant = aux;
                aux = aux -> next;
                }
            if ( ant == nullptr) { // INICIO
                novo -> next = aux;
                head -> prev = novo;
                head = novo;
            }
             else if (aux == nullptr) { // FIM
                ant -> next = novo;
                novo -> prev = ant;
             }
             else { // MEIO
                ant -> next = novo;
                novo -> prev = ant;
                novo -> next = aux;
             }
            }

    }

    strign str() {
        stringstream ss;
        ss << "|";
        Nodo *aux = head;
        while ( aux != nullptr) {
            ss << aux -> noem << "|";
            aux = aux -> next;
        }
        return ss.str();
    } 


/* COMPARACAO_LISTA_6
    bool operator < (Equipe &e1, Equipe &e2){
        if ( e1.obtemPontos() < e2.obtemPontos())
            return true;
        if (e1.obtemPontos() > e2.obtemPontos())
            return false;
        return e1.obtemClube() < e2.obtemClube();
    }
*/
    