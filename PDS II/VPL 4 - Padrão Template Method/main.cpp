/**
 * Este arquivo contem testes para o VPL. Ele nao deve ser modificado em
 * hipotese alguma. Voce pode usa-lo para testar seu VPL localmente.
 */
#include "LineProcessor.hpp"

void testaProcessaEntrada() {
  LineProcessor *lp = new LinePrinter();
  lp->processaEntrada();
}

int leTipoDoTeste() {
  std::string linha;
  std::getline(std::cin, linha);
  return std::stoi(linha);
}

int main() {
  LineProcessor *lp;
  unsigned tipoDoTeste = leTipoDoTeste();
  switch (tipoDoTeste) {
    case 1:
      lp = new ContadorPopRural();
      break;
    case 2:
      lp = new ContadorNumNaturais();
      break;
    case 3:
      lp = new LeitorDeFutebol();
      break;
    case 4:
      lp = new ContadorDePalavras();
      break;
    case 5:
      lp = new InversorDeFrases();
      break;
    case 6:
      lp = new EscritorDeDatas();
      break;
    default:
      lp = new LinePrinter();
  }
  lp->processaEntrada();
  std::cout << "Linhas lidas: " << lp->numeroDeLinhasLidas() << std::endl;
  std::cout << "Linhas validas: " << lp->numeroDeLinhasValidas() << std::endl;
}