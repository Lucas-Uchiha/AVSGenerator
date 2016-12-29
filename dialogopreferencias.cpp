#include "dialogopreferencias.h"
#include "ui_dialogopreferencias.h"

DialogoPreferencias::DialogoPreferencias(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::DialogoPreferencias)
{
    ui->setupUi(this);
}

DialogoPreferencias::~DialogoPreferencias()
{
    delete ui;
}

void DialogoPreferencias::on_botaoOK_clicked()
{
    close();
}
