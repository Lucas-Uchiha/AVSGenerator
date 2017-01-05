#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Principal)
{
    ui->setupUi(this);
    this->setWindowTitle("AVSGenerator - " + versao); // seta titulo da janela principal
    ui->statusBar->showMessage("Bem-vindo!",5000); // exibe mensagem de boas vindas na barra de status

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

    /* Checa se algum arquivo de vídeo foi selecionado.
     * Caso não tenha sido, as funcionalidades:
     *
     * - Gerar AVS
     * - Pre-visualizar AVS
     * - Selecionar arquivo de saida
     * - Visualizar caminho do arquivo de saida
     *
     * são desabilitadas.
     * Caso contrario, as mesmas são habilitadas.
     */

    if(ui->caixaVideo->text().isEmpty()){
        ui->caixaSaida->setEnabled(false);
        ui->botaoSaida->setEnabled(false);
        ui->botaoPreview->setEnabled(false);
        ui->botaoGerarAVS->setEnabled(false);
        ui->actionPr_Visualizar->setEnabled(false);
    }
    else{
        ui->caixaSaida->setEnabled(true);
        ui->botaoSaida->setEnabled(true);
        ui->botaoPreview->setEnabled(true);
        ui->botaoGerarAVS->setEnabled(true);
        ui->actionPr_Visualizar->setEnabled(true);
    }
}

void Principal::on_botaoSaida_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, tr("Salvar arquivo"), ui->caixaSaida->text(), tr("Arquivos AVS (*.avs)"));
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
    texto = "# AVSGenerator versão: " + versao +
            "\n\n";

    texto +=
           "# Plugins carregados:"
           "\n"
           "    LoadPlugin(\"" + QDir::currentPath() + debug + "/VideoPlugins/" + v.getPluginVideo() + "\")";

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
           "    Aud = " + v.getFuncaoVideo() + "(\"" + ui->caixaVideo->text() + "\")"
           "\n"
           "    Vid = " + v.getFuncaoVideo() + "(\"" + ui->caixaVideo->text() + "\")"
           "\n"
           "    AudioDub(vid,aud)"
           "\n\n";

    // Caso legendas estejam habilitadas, carrega as legendas
    if(ui->ativarEdLegendas->isChecked() && l.posicao){
           texto +=
           "# Arquivos de legenda carregados:"
           "\n"
           "    " + l.getListOfLegendas().replace('\n', "\n    "); // pega lista de plugins de legenda
    }

    texto += "\n";

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
    if(arg1){
        ui->botaoEdLegendas->setDisabled(false);
        ui->actionEditar_Legendas->setDisabled(false);
    }
    else{
        ui->botaoEdLegendas->setDisabled(true);
        ui->actionEditar_Legendas->setDisabled(true);
    }
}

void Principal::on_ativarEdComentarios_stateChanged(int arg1)
{
    if(arg1){
        ui->actionEditar_Coment_rios->setDisabled(false);
        ui->botaoEdComentarios->setDisabled(false);
    }
    else{
        ui->actionEditar_Coment_rios->setDisabled(true);
        ui->botaoEdComentarios->setDisabled(true);
    }
}

void Principal::on_ativarCorte_stateChanged(int arg1)
{
    if(arg1){
        ui->actionCorte->setDisabled(false);
        ui->botaoCorte->setDisabled(false);
    }else{
        ui->actionCorte->setDisabled(true);
        ui->botaoCorte->setDisabled(true);
    }
}

void Principal::on_actionPrefer_ncias_triggered()
{
    this->p.show(); // exibe dialogo para edição de preferencias
}

void Principal::on_actionSobre_triggered()
{
    this->s.show(); // exibe dialogo com informações do programa
}

void Principal::on_botaoGerarAVS_clicked()
{
    ui->statusBar->showMessage("Gerando...",0); // seta mensagem na barra de status ao inicio da criação de arquivo
    ui->progressBar->setValue(0); // seta barra de progresso para 0%

    QFile file(ui->caixaSaida->text()); // pega arquivo de saida
    int r = 0; // armazena resultado de mensagem de sobrescrita de arquivo

    ui->progressBar->setValue(10); // seta barra de progresso para 10%

    if(file.exists()){
        ui->progressBar->setValue(22); // seta barra de progresso para 22%
        QMessageBox msg; // cria caixa de mensagem
        msg.setWindowTitle("O arquivo já existe..."); // adiciona titulo a caixa de mensagem
        msg.setText("O arquivo já existe.\nDesaja sobrescreve-lo?"); // adiciona mensagem a caixa de mensagem
        msg.addButton("Sim",QMessageBox::AcceptRole); // adiciona botao 'sim' a caixa de mensagem
        msg.addButton("Não",QMessageBox::RejectRole)->setFocus(); // adiciona botao 'nao' a caixa de mensagem

        ui->progressBar->setValue(30); // seta barra de progresso para 30%

        r = msg.exec(); // exibe caixa de mensagem e armazena seu retorno
    }

    /* caso usuario responda 'sim', o conteudo do arquivo é sunstituido.
     * caso contrario, para a execução
     */

    if( !r ){

        ui->progressBar->setValue(50); // seta barra de progresso para 50%

        if (file.open(QFile::WriteOnly | QFile::Truncate)) { // abre o arquivo
            QTextStream out(&file); // cria objeto de saida
            out << geraDadosAvs(); // escreve conteudo no arquivo de saida

            ui->progressBar->setValue(100); // seta barra de progresso para 100%
            ui->statusBar->showMessage("Gerado com sucesso!",4000); // exibe mensagem na barra de status
        }
    }
    else{
        ui->progressBar->setValue(0); // seta barra de progresso para 0%
        ui->statusBar->showMessage("O arquivo já existe.",4000); // exibe menssagem na barra de status
    }

    file.close(); // fecha arquivo
    ui->progressBar->setValue(0); // seta barra de progresso para 0%
}

void Principal::on_botaoEdVideo_clicked()
{
    this->v.show();
}

void Principal::on_actionEditar_Video_triggered()
{
    on_botaoEdVideo_clicked();
}

void Principal::on_actionSair_triggered()
{
    close();
}
