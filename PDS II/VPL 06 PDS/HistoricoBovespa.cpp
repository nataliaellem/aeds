#include "HistoricoBovespa.hpp"


HistoricoBovespa::HistoricoBovespa(){}

void HistoricoBovespa::inserir_cotacao(string sigla, string data, double valor){

    Cotacao cotacao(data, valor);
    vector<Cotacao> auxiliar;
    this->cotacoes[sigla].push_back(cotacao);
    for (Cotacao c : this->cotacoes[sigla]){
        auxiliar.push_back(c);
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
   
    Cotacao *max_acao = new Cotacao(cotacoes[sigla][0].get_data(), cotacoes[sigla][0].get_valor());

    for (Cotacao c : cotacoes[sigla]){
        if (c.get_valor() > maior){
            maior = c.get_valor();
            max_acao->set_data(c.get_data());
            max_acao->set_valor(c.get_valor());
        }
    }
    
    return max_acao;
}

Cotacao* HistoricoBovespa::recuperar_cotacao_minima_acao(string sigla){
    if (cotacoes[sigla].empty()){
        cout << "esta sigla nao tem historico (min func)";
        return nullptr;
    }
    double menor = cotacoes[sigla][0].get_valor();
    Cotacao *min_acao = new Cotacao(cotacoes[sigla][0].get_data(), cotacoes[sigla][0].get_valor());
   
    for (Cotacao c : cotacoes[sigla]){
        if (c.get_valor() < menor){
            menor = c.get_valor();
            min_acao->set_data(c.get_data());
            min_acao->set_valor(c.get_valor());
        }
    }
    return min_acao;
}

void HistoricoBovespa::imprimir_estatisticas_completas(){
    
    map<string, vector<Cotacao>>::iterator it;

    for (it = this->cotacoes.begin(); it != cotacoes.end(); it++){
        cout << it->first << " ";
        for(Cotacao c : it->second){
            cout << c.get_valor() << " ";
        }
        cout << "| " << recuperar_cotacao_minima_acao(it->first)->get_valor() << " ";
        cout << recuperar_cotacao_maxima_acao(it->first)->get_valor() << " ";
        cout << calcular_valor_medio_acao(it->first);
        cout << endl;
    }
}