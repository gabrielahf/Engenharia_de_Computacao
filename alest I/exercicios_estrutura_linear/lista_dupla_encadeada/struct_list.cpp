// ESTRUTURA
struct Node {
    char info;
    Node* prev, *next;
    Node(char i) { info = i; prev = next = nullptr }
}

//EXEMPLO
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