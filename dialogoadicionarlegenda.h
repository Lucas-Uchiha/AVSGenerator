#ifndef DIALOGOADICIONARLEGENDA_H
#define DIALOGOADICIONARLEGENDA_H

#include <QDialog>
#include "dadoslegenda.h"

namespace Ui {
class DialogoAdicionarLegenda;
}

class DialogoAdicionarLegenda : public QDialog
{
    Q_OBJECT

public:
    explicit DialogoAdicionarLegenda(QWidget *parent = 0);
    ~DialogoAdicionarLegenda();
    DadosLegenda getNewItem(); // retorna novo item

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_botaoAddLegenda_clicked();

private:
    Ui::DialogoAdicionarLegenda *ui;
    DadosLegenda item; // item para ser retornado apos a seleção de uma legenda
    QString filePath; // caminho para arquivo selecionado
};

#endif // DIALOGOADICIONARLEGENDA_H
