#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

template <typename T>
class NodeBT {
    private :
        T info ; NodeBT * parent , * left , * right ;
        string strGraphVizNode ( NodeBT const * node ) const ; // Imprime as conex ões de um nodo com seus filhos em GraphViz
    public :
        NodeBT (T const &i ); // Cria um nodo com o caractere i, e sem pai
        ~NodeBT (); // Destrói o nodo atual e seus descendentes
        T getInfo () const ; // Retorna o caractere armazenado no nodo atual
        void setInfo ( T &i ); // Altera o caractere armazenado no nodo atual
        NodeBT * getParent () const ; // Retorna a refer ê ncia para o nodo - pai do nodo atual
        NodeBT * getLeft () const ; // Retorna a refer ê ncia para o nodo - fiho / sub á rvore da esquerda
        NodeBT * getRight () const ; // Retorna a refer ê ncia para o nodo - fiho / sub á rvore da direita
        void setLeft ( NodeBT * subtree ); // Adiciona uma sub á rvore como subá rvore da esquerda do nodo atual
        void setRight ( NodeBT * subtree ); // Adiciona uma subá rvore como subá rvore da direita do nodo atual
        void removeLeft (); // Remove a sub á rvore da esquerda ( desalocando -a, se necess á rio )
        void removeRight (); // Remove a sub á rvore da direita ( desalocando -a, se necess á rio )
        bool isRoot () const ; // Retorna true se o nodo for raiz
        bool isInternal () const ; // Retorna true se o nodo for interno
        bool isExternal () const ; // Retorna true se o nodo for externo
        int degree () const ; // Retorna o grau (nú mero de filhos ) do nodo atual
        int depth () const ; // Retorna o ní vel do nodo atual
        int height () const ; // Retorna a altura da subá rvore /á rvore a partir do nodo atual
        int size () const ; // Retorna o nú mero de nodos a partir do nodo atual
        bool contains (T &i ) const ; // Retorna true se o nodo atual ou algum de seus descendentes contivere i
        NodeBT const * find ( T const &i ) const ; // Retorna a refer ê ncia para o nodo , a partir do atual , que cont ém i ou nullptr
        string strGraphViz () const ; // Gera uma representa ção da á rvore a partir do nodo atual no formato GraphViz
        string preorder () const ; // Gera uma cadeia de caracteres (um nodo por linha ) em pré-ordem
        string postorder () const ; // Gera uma cadeia de caracteres (um nodo por linha ) em pós- ordem
        string inorder () const ; // Gera uma cadeia de caracteres (um nodo por linha ) em in - ordem
        string levelorder () const ; // Gera uma cadeia de caracteres (um nodo por linha ) em largura
};

template <typename T>
NodeBT <T>::NodeBT ( T const &i ) {
    info = i; parent = left = right = nullptr ;
    # ifdef DEBUG
    cerr << "+ NodeBT < >(" << info << ") created ... " << endl ;
    # endif
}

template <typename T>
    NodeBT <T>::~NodeBT () {
    delete left ; delete right ;
    # ifdef DEBUG
    cerr << "- NodeBT < >(" << info << ") deleted ... " << endl ;
    # endif
}

template <typename T> T NodeBT <T>:: getInfo () const { return info ; }
template <typename T> void NodeBT <T>:: setInfo (T &i) { info = i; }
template <typename T> NodeBT <T> * NodeBT <T>:: getParent () const { return parent ; }
template <typename T> NodeBT <T> * NodeBT <T>:: getLeft () const { return left ; }
template <typename T> NodeBT <T> * NodeBT <T>:: getRight () const { return right ; }

template <typename T> 
void NodeBT <T>::setLeft ( NodeBT * subtree ) {
    left = subtree ;
    if ( subtree != nullptr ) subtree -> parent = this ;
}

template <typename T> void NodeBT <T>::setRight ( NodeBT * subtree ) {
    right = subtree ;
    if ( subtree != nullptr ) subtree -> parent = this ;
}

template <typename T> void NodeBT <T>::removeLeft () { if ( left != nullptr ) { delete left ; left = nullptr ; } }
template <typename T> void NodeBT <T>::removeRight () { if ( right != nullptr ) { delete right ; right = nullptr ; } }
template <typename T> bool NodeBT <T>::isRoot () const { return parent == nullptr ; }
template <typename T> bool NodeBT <T>::isInternal () const { return parent != nullptr && ( left != nullptr || right != nullptr ); }
template <typename T> bool NodeBT <T>::isExternal () const { return left == nullptr && right == nullptr ; }

template <typename T> 
int NodeBT <T>::degree () const {
    int res = 0;
    if ( left != nullptr ) ++ res ;
    if ( right != nullptr ) ++ res ;
    return res ;
}

template <typename T>
int NodeBT <T>::depth () const {
    int res = 0;
    NodeBT * aux = parent ;
    while ( aux != nullptr ) {
        ++ res ;
        aux = aux -> getParent ();
    }
    return res ;
}

template <typename T>
int NodeBT <T>::height () const {
    int l = ( left == nullptr )? 0 : (1+ left -> height ());
    int r = ( right == nullptr )? 0 : (1+ right -> height ());
    return (l >r )? l :r;
}

template <typename T>
    int NodeBT <T>::size () const {
    int res = 1;
    if ( left != nullptr ) res += left -> size ();
    if ( right != nullptr ) res += right -> size ();
    return res ;
}

