#ifndef DIALOGOCONTROLELEGENDAS_H
#define DIALOGOCONTROLELEGENDAS_H

#include <QFrame>
#include "QStringListModel"
#include "dadoslegenda.h"

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

};

#endif // DIALOGOCONTROLELEGENDAS_H
