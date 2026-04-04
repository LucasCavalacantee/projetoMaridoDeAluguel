#include <iostream>
using namespace std;

struct Data{
    int dia = 0, mes = 0, ano = 0;
};

inline ostream& operator<<(ostream &on, Data &data){
    on << data.dia <<"/"<< data.mes <<"/"<< data.ano;
    return on;
}

bool operator==(Data a, Data b){
    if(a.dia == b.dia && a.mes == b.mes && a.ano == b.ano){
        return true;
    } else {
        return false;
    }
}

inline istream& operator>>(istream &in, Data &data){
    in >> data.dia >> data.mes >> data.ano;
    return in;
}

class Pessoa{
    string nome;
    string telefone;

    public:
    Pessoa() = default;
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
    cout<<"Nome: "<<nome<<endl;
    cout<<"Telefone: "<<telefone<<endl;
}

class Trabalhador : public Pessoa{
    double valorHora;
    string habilidade;
    Data especifica;

    public:
    Trabalhador *proximo;
    
    Trabalhador() = default;

    Trabalhador(string nome, string telefone, string habilidade, double valorHora, Data especifica) : Pessoa(nome, telefone){
        this->valorHora = valorHora;
        this->habilidade  = habilidade;
        this->especifica = especifica;
        proximo = NULL;
    }

    Trabalhador getTrabalhador(){
        return *this;
    }

    void imprime(){
        Pessoa:: imprime();
        cout<< "Habilidade: "<<habilidade<<endl;
        cout<<"Valor hora: " <<valorHora<<endl;
        cout<<"Dia que esta disponivel: " <<especifica<<endl;
    }

    Data getData(){
        return this->especifica;
    }
};

class colecaoTrabalhador{
    Trabalhador *inicio;

    public:
        
        void iniciaLista(colecaoTrabalhador &lista){
            lista.inicio = NULL;
        }

        bool listavazia(colecaoTrabalhador &lista){
            return lista.inicio == NULL;
        }

        bool adicionaTrabalhador(colecaoTrabalhador &lista, Trabalhador emp) { //Final da lista
            Trabalhador *novo = new Trabalhador(emp);
            novo->proximo = NULL;

            if(lista.inicio == NULL){
                lista.inicio = novo;
                return true;
            } 

            Trabalhador *nav = lista.inicio;
            while(nav->proximo != NULL){
                nav = nav->proximo; //funciona como se fosse um i++, serve para avançar a lista
            }
            nav->proximo = novo;
            return true;
        }

        Trabalhador recebeTrabalhador(colecaoTrabalhador &lista, string escolha){
            Trabalhador *nav = lista.inicio;

            while(nav != NULL){
                if(nav->getNome() == escolha){
                    return nav->getTrabalhador();
                }
                nav = nav->proximo;
            }
        }
        
