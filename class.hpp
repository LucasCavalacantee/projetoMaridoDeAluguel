#include <iostream>
using namespace std;

struct Data{
    int dia, mes, ano;
};

bool operator==(Data a, Data b){
    if(a.dia == b.dia && a.mes == b.mes && a.ano == b.ano){
        return true;
    } else {
        return false;
    }
}

class Pessoa{
    string nome;
    string telefone;

    public:
    Pessoa(string nome, string telefone);

    void imprime();
};

Pessoa:: Pessoa(string nome, string telefone){
    this->nome = nome;
    this->telefone = telefone;
}

void Pessoa:: imprime(){
    cout<<nome<<", "<<telefone<<endl;
}

class Trabalhador : Pessoa{
    double valorHora;
    string habilidade;
    bool disponivel;
    Data especifica;
    
    public:
    Trabalhador *proximo;
    Trabalhador(string nome, string telefone, string habilidade, double valorHora, bool disponivel, Data especifica) : Pessoa(nome, telefone){
        this->valorHora = valorHora;
        this->habilidade = habilidade;
        this->disponivel = disponivel;
        this->especifica = especifica;
        proximo = NULL;
    }

    void imprime(){
        Pessoa:: imprime();
        cout<<habilidade<<", "<<valorHora<<endl;
    }

    Data getData(){
        return this->especifica;
    }
};

class Cliente : Pessoa{
    string servico;
    string escolhaPrestador;
    Data diaServico;
    
    public:
    Cliente *proximo;
    Cliente(string nome, string telefone, string escolhaPrestador, Data diaServico, string servico) : Pessoa(nome, telefone){
        this->escolhaPrestador = escolhaPrestador;
        this->diaServico = diaServico;
        this->servico = servico;
        proximo = NULL;
    }

    void imprime(){
        Pessoa:: imprime();
        cout<<"Escolheu o prestador: "<<escolhaPrestador;
    }

    void contratarTrabalhador(Trabalhador a1, Data tal){
        Data dataTrabalhador = a1.getData();
        if(dataTrabalhador == tal){
            cout<<"Trabalhador contratado";
        } else {
            cout<<"Trabalhador não esta disponivel nesse dia";
        }
    }

};

class colecaoTrabalhador{
    Trabalhador *inicio;

    public:
        void iniciaLista(colecaoTrabalhador &lista){
            lista.inicio = NULL;
        }

        void adicionaTrabalhador(colecaoTrabalhador &lista, Trabalhador emp) { //Final da lista
            Trabalhador *novo = new Trabalhador(emp);

            *novo = emp;
            novo->proximo = NULL;

            if(lista.inicio == NULL){
                lista.inicio = novo;
                return;
            } 

            Trabalhador *nav = lista.inicio;
            while(nav->proximo != NULL){
                nav = nav->proximo; //funciona como se fosse um i++, serve para avançar a lista
            }
            nav->proximo = novo;
        }

        void imprimir(colecaoTrabalhador lista){
            if(lista.inicio == NULL){
                cout<<"Lista vazia";
                return;
            }

            cout<<"Trabalhadores listados: "<<endl;

            Trabalhador *nav = lista.inicio;
            while(nav != NULL){
                nav->imprime();
                cout<<"--------"<<endl;
                nav = nav->proximo;
            }
        }
};

class colecaoClientes{
    Cliente *inicio;

    public:
        void iniciaLista(colecaoClientes &lista){
            lista.inicio = NULL;
        }

        void adicionaTrabalhador(colecaoClientes &lista, Cliente cli) { //Final da lista
            Cliente *novo = new Cliente(cli);

            *novo = cli;
            novo->proximo = NULL;

            if(lista.inicio == NULL){
                lista.inicio = novo;
                return;
            } 

            Cliente *nav = lista.inicio;
            while(nav->proximo != NULL){
                nav = nav->proximo; //funciona como se fosse um i++, serve para avançar a lista
            }
            nav->proximo = novo;
        }

        void imprimir(colecaoClientes lista){
            if(lista.inicio == NULL){
                cout<<"Lista vazia";
                return;
            }

            cout<<"Trabalhadores listados: "<<endl;

            Cliente *nav = lista.inicio;
            while(nav != NULL){
                nav->imprime();
                cout<<"--------"<<endl;
                nav = nav->proximo;
            }
        }
   
};