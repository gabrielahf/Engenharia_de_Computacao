/*CONSIDERANDO QUE EXISTA UMA CLASSE PONTO E LISTAOBJETOS

utilizar <vector> ou <list>
LISTA OBJETOS: metodo adiciona(que recebe ponteiro para um Ponto e adiciona o objeto apontado por este ponteiro da estrutura)
LISTA OBJETOS: metodo informaMaisProximo (deve receber como parâmetro um ponteiro para um objeto da classe Ponto, procurar na
                                           lista o ponto mais proximo a este e retornar um ponteiro para ele )
obs.:assuma que já exista o método calculaDIstancia(x1,x2,y1,y2)
*/

list<Ponto> lista;
void adiciona(int e){
    lista.push_back(e);
}

Ponto informaMaisProximo(){
    if(lista.size() == 0) return nullptr;
        double dist_prox = calculaDistancia(p1 ->obtemX(), p2->obtemY, lista[0]->obtemX, lista[0]->obtemY());

        int prox = 0;
    for(int i = 1; i <lista.size();i++){
        double dist = calculaDistancia(p1 ->obtemX(), p2->obtemY, lista[0]->obtemX, lista[1]->obtemY());
        if(dist < dist_prox){
            prox = i;
            dist_prox = dist;
        }
    }
   return lista[prox];
}