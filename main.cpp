#include<iostream>
using namespace std;
#define TAM 10

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

class empregado : Pessoa{
    double valorHora;
    string habilidade;
    
    public:
    empregado(string nome, string telefone, string habilidade, double valorHora) : Pessoa(nome, telefone){
        this->valorHora = valorHora;
        this->habilidade = habilidade;
    }
    
    void imprime(){
        Pessoa:: imprime();
        cout<<habilidade<<", "<<valorHora<<endl;
    }
};

class cliente : Pessoa{
    string escolhaPrestador;
    
    public:
    cliente(string nome, string telefone, string escolhaPrestador) : Pessoa(nome, telefone){
        this->escolhaPrestador = escolhaPrestador;
    }
    
    void imprime(){
        Pessoa:: imprime();
        cout<<"Escolheu o prestador: "<<escolhaPrestador;
    }
};

class colecaoEmpregado{
    empregado empregados[TAM];

    public:

};

int main(){
    cout<<"Prestador: "<<endl;
    empregado a1("Lucas", "69993352047", "Engenheiro", 100.0);
    a1.imprime();

    cout<<endl;
    cout<<"Cliente: "<<endl;
    cliente b1("jorge", "4588865632", "Lucas");
    b1.imprime();
    return 0;
}