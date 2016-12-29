#include "dialogosobre.h"
#include "ui_dialogosobre.h"

DialogoSobre::DialogoSobre(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::DialogoSobre)
{
    ui->setupUi(this);
}

DialogoSobre::~DialogoSobre()
{
    delete ui;
}

void DialogoSobre::on_pushButton_clicked()
{
    close();
}
