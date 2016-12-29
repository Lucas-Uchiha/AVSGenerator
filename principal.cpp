#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Principal)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("Bem-vindo!",5000);

}

Principal::~Principal()
{
    delete ui;
}

void Principal::on_botaoEdLegendas_clicked()
{
    this->l.show(); // exibe editor de legendas
}

void Principal::on_botaoEdComentarios_clicked()
{
    this->j.exec(); // exibe editor de comentarios
}

void Principal::on_actionEditar_Coment_rios_triggered()
{
    on_botaoEdComentarios_clicked(); // chama dialogo editor de comentarios para ser exibido
}

void Principal::on_botaoVideo_clicked()
{
    // linha abaixo pega caminho para arquivo de video de entrada
    QString filePath = QFileDialog::getOpenFileName(this, tr("Abrir ficheiro"), caminho, tr("Arquivos de Vídeo (*.mkv *.avi *.mp4)"));

    if(!filePath.isEmpty()){ // testa se caminho retornado é vazio, caso seja não muda nada na caixa de texto
        ui->caixaVideo->setText(filePath); // adiciona caminho para arquivo na caixa
        ui->caixaSaida->setText( filePath.left( filePath.size() - 4 ) + "-AVS.avs" ); // cria caminho para arquivo avs
        caminho = filePath;
    }

}

void Principal::on_botaoSaida_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, tr("Salvar arquivo"), caminho, tr("Arquivos AVS (*.avs)"));
    if(!filePath.isEmpty()){
        ui->caixaSaida->setText(filePath); // salva caminho de saida para arquivo avs caso algum tenha sido selecionado
        caminho = filePath;
    }
}

void Principal::on_botaoCorte_clicked()
{
    this->c.exec(); // exibe dialogo de corte de video
}

void Principal::on_actionCorte_triggered()
{
    on_botaoCorte_clicked(); // chama dialogo de corte de video para ser exibido
}

void Principal::on_botaoPreview_clicked()
{
    PreviewAVS p; // cria dialogo de pre-visualização
    p.setText( geraDadosAvs() ); // adiciona texto ao dialogo
    p.exec(); // exibe o dialogo
}

void Principal::on_actionPr_Visualizar_triggered()
{
    on_botaoPreview_clicked(); // chama dialogo de pre-visualização para ser exibido
}

QString Principal::geraDadosAvs(){

    QString texto; // cria texto do preview
    texto = "# AVSGenerator versão: 0.0.0" // colocar aqui variavel de controle de versão
            "\n\n";

    texto +=
           "# Plugins carregados:"
           "\n"
           "    LoadPlugin(ffms2)";

    // Caso legendas estejam habilitadas, carrega plugins de legenda
    if(ui->ativarEdLegendas->isChecked()){

           texto +=
           "\n"
           "    " + l.getListOfPlugins().replace('\n', "\n   "); // pega lista de plugins de legenda
    }

    texto +=
           "\n\n"
           "# Arquivos de Vídeo / Áudio carregados:"
           "\n"
           "    Aud = FFAudioSource('" + ui->caixaVideo->text() + "')"
           "\n"
           "    Vid = FFVideoSource('" + ui->caixaVideo->text() + "')"
           "\n"
           "    AudioDub(vid,aud)"
           "\n\n";

    // Caso legendas estejam habilitadas, carrega as legendas
    if(ui->ativarEdLegendas->isChecked()){
           texto +=
           "# Arquivos de legenda carregados:"
           "\n"
           "    " + l.getListOfLegendas().replace('\n', "\n    "); // pega lista de plugins de legenda
    }

    // Caso corte de vídeo esteja habilitado, insere comando e tempos de corte
    if(ui->ativarCorte->isChecked()){
           texto +=
           "# Corte de Vídeo / Áudio:"
           "\n"
           "    Trim(" + QString::number(c.getInicio()) + "," + QString::number(c.getFim()) + ")"
           "\n\n";
    }

    // Caso comentários estejam habilitadas, insere comentários
    if(ui->ativarEdComentarios->isChecked()){

        QString comentario = j.getConteudo(); // pega comentarios

        if(! comentario.isEmpty()){
            comentario.insert(0, '#'); // insere # na primeira linha
            comentario.replace('\n', "\n    #"); // insere tabulação e # nas demais linhas
        }

        texto +=
               "#Comentários:"
               "\n"
               "    " + comentario;
    }

    return texto;
}

void Principal::on_actionEditar_Legendas_triggered()
{
    on_botaoEdLegendas_clicked(); // chama dialogo de edição de legendas para ser exibido
}

void Principal::on_ativarEdLegendas_stateChanged(int arg1)
{
    if(arg1)
        ui->botaoEdLegendas->setDisabled(false);
    else
        ui->botaoEdLegendas->setDisabled(true);
}

void Principal::on_ativarEdComentarios_stateChanged(int arg1)
{
    if(arg1)
        ui->botaoEdComentarios->setDisabled(false);
    else
        ui->botaoEdComentarios->setDisabled(true);
}

void Principal::on_ativarCorte_stateChanged(int arg1)
{
    if(arg1)
        ui->botaoCorte->setDisabled(false);
    else
        ui->botaoCorte->setDisabled(true);
}

void Principal::on_actionPrefer_ncias_triggered()
{
    p.show(); // exibe dialogo para edição de preferencias
}

void Principal::on_actionSobre_triggered()
{
    s.show(); // exibe dialogo com informações do programa
}

void Principal::on_botaoGerarAVS_clicked()
{
    ui->statusBar->showMessage("Gerando...",0);
    ui->progressBar->setValue(0);

    // fazer as paradas aqui

    ui->progressBar->setValue(100);
    ui->statusBar->showMessage("Gerado com sucesso!",4000);
    ui->progressBar->setValue(0);
}
