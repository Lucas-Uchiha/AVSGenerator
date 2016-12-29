#ifndef DIALOGOPREFERENCIAS_H
#define DIALOGOPREFERENCIAS_H

#include <QFrame>

namespace Ui {
class DialogoPreferencias;
}

class DialogoPreferencias : public QFrame
{
    Q_OBJECT

public:
    explicit DialogoPreferencias(QWidget *parent = 0);
    ~DialogoPreferencias();

private slots:
    void on_botaoOK_clicked();

private:
    Ui::DialogoPreferencias *ui;
};

#endif // DIALOGOPREFERENCIAS_H
