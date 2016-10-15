#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_selecaoVideo_clicked();

    void on_selecaoLegenda_clicked();

    void on_corte_clicked();

    void on_regras_clicked();

    void on_actionSobre_triggered();

    void on_actionConfigurar_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
