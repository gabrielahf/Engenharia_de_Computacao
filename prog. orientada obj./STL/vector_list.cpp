/*
<list>
<iterator>
for(it = nomeLista.begin(); it != nomeLista.end();it++)
nomeLista.sort()
*/

for ( list <Turma>:: const_iterator it = minhasTurmas.begin(); it != minhasTurmas.end(); ++it )
cout << (*it ). str() << endl ;
minhasTurmas.sort(); // ordenar lista
cout << endl;
for ( list < Turma >:: const_iterator it = minhasTurmas .begin(); it != minhasTurmas .end(); ++it )
cout << (*it ). str() << endl ;

/*
<vector>
<algorithm>
percorrer vetor for (int i =0; i < nomeVetor.size(); ++i )
funcao sort(nomeVetor.begin(), nomeVetor.end()); -- ordenar o vetor
funcao sort + comparacao entre dois valores sort ( minhasTurmas . begin () , minhasTurmas.end(), nomeClasse::nomeMetodoComparacao );
*/

for ( int i =0; i < minhasTurmas.size(); ++ i ) cout << minhasTurmas [ i ]. str () << endl ;
sort ( minhasTurmas . begin () , minhasTurmas.end());
cout << endl; for ( int i =0; i < minhasTurmas.size();++i) cout << minhasTurmas[i].str() << endl;
sort ( minhasTurmas . begin () , minhasTurmas.end(), Turma::compTurma );
cout << endl; for ( int i =0; i < minhasTurmas.size();++i) cout << minhasTurmas[i].str() << endl;