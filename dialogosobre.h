#ifndef DIALOGOSOBRE_H
#define DIALOGOSOBRE_H

#include <QFrame>

namespace Ui {
class DialogoSobre;
}

class DialogoSobre : public QFrame
{
    Q_OBJECT

public:
    explicit DialogoSobre(QWidget *parent = 0);
    ~DialogoSobre();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogoSobre *ui;
};

#endif // DIALOGOSOBRE_H
