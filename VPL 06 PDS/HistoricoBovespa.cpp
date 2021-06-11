#include "HistoricoBovespa.hpp"


HistoricoBovespa::HistoricoBovespa(){}

void HistoricoBovespa::inserir_cotacao(string sigla, string data, double valor){
    
    Cotacao cotacao(data, valor);
    vector<Cotacao> auxiliar;
    this->cotacoes[sigla].push_back(cotacao);
    int i = 0;
    for (Cotacao c : this->cotacoes[sigla]){
        auxiliar[i] = c;
        i++;
    }
    this->cotacoes.insert(pair<string, vector<Cotacao>>(sigla, auxiliar));
}

double HistoricoBovespa::calcular_valor_medio_acao(string sigla){
    double total = 0.0;
    for (Cotacao c : this->cotacoes[sigla]){
        total = total + c.get_valor();
    }
    return total/this->cotacoes[sigla].size();
}

bool ordena_por_valor(Cotacao a, Cotacao b){
    if (a.get_valor() < b.get_valor()){
        return true;
    }
    else {
        return false;
    }
}

Cotacao* HistoricoBovespa::recuperar_cotacao_maxima_acao(string sigla){
    sort(cotacoes[sigla].begin(), cotacoes[sigla].end(), ordena_por_valor);
    int n = cotacoes[sigla].end() - 1;
    return c;
}

Cotacao* HistoricoBovespa::recuperar_cotacao_minima_acao(string sigla){}

void HistoricoBovespa::imprimir_estatisticas_completas(){}