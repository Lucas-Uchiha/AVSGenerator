#include "dialogosobre.h"
#include "ui_dialogosobre.h"

DialogoSobre::DialogoSobre(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::DialogoSobre)
{
    ui->setupUi(this);
    ui->textoTitulo->setText(ui->textoTitulo->text().replace("#versao#",versao));
}

DialogoSobre::~DialogoSobre()
{
    delete ui;
}

void DialogoSobre::on_botaoOk_clicked()
{
    close();
}
