#include <iostream>


using namespace std;

// Struct da lista duplamente encadeada
struct Node {
    char info;
    Node* prev, *next;
    Node(char i) { info = i; prev = next = nullptr;
        //imprimir a cada inserção de valor
        cout << "+" << endl; 
    }
    //destrutor pra imprimir - no final
    ~Node() { cout << "-" << endl;}
};

void imprimirlista(Node* head) {
    cout << "|";
    Node* aux = head;
    while (aux != nullptr) { cout << aux->info << "|";aux = aux->next;}
    cout << endl;
}

void Reverse(Node* tail) {
    cout << "|";
    Node* aux = tail;
    while (aux != nullptr) { cout << aux->info << "|"; aux = aux->prev;}
    cout << endl;
}

int main() {
    Node* head = nullptr, *tail = nullptr, *aux = nullptr; char c; bool fim = false; unsigned pos; // criacao

    while (!fim) {
        imprimirlista(head);
        cin >> c;

        switch (c) {
        case '<': cin >> c;
            {
                // Insere a letra especificada no início da lista
                Node* node = new Node(c);
                if (head == nullptr) { head = tail = node;
                }else {
                    node->next = head;
                    head->prev = node;
                    head = node;
                }
            }
            break;

        case '>':cin >> c;
            {
                // Insere a letra especificada no fim da lista
                Node* node = new Node(c);
                if (head == nullptr) { head = tail = node;
                }else {
                    node->prev = tail;
                    tail->next = node;
                    tail = node;
                }
            }
            break;

        case '+':
    {
      cin >> c >> pos;
      Node *node = new Node(c);
      if (pos == 0) // início da lista
      {
        if(head == nullptr) {
          head = tail = node;
        } else{
          node->next = head;
          head->prev = node;
          head = node;
        } 
      } else{
        Node *aux = head;
        unsigned e = 0;
        while (e < pos && aux != nullptr){aux = aux->next;e++;}

        if (aux == nullptr)
        {
            if(head == nullptr) { head = tail = node;
            } else{
            node->prev = tail;
            tail->next = node;
            tail = node;
            }
        }
        if(aux != nullptr){     
          node->prev = aux->prev;
          node->next = aux;
          aux->prev->next = node;
          aux->prev = node;  
        
        }
      }
    }
    break;

        case '{':
            {
                 /*  remove a letra/nodo do início da lista (imprime “ERRO” se a lista estiver vazia) */ 
                if (head != nullptr) {
                    Node* aux = head;
                    head = head->next;
                    if (head == nullptr) {tail = nullptr;
                    }else { head->prev = nullptr;}
                    delete aux;
                } else { cout << "ERRO" << endl;}
            }
            break;

        case '}':
            {
                /* remove a letra/nodo do final da lista (imprime “ERRO” se a lista estiver vazia) */ 
                if (tail != nullptr) {
                    Node* aux = tail;
                    tail = tail->prev;
                    if (tail == nullptr) { head = nullptr;
                    }else {tail->next = nullptr;}
                    delete aux;
                } else { cout << "ERRO" << endl;}
            }
            break;

        case '-':cin >> pos;
            {
                /* remove o elemento no índice especificado (imprime “ERRO” se o índice for inválido) */ 
                if (head == nullptr) {cout << "ERRO" << endl;
                } else if (pos == 0) {
                    Node* aux = head; // Remove o primeiro elemento
                    head = head->next;
                    if (head == nullptr) {tail = nullptr;
                    } else { head->prev = nullptr;}
                    delete aux;
                } else{
                    Node* index = head;  // Encontra o nó na posição especificada
                    unsigned e = 0;
                    while (index != nullptr && e < pos) { index = index->next; e++;
                    } if (index == nullptr) { cout << "ERRO" << endl;
                    } else{
                        index->prev->next = index->next; // Remove o nó na posição especificada
                        if (index->next != nullptr) { index->next->prev = index->prev;
                        } else{ tail = index->prev;}
                        delete index;
                    }
                }
            }
            break;

        case '.': fim = true;
            break;
        }

    }

        Reverse(tail); // imprimir reverso

    while (head != nullptr) { aux = head; head = head->next; delete aux;} // desloca lista
    return 0;
}
