#include "dialogoeditarlegenda.h"
#include "ui_dialogoeditarlegenda.h"

DialogoEditarLegenda::DialogoEditarLegenda(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogoEditarLegenda)
{
    ui->setupUi(this);

    // inicio do carregamento de plugins de legenda

    QDir dir(QDir::currentPath() + debug + "/LegendaPlugins"); // abre diretorio com filtros de legenda

    QStringList caminhosFiltrosLegenda = dir.entryList(QDir::Filter::Files,QDir::SortFlag::NoSort); // cria lista de arquivos
                                                                                                    // de filtros de legenda
    // fim do carregamento de plugins de legenda

    ui->seleciocaoTipoLegenda->insertItems(0,caminhosFiltrosLegenda); // adiciona itens ao menu de seleção e filtro de legenda
}

DialogoEditarLegenda::~DialogoEditarLegenda()
{
    delete ui;
}

void DialogoEditarLegenda::on_buttonBox_accepted()
{
    // caso botao OK seja pressionado, salva alterações e fecha janela
    item.setCaminho(filePath); // seta caminho do arquivo
    item.setTipo(ui->seleciocaoTipoLegenda->currentText()); // seta tipo de plugin do arquivo
    QFileInfo info(filePath); // pega informações do arquivo selecionado
    item.setNome(info.fileName()); // seta nome do arquivo
    close();
}

void DialogoEditarLegenda::on_buttonBox_rejected()
{
    // caso botao cancelar seja pressionado, fecha sem mudar nada
    close();
}

// função para inicializar variaveis com valores a serem editados
void DialogoEditarLegenda::editItem(DadosLegenda i){
    ui->caixaCaminhoLegenda->setText(i.getCaminho()); // seta caminho na caixa de texto
    ui->seleciocaoTipoLegenda->setCurrentText(i.getTipo()); // seta tipo de legenda na lista
    item.setCaminho(i.getCaminho()); // adiciona caminho ao item
    item.setNome(i.getNome()); // adiciona nome ao item
    item.setTipo(i.getTipo()); // adiciona tipo ao item
    filePath = i.getCaminho(); // seta caminho para variavel filename
}

// função que retorna o item editado
DadosLegenda DialogoEditarLegenda::getEditedItem(){
    return item; // retorna item modificado
}

// função que abre dialogo para seleção de arquivo
void DialogoEditarLegenda::on_botaoAddLegenda_clicked()
{
    // linha abaixo pega caminho para arquivo de video de entrada
    filePath = QFileDialog::getOpenFileName(this, tr("Abrir ficheiro"), ui->caixaCaminhoLegenda->text(), tr("Arquivos de Vídeo (*.ass *.ssa *.srt)"));

    if(!filePath.isEmpty()){ // testa se caminho retornado é vazio, caso seja não muda nada na caixa de texto
        ui->caixaCaminhoLegenda->setText(filePath); // adiciona caminho para arquivo na caixa
        caminho = filePath;
    }
}
