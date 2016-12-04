#include "dialogocorte.h"
#include "ui_dialogocorte.h"
#include <QMessageBox>
#include <iostream>

DialogoCorte::DialogoCorte(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogoCorte)
{
    ui->setupUi(this);
}

DialogoCorte::~DialogoCorte()
{
    delete ui;
}

// zera tempos de corte
void DialogoCorte::on_botaoCorteZerar_clicked()
{
    ui->corteInicio->setValue(0);
    ui->corteFim->setValue(0);
}

// salva valores de corte
void DialogoCorte::on_buttonBox_accepted()
{
    /* caso valor do tempo final seja menor que o inicial,
     * exibe menssagem de erro e não salva valores ate que o problema seja resolvido.
     */
    if(ui->corteFim->value() < ui->corteInicio->value()){
        QMessageBox msgBox; // cria caixa de mensagem
        msgBox.setWindowTitle("Erro"); // seta titulo da caixa de menssagem
        msgBox.setText("Erro ao salvar tempos de corte."); // seta texto da caixa de mensagem
        msgBox.setInformativeText("O tempo final não pode ser menor do que o tempo inicial."); // seta descrição da caixa de mensagem
        msgBox.exec(); // exibe caixa de mensagem
    }
    else{
        inicio = ui->corteInicio->value(); // salva valor de corte inicial
        fim = ui->corteFim->value(); // salva valor de corte final
        close(); // fecha janela
    }
}

void DialogoCorte::on_buttonBox_rejected()
{
    ui->corteInicio->setValue(inicio); // restaura valor inicial anterior
    ui->corteFim->setValue(fim); // restaura valor final anterior
    close(); // fecha janela
}

// retorna valor de inicial de corte
int DialogoCorte::getInicio(){
    return inicio;
}

// retorna valor final de corte
int DialogoCorte::getFim(){
    return fim;
}
