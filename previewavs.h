#ifndef PREVIEWAVS_H
#define PREVIEWAVS_H

#include <QDialog>

namespace Ui {
class PreviewAVS;
}

class PreviewAVS : public QDialog
{
    Q_OBJECT

public:
    explicit PreviewAVS(QWidget *parent = 0);
    ~PreviewAVS();
    void setText(QString text); // prototipo de função para setar texto do dialogo de pre-visualização

private slots:
    void on_botaoOk_clicked();

private:
    Ui::PreviewAVS *ui;
};

#endif // PREVIEWAVS_H
