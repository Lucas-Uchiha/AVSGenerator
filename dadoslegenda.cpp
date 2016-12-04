#include "dadoslegenda.h"

DadosLegenda::DadosLegenda(){

}

DadosLegenda::DadosLegenda(QString nome, QString caminho, int tipo){
    this->nome = nome;
    this->caminho = caminho;
    this->tipo = tipo;
}

QString DadosLegenda::getNome(){
    return this->nome;
}

QString DadosLegenda::getCaminho(){
    return this->caminho;
}

int DadosLegenda::getTipo(){
    return this->tipo;
}

void DadosLegenda::setNome(QString nome){
    this->nome = nome;
}

void DadosLegenda::setCaminho(QString caminho){
    this->caminho = caminho;
}

void DadosLegenda::setTipo(int tipo){
    this->tipo = tipo;
}
