#include<iostream>
using namespace std;

struct Data{
    int dia = 0, mes = 0, ano = 0;
};

inline std::ostream& operator<<(std::ostream &on, Data &data){
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
