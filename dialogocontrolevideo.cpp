#include "dialogocontrolevideo.h"
#include "ui_dialogocontrolevideo.h"

DialogoControleVideo::DialogoControleVideo(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::DialogoControleVideo)
{
    ui->setupUi(this);

    /*// inicio do carregamento de decoders de video

    QDir dir(QDir::currentPath() + debug + "/VideoPlugins"); // abre diretorio com filtros de legenda

    QStringList listaDeFiltros = dir.entryList(QDir::Filter::Files,QDir::SortFlag::NoSort); // cria lista de arquivos
                                                                                            // de decoders de video
    // fim do carregamento de decoders de video

    ui->selecaoTipoVideo->insertItems(0,listaDeFiltros); // adiciona itens ao menu de seleção do tipo de video
    */
}

DialogoControleVideo::~DialogoControleVideo()
{
    delete ui;
}

void DialogoControleVideo::on_botaoOk_clicked()
{
    close();
}

QString DialogoControleVideo::getPluginVideo(){
    QString retorno = ""; // armazena retono da função
    QString nomeDoPlugin = ui->selecaoTipoVideo->currentText();

    QFile file(QDir::currentPath() + debug + "/Functions/video.txt"); // caminho para o arquivo

    // Tenta abrir arquivo, caso não consiga, retorna uma string vazia
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        // le arquivo linha por linha ate o fim ou ate encontrar a linha desejada
        QTextStream in(&file);
        while (! in.atEnd() ) {
            QString line = in.readLine(); // le as linhas
            if(line.contains(nomeDoPlugin,Qt::CaseInsensitive)){
                retorno += in.readLine(); // pega nome da função
                break; // para execução
            }
            in.readLine(); // pula uma linha
        }
        file.close();
    }

    if(retorno.isEmpty()) // caso não encontre a função na lista, retorna erro
        retorno += "666error666";
    else if(retorno.contains("DirectShowSource",Qt::CaseInsensitive)) // caso Plugin de video seja "DirectShowSource",
        retorno = "";                                                 // retorna string vazia.
    else
        retorno = "LoadPlugin(\"" + QDir::currentPath() + debug + "/VideoPlugins/" + retorno + "\")";

    return retorno;
}

QString DialogoControleVideo::getFuncaoVideo(){
    return ui->selecaoTipoVideo->currentText();
}
