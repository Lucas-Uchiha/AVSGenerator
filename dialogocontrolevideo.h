#ifndef DIALOGOCONTROLEVIDEO_H
#define DIALOGOCONTROLEVIDEO_H

#include <QFrame>
#include <QFileDialog>
#include <QString>
#include <QTextStream>
#include "global.h"

namespace Ui {
class DialogoControleVideo;
}

class DialogoControleVideo : public QFrame
{
    Q_OBJECT

public:
    explicit DialogoControleVideo(QWidget *parent = 0);
    ~DialogoControleVideo();
    QString getFuncaoVideo(); // retorna nome da função para o plugin de video selecionado
    QString getPluginVideo(); // retorna plugin de video selecionado

private slots:
    void on_botaoOk_clicked();

private:
    Ui::DialogoControleVideo *ui;
};

#endif // DIALOGOCONTROLEVIDEO_H
