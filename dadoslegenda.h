#ifndef DADOSLEGENDA_H
#define DADOSLEGENDA_H
#include <QString>
/*
 * Esta classe armazena dados das legendas carregadas pelo usuário
 */
class DadosLegenda
{
public:
    DadosLegenda();
    DadosLegenda(QString nome, QString caminho, QString tipo);

    void setNome(QString nome);
    void setCaminho(QString caminho);
    void setTipo(QString tipo);
    QString getNome();
    QString getCaminho();
    QString getTipo();

private:
    QString nome;
    QString caminho;
    QString tipo;
};

#endif // DADOSLEGENDA_H
