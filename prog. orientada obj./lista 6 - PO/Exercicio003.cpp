#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Equipe {
private:
    string clube;
    int    pontos;
public:
    Equipe(string c="", int p=0) {
        clube = c;
        pontos = p;
    }
    string obtemClube() { return clube; }
    void defineClube(string c) { clube = c; }
    int obtemPontos() { return pontos; }
    void definePontos(int p) { pontos = p; }
    string toString() {
        stringstream ss;
        ss << clube << ": " << pontos << " pontos";
        return ss.str();
    }
    string toCSV() {
        stringstream ss;
        ss << clube << ";" << pontos;
        return ss.str();
    }
};

class Campeonato {
private:
    class Nodo {
    public:
        Equipe *equipe;
        Nodo *prox, *ant;

        Nodo(Equipe *e) : equipe(e), prox(nullptr), ant(nullptr) {
            // Construtor de Nodo que inicializa o campo equipe com o ponteiro 'e'
            // e os campos 'prox' e 'ant' como nullptr para "zerar" os encadeamentos.
        }
    };

    Nodo *primeiro;
    int numEquipes;

public:
    Campeonato() : primeiro(nullptr), numEquipes(0) {
        // Construtor: cria uma lista vazia de equipes.
    }

    ~Campeonato() {
        // Destrutor: desaloca os nodos da estrutura, simplesmente chamando limpa().
        limpa();
    }

    int obtemNumEquipes() {
        // Retorna o número de equipes na estrutura de dados.
        return numEquipes;
    }

    Equipe *obtemEquipe(int indice) {
        // Retorna o endereço da equipe que está no nodo na posição 'índice' da lista
        // ou nullptr se o índice for inválido.
        if (indice < 0 || indice >= numEquipes) {
            return nullptr;
        }

        Nodo *atual = primeiro;
        for (int i = 0; i < indice; i++) {
            atual = atual->prox;
        }

        return atual->equipe;
    }

    void insere(string c, int p) {
        // Cria uma equipe (formada por nome do clube e número de pontos) e a insere na lista.
        insere(new Equipe(c, p));
    }

    void insere(Equipe *e) {
        // Recebe o endereço de uma equipe e insere-a na lista de clubes do campeonato
        // em ordem decrescente de número de pontos (em caso de igualdade no número de pontos,
        // o critério seguinte é a ordem alfabética crescente).
        Nodo *novoNodo = new Nodo(e);

        if (!primeiro || e->obtemPontos() > primeiro->equipe->obtemPontos() || (e->obtemPontos() == primeiro->equipe->obtemPontos() && e->obtemClube() < primeiro->equipe->obtemClube())) {
            novoNodo->prox = primeiro;
            if (primeiro) {
                primeiro->ant = novoNodo;
            }
            primeiro = novoNodo;
        } else {
            Nodo *atual = primeiro;

            while (atual->prox && (e->obtemPontos() < atual->prox->equipe->obtemPontos() || (e->obtemPontos() == atual->prox->equipe->obtemPontos() && e->obtemClube() > atual->prox->equipe->obtemClube()))){
                atual = atual->prox;
            }

            novoNodo->prox = atual->prox;
            if (atual->prox) {
                atual->prox->ant = novoNodo;
            }
            atual->prox = novoNodo;
            novoNodo->ant = atual;
        }

        numEquipes++;
    }

    void limpa() {
        // Desaloca cada um dos nodos de equipes da estrutura, bem como a equipe do nodo,
        // deixando a lista vazia.
        Nodo *atual = primeiro;
        while (atual) {
            Nodo *prox = atual->prox;
            delete atual->equipe;
            delete atual;
            atual = prox;
        }

        primeiro = nullptr;
        numEquipes = 0;
    }
};





void mostraCampeonato(Campeonato *c) {
  int tam = c->obtemNumEquipes();
  for (int i=0; i<tam; ++i) {
      Equipe *e = c->obtemEquipe(i);
      cout << e->toString() << endl;
  }
  cout << "------------------" << endl;
}

int main() {
    Campeonato *brasileirao2021 = new Campeonato();
    mostraCampeonato(brasileirao2021);
    Equipe *e = new Equipe("Chapecoense",12);
    brasileirao2021->insere(e);
    mostraCampeonato(brasileirao2021);
    brasileirao2021->insere("Santos",28);
    brasileirao2021->insere("Bragantino",41);
    brasileirao2021->insere("Atletico Goianiense",31);
    mostraCampeonato(brasileirao2021);
    brasileirao2021->insere("Flamengo",42);
    brasileirao2021->insere("Atletico-MG",53);
    brasileirao2021->insere("Internacional",36);
    brasileirao2021->insere("Fluminense",33);
    brasileirao2021->insere("Juventude",28);
    brasileirao2021->insere("Sport",26);
    brasileirao2021->insere("Cuiaba",31);
    brasileirao2021->insere("Gremio",23);
    mostraCampeonato(brasileirao2021);
    brasileirao2021->insere("Corinthians",37);
    brasileirao2021->insere("Athletico-PR",33);
    brasileirao2021->insere("Palmeiras",40);
    brasileirao2021->insere("Sao Paulo",30);
    brasileirao2021->insere("Ceara",29);
    brasileirao2021->insere("Fortaleza EC",39);
    brasileirao2021->insere("Bahia",27);
    brasileirao2021->insere("America-MG",31);
    mostraCampeonato(brasileirao2021);
    delete brasileirao2021;
    return 0;
}
