#ifndef COTACAO_HPP
#define COTACAO_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>

struct Cotacao {

    std::string data;
    double valor;

    Cotacao(std::string data, double valor);

    // Getters and Setters

    std::string get_data();

    double get_valor();

    void set_data(std::string data);
    void set_valor(double valor);

};


#endif