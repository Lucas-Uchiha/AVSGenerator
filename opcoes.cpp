#include "opcoes.h"
#include "ui_opcoes.h"

Opcoes::Opcoes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Opcoes)
{
    ui->setupUi(this);
}

Opcoes::~Opcoes()
{
    delete ui;
}
