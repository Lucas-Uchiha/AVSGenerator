#include "principal.h"
#include "ui_principal.h"
#include <QFileDialog>
#include "previewavs.h"
#include "global.h"

Principal::Principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Principal)
{
    ui->setupUi(this);

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
    QString comentario = j.getConteudo(); // pega comentarios
    comentario.insert(0, '#'); // insere # na primeira linha
    comentario.replace('\n', "\n    #"); // insere tabulação e # nas demais linhas

    return "# AVSGenerator versão: 0.0.0"
           "\n\n"
           "# Plugins carregados:"
           "\n"
           "    LoadPlugin(ffms2)"
           "\n"
           "    LoadPlugin(vsfilter)"
           "\n\n"
           "# Arquivos de Vídeo / Áudio carregados:"
           "\n"
           "    Aud = FFAudioSource('" + ui->caixaVideo->text() + "')"
           "\n"
           "    Vid = FFVideoSource('" + ui->caixaVideo->text() + "')"
           "\n"
           "    AudioDub(vid,aud)"
           "\n\n"
           "# Arquivos de legenda carregados:"
           "\n"
           "    TextSub(legenda.ass)"
           "\n\n"
           "# Corte de Vídeo / Áudio:"
           "\n"
           "    Trim(" + QString::number(c.getInicio()) + "," + QString::number(c.getFim()) + ")"
           "\n\n"
           "#Comentários:"
           "\n"
           "    " + comentario;
}

void Principal::on_actionEditar_Legendas_triggered()
{
    on_botaoEdLegendas_clicked(); // chama dialogo de edição de legendas para ser exibido
}
