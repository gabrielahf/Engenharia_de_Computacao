# include "NodeCharTree.hpp"

  NodeCharTree::NodeCharTree(char i){
   char info;  // dado do nó
   Node *left, *right;
   Node(char i) : info(i), left(nullptr), right(nullptr) {}
  
  }// Cria um nodo com o caractere i, e sem pai

  NodeCharTree::~NodeCharTree(){
    if ( left != nullptr ) delete left;
    if ( right != nullptr ) delete right;
    
  }// Destrói o nodo atual e seus descendentes

  char NodeCharTree::getInfo() const{ return info; } // Retorna o caractere armazenado no nodo atual

  void NodeCharTree::setInfo() const{info = i;}

  NodeCharTree NodeCharTree::*getParent() const{return parent;} // Retorna a referência para o nodo-pai do nodo atual

  NodeCharTree NodeCharTree::*getChild(int index) const{
    if(index < 0 || index >= childs.size()){
        return childs[index];
    }
  } // Retorna a referência para o nodo-fiho de índice index ou nullptr
  
  bool NodeCharTree::isRoot() const{
    return parent == nullptr;
  }// Retorna true se o nodo for raiz

  bool NodeCharTree::isInternal() const{
    if(parent != nullptr && childs.size() != 0) return true;
  }// Retorna true se o nodo for interno (ou seja, possui filhos)

  bool NodeCharTree::isExternal() const{
    if(childs.size() == nullptr) return true;
  }// Retorna true se o nodo for externo (ou seja, nao possui filhos)

  int NodeCharTree::degree() const{ 
    int filho = 0;
    if(subtree ->left != nullptr) ++filho; // a condicao if faz andar o ponteiro
    if(subtree-> right != nullptr) ++filho;
    return filho;
    }// Retorna o grau (número de filhos) do nodo atual

  int NodeCharTree::depth() const{
    int nivel = 0;
    Node *aux = subtree -> info;
    while(aux != nullptr) {
        nivel++;
        aux = aux -> info; 
    }
    return nivel; 
  }// Retorna o nível do nodo atual

  int NodeCharTree::size() const{
    if(subtree == nullptr) return 0;
    return 1 + size(subtree -> left) + size(subtree -> right);

  }// Retorna o número de nodos a partir do nodo atual

  void NodeCharTree::addSubtree(NodeCharTree *subtree){
    if (subtree == nullptr) return -1;
    child.push_back(subtree); //insercao do filho
    subtree -> parent = this; // cadastrar o proprio pai na sub arvore
    
  }// Adiciona uma subárvore como filho do nodo atual

  bool NodeCharTree::removeSubtree(NodeCharTree *subtree){
    for ( int i =0; i < childs.size(); ++i) // percorrer a quantidade de nodos-filho
    if ( childs [ i ] == subtree ){ //verifica se o filho atual combina com a subarvore fornecida
        childs.erase ( childs.begin () + i ); // remoção do filho
        return true;}

    return false;

}// Remove a subárvore dentre os filhos do atual (true indica sucesso)
  
  bool NodeCharTree::contains(char i) const{
    if ( info == i ) return true ; // se o dado do nodo for igual a i nao segue a execucao
        for ( int j =0; j < childs.size(); ++j ) // percorre a quantidade de nodos e seus descendentes
            if ( childs [j] -> contains (i) ) return true; // verifica se o filho atual esta apontado para o metodo(i)
    return false ;

  } // Retorna true se o nodo atual ou algum de seus descendentes contains i

  NodeCharTree const NodeCharTree::*find(char i) const{
    if ( info == i ) return true ; // se o dado do nodo for igual a i nao segue a execucao
        for ( int j =0; j < childs.size(); ++j ) // percorre a quantidade de nodos e seus descendentes
        NodeCharTree const *child = childs[j] -> find(i); // referencia para o nodo 
          if(child != nullptr) return child; // caso seja diferente de vazio se retorna a referencia para o nodo

  }// Retorna a referência para o nodo, a partir do atual, que contém i ou nullptr


  string NodeCharTree::strGraphVizNode() const{
    stringstream ss;
    for (int i = 0; i < node-> childs.size(); i++)
    {
      ss << "  " << node->info << " -- " << node->childs[i]->info << endl << strGraphVizNode(node->childs[i]);
    }
    
  } //metodo auxiliar para imprimir a arvore

  string NodeCharTree::strGraphViz() const{
    stringstream ss;
    ss << "graficoNodeCharTree {" << endl << "  node [shape=circle]" << endl << strGraphVizNode(this) << "}" << endl;
  
  } // Gera uma representação da árvore a partir do nodo atual no formato GraphViz

