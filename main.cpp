#include<iostream>
#include "class.hpp"
using namespace std;

inline istream& operator>>(istream &in, Data &data){
    in >> data.dia >> data.mes >> data.ano;
    return in;
}

/*
RESUMO DE IMPLEMENTAÇÃO

- Menu quase pronto
- funções de verificação de trabalhador e cliente ativo implementadas
- Lista de clientes e trabalhadores prontas

O que falta:

- Finalizar a pagina de clientes e trabalhadores
- Clientes precisam poder abrir serviços 
- Trabalhadores podem visualizar todos os pedidos pendentes feitos para ele

*/

int main(){
    int opcao;
    do{
        colecaoTrabalhador listaTrabalhador;
        colecaoClientes listaClientes;
        system("clear");
        cout<<"Menu de opções"<<endl;
        cout<<"1. Cadastrar trabalhador"<<endl;
        cout<<"2. Pagina do trabalhador"<<endl;
        cout<<"3. Cadastrar cliente"<<endl;
        cout<<"4. Pagina do cliente"<<endl;
        cout<<"5. Listar trabalhadores"<<endl;
        cout<<"6. Listar clientes"<<endl;
        cout<<"7. Sair"<<endl;
        cout<<"Escolha uma opcao: "; cin>>opcao;

        switch (opcao) {
        case 1: {
            system("clear");
            string nomeT, telefoneT, habilidade;
            double valorHora;
            Data dataEscolhida;

            cout<<"Digite informações sobre o novo trabalhador abaixo"<<endl<<endl;
            cout<<"Nome: "; cin>>nomeT;
            cout<<"Telefone: "; cin>>telefoneT;
            cout<<"Digite a habilidade que ele vai ter: "; cin>>habilidade;
            cout<<"Valor da hora desse trabalhador: "; cin>>valorHora;
            cout<<"Dia que este trabalhador estara disponivel: (dd/mm/aaaa)"; cin>>dataEscolhida;

            Trabalhador novo(nomeT, telefoneT, habilidade, valorHora, dataEscolhida);
            listaTrabalhador.adicionaTrabalhador(listaTrabalhador, novo);
        }
            break; 
        case 2:{
            system("clear");
            if(listaTrabalhador.listavazia(listaTrabalhador) == false){
                string sair;
                cout<<"Lista vazia! Não há trabalhadores cadastrados."<<endl<<endl;
                cout<<"Clique em qualquer tecla e pressione ENTER para sair";
                cin>>sair;
            } else {
                string trabalhadorEscolhido;
                cout<<"Digite o nome do trabalhador que fará a operação:";
                cin>>trabalhadorEscolhido;
                if(listaTrabalhador.buscaCliente(listaTrabalhador, trabalhadorEscolhido) == true){
                    string sair;
                    cout<<"Trabalhador ativo"<<endl<<endl;
                    cout<<"Clique em qualquer tecla e pressione ENTER para sair";
                    cin>>sair;
                } else {
                    cout<<"Esse trabalhador não existe";
                }
            }
            //Trabalhador consegue visualizar pedidos apenas feitos para ele
            //pedidos aparecem como abertos, fechados ou em andamento
        }
            
            break;
        case 3:{
            system("clear");
            string nomeC, telefoneC;
            cout<<"Digite informações sobre o novo cliente abaixo"<<endl<<endl;
            cout<<"Nome: "; cin>>nomeC;
            cout<<"Telefone: "; cin>>telefoneC;

            Cliente novo(nomeC, telefoneC);
            listaClientes.adicionarCliente(listaClientes, novo);
            cout<<"Cliente cadastrado com sucesso!";
        }
            break;
        case 4:{
            system("clear");
            if(listaClientes.listavazia(listaClientes) == false){
                string sair;
                cout<<"Lista vazia! Não há clientes cadastrados."<<endl<<endl;
                cout<<"Clique em qualquer tecla e pressione ENTER para sair";
                cin>>sair;
            } else {
                string clienteEscolhido;
                cout<<"Digite o nome do cliente que fará a operação:";
                cin>>clienteEscolhido;
                if(listaClientes.buscaCliente(listaClientes, clienteEscolhido) == true){
                    string sair;
                    cout<<"Cliente ativo"<<endl<<endl;
                    cout<<"Clique em qualquer tecla e pressione ENTER para sair";
                    cin>>sair;
                } else {
                    cout<<"Esse cliente não existe";
                }
            }
            //Cliente precisa cadastrar um serviço
        }
            break;
        case 5:{
            system("clear");
            string sair;
                listaTrabalhador.imprimir(listaTrabalhador);
            cout<<"Clique em qualquer tecla e pressione ENTER para sair";
            cin>>sair;
        }
            break;
        case 6:{
            system("clear");
            string sair;
                listaClientes.imprimir(listaClientes);
            cout<<"Clique em qualquer tecla e pressione ENTER para sair";
            cin>>sair;
        }
            break;
        case 7:
            cout<<"Saindo...";
            opcao = 0;
            break;
        default:
            cout << "Opção inválida.\n";
            break;
    }

    } while(opcao != 0);

    return 0;
}