#ifndef LINE_PROCESSOR_H
#define LINE_PROCESSOR_H

#include <iostream>

/**
 * \class LineProcessor
 *
 * \brief Esta classe usa o padrao de projetos template para implementar um
 * algoritmo que processa linhas de texto da entrada padrao.
 */
class LineProcessor {

  private:

    std::istream &_in; ///< A entrada padrao de texto
    unsigned _numLinhasValidas; ///< O numero de linhas validas lidas
    // TODO: talvez voce queira declarar algum contador para contar o numero
    // de linhas lidas.

    unsigned _numLinhasLidas;

  public:

    /**
     * \brief Contrutor padrao que inicializa todas as variaveis privadas da
     * classe.
     */
    LineProcessor(): _in(std::cin), _numLinhasValidas(0) {
      // TODO: talvez voce queira inicializar algum contador para contar o
      // numero de linhas lidas.
      _numLinhasLidas = 0;
    }

    /**
     * \brief Destrutor virtual padrao. O destrutor virtual eh necessario, pois
     * esta classe, sendo abstrata, somente pode ser usada via heranca.
     */
    virtual ~LineProcessor() {}

    /**
     * \brief Determina se uma linha eh valida ou nao.
     * Este metodo deve ser implementado pela classe concreta. Cada classe
     * concreta pode usar um criterio diferente para verificar se uma linha eh
     * valida.
     * \param str a string que representa a linha de texto.
     */
    virtual bool linhaValida(const std::string &str) const = 0;

    /**
     * \brief Realiza o processamento de uma linha de texto.
     * \param str a string que representa a linha de texto.
     */
    virtual void processaLinha(const std::string &str) = 0;

    /**
     * \brief Algoritmo que processa as linhas validas da entrada.
     * Note que este algoritmo possui uma implementacao concreta (esta
     * implementacao que pode ser vista logo abaixo). Porem, seu comportamento
     * ainda eh abstrato, pois o algoritmo depende de dois metodos abstratos,
     * a saber, linha valida e processaLinha. Diferentes implementacoes desses
     * metodos vao levar a algoritmos concretos muito diferentes. Ainda assim,
     * o funcionamento do algoritmo eh sempre o mesmo: para cada linha,
     * verifica-se quais delas sao validas. As linhas validas sao entao
     * processadas.
     */
    void processaEntrada() {
      // TODO: voce terah de implementar algo para contar o numero de
      // linhas lidas.
      std::string linha;
      while (std::getline(_in, linha)) {
        if (linhaValida(linha)) {
          _numLinhasValidas++;
          processaLinha(linha);
        }
      }
    }

    /**
     * \brief Informa o numero de linhas validas encontradas durante o
     * processamento.
     */
    unsigned numeroDeLinhasValidas() const {
      return _numLinhasValidas;
    }

    /**
     * \brief Informa o numero total de linhas (validas ou nao) encontradas
     * durante o processamento.
     */
    unsigned numeroDeLinhasLidas() const {
      // TODO: Implemente este metodo. Provavelmente serah necessario modificar
      // a implementacao do metodo processaEntrada, para que voce possa contar
      // o numero de linhas lidas.
      return 0;
    }

};

/**
 * \class LinePrinter
 *
 * Esta classe imprime todas as linhas processadas.
 */
class LinePrinter: public LineProcessor {

  public:

    /**
     * Qualquer linha eh considerada valida:
     */
    bool linhaValida(const std::string &str) const override {
      return true;
    }

    /**
     * Imprime a linha recebida na saida padrao (std::cout).
     */
    void processaLinha(const std::string &str) override;
};

/**
 * \class ContadorPopRural
 *
 * Esta class le linhas contendo "nome_pais populacao porcentagem_urbana",
 * sendo:
 * populacao: numero natural que representa a quantidade de habitantes do pais.
 * porcentagem_urbana: numero natural que representa um arredondamento da
 * porcentagem da populacao que vive em cidades.
 */
class ContadorPopRural: public LineProcessor {

  public:

    /**
     * Somente linhas no formato: <nome> <int> <int> sao validas.
     * Exemplos de linhas validas:
     * Afganistao 38928346 25
     *    Afganistao         38928346     25
     *
     * Qualquer caracter nao alfa-numerico torna um nome invalido.
     * Exemplos de linhas invalidas:
     * Afganist&atilde;o 38928346 25
     * Estados Unidos 318562093 96   // (note o espaco entre Estados e Unidos)
     */
    bool linhaValida(const std::string &str) const override;

    /**
     * Para cada linha valida, deve-se imprimir a frase:
     * "XX pessoas vevem no campo no PP", sendo XX a quantidade (piso inferior)
     * de pessoas que vivem na zona rural no pais PP.
     *
     * Exemplos:
     * Afganistao 38928346 25  -->
     * 29196259 pessoas vivem no campo no Afganistao
     * EstadosUnidos 331002651 83  -->
     * 56270450 pessoas vivem no campo no EstadosUnidos
     */
    void processaLinha(const std::string &str) override;
};

/**
 * \class ContadorNumNaturais
 *
 * Esta classe imprime a soma dos numeros encontrados em linhas que contem
 * somente numeros.
 */
class ContadorNumNaturais: public LineProcessor {

  public:

    /**
     * Uma linha valida deve conter somente numeros naturais. Os numeros podem
     * ser seguidos ou precedidos por qualquer quantidade de espacos.
     * Exemplos de linhas validas:
     * 1
     * 1  2     4 8
     *       0 0 0         0
     *
     * Exemplos de linhas invalidas:
     * -1 1 2    // (note o sinal negativo)
     * 1 +1 0    // (note o sinal positivo)
     * Um 1 2
     * 1 2.      // (note o ponto no final da linha)
     */
    bool linhaValida(const std::string &str) const override;

