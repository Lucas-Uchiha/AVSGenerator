#ifndef DIALOGOCOMENTARIOS_H
#define DIALOGOCOMENTARIOS_H

#include <QDialog>

namespace Ui {
class DialogoComentarios;
}

class DialogoComentarios : public QDialog
{
    Q_OBJECT

public:
    explicit DialogoComentarios(QWidget *parent = 0);
    ~DialogoComentarios();
    QString getConteudo();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::DialogoComentarios *ui;
    QString oldText; // armazena texto anterior a edição
};

#endif // DIALOGOCOMENTARIOS_H
