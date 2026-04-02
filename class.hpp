#include <iostream>
#include <vector>
using namespace std;

struct Data{
    int dia = 0, mes = 0, ano = 0;
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

    string getNome(){
        return this->nome;
    }
};

Pessoa:: Pessoa(string nome, string telefone){
    this->nome = nome;
    this->telefone = telefone;
}

void Pessoa:: imprime(){
    cout<<nome<<", "<<telefone<<endl;
}

class Trabalhador : public Pessoa{
    double valorHora;
    string habilidade;
    Data especifica;

    public:
    Trabalhador *proximo;
    Trabalhador(string nome, string telefone, string habilidade, double valorHora, Data especifica) : Pessoa(nome, telefone){
        this->valorHora = valorHora;
        this->habilidade  = habilidade;
        this->especifica = especifica;
        proximo = NULL;
    }

    void imprime(){
        Pessoa:: imprime();
        cout<< "Habilidade: "<<habilidade<<endl<<"Valor hora: " <<valorHora;
    }

    Data getData(){
        return this->especifica;
    }
};

class Cliente : public Pessoa{
    string escolhaServico = NULL;
    Data diaServico;
    
    public:
    Cliente *proximo;
    Cliente(string nome, string telefone) : Pessoa(nome, telefone){
        proximo = NULL;
    }

    void imprime(){
        Pessoa:: imprime();
        cout<<"Escolheu o serviço: "<<escolhaServico;
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

        bool listavazia(colecaoTrabalhador &lista){
            if(lista.inicio == NULL){
                return false;
            } else {
                return true;
            }
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

        bool buscaCliente(colecaoTrabalhador &lista, string escolha){
            Trabalhador *nav = lista.inicio;

            while(nav != NULL){
                if(nav->getNome() == escolha){
                    return true;
                } else {
                    return false;
                }
                nav = nav->proximo;
            }
        }

        void imprimir(colecaoTrabalhador lista){
            if(lista.inicio == NULL){
                cout<<"Lista vazia"<<endl;
                return;
            }

            cout<<"Trabalhadores listados: "<<endl;

            Trabalhador *nav = lista.inicio;
            while(nav != NULL){
                nav->imprime();
                cout<<endl<<"--------"<<endl;
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

        bool listavazia(colecaoClientes &lista){
            if(lista.inicio == NULL){
                return false;
            } else {
                return true;
            }
        }

        void adicionarCliente(colecaoClientes &lista, Cliente cli) { //Final da lista
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

        
        bool buscaCliente(colecaoClientes &lista, string escolha){
            Cliente *nav = lista.inicio;

            while(nav != NULL){
                if(nav->getNome() == escolha){
                    return true;
                } else {
                    return false;
                }
                nav = nav->proximo;
            }
        }
        

        void imprimir(colecaoClientes lista){
            if(lista.inicio == NULL){
                cout<<"Lista vazia"<<endl;
                return;
            }

            cout<<"Trabalhadores listados: "<<endl;

            Cliente *nav = lista.inicio;
            while(nav != NULL){
                nav->imprime();
                cout<<endl<<"--------"<<endl;
                nav = nav->proximo;
            }
        }
   
};