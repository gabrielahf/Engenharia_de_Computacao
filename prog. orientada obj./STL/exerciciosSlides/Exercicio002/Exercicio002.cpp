#include <iostream>
#include <vector> // nao possui metodo sort() - ordenar lista, usar a funcao sort()
#include <iterator>
#include <algorithm> 
#include "Turma.hpp"

using namespace std;

bool compTurma(Turma &t1, Turma &t2){
    if(t1.obtemNome() < t2.obtemNome()) return true;
    if(t1.obtemNome() > t2.obtemNome()) return false;
    if(t1.obtemCodigo() < t2.obtemCodigo()) return true;
    if(t1.obtemCodigo() > t2.obtemCodigo()) return false;
    return (t1.obtemTurma() < t2.obtemTurma());
}

int main() {
Turma poo1 ( " 98718 " ,4 , " Programa ç ã o Orientada A Objetos - Eco " ," 10 " );
poo1.adicionaEncontro (2 , " AB " ); poo1 . adicionaEncontro (4 , " AB " );
Turma poo2 ( " 98718 " ,4 , " Programa ç ã o Orientada A Objetos - Eco " ," 11 " );
poo2.adicionaEncontro (2 , " CD " ); poo2 . adicionaEncontro (4 , " CD " );
Turma aed1 ( " 4645 " ,4 , " Algoritmos e Estruturas de Dados I " ," 14 " );
aed1.adicionaEncontro (2 , " AB " ); aed1 . adicionaEncontro (4 , " AB " );
Turma str ( " 4620 J " ,4 , " Sistemas de Tempo Real " ," 30 " );
str.adicionaEncontro (3 , " JK " ); str . adicionaEncontro (5 , " JK " );
Turma pp ( " 46528 " ,2 , " Programa ç ã o Paralela " , " 30 " );
pp.adicionaEncontro (5 , " LM " );

vector <Turma> minhasTurmas;
minhasTurmas.push_back ( poo1 );
minhasTurmas.push_back ( poo2 );
minhasTurmas.push_back ( aed1 );
minhasTurmas.push_back ( str );
minhasTurma.push_back ( pp );

for ( int i =0; i < minhasTurmas.size(); ++ i ) cout << minhasTurmas [ i ]. str () << endl ;
sort ( minhasTurmas . begin () , minhasTurmas.end());
cout << endl; for ( int i =0; i < minhasTurmas.size();++i) cout << minhasTurmas[i].str() << endl;
sort ( minhasTurmas . begin () , minhasTurmas.end(), compTurma );
cout << endl; for ( int i =0; i < minhasTurmas.size();++i) cout << minhasTurmas[i].str() << endl;

return 0;
}