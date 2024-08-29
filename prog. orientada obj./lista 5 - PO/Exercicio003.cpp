#include <iostream>
#include <sstream>

using namespace std;    

class Pessoa {
private:
    string nome;
    int idade;
public:
    Pessoa(string n="", int i=0);
    ~Pessoa();
    string obtemNome() const;
    int obtemIdade() const;
    void defineNome(string n);
    void defineIdade(int i);
    void fazAniversario();
    string str() const;

    Pessoa operator+(const int i) const;
    void operator+=(const int i);
    Pessoa operator++(); // pre-incremento
    Pessoa operator++(int); // pos-incremento

    bool operator>(const Pessoa &p) const;
    bool operator<(const Pessoa &p) const;
    bool operator==(const Pessoa &p) const;
    bool operator!=(const Pessoa &p) const;
    bool operator>=(const Pessoa &p) const;
    bool operator<=(const Pessoa &p) const;
    
    bool operator>(const int i) const;
    bool operator<(const int i) const;
    bool operator==(const int i) const;
    bool operator!=(const int i) const;
    bool operator>=(const int i) const;
    bool operator<=(const int i) const;

    friend ostream &operator<<(ostream &out, const Pessoa &p);
    friend istream &operator>>(istream &in, Pessoa &p);
};

    Pessoa::Pessoa(string n, int i) : nome(n), idade (i) {}
    Pessoa::~Pessoa(){}
    string Pessoa::obtemNome() const{return nome;}
    int Pessoa::obtemIdade() const{return idade;}
    void Pessoa::defineNome(string n){nome = n;}
    void Pessoa::defineIdade(int i){idade = i;}
    void Pessoa::fazAniversario(){idade++;}
    string Pessoa::str() const
    {
        stringstream ss;
        ss << nome << " (" << idade << ")";
        return ss.str();
    }
    Pessoa Pessoa::operator+(const int i) const{/*m´etodo que sobrecarrega o operador +, recebendo um valor inteiro
(i) e retornando um novo objeto com o nome do objeto atual e com a idade do objeto atual somada a este
valor inteiro*/
                Pessoa NovaPessoa(nome,idade + i);
                return NovaPessoa;               
}
    void Pessoa::operator+=(const int i){/*m´etodo que sobrecarrega o operador +=, recebendo um inteiro que ser´a
somado na idade do objeto atual*/
                idade += i;
}
    Pessoa Pessoa::operator++(){/*m´etodo q ue sobrecarrega o operador de pr´e-incremento, incrementando a idade do objeto
atual e retornando um novo objeto igual ao objeto atual*/
                ++idade;
                return *this;
} // pre-incremento
    Pessoa Pessoa::operator++(int){/*m´etodo que sobrecarrega o operador de p ´os-incremento, armazenando uma c ´opia do
objetot atual, incrementando a idade do objeto atual e retornando a c ´opia do objeto atual feita anteriormente*/
                Pessoa copia(nome,idade);
                idade++;
                return copia;

} // pos-incremento

    bool Pessoa::operator>(const Pessoa &p) const{/*retorna verdadeiro se a idade do objeto atual for maior do que a
idade do objeto recebido como parˆametro, ou falso, em caso contr´ario*/
                if (idade > p.idade)
                {
                    return true;
                }
                 return false; 
}
    bool Pessoa::operator<(const Pessoa &p) const{/*retorna verdadeiro se a idade do objeto atual for menor do que
a idade do objeto recebido como parˆametro, ou falso, em caso contr´ario*/
                if (idade < p.idade)
                {
                    return true;
                }
                 return false; 
}
    bool Pessoa::operator==(const Pessoa &p) const{/*retorna verdadeiro se a idade do objeto atual for igual `a idade
do objeto recebido como parˆametro, ou falso, em caso contr´ario*/
                if (idade == p.idade)
                {
                    return true;
                }
                 return false; 
}
    bool Pessoa::operator!=(const Pessoa &p) const{/*retorna verdadeiro se a idade do objeto atual for diferente da
idade do objeto recebido como parˆametro, ou falso, em caso contr´ario*/
                if (idade != p.idade)
                {
                    return true;
                }
                 return false; 
}
    bool Pessoa::operator>=(const Pessoa &p) const{/*retorna verdadeiro se a idade do objeto atual for maior ou igual
`a idade do objeto recebido como parˆametro, ou falso, em caso contr´ario*/
                if (idade >= p.idade)
                {
                    return true;
                }
                 return false; 
}
    bool Pessoa::operator<=(const Pessoa &p) const{/*etorna verdadeiro se a idade do objeto atual for menor ou
igual `a idade do objeto recebido como parˆametro, ou falso, em caso contr´ario*/
                if (idade <= p.idade)
                {
                    return true;
                }
                 return false; 
}
    
    bool Pessoa::operator>(const int i) const{/*retorna verdadeiro se a idade do objeto atual for maior do que o valor
recebido como parˆametro (i), ou falso, em caso contr´ario;*/
                if (idade > i)
                {
                    return true;
                }
                 return false; 
}
    bool Pessoa::operator<(const int i) const{/*retorna verdadeiro se a idade do objeto atual for menor do que o valor
recebido como parˆametro (i), ou falso, em caso contr´ario*/
                if (idade < i)
                {
                    return true;
                }
                 return false; 
}
    bool Pessoa::operator==(const int i) const{/*retorna verdadeiro se a idade do objeto atual for igual ao valor rece-
bido como parˆametro (i), ou falso, em caso contr´ario;*/
                if (idade == i)
                {
                    return true;
                }
                 return false; 
}
    bool Pessoa::operator!=(const int i) const{/*retorna verdadeiro se a idade do objeto atual for diferente do valor
recebido como parˆametro (i), ou falso, em caso contr´ario*/
                if (idade != i)
                {
                    return true;
                }
                 return false; 
}
    bool Pessoa::operator>=(const int i) const{/*retorna verdadeiro se a idade do objeto atual for maior ou igual ao
valor recebido como parˆametro (i), ou falso, em caso contr´ario*/
                if (idade >= i)
                {
                    return true;
                }
                 return false; 
}
    bool Pessoa::operator<=(const int i) const{/*retorna verdadeiro se a idade do objeto atual for menor ou igual ao
valor recebido como parˆametro (i), ou falso, em caso contr´ario*/
                if (idade <= i)
                {
                    return true;
                }
                 return false; 
}

    ostream &operator<<(ostream &out, const Pessoa &p){/* envia o resultado do m´etodo str() do parˆametro
p para o fluxo de sa´ıda out*/
                out << p.str() << endl;
                return out;
}
    istream &operator>>(istream &in, Pessoa &p){/*lˆe do fluxo de entrada uma linha com o nome (usando getline)
e uma idade, atualizando o objeto p com estas informac¸ ˜oes*/
                getline(in,p.nome);
                in >> p.idade;
                return in;
                
}

