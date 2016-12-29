#ifndef DIALOGOCORTE_H
#define DIALOGOCORTE_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class DialogoCorte;
}

class DialogoCorte : public QDialog
{
    Q_OBJECT

public:
    explicit DialogoCorte(QWidget *parent = 0);
    ~DialogoCorte();
    int getInicio();
    int getFim();

private slots:
    void on_botaoCorteZerar_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::DialogoCorte *ui;
    int inicio = 0,fim = 0; // tempo de corte inicial e fim
};

#endif // DIALOGOCORTE_H
