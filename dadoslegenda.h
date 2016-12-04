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
    DadosLegenda(QString nome, QString caminho, int tipo);

    void setNome(QString nome);
    void setCaminho(QString caminho);
    void setTipo(int tipo);
    QString getNome();
    QString getCaminho();
    int getTipo();

private:
    QString nome;
    QString caminho;
    int tipo;
};

#endif // DADOSLEGENDA_H
