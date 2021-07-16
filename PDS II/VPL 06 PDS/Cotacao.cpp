#include "Cotacao.hpp"


Cotacao::Cotacao(std::string data, double valor){
    this->data = data;
    this->valor = valor;
}

std::string Cotacao::get_data(){
    return this->data;
}

double Cotacao::get_valor(){
    return this->valor;
}

void Cotacao::set_data(std::string data){
    this->data = data;
}
void Cotacao::set_valor(double valor){
    this->valor = valor;
}