int main() {
    
    Pessoa batman;
    cout << "Nome = " << batman.obtemNome() << endl;
    cout << "Idade = " << batman.obtemIdade() << endl;
    batman.defineNome("Bruce Wayne");
    batman.defineIdade(34);
    cout << batman << endl;
    cout << endl;
    
    Pessoa homemAranha("Peter Parker",35);
    cout << "Nome = " << homemAranha.obtemNome() << endl;
    cout << "Idade = " << homemAranha.obtemIdade() << endl;
    homemAranha.fazAniversario();
    cout << homemAranha << endl << endl;

    cout << (batman >= homemAranha?"ERRO":"OK") << " ";
    cout << (batman > homemAranha?"ERRO":"OK")<< " ";
    cout << (batman <= homemAranha?"OK":"ERRO") << " ";
    cout << (batman < homemAranha?"OK":"ERRO") << " ";
    cout << (batman != homemAranha?"OK":"ERRO") << " ";
    cout << (batman == homemAranha?"ERRO":"OK") << endl << endl;

    cout << batman << endl;
    batman = batman + 2;
    cout << batman << endl;
    cout << endl;

    cout << (batman >= homemAranha?"OK":"ERRO") << " ";
    cout << (batman > homemAranha?"ERRO":"OK") << " ";
    cout << (batman <= homemAranha?"OK":"ERRO") << " ";
    cout << (batman < homemAranha?"ERRO":"OK") << " ";
    cout << (batman != homemAranha?"ERRO":"OK") << " ";
    cout << (batman == homemAranha?"OK":"ERRO") << endl << endl;

    cout << batman << endl;
    ++batman;
    cout << batman << endl;
    cout << endl;

    cout << (batman >= homemAranha?"OK":"ERRO") << " ";
    cout << (batman > homemAranha?"OK":"ERRO") << " ";
    cout << (batman <= homemAranha?"ERRO":"OK") << " ";
    cout << (batman < homemAranha?"ERRO":"OK") << " ";
    cout << (batman != homemAranha?"OK":"ERRO") << " ";
    cout << (batman == homemAranha?"ERRO":"OK") << endl << endl;

    cout << batman << endl;
    batman += 2;
    cout << batman << endl;
    cout << endl;

    cout << (batman >= 40?"ERRO":"OK") << " ";
    cout << (batman > 40?"ERRO":"OK") << " ";
    cout << (batman <= 40?"OK":"ERRO") << " ";
    cout << (batman < 40?"OK":"ERRO") << " ";
    cout << (batman != 40?"OK":"ERRO") << " ";
    cout << (batman == 40?"ERRO":"OK") << endl << endl;

    batman.fazAniversario();
    cout << (batman >= 40?"OK":"ERRO") << " ";
    cout << (batman > 40?"ERRO":"OK") << " ";
    cout << (batman <= 40?"OK":"ERRO") << " ";
    cout << (batman < 40?"ERRO":"OK") << " ";
    cout << (batman != 40?"ERRO":"OK") << " ";
    cout << (batman == 40?"OK":"ERRO") << endl << endl;

    batman.fazAniversario();
    cout << (batman >= 40?"OK":"ERRO") << " ";
    cout << (batman > 40?"OK":"ERRO") << " ";
    cout << (batman <= 40?"ERRO":"OK") << " ";
    cout << (batman < 40?"ERRO":"OK") << " ";
    cout << (batman != 40?"OK":"ERRO") << " ";
    cout << (batman == 40?"ERRO":"OK") << endl << endl;

    Pessoa p1, p2;
    cin >> p1;
    p2 = p1++;
    cout << "p1=" << p1 << endl;
    cout << "p2=" << p2 << endl;
    p2 = ++p1;
    cout << "p1=" << p1 << endl;
    cout << "p2=" << p1 << endl;
    
    return 0;
}
