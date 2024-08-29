#include <iostream>
#include <list>
#include <iterator>
#include "Turma.hpp"

using namespace std;

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

list <Turma> minhasTurmas;
minhasTurmas.push_back ( poo1 );
minhasTurmas.push_back ( poo2 );
minhasTurmas.push_back ( aed1 );
minhasTurmas.push_back ( str );
minhasTurma.push_back ( pp );

for ( list <Turma>:: const_iterator it = minhasTurmas.begin(); it != minhasTurmas.end(); ++it )
cout << (*it ). str() << endl ;
minhasTurmas.sort(); // ordenar lista
cout << endl;
for ( list < Turma >:: const_iterator it = minhasTurmas .begin(); it != minhasTurmas .end(); ++it )
cout << (*it ). str() << endl ;
return 0;
}