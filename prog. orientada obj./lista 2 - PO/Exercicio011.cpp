
#include <iostream>
#define TAM 10

using namespace std;

typedef struct{
    int dia, mes, ano;
}data;

typedef struct{
    string nome;
    double altura;
    data nascimento;
}dados;

void save(dados p[], string a, int n, int aqui){
    if(n < TAM){
        switch (aqui){
        case 0:
            p[n].nome = a;
            break;

        case 1:
            p[n].altura = stod(a) ;
            break;
        
        case 2:
            p[n].nascimento.dia = stoi(a);
            break;

        case 3:
            p[n].nascimento.mes = stoi(a);
            break;

        case 4:
            p[n].nascimento.ano = stoi(a);
            break;

        default:
            break;
        }
    }
}

void aniversario(dados p[], string mes){
    int sinal = 1;

    for (int ind = 0; ind < TAM; ind++){
        if(p[ind].nascimento.mes == stoi(mes)){
            sinal = 0;
            cout << p[ind].nome << ";" << p[ind].altura << "00"<<";" << 
            p[ind].nascimento.dia << "," << p[ind].nascimento.mes << 
            "," << p[ind].nascimento.ano << endl;
        }
    }

    if(sinal){
        cout << "> SEM ANIVERSARIOS" << endl;
    }
}


int main(){

    dados pessoa[TAM];
    string linha;
    int i = 0;

    while(true){

        getline(cin, linha);

        if(linha == "+"){
            for(int rep = 0; rep < 5; rep++){
                getline(cin, linha);
                save(pessoa, linha, i, rep);
            }

            i < TAM ? cout << "> OK"  << endl : cout << "> VETOR CHEIO"  << endl;
            i++;
        }
        else if( linha == "."){
            getline(cin, linha);
            aniversario(pessoa, linha);

            break;
        }
        else{
            cout << "> OPCAO INVALIDA" << endl;
        }
    }

    return 0;
}