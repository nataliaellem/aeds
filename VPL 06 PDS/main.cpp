
// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_bovespa.hpp"

using namespace std;

int main() {
  
    // NÃO ALTERE ESSA LINHA
    avaliacao_basica();


    
    HistoricoBovespa historico;
    for (int i = 0; i < 12; i++){

        string sigla, data;
        double valor;

        cin >> sigla;
        cin >> data;
        cin >> valor; 

        historico.inserir_cotacao(sigla, data, valor);
    }


    historico.imprimir_estatisticas_completas();
    

    return 0;
}