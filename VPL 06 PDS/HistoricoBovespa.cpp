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
    if (cotacoes[sigla].empty()){
        cout << "esta sigla nao tem historico (max func)";
        return nullptr;
    }
    double maior = cotacoes[sigla][0].get_valor();
    Cotacao max_acao = cotacoes[sigla][0];
    for (Cotacao c : cotacoes[sigla]){
        if (c.get_valor() > maior){
            maior = c.get_valor();
            max_acao = c;
        }
    }
    return &max_acao;
}

Cotacao* HistoricoBovespa::recuperar_cotacao_minima_acao(string sigla){
    if (cotacoes[sigla].empty()){
        cout << "esta sigla nao tem historico (min func)";
        return nullptr;
    }
    double menor = cotacoes[sigla][0].get_valor();
    Cotacao min_acao = cotacoes[sigla][0];
    for (Cotacao c : cotacoes[sigla]){
        if (c.get_valor() < menor){
            menor = c.get_valor();
            min_acao = c;
        }
    }
    return &min_acao;
}

void HistoricoBovespa::imprimir_estatisticas_completas(){}