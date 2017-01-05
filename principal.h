#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include "dialogocomentarios.h"
#include "dialogocorte.h"
#include "dialogocontrolelegendas.h"
#include "dialogopreferencias.h"
#include "dialogosobre.h"
#include "dialogocontrolevideo.h"
#include "previewavs.h"
#include "global.h"
#include <QString>
#include <QFileDialog>

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

    void on_ativarEdLegendas_stateChanged(int arg1);

    void on_ativarEdComentarios_stateChanged(int arg1);

    void on_ativarCorte_stateChanged(int arg1);

    void on_actionPrefer_ncias_triggered();

    void on_actionSobre_triggered();

    void on_botaoGerarAVS_clicked();

    void on_botaoEdVideo_clicked();

    void on_actionEditar_Video_triggered();

    void on_actionSair_triggered();

private:
    Ui::Principal *ui;
    DialogoComentarios j; // cria dialogo de edição de comentarios
    DialogoCorte c; // cria dialogo de edição de corte
    DialogoControleLegendas l; // cria dialogo de edição de legendas
    DialogoPreferencias p; // cria dialogo para edição de preferencias do programa
    DialogoSobre s; // cria dialogo com informações sobre o programa
    DialogoControleVideo v; // cria dialogo de edição de vídeo
};

#endif // PRINCIPAL_H
