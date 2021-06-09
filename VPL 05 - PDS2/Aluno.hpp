#ifndef ALUNO_HPP
#define ALUNO_HPP

#include <iostream>
#include <string>

using namespace std;

struct Aluno {

    // Atributos

    int matricula;
    string nome;

    // Construtor

    Aluno(int matricula, string nome);
    Aluno();

    // Getters

    int get_matricula();
    string get_nome();

    // Setters

    void set_matricula(int matricula);
    void set_nome(string nome);

    void imprimir_dados();
};

#endif