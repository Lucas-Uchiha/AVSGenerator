#ifndef DIALOGOCONTROLELEGENDAS_H
#define DIALOGOCONTROLELEGENDAS_H

#include <QFrame>
#include "dadoslegenda.h"
#include "dialogoeditarlegenda.h"
#include "dialogoadicionarlegenda.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include "global.h"

namespace Ui {
class DialogoControleLegendas;
}

class DialogoControleLegendas : public QFrame
{
    Q_OBJECT

public:
    explicit DialogoControleLegendas(QWidget *parent = 0);
    ~DialogoControleLegendas();
    int posicao = 0; // salva posição atual no array
    QString getListOfPlugins(); // retorna lista de Plugins para o AVS
    QString getListOfLegendas(); // retorna lista de legendas para o AVS

private slots:
    void on_botaoAddLegenda_clicked();

    void on_botaoOK_clicked();

    void on_botaoEditaLegenda_clicked();

    void on_botaoRemoveLegenda_clicked();

    void on_botaoSubirLegenda_clicked();

    void on_botaoDescerLegenda_clicked();

private:
    Ui::DialogoControleLegendas *ui;
    DadosLegenda *dados; // armazena dados
    QString getFuncao(QString nomeDoTipo); // retorna nome da função a ser usada de acordo com o plugin carregado

};

#endif // DIALOGOCONTROLELEGENDAS_H
