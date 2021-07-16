#include "Aluno.hpp"

Aluno::Aluno(int matricula, string nome){
    this->matricula = matricula;
    this->nome = nome;
}

Aluno::Aluno(){}

int Aluno::get_matricula(){
    return this->matricula;
}

string Aluno::get_nome(){
    return this->nome;
}

void Aluno::set_matricula(int matricula){
    this->matricula = matricula;
}

void Aluno::set_nome(string nome){
    this->nome = nome;
}

void Aluno::imprimir_dados(){
    cout << this->get_matricula() << " " << this->get_nome() << endl;
}