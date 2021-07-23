#ifndef AREAS_H
#define AREAS_H

#include <map>
#include <string>
#include <vector>
#include <iostream>

/**
 * \class AreaSet
 *
 * Esta classe armazena objetos que possuem um metodo getArea. Em outras
 * palavras, pode-se supor que qualquer objeto o armazenado em AreaSet possui
 * um metodo getArea(), sendo, portanto, possivel a chamada o.getArea().
 */
template <class T> class AreaSet {
  std::vector<T> areas;
  public:
    /**
     * \brief Metodo que adiciona um novo elemento a este conjunto de areas.
     */
    void add(T e) {
      // TODO: Implemente este metodo.
    }
    /**
     * \brief Reporta a area total de todos os objetos armazenados neste
     * conjunto.
     * Par obter a area total, eh necessario somar a area de todos os objetos
     * que foram adicionados ao conjunto via o metodo add. O metodo getArea()
     * pode ser invocado sobre esses objetos.
     */
    int getTotalArea() const {
      // TODO: Implemente este metodo.
    }
};

/**
 * \class Pais
 *
 * \brief Um pais eh um objeto com dois campos: nome e area.
 */
class Pais {
  std::string nome;
  int area;
  public:
    /**
     * O unico construtor de objetos paises recebe dois parametros. Esses
     * parametros possuem valores padrão. Assim, é possível criar objetos do
     * tipo Pais com construtores vazios. Em outras palavras, a declaracao
     * "Pais p;" compila, e cria um objeto com o nome "Brasil" e a area igual
     * a 8_515_767.
     */
    Pais(std::string n = "Brasil", int a=8515767): nome(n), area(a) {}
    /**
     * \brief informa a area armazenada no objeto.
     * \return um numero inteiro que denota a area do pais, em quilometros
     * quadrados.
     */
    int getArea() const {
      // TODO: Implemente este metodo.
    }
    /**
     * \brief informa nome do pais.
     */
    std::string getNome() const {
      // TODO: Implemente este metodo.
    }
    /**
     * \brief Operador de entrada de dados.
     *
     * Paises sao lidos como dois valores, separados por espaco em branco: um
     * nome e um inteiro denotando uma area. Como um exemplo, considere um
     * arquivo de texto chamado pais.txt, com o seguinte conteudo:
     * Brasil 8515000
     * Um programa que le um objeto pais deveria ser capaz de ler este arquivo.
     */
    friend std::istream &operator >> (std::istream &input, Pais &p) {
      input >> p.nome >> p.area;
      return input;
    }
    /**
     * \brief Operador de saida de dados. Paises sao impressos assim:
     * <nome> contem <area>km^2, sendo nome uma string, e area um inteiro.
     */
    friend std::ostream &operator << (std::ostream &output, Pais &p) {
      output << p.nome << " contem " << p.area << "km^2";
      return output;
    }
};

/**
 * \class Retangulo
 *
 * \brief Esta classe descreve retangulos. Retangulos sao objetos com dois
 * campos: um lado e uma altura, ambos inteiros.
 */
class Retangulo {
  int lado;
  int altura;
  public:
    /**
     * O unico construtor de objetos Retangulo recebe dois parametros inteiros:
     * lado e altura. Esses parametros possuem valores padrão. Na ausencia de
     * valores, o valor zero eh considerado.
     */
    Retangulo(int l=0, int a=0) {
      // TODO: Implemente o construtor.
    }
    int getArea() const {
      // TODO: Implemente este metodo.
      return 0;
    }
    /**
     * \brief Operador de leitura de dados. Retangulos sao lidos como dois
     * numeros em sequencia, separados por espaco(s). O primeiro numero eh o
     * valor do lado do retangulo, e o segundo numero eh o valor da altura.
     */
    friend std::istream &operator >> (std::istream &input, Retangulo &r) {
      // TODO: Implemente este metodo.
      return input;
    }
    /**
     * Operador de saida de dados. Retangulos sao impressos assim:
     * Rect(lado, altura), sendo lado e altura numeros inteiros.
     */
    friend std::ostream &operator << (std::ostream &output, Retangulo &r) {
      output << "Rect(" << r.lado << " * " << r.altura << ")";
      return output;
    }
};

/**
 * \class Imovel
 *
 * \brief Esta classe descreve imoveis. Imoveis sao formados por comodos.
 * Cada comodo eh armazenado a uma tabela, em que ele eh associado a um inteiro.
 * Esse inteiro denota a area do comodo, em metros quadrados.
 */
class Imovel {
  std::map<std::string, int> comodos; ///< Tabela de area de cada comodo.
  public:
    /**
     * \brief Informa a area total do imovel, somando as areas de cada um dos
     * comodos que esse imovel contem.
     */
    int getArea() const {
      // TODO: Implemente este metodo.
      return 0;
    }
    /**
     * Adiciona um novo comodo ao imovel. Um comodo eh formado por um nome e uma
     * area. Eh possivel que o imovel contenha comodos com nomes repetidos.
     * Nesse caso, numeros sao adicionados aos nomes de comodos, para fazer a
     * distincao entre eles.
     */
    void addComodo(std::string nomeComodo, int areaComodo) {
      unsigned int numComodos = comodos.size();
      std::string nomeChave = nomeComodo + "_" + std::to_string(numComodos);
      comodos[nomeChave] = areaComodo;
    }
    /**
     * Operador de leitura de dados. Um objeto imovel eh representado,
     * textualmente, com um numero de comodos, e uma sequencia de pares. Cada
     * par eh formado por um nome de comodo (uma string) e a area daquele
     * comodo. Por exemplo:
     * 4
     * quarto 18
     * cozinha 9
     * banheiro 5
     * sala 13
     */
    friend std::istream &operator >> (std::istream &input, Imovel &m) {
      int numComodos;
      input >> numComodos;
      for (int i = 0; i < numComodos; i++) {
        std::string nomeComodo;
        int areaComodo;
        input >> nomeComodo >> areaComodo;
        m.addComodo(nomeComodo, areaComodo);
      }
      return input;
    }
    /**
     * Operador de escrita de dados. Imoveis sao escritos como sequências de
     * nomes de comodos tabulados com suas areas. Por exemplo:
     * banheiro_2: 5
     * cozinha_1: 9
     * quarto_0: 18
     * sala_3: 13
     */
    friend std::ostream& operator << (std::ostream& output, const Imovel& im) {
      for (auto iter = im.comodos.begin(); iter != im.comodos.end(); ++iter) {
        output << iter->first << ": " << iter->second << std::endl;
      }
      return output;
    }
};

#endif