template <typename T>
bool NodeBT <T>::contains (T &i) const {
    if ( info == i ) return true ;
    if ( left != nullptr && left -> contains (i) ) return true ;
    if ( right != nullptr && right -> contains (i) ) return true ;
    return false ;
}

template <typename T>
NodeBT <T > const * NodeBT <T>::find (T const &i) const {
    if ( info == i ) return this ;
    if ( left != nullptr ) {
    NodeBT const * child = left -> find (i );
    if ( child != nullptr ) return child ;
    }
    if ( right != nullptr ) {
    NodeBT const * child = right -> find ( i );
    if ( child != nullptr ) return child ;
    }
    return nullptr ;
}

template <typename T>
string NodeBT <T>::strGraphVizNode ( NodeBT const * node ) const {
    stringstream ss;
    if ( node->left != nullptr ) ss << " " << node->info << " -- " << node->left->info << endl << strGraphVizNode ( node->left );
    if ( node->right != nullptr ) ss << " " << node->info << " -- " << node->right->info << endl << strGraphVizNode ( node->right );
    return ss . str ();
}

template <typename T>
string NodeBT <T>:: strGraphViz () const {
    stringstream ss ;
    ss << " graph NodeBT {" << endl << " node [ shape = circle ]" << endl << strGraphVizNode ( this ) << "}" << endl ;
    return ss . str ();
}

template <typename T>
string NodeBT <T>::preorder () const {
    stringstream ss;
    ss << info << " " ;
    if ( left != nullptr ) ss << left -> preorder ();
    if ( right != nullptr ) ss << right -> preorder ();
    return ss . str ();
}

template <typename T>
string NodeBT <T>::postorder () const {
    stringstream ss ;
    if ( left != nullptr ) ss << left -> postorder ();
    if ( right != nullptr ) ss << right -> postorder ();
    ss << info << " " ;
    return ss . str ();
}

template <typename T>
    string NodeBT <T>::inorder () const {
    stringstream ss ;
    if ( left != nullptr ) ss << left -> inorder ();
    ss << info << " " ;
    if ( right != nullptr ) ss << right -> inorder ();
    return ss . str ();
}

template <typename T>
string NodeBT <T>::levelorder () const {
    stringstream ss ;
    vector <const NodeBT *> nodes ;
    nodes.push_back ( this );
    while ( nodes . size () != 0) {
    const NodeBT * node = nodes [0];
    ss << node -> getInfo () << " " ;
    nodes . erase ( nodes . begin ());
    if ( node -> left != nullptr ) nodes . push_back ( node -> left );
    if ( node -> right != nullptr ) nodes . push_back ( node -> right );
    }
    return ss . str ();
}

template <typename T>
class BST {
    private :
        void add ( NodeBT <T > * node , NodeBT <T > * newNode );
        bool contains ( NodeBT <T > * node , const T &e );
        NodeBT <T > * root ;
    public :
        BST ();
        ~BST ();
        string strGraphViz () const ;
        void add ( const T &e );
        bool contains ( const T & e );
        string preorder () const ; 
        string postorder () const ; 
        string inorder () const ; 
        string levelorder () const ; 
};

template <typename T>
BST <T>::BST () {
    root = nullptr ;
}

template <typename T>
BST <T>::~BST () {
    if ( root != nullptr ) delete root ;
}

template <typename T>
string BST <T>::strGraphViz () const {
    if ( root == nullptr ) return ""; else return root -> strGraphViz ();
}

template <typename T>
void BST <T>::add ( NodeBT <T> * node , NodeBT <T> * newNode ) {
    if ( newNode->getInfo() < node->getInfo() ) { // Left
        NodeBT <T> * left = node->getLeft();
        if ( left == nullptr ) node->setLeft( newNode );
        else add ( left , newNode );
    }
    else { // Right
        NodeBT <T> * right = node -> getRight ();
        if ( right == nullptr ) node -> setRight ( newNode );
        else add ( right , newNode );
    }
}

template <typename T>
void BST <T>::add ( const T &e) {
    NodeBT <T> * newNode = new NodeBT <T >( e );
    if ( root == nullptr ) root = newNode ;
    else add ( root , newNode );
}

template <typename T>
bool BST <T>::contains ( NodeBT <T> * node , const T &e) {
    if ( e == node -> getInfo () ) return true ;
    if ( e < node -> getInfo () ) { // Left
        NodeBT <T> * left = node -> getLeft ();
        if ( left == nullptr ) return false ;
        else return contains ( left ,e );
    }
    else { // Right
        NodeBT <T> * right = node -> getRight ();
        if ( right == nullptr ) return false ;
        else return contains ( right ,e );
    }
}

template <typename T>
bool BST <T>::contains ( const T &e) {
    if ( root == nullptr ) return false ;
    return contains ( root , e );
}

template <typename T>
string BST <T>::preorder () const  {
    return root->preorder();
}

template <typename T>
string BST <T>::postorder () const  {
    return root->postorder();
}

template <typename T>
string BST <T>::inorder () const  {
    return root->inorder();
}

template <typename T>
string BST <T>::levelorder () const  {
    return root->levelorder();
}


int main(){
    int in;
    cin >> in;

    BST<int> *bst = new BST<int>();

    while (in > 0){
        int num;
        cin >> num;
        bst->add(num);
        --in;
    }
    cout << bst->preorder() << endl;
    cout << bst->postorder() << endl;
    cout << bst->inorder() << endl;
    cout << bst->levelorder() << endl;

    return 0;
}