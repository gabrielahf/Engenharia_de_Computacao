
#include <iostream>
#include <sstream>

using namespace std;

struct BinaryNode {
char info; BinaryNode *parent; BinaryNode *left, *right;
BinaryNode (char i, BinaryNode *l = nullptr, BinaryNode *r = nullptr ) {
    info = i ; left = l ; right = r ; parent = nullptr;
    // ajusar quem é pai de quem 
    if(left != nullptr) left -> parent = this; // referencia ao proprio objeto (pai do filho da esquerda é o atual)
    if (right != nullptr) right -> parent = this; 
    cerr << "+ BinaryNode (" << info << ") criado ... " << endl ;
}
~BinaryNode () { cerr << "- BinaryNode (" << info << ") destruido ... " << endl ; }
};

string strBinaryNode(BinaryNode *father) { //funcao auxiliar de strGraphViz para ajudar na chamada recursiva
    stringstream ss;
    if(father-> left != nullptr) {
        ss << " " << father -> info << "--" << father -> left -> info << endl;
        ss << strBinaryNode(father -> left);
    }
    if(father-> right != nullptr) {
        ss << " " << father -> info << "--" << father -> right -> info << endl;  
         ss << strBinaryNode(father -> right);
    }
    
    return ss.str();
}
string strGraphViz ( BinaryNode * root ) { 
stringstream ss ; 

ss << "graph \"Arvore\" {"<< endl;
ss << " BinaryNode[shape = circle]" << endl;
ss << strBinaryNode(root); //chama funcao com a estrutura da arvore
ss << "}" << endl;
return ss . str ();

/* que recebe o endereço de um nodo e faz a desalocação de todos os
nodos da árvore a partir do nodo recebido (root) esta função deve ser implementada de forma
recursiva  */
}

void clean (BinaryNode *root) { 
    if(root == nullptr) return; // caso base: arvore vazia

// exclui as subarvores 
    clean(root -> left); 
    clean(root -> right);

    delete root; // exclui o nó atual apos excluir a subarvore
    root = nullptr; // define root como null antes de retornar

/* que recebe o endereço de um nodo e gera uma cadeia de
caracteres (string) com representação da árvore no formato DOT, usado pelo GraphViz esta
função deve: imprimir a parte inicial do formato DOT; chamar um outro método recursivo (por
exemplo, string strNode(Node *node)) para gerar a lista de arestas entre os nodos; imprimir a
parte final do formato DOT  */ 
}

int main () {
BinaryNode *d = new BinaryNode ('D'), *e = new BinaryNode ('E'),
*f = new BinaryNode ('F'), * g = new BinaryNode ('G'); // Folhas
BinaryNode *c = new BinaryNode ('C',f, g), *b = new BinaryNode ('B',d,e ); // Intermediarios
BinaryNode *root = new BinaryNode ('A',b ,c ); // Raiz
cout << strGraphViz (root);
clean (root);
return 0;
}