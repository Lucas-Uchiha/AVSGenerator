#ifndef DIALOGOEDITARLEGENDA_H
#define DIALOGOEDITARLEGENDA_H

#include <QDialog>
#include "dadoslegenda.h"
#include <QFileDialog>
#include "global.h"

namespace Ui {
class DialogoEditarLegenda;
}

class DialogoEditarLegenda : public QDialog
{
    Q_OBJECT

public:
    explicit DialogoEditarLegenda(QWidget *parent = 0);
    ~DialogoEditarLegenda();
    void editItem(DadosLegenda i); // seta valores do dialogo de edição
    DadosLegenda getEditedItem(); // retorna item editado

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_botaoAddLegenda_clicked();

private:
    Ui::DialogoEditarLegenda *ui;
    DadosLegenda item; // item a ser retornado apos edição
    QString filePath; // caminho do arquivo selecionado
};

#endif // DIALOGOEDITARLEGENDA_H
