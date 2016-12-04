#include "dialogocomentarios.h"
#include "ui_dialogocomentarios.h"

DialogoComentarios::DialogoComentarios(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogoComentarios)
{
    ui->setupUi(this);
}

DialogoComentarios::~DialogoComentarios()
{
    delete ui;
}

void DialogoComentarios::on_buttonBox_accepted()
{
    oldText = ui->textoComentario->toPlainText(); // salva texto editado
    close(); // fecha janela
}

void DialogoComentarios::on_buttonBox_rejected()
{
    ui->textoComentario->setText(oldText); // restaura texto sem edição
    close(); // fecha janela
}

// retorna comentario
QString DialogoComentarios::getConteudo(){
    return ui->textoComentario->toPlainText();
}
