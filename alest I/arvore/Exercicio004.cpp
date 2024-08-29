#include <iostream>
#include <sstream>

using namespace std;

struct Node {
char info; Node *child1, *child2, *child3;
Node (char i, Node *c1 = nullptr, Node *c2 = nullptr, Node *c3 = nullptr ) {
    info = i ; child1 = c1 ; child2 = c2 ; child3 = c3 ;
    cerr << "+ Node (" << info << ") criado ... " << endl ;
}
~Node () { cerr << "- Node (" << info << ") destruido ... " << endl ; }
};

string strChild(Node *father) { //funcao auxiliar de strGraphViz para ajudar na chamada recursiva
    stringstream ss;
    if(father-> child1 != nullptr) {
        ss << " " << father -> info << "--" << father -> child1 -> info << endl;
        ss << strChild(father -> child1);
    }
    if(father-> child2 != nullptr) {
        ss << " " << father -> info << "--" << father -> child2 -> info << endl;  
         ss << strChild(father -> child2);
    }
    if(father-> child3 != nullptr) {
        ss << " " << father -> info << "--" << father -> child3 -> info << endl;
         ss << strChild(father -> child3);
    }
    return ss.str();
}
string strGraphViz ( Node * root ) { 
stringstream ss ; 

ss << "graph \"Arvore\" {"<< endl;
ss << " node[shape = circle]" << endl;
ss << strChild(root); //chama funcao com a estrutura da arvore
ss << "}" << endl;
return ss . str ();


}

void clean ( Node * root ) { 
    if(root == nullptr) return; // caso base: arvore vazia

// exclui as subarvores 
    clean(root -> child1); 
    clean(root -> child2);
    clean(root -> child3);

    delete root; // exclui o nó atual apos excluir a subarvore
    root = nullptr; // define root como null antes de retornar

}

int main () {
Node *e = new Node ('E'), *f = new Node ('F'),
*g = new Node ('G'), *k = new Node ('K'),
*i = new Node ('I'), *j = new Node ('J'); // Folhas
Node *c = new Node ('C',g), *h = new Node ('H',k),
*b = new Node ('B',e,f), *d = new Node ('D',h,i,j); // Intermediarios
Node * root = new Node ('A',b, c,d); // Raiz
cout << strGraphViz ( root );
clean ( root );
return 0;
}