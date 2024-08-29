# include <sstream>
# include <iomanip>
# include "Turma.hpp"

Turma::Turma ( string c , int cr , string n , string t ) : codigo ( c ) , creditos ( cr ) , nome ( n ) , turma ( t ) {}
void Turma::adicionaEncontro ( int ds , string h ) {
    diaSemana.push_back ( ds );
    horario.push_back ( h );
}
string Turma::obtemCodigo() const { return codigo; }
string Turma::obtemNome() const { return nome; }
string Turma::obtemTurma() const { return turma; }
string Turma::str() const {
stringstream ss ;
ss << codigo << " -" << setw (2) << setfill ( '0 ') << creditos << " " ;
ss << nome << " - Turma " << turma << " : " ;
for ( int i =0; i < diaSemana.size(); ++i ) ss << " " << diaSemana[i] << horario[i];
return ss . str ();
}
bool Turma::operator ==( Turma &t ) const { return codigo == t.codigo; }
bool Turma::operator <( Turma &t ) const { return codigo < t.codigo; }