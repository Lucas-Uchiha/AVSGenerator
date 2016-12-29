#include "dialogocontrolelegendas.h"
#include "ui_dialogocontrolelegendas.h"

DialogoControleLegendas::DialogoControleLegendas(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::DialogoControleLegendas)
{
    ui->setupUi(this);
    dados = new DadosLegenda[100](); // cria vetor de tamanho 100 para guardar dados

}

DialogoControleLegendas::~DialogoControleLegendas()
{
    delete ui;
    delete [] dados; // liberar memoria do vetor de objetos
}

void DialogoControleLegendas::on_botaoAddLegenda_clicked()
{

    if(posicao >= 99){ // caso esteja no numero maximo de legendas suportadas
        QMessageBox msgBox; // cria caixa de mensagem
        msgBox.setWindowTitle("Erro"); // seta titulo da caixa de menssagem
        msgBox.setText("Número máximo de legendas atingido."); // seta texto da caixa de mensagem
        msgBox.exec(); // exibe caixa de mensagem
    }
    else{ // caso ainda possa adicionar novas legendas
        DialogoAdicionarLegenda win; // cria dialogo para adição de legendas
        int re = win.exec(); // exibe dialogo
        // somente se o botao OK for pressionado e um item foi selecionado, faz mudanças
        if( !win.getNewItem().getCaminho().isEmpty() && re ){
            dados[posicao] = win.getNewItem(); // adiciona novo item ao array de legendas
            ui->listaDeLegendas->addItem(dados[posicao].getNome()); // adiciona o novo item a lista de legendas
            posicao++; // inclementa a posição no array
        }
    }
}

void DialogoControleLegendas::on_botaoOK_clicked()
{
    close();
}

void DialogoControleLegendas::on_botaoEditaLegenda_clicked()
{
    QListWidget *lista = ui->listaDeLegendas; // cria ponteiro para facilitar leitura do codigo
    // caso não tenha nenhum item selecionado não faz nada
    if(lista->currentRow() >= 0){

        DialogoEditarLegenda win; // cria dialogo para edição de legendas

        win.editItem(dados[lista->currentRow()]);

        int re = win.exec(); // exibe dialogo
        // somente se o botao OK for pressionado e um item foi selecionado, faz mudanças
        if( !win.getEditedItem().getCaminho().isEmpty() && re ){
            dados[lista->currentRow()] = win.getEditedItem(); // adiciona novo item ao array de legendas
            lista->item(lista->currentRow())->setText(dados[lista->currentRow()].getNome()); // atualiza texto da lista de legendas
        }
    }
}

void DialogoControleLegendas::on_botaoRemoveLegenda_clicked()
{
    QListWidget *lista = ui->listaDeLegendas; // cria ponteiro para facilitar leitura do codigo

    // caso não tenha nenhum item selecionado não faz nada
    if(lista->currentRow() >= 0){

        // percorre o vetor de itens a partir do selecionado
        for(int i = lista->currentRow(); i < posicao - 1; i++)
            dados[i] = dados[i+1];

        posicao--; // reduz em 1 o numero de posições ocupadas do vetor

        delete lista->takeItem(ui->listaDeLegendas->currentRow()); // remove item da visualização
    }
}

void DialogoControleLegendas::on_botaoSubirLegenda_clicked()
{
    QListWidget *lista = ui->listaDeLegendas; // cria ponteiro para facilitar leitura do codigo

    // caso nenhum ou o primeiro item esteja marcado, não faz nada
    if(lista->currentRow() >= 1){
        DadosLegenda temp = dados[lista->currentRow()]; // guarda dados temporariamente
        int linhaAtual = lista->currentRow(); // salva atual linha selecionada na lista
        dados[linhaAtual] = dados[linhaAtual - 1 ]; // substitui o conteudo da atual linha selecionada com o da linha acima
        dados[linhaAtual - 1 ] = temp; // substitui o conteudo da linha acima com o antigo conteudo da linha abaixo

        QString nome = lista->item(linhaAtual)->text(); // copia texto da atual linha selecionada
        lista->item(linhaAtual)->setText( lista->item(linhaAtual - 1)->text() ); // substitui texto da linha atual pelo da linha acima
        lista->item(linhaAtual - 1)->setText(nome); // substitui texto da linha acima pelo salvo anteriormente
        lista->setCurrentRow(linhaAtual - 1); // seta atual linha para a linha acima
        lista->item(linhaAtual - 1)->setSelected(true); // marca linha acima como selecionada
        lista->setFocus(); // foca lista
    }
}

