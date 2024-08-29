#include <iostream>
#include <sstream>

using namespace std;

struct Node {
  char info;  Node *parent;  Node *left, *right;
  Node(char i, Node *l = nullptr, Node *r = nullptr) {
    info = i;  left = l;  right = r;  parent = nullptr;
    if ( left != nullptr ) left->parent = this;
    if ( right != nullptr ) right->parent = this;
    #ifdef DEBUG
    cerr << "+ Node("<< info << ") criado..." << endl;
    #endif
  }
  ~Node() {
    if ( left != nullptr ) delete left;
    if ( right != nullptr ) delete right;
    #ifdef DEBUG
    cerr << "- Node("<< info << ") destruido..." << endl;
    #endif
  }
};

string strNode(Node *Node) {
  stringstream ss;
  if ( Node->left != nullptr ) ss << "  " << Node->info << " -- " << Node->left->info << endl << strNode(Node->left);
  if ( Node->right != nullptr ) ss << "  " << Node->info << " -- " << Node->right->info << endl << strNode(Node->right);
  return ss.str();
}

string strGraphViz(Node *root) {
  stringstream ss; 
  ss << "graph Arvore {" << endl << "  Node [shape=circle]" << endl << strNode(root) << "}" << endl;
  return ss.str();
}

int degree(Node *subtree) { // retorn o grau (numero de filhos) do nodo atual
    int filho = 0;
    if(subtree ->left != nullptr) ++filho; // a condicao if faz andar o ponteiro
    if(subtree-> right != nullptr) ++filho;
    
    return filho;
}

int depth(Node *subtree) { // retorna o nivel do nodo atual
    int nivel = 0;
    Node *aux = subtree -> parent;
    while(aux != nullptr) {
        nivel++;
        aux = aux -> parent; 
    }
    return nivel; 
}
    
int size(Node *subtree) { // retorna o numero de nodos a partir do nodo atual
    if(subtree == nullptr) return 0;
    return 1 + size(subtree -> left) + size(subtree -> right);
    
    /*if (subtree == nullptr) return 0;
    int res = 1;
    if(subtree -> left != nullptr) res += size (subtree -> left);
    if(subtree -> right != nullptr) res += size (subtree -> right);
    return res;*/
    
 }

int treeDepth(Node *subtree) {
    if(subtree == nullptr) return -1;
    else {
        int l = (subtree -> left == nullptr) ? 0 : (1 + treeDepth(subtree -> left)); // necessario criar uma condicao if para verificar se esta vazio
        int r = (subtree -> right == nullptr) ? 0 : (1 + treeDepth(subtree -> right));
        return (l > r) ? l:r;
    }
}

int main() {
  Node *d = new Node('D');
  Node *b = new Node('B',d,new Node('E'));
  Node *f = new Node('F',new Node('H'),new Node('I'));
  Node *c = new Node('C',f,new Node('G'));
  Node *root = new Node('A',b,c);
  cout << strGraphViz(root);
  cout << "degree(root):    " << degree(root) << " [2]" << endl;
  cout << "degree(b):       " << degree(b) << " [2]" << endl;
  cout << "degree(d):       " << degree(d) << " [0]" << endl;
  cout << "depth(root):     " << depth(root) << " [0]" << endl;
  cout << "depth(b):        " << depth(b) << " [1]" << endl;
  cout << "depth(f):        " << depth(f) << " [2]" << endl;
  cout << "size(root):      " << size(root) << " [9]" << endl;
  cout << "size(b):         " << size(b) << " [3]" << endl;
  cout << "size(c):         " << size(c) << " [5]" << endl;
  cout << "treeDepth(root): " << treeDepth(root) << " [3]" << endl;
  cout << "treeDepth(b):    " << treeDepth(b) << " [1]" << endl;
  cout << "treeDepth(c):    " << treeDepth(c) << " [2]" << endl;
  delete root;
  return 0;
}