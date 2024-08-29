#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

template < typename T >
class NodeBT {
private :
T info ; NodeBT *parent , *left , *right ;
string strGraphVizNode ( NodeBT const *node ) const ; // Imprime as conex õ es de um nodo com seus filhos em GraphViz
public :
NodeBT ( T const &i ); // Cria um nodo com o caractere i , e sem pai
~NodeBT (); // Destr ó i o nodo atual e seus descendentes
T getInfo () const ; // Retorna o caractere armazenado no nodo atual
void setInfo ( T &i ); // Altera o caractere armazenado no nodo atual
NodeBT *getParent () const ; // Retorna a refer ê ncia para o nodo - pai do nodo atual
NodeBT *getLeft () const ; // Retorna a refer ê ncia para o nodo - fiho / sub á rvore da esquerda
NodeBT *getRight () const ; // Retorna a refer ê ncia para o nodo - fiho / sub á rvore da direita
void addLeft ( NodeBT *subtree ); // Exclui a sub á rvore da esquerda ( se ela existir ) e adiciona uma nova
void addRight ( NodeBT *subtree ); // Exclui a sub á rvore da direira ( se ela existir ) e adiciona uma nova
void removeLeft(); // Remove a sub á rvore da esquerda ( simplesmente chama addLeft ( nullptr ))
void removeRight(); // Remove a sub á rvore da direita ( simplesmente chama addRight ( nullptr ))
bool isRoot() const ; // Retorna true se o nodo for raiz
bool isInternal() const ; // Retorna true se o nodo for interno
bool isExternal() const ; // Retorna true se o nodo for externo
int degree() const ; // Retorna o grau ( n ú mero de filhos ) do nodo atual
int depth() const ; // Retorna o n í vel do nodo atual
int height() const ; // Retorna a altura da sub á rvore / á rvore a partir do nodo atual
int size() const ; // Retorna o n ú mero de nodos a partir do nodo atual
bool contain ( T &i ) const ; // Retorna true se o nodo atual ou algum de seus descendentes contivere i
NodeBT const *find( T const &i ) const ; // Retorna a refer ê ncia para o nodo , a partir do atual , que cont é m i ou nullptr
string strGraphVizNode(NodeBT const *node)const; // funcao auxiliar para strGraphViz
string strGraphViz() const ; // Gera uma representa ç ã o da á rvore a partir do nodo atual no formato GraphViz
string preorder() const ; // Gera uma cadeia de caracteres ( um nodo por linha ) em pr é - ordem
string postorder() const ; // Gera uma cadeia de caracteres ( um nodo por linha ) em p ós - ordem
string inorder() const ; // Gera uma cadeia de caracteres ( um nodo por linha ) em in - ordem
string levelorder() const ; // Gera uma cadeia de caracteres ( um nodo por linha ) em largura
};



template <typename T>
   NodeBT<T> ::NodeBT(T const &i ){ 
    info = i; //atribuir parametros e variaveis
    parent = left = right = nullptr; // inicializar atributos vazios
  }

template <typename T>
   NodeBT<T> ::~NodeBT(){ // verificar se os atributos nao estao vazios, para entao deletar
    if ( left != nullptr ) delete left; 
    if ( right != nullptr ) delete right;
  }

template <typename T>
  T NodeBT<T> :: getInfo()const{return info;}

template <typename T>
void setInfo ( T &i ){info = i;}

template <typename T>
  int NodeBT<T> :: *getParent()const{return parent;}

template <typename T>
NodeBT *getLeft() const{return left;} // Retorna a referência para o nodo - fiho / sub á rvore da esquerda]

template <typename T>
NodeBT *getRight() const{return right;} // Retorna a referência para o nodo - fiho / sub á rvore da direita

template <typename T>
void NodeBT<T> ::addLeft( NodeBT *subtree ){
  if (left != nullptr) delete left; // verifica se ja existe subtree na esquerda e exclui
  left = subtree;
  if(subtree != nullptr) subtree -> parent = this; // verifica se ja existe subarvore e a aponta como parent
} // Exclui a sub árvore da esquerda ( se ela existir ) e adiciona uma nova

template <typename T>
void NodeBT<T> ::addRight( NodeBT *subtree ){
   if (right != nullptr) delete right;
  right = subtree;
  if(subtree != nullptr) subtree -> parent = this;
} // Exclui a sub á rvore da direira ( se ela existir ) e adiciona uma nova

template <typename T>
void NodeBT<T> ::removeLeft(){
  addLeft(nullptr);
} // simplesmente chama addLeft ( nullptr )

