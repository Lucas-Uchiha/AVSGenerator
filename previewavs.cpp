#include "previewavs.h"
#include "ui_previewavs.h"

PreviewAVS::PreviewAVS(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreviewAVS)
{
    ui->setupUi(this);
}

PreviewAVS::~PreviewAVS()
{
    delete ui;
}

// função para adicionar texto ao editor de texto do pre-visualizador
void PreviewAVS:: setText(QString text){
    ui->pvTexto->document()->setPlainText(text);
}

void PreviewAVS::on_botaoOk_clicked()
{
    close(); // fecha janela
}