    /**
     * Imprime a soma de cada linha valida.
     * Exemplo:
     * 1  -->  1
     * 1  2     4 8  -->  15
     *       0 0 0         0  -->  0
     */
    void processaLinha(const std::string &str) override;
};

/**
 * \class LeitorDeFutebol
 *
 * Esta classe le uma sequencia de resultados de jogos de futebol, e imprime o
 * vencedor de cada partida.
 */
class LeitorDeFutebol: public LineProcessor {

  public:

    /**
     * Linhas validas contem quatro campos: "time1 gols1 time2 gols2". Time1 e
     * time2 sao nomes de times (palavras somente com letras, sem espacos ou
     * caracteres especiais). Gols1 e gols2 sao numeros naturais, isto eh,
     * inteiros positivos (sem o sinal de adicao).
     *
     * Exemplos de linhas validas:
     * America 2000 Atletico 1
     * Cruzeiro 42 Atletico 3
     * VilaChurupitaFC 0 GalaoDasMacas 0
     *
     * Exemplos de linhas invalidas:
     * Sao Paulo 0 GalaoDasMacas 0   // (note o espaco entre Sao e Paulo)
     * Sao_Paulo 0 Galao 0           // (note o sublinha)
     */
    bool linhaValida(const std::string &str) const override;

    /**
     * Para cada linha, deve-se imprimir o time vencedor, ou a palavra
     * 'Empate' no caso de placar igual. Quando houver time vencedor, o nome
     * do time deve ser precedido pela palavra "Vencedor: ". Note o espaco.
     * Exemplos:
     *
     * America 2000 Atletico 1  -->  Vencedor: America
     * Cruzeiro 42 Atletico 3  -->  Vencedor: Cruzeiro
     * VilaChurupitaFC 0 GalaoDasMacas 0  -->  Empate
     */
    void processaLinha(const std::string &str) override;
};

/**
 * \class ContadorDePalavras
 *
 * Esta classe conta o numero de palavras em cada linha processada.
 */
class ContadorDePalavras: public LineProcessor {

  public:

    /**
     * Qualquer linha eh valida.
     */
    bool linhaValida(const std::string &str) const override {
      return true;
    }

    /**
     * Este metod imprime o numero de palavras encontrado em cada linha.
     * Uma palavra eh qualquer sequencia de simbolos que nao inclui um espaco em
     * branco.
     * Exemplos:
     * Uma palavra e meia palavra sao 1.5 palavras!!!  -->  8
     * 1 palavra e 2 palavras = 3 palavras, hihi...  -->  9
     */
    void processaLinha(const std::string &str) override;

  private:

    unsigned contaPalavras(const std::string &str);
};

/**
 * \class InversorDeFrases
 *
 * Esta classe inverte a ordem em que as palavras aparecem na sentenca de
 * entrada, caso a sentenca contenha somente palavras.
 */
class InversorDeFrases: public LineProcessor {

  public:

    /**
     * Linhas validas contem somente palavras, ou seja, letras (maiusculas ou
     * minusculas) e espacos (espacos em branco, tabs, returns, etc).
     *
     * Exemplos de linhas validas:
     * Duas galinhas botam ovos
     * a aAa aAaAa AAAA
     *
     * Exemplos de linhas invalidas
     * 2 galinhas botam ovos
     * a aAa aAaAa AAAA.
     */
    bool linhaValida(const std::string &str) const override;

    /**
     * Este metodo inverte a ordem em que as palavras aparecem na linha.
     * Exemplo:
     * Duas galinhas botam ovos  -->  ovos botam galinhas Duas
     * a aAa aAaAa AAAA  -->  AAAA aAaAa aAa a
     */
    void processaLinha(const std::string &str) override;
};

/**
 * \class EscritorDeDatas
 *
 * Esta classe reescreve datas no formato NN?/NN?/NNNN no formato NN?/MMM/NNNN,
 * onde MMM sao as tres primeiras letras dos meses do ano.
 */
class EscritorDeDatas: public LineProcessor {

  public:

    /**
     * Linhas validas possuem somente uma ocorrencia do padrao NN?/NN?/NNNN,
     * sendo cada N um digito, e sendo N? um digito opcional. Exemplos de linhas
     * validas:
     * 5/2/1982
     * 05/2/1982
     * 5/02/1982
     * 05/02/1982
     * Note que podem haver espacos antes do padrao. A seguinte linha eh valida:
     *          05/02/1982
     * Mas nao podem haver espacos entre as barras, ou outros caracteres na
     * linha. Assim, as seguintes linhas nao sao validas (veja o ponto na ultima
     * linha---o ponto torna a linha invalida):
     * 05/ 02/1982
     * 05/02 /1982
     * 05 /02 /1982
     * Data: 05/02/1982
     * 05/02/1982.
     */
    bool linhaValida(const std::string &str) const override;

    /**
     * Imprime a linha valida, porem com o valor do mes substituido pelas
     * iniciais do mes. Exemplos de saidas que
     * seriam produzidas:
     * 5/2/1982   ------->    Fev
     * 5/01/1982   ------->    Jan
     *
     * As iniciais sao:
     * "Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Ago", "Set", "Out",
     * "Nov", "Dez"
     */
    void processaLinha(const std::string &str) override;
};

#endif