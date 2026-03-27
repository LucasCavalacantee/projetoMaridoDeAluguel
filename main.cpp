#include<iostream>
using namespace std;

class Pessoa{
    string nome;
    string cpf;
    string telefone;
    string email;

    public:
    Pessoa(string nome, string cpf, string telefone, string email){
        this->nome = nome; 
        this->cpf = cpf;
        this->telefone = telefone;
        this->email = email;
    }

};

void Pessoa 
class habilidade{
    string nomeHabilidade;
    string descriçãoHabilidade;

    public:
    habilidade(string nome, string descrição){
        this->nomeHabilidade = nome;
        this->descriçãoHabilidade = descrição;
    }

};

class prestadorServiço : Pessoa{
    double valorHora;

    public:
    prestadorServiço(string nome, string cpf, string telefone, string email, double valorHora) : Pessoa(nome, cpf, telefone, email){
        this->valorHora = valorHora;
    }


};

class cliente : Pessoa{
    string escolha;

    public:
    cliente(string nome, string cpf, string telefone, string email, string escolha) : Pessoa(nome, cpf, telefone, email){
        this->escolha = escolha;
    }


};

int main(){


    return 0;
}