        bool buscaTrabalhador(colecaoTrabalhador &lista, string escolha){
            Trabalhador *nav = lista.inicio;

            while(nav != NULL){
                if(nav->getNome() == escolha){
                    return true;
                }
                nav = nav->proximo;
            }
            return false; //checar essa linha
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

class Cliente : public Pessoa{
    
    public:
    Cliente *proximo = NULL;

    Cliente() = default;

    Cliente(string nome, string telefone) : Pessoa(nome, telefone){
        proximo = NULL;
    }

    Cliente getCliente(){
        return *this;
    } 

    void imprime(){
        Pessoa:: imprime();
    }

    bool contratarTrabalhador(Trabalhador a1, Data tal){
        Data dataTrabalhador = a1.getData();
        if(tal == dataTrabalhador){
            return true;
        } else {
            return false;
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
            return lista.inicio == NULL;
        }

        bool adicionarCliente(colecaoClientes &lista, Cliente cli) { //Final da lista
            Cliente *novo = new Cliente(cli);

            *novo = cli;
            novo->proximo = NULL;

            if(lista.inicio == NULL){
                lista.inicio = novo;
                return true;
            } 

            Cliente *nav = lista.inicio;
            while(nav->proximo != NULL){
                nav = nav->proximo; //funciona como se fosse um i++, serve para avançar a lista
            }
            nav->proximo = novo;
            return true;
        }

        
        bool buscaCliente(colecaoClientes &lista, string escolha){
            Cliente *nav = lista.inicio;

            while(nav != NULL){
                if(nav->getNome() == escolha){
                    return true;
                }
                nav = nav->proximo;
            }

            return false; //CHECAR ESSA LINHA
        }
        

        void imprimir(colecaoClientes lista){
            if(lista.inicio == NULL){
                cout<<"Lista vazia"<<endl;
                return;
            }

            cout<<"Clientes listados: "<<endl;

            Cliente *nav = lista.inicio;
            while(nav != NULL){
                nav->imprime();
                cout<<endl<<"--------"<<endl;
                nav = nav->proximo;
            }
        }
   
};


class PedidosTrabalhador{
    string clientePedido;
    string trabalhadorRequisitado;
    Data dataPedido;
    string status;
    
    public:
    PedidosTrabalhador *proximo;
    PedidosTrabalhador() = default;
    
    PedidosTrabalhador(string trabalhadorRequisitado, string clientePedido, Data dataPedido, string status){
        this->clientePedido = clientePedido;
        this->trabalhadorRequisitado = trabalhadorRequisitado;
        this->dataPedido = dataPedido;
        
            this->status = status;
        }

        void imprimirPedido(){
            cout<<"Este cliente gostaria do seu serviço: "<<endl<<endl;
            cout<<"Nome: "<<clientePedido;
            cout<<"Data do pedido: "<<dataPedido;
            cout<<"Status do pedido: "<<status;
        }
};

class colecaoPedidos{
    PedidosTrabalhador *inicio;

    public:
        void iniciaLista(colecaoPedidos &lista){
            lista.inicio = NULL;
        }

        bool listavazia(colecaoPedidos &lista){
            return lista.inicio == NULL;
        }

        void adicionarPedidos(colecaoPedidos &lista, PedidosTrabalhador serv, string cliente){
            PedidosTrabalhador *novo = new PedidosTrabalhador(serv);

            *novo = serv;
            novo->proximo = NULL;

            if(lista.inicio == NULL){
                lista.inicio = novo;
                return;
            } 

            PedidosTrabalhador *nav = lista.inicio;
            while(nav->proximo != NULL){
                nav = nav->proximo; //funciona como se fosse um i++, serve para avançar a lista
            }
            nav->proximo = novo;
        }

        void imprimirPedidos(colecaoPedidos lista){
            if(lista.inicio == NULL){
                cout<<"Lista vazia"<<endl;
                return;
            }

            cout<<"Lista de pedidos para este trabalhador: "<<endl;

            PedidosTrabalhador *nav = lista.inicio;
            while(nav != NULL){
                nav->imprimirPedido();
                cout<<endl<<"--------"<<endl;
                nav = nav->proximo;
            }
        }
    
};

/*

class AgendaTrabalhador : Trabalhador{
    Trabalhador trabalhador;
    Servico servico;
    Data disponivel;

    public:
        AgendaTrabalhador() = default;

        AgendaTrabalhador(Trabalhador trabalhador, Servico servico, Data disponivel){
            this->trabalhador = trabalhador;
            this->servico = servico;
            this->disponivel = disponivel;
        }

};

class Servico {
            string tipoServico;
            Data dataInicio;
            string duracaoEstimada;
            string valorServico;
            string trabalhadorResponsavel;
        
            public:
                Servico *proximo;
                Servico() = default;
        
                Servico(string trabalhadorResponsavel, string tipoServico, Data dataInicio, string duracaoEstimada, string valorServico, string status){
                    this->trabalhadorResponsavel = trabalhadorResponsavel;
                    this->tipoServico = tipoServico;
                    this->dataInicio = dataInicio;
                    this->duracaoEstimada = duracaoEstimada;
                    this->valorServico = valorServico;       
                }
            
                void imprimirServico(){
                    cout<<"Tipo do serviço: "<<tipoServico<<endl;
                    cout<<"Data de inicio do servico: "<<dataInicio<<endl;
                    cout<<"Duração estimada do serviço (em dias): "<<duracaoEstimada<<endl;
                    cout<<"Valor a ser pago(R$): "<<valorServico<<endl;
                }
        
        };
        
        class colecaoServico{
            Servico *inicio;
        
            public:
                void iniciaLista(colecaoServico &lista){
                    lista.inicio = NULL;
                }
        
                bool adicionarServico(colecaoServico &lista, Servico serv){
                    Servico *novo = new Servico(serv);
        
                    *novo = serv;
                    novo->proximo = NULL;
        
                    if(lista.inicio == NULL){
                        lista.inicio = novo;
                        return true;
                    } 
        
                    Servico *nav = lista.inicio;
                    while(nav->proximo != NULL){
                        nav = nav->proximo; //funciona como se fosse um i++, serve para avançar a lista
                    }
                    nav->proximo = novo;
                    return true;
                }
        
                void imprimirServicos(colecaoServico lista){
                    if(lista.inicio == NULL){
                        cout<<"Lista vazia"<<endl;
                        return;
                    }
        
                    cout<<"Trabalhadores listados: "<<endl;
        
                    Servico *nav = lista.inicio;
                    while(nav != NULL){
                        nav->imprimirServico();
                        cout<<endl<<"--------"<<endl;
                        nav = nav->proximo;
                    }
                }
        };

*/