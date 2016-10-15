#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QFileDialog>
#include <sobre.h>
#include <opcoes.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
        ui->setupUi(this);
    }

MainWindow::~MainWindow(){
    delete ui;
}

// Abre janela para seleção de arquivo de vídeo
void MainWindow::on_selecaoVideo_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Abrir ficheiro"), "/home/Documentos/", tr("Arquivos de Vídeo (*.mkv *.avi *.mp4)"));
    ui->caminhoVideo->setText(filename);
}

// Abre janela para seleção de arquivo de legenda
void MainWindow::on_selecaoLegenda_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Abrir ficheiro"), "/home/Documentos/", tr("Arquivos de Legenda (*.ass *.ssa *.srt)"));
    ui->caminhoLegenda->setText(filename);
}

// Se selecionado, habilita controles de corte de video
void MainWindow::on_corte_clicked()
{
    if(ui->corte->isChecked()){
        ui->corteFim->setEnabled(true);
        ui->corteInicio->setEnabled(true);
    }
    else{
        ui->corteFim->setEnabled(false);
        ui->corteInicio->setEnabled(false);
    }
}

// Se selecionado, habilita inserção de texto com regras adicionais ao arquivo
void MainWindow::on_regras_clicked()
{
    if(ui->regras->isChecked())
        ui->regrasTexto->setEnabled(true);
    else
        ui->regrasTexto->setEnabled(false);
}

// Chama janela com informações
void MainWindow::on_actionSobre_triggered()
{
    Sobre s;
    s.exec();
}

// Chama janela de opções
void MainWindow::on_actionConfigurar_triggered()
{
    Opcoes o;
    o.exec();
}
