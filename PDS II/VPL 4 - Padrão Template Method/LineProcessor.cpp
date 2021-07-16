#include <regex>
#include <math.h>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>


#include "LineProcessor.hpp"

void LinePrinter::processaLinha(const std::string &str) {
  std::cout << str << std::endl;
}

bool ContadorPopRural::linhaValida(const std::string &str) const {
  // Neste exemplo usaremos expressoes regulares para verificar se uma linha
  // eh valida ou nao.
  //
  // Esta expressao regular eh formada por cinco partes. Cada uma dessas
  // partes eh um dos tres tipos de padrao regular abaixo:
  //
  // \\w+ eh qualquer palavra com um ou mais digitos, letras e sublinhas (_)
  // \\s* eh qualquer sequencia de zero ou mais espacos (inclui tab)
  // \\d+ eh qualquer sequencia de um ou mais digitos
  std::regex regularExpr("\\w+\\s*\\d+\\s*\\d+");

  // A funcao regex_match vai retornar verdadeiro se a string str casa-se com
  // a expressao regular que acabamos de criar:
  return std::regex_match(str, regularExpr);
}

void ContadorPopRural::processaLinha(const std::string &str) {
  //
  // Em geral eh mais facil ler dados de uma string se a string eh transformada
  // em um objeto do tipo stringstream:
  std::stringstream ss(str);
  //
  // Iremos ler os dados da string nestas tres variaveis abaixo:
  std::string nomePais;
  unsigned populacao, percUrbana;
  //
  // Como sabemos que a linha contem string int int, podemos fazer a leitura
  // facilmente usando o operador de streaming:
  ss >> nomePais >> populacao >> percUrbana;
  //
  // Note que precisamos arredondar o valor que serah impresso. O arredondamento
  // serah feito via a funcao floor. Ou seja, decimais serao sempre
  // arredondados para baixo:
  unsigned popRural = floor(populacao - (populacao * (percUrbana/100.0)));
  //
  // Uma vez encontrados os valores que precisam ser impressos, seguimos o
  // modelo do enunciado do exercicio:
  std::cout << popRural << " pessoas vivem no campo no " << nomePais <<
    std::endl;
}

bool ContadorNumNaturais::linhaValida(const std::string &str) const {
  // TODO: Implemente este metodo
  
  std::regex regularExp("\\d+\\s*");
  return std::regex_match(str, regularExp);
  
}

void ContadorNumNaturais::processaLinha(const std::string &str) {

 /* int somador = 0;
  std::stringstream ss(str);
	while (! ss.eof()){
		int aux;
		ss >> aux; 
		somador += aux;
	} 
  std::cout << somador << std::endl; */
}

bool LeitorDeFutebol::linhaValida(const std::string &str) const {
  // TODO: Implemente este metodo
	std::regex regularExp("\\w+\\s*\\d+\\s*\\w+\\s*\\d+");
	return std::regex_match(str, regularExp);
}

void LeitorDeFutebol::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
	std::stringstream ss(str);
	while (! ss.eof()){
		std::string time1, time2;
		int pontos_t1, pontos_t2;
		ss >> time1 >> pontos_t1 >> time2 >> pontos_t2;

		if (pontos_t1 > pontos_t2){
	  	std::cout << "Vencedor: " << time1 << std::endl;
		}
		else if (pontos_t2 > pontos_t1){
	  	std::cout << "Vencedor: " << time2 << std::endl;
		}
		else if (pontos_t1 == pontos_t2){
			std::cout << "Empate" << std::endl;
		}
	}
}

void ContadorDePalavras::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
	std::stringstream ss(str);
	int contador = 0;
	while (! ss.eof()){
		std::string palavra;
		ss >> palavra;
		contador++;
	}
  std::cout << contador << std::endl;
}

bool InversorDeFrases::linhaValida(const std::string &str) const {
  std::regex regExp("[A-Za-z ]+");
  return std::regex_match(str, regExp);
}

void InversorDeFrases::processaLinha(const std::string &str) {

  std::vector <std::string> palavras{};
	std::string s = str;
  
  std::string space = " ";
	size_t pos;
	while ((pos = s.find(space)) != std::string::npos) {
		palavras.push_back(s.substr(0, pos));
		s.erase(0, pos + space.length());
	}

  for (int i = palavras.size() - 1; i >= 0; i--){
  	std::cout << palavras[i] << " ";
  }
	std::cout << std::endl;
}

bool EscritorDeDatas::linhaValida(const std::string &str) const {
  	std::string dateFormat = "\\s*\\d\\d?/\\d\\d?/\\d{4}";
	std::regex regularExp(dateFormat);
	return std::regex_match(str, regularExp);
}


// função auxiliar

std::string retornaMes(char c){
	std::string mes;
	switch (c) {
		case '1':
			mes = "Jan";
			break;
		case '2':
			mes = "Fev";
			break;
		case '3':
			mes = "Mar";
			break;
		case '4':
			mes = "Abr";
			break;
		case '5':
			mes = "Mai";
			break;
		case '6':
			mes = "Jun";
			break;
		case '7':
			mes = "Jul";
			break;
		case '8':
			mes = "Ago";
			break;
		case '9':
			mes = "Set";
			break;
		default:
			break;
	}
	return mes;

}

void EscritorDeDatas::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  // Lembre-se que as iniciais dos meses sao:
  // "Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Ago", "Set", "Out",
  // "Nov", e "Dez".
	std::string mes;
	for (int i = 0; i < str.size(); i++){
		//Quando chegar na primeira barra significa que o(s) próximo(s)
		//dígitos serão do mes
		if (str[i] == '/'){
			if (str[i+1] == '0'){
				mes = retornaMes(str[i+2]);
			}
			else if (str[i+1] != '0' && str[i+2] == '/'){
				mes = retornaMes(str[i+1]);
			}

			// Caso seja um dos meses: 10, 11 e 12
			else if (str[i+1] != '0' && str[i+2] != '/') {
				if (str[i+2] == '0'){
					mes = "Out";
				}
				else if (str[i+2] == '1'){
					mes = "Nov";
				}
				else if (str[i+2] == '2'){
					mes = "Dez";
				}
			}
  		std::cout << mes << std::endl;
		return; 
		}
	}

}