template <typename T>
void NodeBT<T> ::removeRight(){
  addRight(nullptr);
} // simplesmente chama addRight ( nullptr )

template <typename T>
  bool NodeBT<T> :: isRoot()const{return parent == nullptr;} // pois sem pais não ha nenhuma conexao com a raiz, facilitando a verificacao de quem é ela

template <typename T>
  bool NodeBT<T> :: isInternal()const{
    if(parent != nullptr && (left != nullptr || right != nullptr)) return true; // verifica se existe nodos (parent ou filhos(left/right))
  }

  bool NodeBT<T> :: isExternal()const{
    if(left == nullptr && right == nullptr) return true; // esvaziar nodos(left/right)
  }

template <typename T>
  int NodeBT<T> :: degree()const{
    int filho = 0;
    if(subtree ->left != nullptr) ++filho; // a condicao if faz andar o ponteiro
    if(subtree-> right != nullptr) ++filho;
    return filho;
  }

template <typename T>
  int NodeBT<T> :: depth()const{
    int nivel = 0;
    Node *aux = parent; //Cria um ponteiro aux e o inicializa com o ponteiro para o pai (membro da classe NodeBT que aponta para o nó pai) do nó atual.
    while(aux != nullptr) {
        nivel++;
        aux = aux -> getParent(); //Atualiza o ponteiro aux para apontar para o pai do nó atual. Isso move o algoritmo para o próximo nível da árvore.
    }
    return nivel; 
  }

template <typename T>
int NodeBT<T> :: height()const{
  /*Ao adicionar + 1, você está contando o próprio nó atual na altura total, 
  pois o nó em si contribui com uma unidade para a altura da subárvore.*/
  if(left == nullptr && right == nullptr) return 0;
    int L = 1 + left -> height(); 
    int R = 1 + right -> height(); 
  if(L > R) { //sempre comecar pela esquerda
    return left;
  } else {
    return right;
  }
}

template <typename T>
  int NodeBT<T> :: size()const{ //chamada recursiva
    if(subtree == nullptr) return 0;
    return 1 + size(subtree -> left) + size(subtree -> right);
  }


template <typename T>
  NodeBT NodeBT<T> :: const find(T const &i){
     if ( info == i ) return this ; 
     if(left != nullptr){
      NodeBT const *child = left -> find(i); //busca recursiva 
       if(child != nullptr) return child; //retorna ponteiro
     }
     if(right != nullptr){
      NodeBT const *child = right -> find(i);
       if(child != nullptr) return child;
     }
  }

template <typename T>
  bool NodeBT<T> :: contains(T &i)const{ 
    if ( info == i ) return true ; 
    if(left != nullptr && left -> contains(i)) return true;
    if(right != nullptr && right -> contains(i)) return true;
    return false;
  }

template <typename T>
  string NodeBT<T> :: strGraphVizNode(){
    stringstream ss;
    if(node -> left != nullptr) ss << "  " << node -> left -> info << endl << strGraphVizNode(node -> left);
    if(node -> right != nullptr) ss << "  " << node -> right -> info << endl << strGraphVizNode(node -> right);
  }

template <typename T>
  string NodeBT<T> :: strGraphViz(T const &i)const{
    stringstream ss;
    ss << "graficoNodeBT {" << endl << "  node [shape=circle]" << endl << strGraphVizNode(this) << "}" << endl;
    return ss.str();
  }

template <typename T>
  string NodeBT<T> :: preorder(T const &i)const{
   strinstream ss;
   ss << info << endl;
   if(left != nullptr) ss << left -> preorder();
   if(right != nullptr) ss << right -> preorder();
   return ss.str();
  }

template <typename T>
  string NodeBT<T> :: postorder(T const &i)const{
    strinstream ss;
   if(left != nullptr) ss << left -> postorder();
   if(right != nullptr) ss << right -> postorder();
   ss << info << endl;
   return ss.str();
  }

template <typename T> 
string NodeBT<T>::inorder() const{
  strinstream ss;
   if(left != nullptr) ss << left -> inorder();
   ss << info << endl;
   if(right != nullptr) ss << right -> inorder();
   return ss.str();
}

template <typename T>
  string NodeBT<T> :: levelorder(T const &i)const{
    stringstream ss;
    vector<const NodeBT *> nodes;
    nodes.push_back(this);
    
    while(nodes.size() != 0){
      const NodeBT *node = node[0];
      ss << node -> getinfo() << endl;
      nodes.erase(nodes.begin());
        if(node -> left != nullptr) nodes.push_back(node -> left);
        if(node -> right != nullptr) nodes.push_back(node -> right);
    }
    return ss.str();
  }

