#include <iostream>
#include <string>

#include "ContadorDePalavras.hpp"


ContadorDePalavras::ContadorDePalavras(){
    _lista_de_palavras = {};
}


void ContadorDePalavras::Adicionar(string s){
    
    for (list<Palavra>::iterator it = _lista_de_palavras.begin(); it != _lista_de_palavras.end(); ++it){
        if (it->palavra() == s){
            it->Incrementar();            
            return;
        }
    
    }
    Palavra new_palavra = Palavra(s);
    _lista_de_palavras.insert(_lista_de_palavras.end(), new_palavra);
}


bool compara_palavras(Palavra& p1, Palavra& p2){
    return (p1.palavra() < p2.palavra());
};


list<Palavra> ordena_palavras(list<Palavra> lista){
    lista.sort(compara_palavras); 
    return lista;
}


void ContadorDePalavras::ImprimirOrdenado(){
    _lista_de_palavras = ordena_palavras(this->_lista_de_palavras);
    for (Palavra p : _lista_de_palavras){
        std::cout << p.palavra() << " " << p.ocorrencias() << "\n";
    }
}
