#include<iostream>
#include <unistd.h>
#include "class.hpp"
#include "dataOperacao.hpp"
using namespace std;


/*
PROBLEMAS PARA RESOLVER:

- Busca de trabalhador na pagina de cliente
- Comecar pagina do trabalhador
- Finalizar class Pedidos
- Estruturar pedidos que chegam ao trabalhador

*/


/*
RESUMO DE IMPLEMENTAÇÃO

- Menu quase pronto
- funções de verificação de trabalhador e cliente ativo implementadas
- Lista de clientes e trabalhadores prontas

O que falta:

- Criar lista encadeada generica para melhor otimização do código
- Finalizar a pagina de clientes e trabalhadores
- Clientes precisam poder abrir serviços 
- Trabalhadores podem visualizar todos os pedidos pendentes feitos para ele

*/

int main(){
    int opcao;
    colecaoTrabalhador listaTrabalhador;
    colecaoClientes listaClientes;
    colecaoServico servicos;
    colecaoPedidos pedidos;


    listaTrabalhador.iniciaLista(listaTrabalhador);
    listaClientes.iniciaLista(listaClientes);
    servicos.iniciaLista(servicos);
    pedidos.iniciaLista(pedidos);

    do{
        system("clear");
        cout<<"Menu de opções"<<endl;
        cout<<"1. Cadastrar trabalhador"<<endl;
        cout<<"2. Cadastrar serviço do trabalhador"<<endl;
        cout<<"3. Visualizar pedidos do trabalhador"<<endl;
        cout<<"4. Cadastrar cliente"<<endl;
        cout<<"5. Pagina do cliente"<<endl;
        cout<<"6. Listar trabalhadores"<<endl;
        cout<<"7. Listar clientes"<<endl;
        cout<<"8. Sair"<<endl;
        cout<<"Escolha uma opcao: "; cin>>opcao;

        switch (opcao) {
        case 1: { //Cadastrar trabalhador
            system("clear");
            string nomeT, telefoneT, habilidade;
            double valorHora;
            Data dataEscolhida;

            cout<<"Digite informações sobre o novo trabalhador abaixo"<<endl<<endl;
            cout<<"Nome: "; cin>>nomeT;
            cout<<"Telefone: "; cin>>telefoneT;
            cout<<"Digite as habilidades que ele vai ter: "; cin>>habilidade;
            cout<<"Valor da hora desse trabalhador: "; cin>>valorHora;
            cout<<"Dia que este trabalhador estara disponivel: ((d m aa))"; cin>>dataEscolhida;

            Trabalhador novo(nomeT, telefoneT, habilidade, valorHora, dataEscolhida);
            listaTrabalhador.adicionaTrabalhador(listaTrabalhador, novo);
        }
            break; 
        case 2:{ //Pagina do trabalhador
            system("clear");
            if(listaTrabalhador.listavazia(listaTrabalhador)){
                string sair;
                cout<<"Lista vazia! Não há trabalhadores cadastrados."<<endl<<endl;
                cout<<"Clique em qualquer tecla e pressione ENTER para sair";
                cin>>sair;
            } else {
                string trabalhadorEscolhido;
                cout<<"Digite o nome do trabalhador que fará a operação:";
                cin>>trabalhadorEscolhido;
                if(listaTrabalhador.buscaTrabalhador(listaTrabalhador, trabalhadorEscolhido) == true){
                    string tipoServico;
                    Data dataInicio;
                    string duracaoEstimada;
                    string valorServico;
                    string status = "ABERTO";
                    string clienteEscolhido;

                   cout<<"Crie um serviço abaixo: "<<endl<<endl;
                   cout<<"Tipo do serviço: "; getline(cin, tipoServico);
                   cout<<"Data de inicio do servico: "; cin>>dataInicio;
                   cout<<"Duração estimada do serviço: (em dias) "; getline(cin, duracaoEstimada);
                   cout<<"Valor a ser pago(R$): "; cin>>valorServico;
            
                   Servico servico(trabalhadorEscolhido, tipoServico, dataInicio, duracaoEstimada, valorServico, status);
                   servicos.adicionarServico(servicos, servico);

                    cout<<"Cadastre um serviço paraa este trabalhador abaixo: "<<endl<<endl;

                } else {
                    cout<<"Esse trabalhador não existe";
                }
            }
            //Trabalhador consegue visualizar pedidos apenas feitos para ele
            //pedidos aparecem como abertos, fechados ou em andamento
        }
            
            break;
        case 3:{ //Visualizar pedidos do trabalhador 
            
        }
            break;
        case 4:{ //Cadastro do cliente
            system("clear");
            string nomeC, telefoneC;
            cout<<"Digite informações sobre o novo cliente abaixo"<<endl<<endl;
            cout<<"Nome: "; cin>>nomeC;
            cout<<"Telefone: "; cin>>telefoneC;

            Cliente novo(nomeC, telefoneC);
            if(listaClientes.adicionarCliente(listaClientes, novo) == true){
                string sair;
                cout<<"Cliente cadastrado com sucesso!"<<endl;
                cout<<"Digite qualquer tecla e pressione ENTER para voltar ao menu: ";
                cin>>sair;
            } else {
                cout<<"Algo de errado aconteceu";
            }
        }
            break;
        case 5:{ //Pagina do cliente
            system("clear");
            if(listaClientes.listavazia(listaClientes)){
                string sair;
                cout<<"Lista vazia! Não há clientes cadastrados."<<endl<<endl;
                cout<<"Clique em qualquer tecla e pressione ENTER para sair";
                cin>>sair;
            } else {
                string clienteEscolhido;
                string contratarTrabalhador;
                Data datapedido;
                string status = "EM ABERTO";
                Cliente cli;
                Trabalhador tr;
                

                cout<<"Digite o nome do cliente que fará a operação:";
                cin>>clienteEscolhido;

                if(listaClientes.buscaCliente(listaClientes, clienteEscolhido) == true){
                    int simounao;
                    cout<<"Verifique os trabalhadores e seus servicos abaixo: "<<endl<<endl;
                    listaTrabalhador.imprimir(listaTrabalhador);
                    cout<<endl<<"Gostaria de ir para contratação de serviços?(1/2)"; cin>>simounao;
                    switch (simounao){
                        case 1: {
                            system("clear");
                            cout<<endl<<"Qual trabalhador você gostaria de contratar?"<<endl;
                            cin>>contratarTrabalhador;
                            string sair;
                            //Verifica se trabalhador existe
                            if(listaTrabalhador.buscaTrabalhador(listaTrabalhador, contratarTrabalhador) == true){
                                cout<<"Para quando voce precisa do servico dele?(d m aa)"<<endl; 
                                cin>>datapedido;

                                //verifica se a data bate com a do trabalhador
                                if(cli.contratarTrabalhador(tr, datapedido) == true){ 
                                    PedidosTrabalhador pnovo(contratarTrabalhador, clienteEscolhido, datapedido, status);
                                    pedidos.adicionarPedidos(pedidos, pnovo, clienteEscolhido);
                                    cout<<"Pedido enviado ao trabalhador! Aguarde a resposta."<<endl<<endl;
                                    cout<<"Clique em qualquer tecla e pressione ENTER para sair";
                                    cin>>sair;
                                } else{

                                    cout<<"Trabalhador esta indisponivel nesse dia";
                                    cout<<"Clique em qualquer tecla e pressione ENTER para sair";
                                    cin>>sair;
                                }

                            } else {
                                cout<<"Esse trabalhador não consta na nossa base de dados";
                                cout<<"Clique em qualquer tecla e pressione ENTER para sair";
                                cin>>sair;
                            }
                        }
                        break;
                        case 2:
                            cout<<"Adeus";
                            sleep(2);
                            system("clear");
                        break;
                        default:
                            cout<<"Não existe essa resposta, leia atentamente."<<endl<<endl;
                        break;
                    }
                } else {
                    cout<<"Esse cliente não existe";
                }
            }
            //Cliente precisa cadastrar um serviço
        }
            break;
        case 6:{ //Listas de trabalhadores
           system("clear");
            string sair;
                listaTrabalhador.imprimir(listaTrabalhador);
            cout<<"Clique em qualquer tecla e pressione ENTER para sair";
            cin>>sair;
        }
            break;
        case 7: { //Lista de clientes
            system("clear");
           string sair;
               listaClientes.imprimir(listaClientes);
           cout<<"Clique em qualquer tecla e pressione ENTER para sair";
           cin>>sair;
        }
            break;
            case 8: {//Sair
            cout<<"Saindo...";
            opcao = 0;

            }
            break;
        default:
            cout << "Opção inválida.\n";
            break;
    }

    } while(opcao != 0);

    return 0;
}