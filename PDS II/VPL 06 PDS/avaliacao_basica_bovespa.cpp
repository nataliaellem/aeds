#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>

#include "Cotacao.hpp"
#include "HistoricoBovespa.hpp"
#include "avaliacao_basica_bovespa.hpp"

using namespace std;

void avaliacao_basica() {
    
    HistoricoBovespa historico;

    historico.inserir_cotacao("XYZ", "01/01/2020", 10.0);
    historico.inserir_cotacao("XYZ", "02/02/2020", 20.0);
    historico.inserir_cotacao("XYZ", "03/03/2020", 30.0);

    historico.inserir_cotacao("ABC", "04/04/2020", 40.0);

    cout << fixed << showpoint; 
    cout << setprecision(2);

    historico.imprimir_estatisticas_completas();


    // XYZ
    Cotacao* min1 = historico.recuperar_cotacao_minima_acao("XYZ");
    Cotacao* max1 = historico.recuperar_cotacao_maxima_acao("XYZ");
    double avg1 = historico.calcular_valor_medio_acao("XYZ");

    cout << "XYZ min" << " " << min1->get_valor() << endl;
    cout << "XYZ max" << " " << max1->get_valor() << endl; 

    cout << "XYZ" << " " << avg1 << endl;
    cout << min1->get_data() << " "; 
    cout << min1->get_valor() << " " << max1->get_data() << " " << max1->get_valor() << endl;

    // ABC
    Cotacao* min2 = historico.recuperar_cotacao_minima_acao("ABC");
    Cotacao* max2 = historico.recuperar_cotacao_maxima_acao("ABC");
    double avg2 = historico.calcular_valor_medio_acao("ABC");
    cout << "ABC" << " " << avg2 << endl;
    cout << min2->get_data() << " " << min2->get_valor() << " " << max2->get_data() << " " << max2->get_valor() << endl;

    cout << "---------------" << endl;

    //historico.imprimir_estatisticas_completas();
}