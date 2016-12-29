#include "global.h"

QString caminho = QDir::homePath();

//QString debug = ""; // descomentar essa linha durante release
QString debug = "/debug"; // descomentar essa linha durante debug

QDir dir(QDir::currentPath() + debug + "/LegendaPlugins"); // abre diretorio com filtros de legenda

QStringList caminhosFiltrosLegenda = dir.entryList(QDir::Filter::Files,QDir::SortFlag::NoSort); // cria lista de arquivos
                                                                                                // de filtros de legenda