void DialogoControleLegendas::on_botaoDescerLegenda_clicked()
{
    QListWidget *lista = ui->listaDeLegendas; // cria ponteiro para facilitar leitura do codigo

    /*
     * Para ocorrer a condição abaixo precisa estar dentro de 3 situações ao mesmo tempo:
     * 1 - Ter ao menos um item selecionado (checar situação 3)
     * 2 - O item selecionado não pode ser o último da lista
     * 3 - O item selecionado não pode ser o o único da lista
     */
    if(lista->currentRow() >= 0 && lista->currentRow() < lista->count() - 1 ){
        DadosLegenda temp = dados[lista->currentRow()]; // guarda dados temporariamente
        int linhaAtual = lista->currentRow(); // salva atual linha selecionada na lista
        dados[linhaAtual] = dados[linhaAtual + 1 ]; // substitui o conteudo da atual linha selecionada com o da linha abaixo
        dados[linhaAtual + 1 ] = temp; // substitui o conteudo da linha abaixo com o antigo conteudo da linha acima

        QString nome = lista->item(linhaAtual)->text(); // copia texto da atual linha selecionada
        lista->item(linhaAtual)->setText( lista->item(linhaAtual + 1)->text() ); // substitui texto da linha atual pelo da linha abaixo
        lista->item(linhaAtual + 1)->setText(nome); // substitui texto da linha abaixo pelo salvo anteriormente
        lista->setCurrentRow(linhaAtual + 1); // seta atual linha para a linha abaixo
        lista->item(linhaAtual + 1)->setSelected(true); // marca linha abaixo como selecionada
        lista->setFocus(); // foca lista
    }
}

QString DialogoControleLegendas::getListOfPlugins(){

    QString retorno = ""; // armazena retorno da função
    int i;

    if(posicao){ // caso não tenha nenhuma legenda adicionada, retorna um string vazio
        retorno = "LoadPlugin(" + QDir::currentPath() + "/legendaPlugins/" + dados[0].getTipo() + ")"; // pega o primeiro plugin
        QString novaLinha = ""; // armazena nova linha a ser inserida no retorno
        /* o for abaixo varre a lista de legendas adicionadas e compara seus plugins
         * adicionando-os a variavel de retorno desde que nao sejam iguais
         */
        for(i = 1; i < posicao; i++){
            novaLinha = "\n LoadPlugin(" + QDir::currentPath() + "/legendaPlugins/" + dados[i].getTipo() + ")";
            if(! retorno.contains( novaLinha )) // caso nova linha não esteja presente
                retorno += novaLinha;           // adiciona nova linha
        }
    }

    return retorno;
}

QString DialogoControleLegendas::getListOfLegendas(){

    QString retorno = ""; // armazena retorno da função
    int i;

    if(posicao){ // caso não tenha nenhuma legenda adicionada, retorna um string vazio

        // o for abaixo varre a lista de legendas adicionando-as
        for(i = 0; i < posicao; i++){
            retorno += getFuncao(dados[i].getTipo()) + "(\"" + dados[i].getCaminho() + "\")\n";
        }
    }

    return retorno;
}

QString DialogoControleLegendas::getFuncao(QString nomeDoTipo){

    QString retorno = ""; // armazena retorno da função
    QString debug = ""; // armazena caminho para debug
    debug += "/debug"; // comentar essa linha para deploy

    QFile file(QDir::currentPath() + debug + "/Functions/legenda.txt"); // caminho para o arquivo

    // Tenta abrir arquivo, caso não consiga, retorna uma string vazia
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){

        // le arquivo linha por linha ate o fim ou ate encontrar a linha desejada
        QTextStream in(&file);
        while (! in.atEnd() ) {
            QString line = in.readLine(); // le as linhas
            if(line.contains(nomeDoTipo,Qt::CaseInsensitive)){
                retorno += in.readLine(); // pega nome da função
                break; // para execução
            }
            in.readLine(); // pula uma linha
        }
    }

    return retorno;
}
