#include "dialogoadicionarlegenda.h"
#include "ui_dialogoadicionarlegenda.h"

DialogoAdicionarLegenda::DialogoAdicionarLegenda(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogoAdicionarLegenda)
{
    ui->setupUi(this);
    ui->seleciocaoTipoLegenda->insertItems(0,caminhosFiltrosLegenda); // adiciona itens ao menu de seleção e filtro de legenda
}

DialogoAdicionarLegenda::~DialogoAdicionarLegenda()
{
    delete ui;
}

void DialogoAdicionarLegenda::on_buttonBox_accepted()
{
    // caso botao OK seja pressionado salva os dados e fecha a janela
    item.setCaminho(filePath); // seta caminho do arquivo
    item.setTipo(ui->seleciocaoTipoLegenda->currentText()); // seta tipo de plugin do arquivo
    QFileInfo info(filePath); // pega informações do arquivo selecionado
    item.setNome(info.fileName()); // seta nome do arquivo
    close();
}

void DialogoAdicionarLegenda::on_buttonBox_rejected()
{
    // caso botao cancelar seja pressionado, fecha a janela sem salvar dados
    close();
}

// função que abre dialogo de seleção de arquivo
void DialogoAdicionarLegenda::on_botaoAddLegenda_clicked()
{
    // linha abaixo pega caminho para arquivo de video de entrada
    filePath = QFileDialog::getOpenFileName(this, tr("Abrir ficheiro"), caminho, tr("Arquivos de Vídeo (*.ass *.ssa *.srt)"));

    if(!filePath.isEmpty()){ // testa se caminho retornado é vazio, caso seja não muda nada na caixa de texto
        ui->caixaCaminhoLegenda->setText(filePath); // adiciona caminho para arquivo na caixa
        caminho = filePath; // seta novo caminho padrao
    }
}

// função para retornar novo item
DadosLegenda DialogoAdicionarLegenda::getNewItem(){
    return item;
}
