#include <iostream>

using namespace std;

class ListaLinkSinal {
private:
    class Nodo { // classe interna
    public:
        int elemento;
        Nodo* prev; //anterior
        Nodo* next; //proximo
        
        Nodo(int n) {
            elemento = n;
            prev = next = nullptr;
            cout << "+ Nodo (" << elemento << ") criado..." << endl;
        }
        
        ~Nodo() {
            cout << "- Nodo (" << elemento << ") destruído..." << endl;
        }
    };

    Nodo* head; // inicio

public:
    ListaLinkSinal() {
        head = nullptr;
    }

    void add(int n) {
        Nodo* novo = new Nodo(n);
        if (head == nullptr) {
            head = novo;
        } else {
            Nodo* aux = head; //nodo auxiliar para efetuar a troca de variaveis 
            while (aux->next != nullptr) { 
                aux = aux->next;
            }
            aux->next = novo;
            novo->prev = aux;
            // ordem da lista: {aux, novo}
        }
    } // adicionar elementos no final da lista

    string soPositivos() {
        string resultado;
        Nodo* aux = head;
        while (aux != nullptr) {
            if (aux->elemento >= 0) { // verificar se o elemento é positivo
                resultado += to_string(aux->elemento) + " "; // converte valores de tipos numéricos em representações de texto (strings)
            }
            aux = aux->next; // avança para o prox nodo da cadeia
        }
        return resultado;
    } // retorna uma cadeia de caracteres com os numeros positivos da lista

    string soNegativos() {
        string resultado;
        Nodo* aux = head;
        while (aux != nullptr) {
            if (aux->elemento < 0) {  // verificar se o elemento é negativo
                resultado += to_string(aux->elemento) + " ";
            }
            aux = aux->next; 
        }
        return resultado;
    } // retorna uma cadeia de caracteres com os numeros negativos da lista
};
