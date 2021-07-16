#ifndef HistoricoBovespa_HPP
#define HistoricoBovespa_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>
#include "Cotacao.hpp"

using namespace std;

struct HistoricoBovespa {

    // Atributo

    map<string, vector<Cotacao>> cotacoes;


    // Funções

    HistoricoBovespa();

    void inserir_cotacao(string sigla, string data, double valor);

    double calcular_valor_medio_acao(string sigla);

    Cotacao* recuperar_cotacao_maxima_acao(string sigla);

    Cotacao* recuperar_cotacao_minima_acao(string sigla);

    void imprimir_estatisticas_completas();

};

#endif