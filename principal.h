#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include "dialogocomentarios.h"
#include "dialogocorte.h"
#include "dialogocontrolelegendas.h"
#include <QString>

namespace Ui {
class Principal;
}

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Principal(QWidget *parent = 0);
    ~Principal();

private slots:
    void on_botaoEdLegendas_clicked();

    void on_botaoEdComentarios_clicked();

    void on_actionEditar_Coment_rios_triggered();

    void on_botaoVideo_clicked();

    void on_botaoSaida_clicked();

    void on_botaoCorte_clicked();

    void on_actionCorte_triggered();

    void on_botaoPreview_clicked();

    void on_actionPr_Visualizar_triggered();

    QString geraDadosAvs();

    void on_actionEditar_Legendas_triggered();

private:
    Ui::Principal *ui;
    DialogoComentarios j; // cria dialogo de edição de comentarios
    DialogoCorte c; // cria dialogo de edição de corte
    DialogoControleLegendas l; // cria dialogo de edição de legendas
};

#endif // PRINCIPAL_H
