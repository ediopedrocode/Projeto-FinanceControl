#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tabela->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tabela->setColumnWidth(0,140);
    ui->tabela->setColumnWidth(1,90);
    ui->tabela->setColumnWidth(2,100);
    ui->tabela->setColumnWidth(3,100);
    ui->tabela->setColumnWidth(4,120);
    ui->tabela->setColumnWidth(5,120);

    connect(&alterar, SIGNAL(dataObtida()), this, SLOT(atualizarData()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Adicionar_clicked()
{
    if (c.setNome(ui->inputNome->text())==false){
        ui->nome_invalido->setText("nome inválido*");
        ui->inputNome->clear();
    }else{
        ui->nome_invalido->setText("");
    }

    if (c.setQuantidade(ui->inputQuantidade->text().toInt())==false){
        ui->quantidade_invalida->setText("quantidade inválida*");
        ui->inputQuantidade->clear();
    }else{
        ui->quantidade_invalida->setText("");
    }

    if (c.setPreco(ui->inputPreco->text().toDouble())==false){
        ui->preco_invalido->setText("preço inválido*");
        ui->inputPreco->clear();
    }else{
        ui->preco_invalido->setText("");
    }

    if (c.setLocal(ui->inputLocal->text())==false){
        ui->local_invalido->setText("local inválido*");
        ui->inputLocal->clear();
    }else{
        ui->local_invalido->setText("");
    }


    if (c.setLocal(ui->inputLocal->text())==true and c.setNome(ui->inputNome->text())==true and c.setQuantidade(ui->inputQuantidade->text().toInt())==true and c.setPreco(ui->inputPreco->text().toDouble())==true){
        ui->nome_invalido->setText("");
        ui->quantidade_invalida->setText("");
        ui->preco_invalido->setText("");
        ui->local_invalido->setText("");

        c.setNome(ui->inputNome->text());

        c.setPreco(ui->inputPreco->text().toDouble());

        c.setQuantidade(ui->inputQuantidade->text().toInt());

        c.setLocal(ui->inputLocal->text());

        c.setData(ui->dateEdit->date());

        ui->inputNome->clear();
        ui->inputQuantidade->clear();
        ui->inputPreco->clear();
        ui->inputLocal->clear();

        int quantidade_linhas = ui->tabela->rowCount();

        ui->tabela->insertRow(quantidade_linhas);

        inserirNaTabela(c,quantidade_linhas);

        l.inserirCompra(c);

        atualizarEstatisticas();
    }else{
        QMessageBox::about(this, "ERRO", "Alguns dados inseridos estão inválidos.");
    }
}

void MainWindow::inserirNaTabela(Compra a, int linha)
{
    ui->tabela->setItem(linha,0, new QTableWidgetItem(a.getNome()));
    ui->tabela->setItem(linha,1, new QTableWidgetItem(QString::number(a.getQuantidade())));
    ui->tabela->setItem(linha,2, new QTableWidgetItem(QString::number(a.getPreco(), 'f', 2)));
    ui->tabela->setItem(linha,3, new QTableWidgetItem(a.getLocal()));
    ui->tabela->setItem(linha,4, new QTableWidgetItem(a.getData().toString()));
    ui->tabela->setItem(linha,5, new QTableWidgetItem(QString::number(a.getValorTotal(), 'f', 2)));
}

void MainWindow::atualizarEstatisticas()
{
    ui->produto_mais_barato->setText("R$ "+ QString::number(l.getMenorPreco(), 'f', 2));
    ui->produto_mais_caro->setText("R$ "+ QString::number(l.getMaiorPreco(), 'f', 2));
    ui->media_total->setText("R$ "+ QString::number(l.getMedia(), 'f', 2));
}

void MainWindow::on_tabela_cellDoubleClicked(int row, int column)
{
    linha = row;
    coluna = column;
    qDebug() << QString::number(linha) + " , " + QString::number(coluna);
    if (column == 0){
        QMessageBox::StandardButton resposta = QMessageBox::question(this, "Alterar dado", "Deseja alterar este dado?", QMessageBox::Yes|QMessageBox::No);

        if (resposta == QMessageBox::Yes){
            bool ok;

            QString txt = QInputDialog::getText(this, "Alterar dado", "Digite o novo nome do produto:", QLineEdit::Normal,"",&ok);

            while(c.setNome(txt)==false and ok){
                txt = QInputDialog::getText(this, "Alterar dado", "Digite um nome válido:", QLineEdit::Normal,"",&ok);
            }

            if (ok and c.setNome(txt)==true){

                c.setNome(txt);
                c.setPreco(l[row].getPreco());
                c.setQuantidade(l[row].getQuantidade());
                c.setLocal(l[row].getLocal());
                c.setData(l[row].getData());

                l.removerCompra(row);
                l.inserirCompra(c);

                for (int i=0; i<l.size(); i++){
                    inserirNaTabela(l[i], i);
                }

                qDebug() << l[row].getNome();
            }
        }
    }

    if (column == 1){
        QMessageBox::StandardButton resposta = QMessageBox::question(this, "Alterar dado", "Deseja alterar este dado?", QMessageBox::Yes|QMessageBox::No);

        if (resposta == QMessageBox::Yes){
            bool ok;

            QString txt = QInputDialog::getText(this, "Alterar dado", "Digite a nova quantidade:", QLineEdit::Normal,"",&ok);

            while(c.setQuantidade(txt.toInt())==false and ok){
                txt = QInputDialog::getText(this, "Alterar dado", "Digite uma quantidade válida:", QLineEdit::Normal,"",&ok);
            }

            if (ok and c.setQuantidade(txt.toInt())==true){

                c.setNome(l[row].getNome());
                c.setPreco(l[row].getPreco());
                c.setQuantidade(txt.toInt());
                c.setLocal(l[row].getLocal());
                c.setData(l[row].getData());

                //ui->tabela->setItem(row,column, new QTableWidgetItem(QString::number(c.getQuantidade())));
                //ui->tabela->setItem(row,5, new QTableWidgetItem(QString::number(c.getValorTotal(), 'f', 2)));

                l.removerCompra(row);
                l.inserirCompra(c);

                for (int i=0; i<l.size(); i++){
                    inserirNaTabela(l[i], i);
                }
            }
        }
    }

    if (column == 2){
        QMessageBox::StandardButton resposta = QMessageBox::question(this, "Alterar dado", "Deseja alterar este dado?", QMessageBox::Yes|QMessageBox::No);

        if (resposta == QMessageBox::Yes){
            bool ok;

            QString txt = QInputDialog::getText(this, "Alterar dado", "Digite o novo preço:", QLineEdit::Normal,"",&ok);

            while(c.setPreco(txt.toDouble())==false and ok){
                txt = QInputDialog::getText(this, "Alterar dado", "Digite um preço válido:", QLineEdit::Normal,"",&ok);
            }

            if (ok and c.setPreco(txt.toDouble())==true){

                c.setNome(l[linha].getNome());
                c.setPreco(txt.toDouble());
                c.setQuantidade(l[linha].getQuantidade());
                c.setLocal(l[linha].getLocal());
                c.setData(l[linha].getData());

                //ui->tabela->setItem(row,column, new QTableWidgetItem(QString::number(c.getPreco(),'f', 2)));
                //ui->tabela->setItem(row,5, new QTableWidgetItem(QString::number(c.getValorTotal(), 'f', 2)));

                l.removerCompra(linha);
                l.inserirCompra(c);

                for (int i=0; i<l.size(); i++){
                    inserirNaTabela(l[i], i);
                }
            }
        }
    }

    if (column == 3){
        QMessageBox::StandardButton resposta = QMessageBox::question(this, "Alterar dado", "Deseja alterar este dado?", QMessageBox::Yes|QMessageBox::No);

        if (resposta == QMessageBox::Yes){
            bool ok;

            QString txt = QInputDialog::getText(this, "Alterar dado", "Digite o novo local:", QLineEdit::Normal,"",&ok);

            while(c.setLocal(txt)==false and ok){
                txt = QInputDialog::getText(this, "Alterar dado", "Digite um local válido:", QLineEdit::Normal,"",&ok);
            }

            if (ok and c.setLocal(txt)==true){

                c.setNome(l[row].getNome());
                c.setPreco(l[row].getPreco());
                c.setQuantidade(l[row].getQuantidade());
                c.setLocal(txt);
                c.setData(l[row].getData());

                //ui->tabela->setItem(row,column, new QTableWidgetItem(c.getLocal()));

                l.removerCompra(row);
                l.inserirCompra(c);

                for (int i=0; i<l.size(); i++){
                    inserirNaTabela(l[i], i);
                }
                qDebug() << c.getLocal();
            }
        }
    }

    if (column == 4){
        QMessageBox::StandardButton resposta = QMessageBox::question(this, "Alterar dado", "Deseja alterar este dado?", QMessageBox::Yes|QMessageBox::No);

        if (resposta == QMessageBox::Yes){
            alterar.show();
        }
    }

    if (column == 5){
        QMessageBox::StandardButton resposta = QMessageBox::question(this, "Alterar dado", "Deseja alterar este dado?", QMessageBox::Yes|QMessageBox::No);

        if (resposta == QMessageBox::Yes){
            QMessageBox::about(this, "Impedido", "Você não pode alterar o valor total.\nEle é calculado automaticamente\nde acordo com a quantidade e o preço.");

        }
    }
    atualizarEstatisticas();
}



void MainWindow::on_btn_ordenar_qtd_clicked()
{
    if (l.size()>0){
        l.ordenarPorQuantidade();
        ui->tabela->clearContents();

        for (int i=0; i<l.size(); i++){
            inserirNaTabela(l[i], i);
        }
    }else{
        QMessageBox::information(this, "Ordenar", "Você ainda não adicionou nenhuma compra.");
    }
}

void MainWindow::on_btn_ordenar_preco_clicked()
{
    if (l.size()>0){
        l.ordenarPorPreco();
        ui->tabela->clearContents();

        for (int i=0; i<l.size(); i++){
            inserirNaTabela(l[i], i);
        }
    }else{
        QMessageBox::information(this, "Ordenar", "Você ainda não adicionou nenhuma compra.");
    }
}

void MainWindow::on_btn_remover_2_clicked()
{
    bool ok;
    QString select;

    if (l.size()>0){
        QString txt = QInputDialog::getText(this, "Remover dado", "Digite o produto que deseja remover:", QLineEdit::Normal,"",&ok);

        if(ok){
            if (!txt.isEmpty()){
                if (l.verificarExistencia(txt)){
                    if (l.contador_iguais>1){
                        select = QInputDialog::getText(this, "OPS", l.getText(l), QLineEdit::Normal,"",&ok);

                        if(ok and (select.toInt()>0) and (select.toInt()<=l.contador_iguais)){
                            qDebug() << l.size();
                            l.removerCompra(l.indices[select.toInt()-1]);
                            ui->tabela->clearContents();

                            ui->tabela->removeRow(0);

                            for (int i=0; i<l.size(); i++) {
                                inserirNaTabela(l[i], i);
                            }

                            QMessageBox::about(this, "Remover", "Dado removido com sucesso.");

                        }else{
                            if (ok){
                                QMessageBox::warning(this, "ERRO", "Sua resposta não corresponde a nenhuma opção.");
                            }
                        }
                    }else{
                        l.removerCompra(l.indices[0]);

                        ui->tabela->clearContents();

                        ui->tabela->removeRow(0);
                        for (int i=0; i<l.size(); i++) {
                            inserirNaTabela(l[i], i);
                        }
                        QMessageBox::about(this, "Remover dado", "Dado removido com sucesso.");
                    }
                }else{
                    QMessageBox::warning(this, "ERRO", "Você não cadastrou nenhum produto com esse nome.");
                }
            }else{
                QMessageBox::information(this, "Atenção", "Você não escreveu nada.");
            }
        }
    }else{
        QMessageBox::information(this, "Remover dado", "Você ainda não adicionou nenhuma compra.");
    }
    l.contador_iguais = 0;
    atualizarEstatisticas();
}


void MainWindow::atualizarData()
{
    c.setNome(l[linha].getNome());
    c.setPreco(l[linha].getPreco());
    c.setQuantidade(l[linha].getQuantidade());
    c.setLocal(l[linha].getLocal());
    c.setData(alterar.getDataAlterada());

    //ui->tabela->setItem(linha,coluna, new QTableWidgetItem(c.getData().toString()));

    l.removerCompra(linha);
    l.inserirCompra(c);

    for (int i=0; i<l.size(); i++){
        inserirNaTabela(l[i], i);
    }

    atualizarEstatisticas();

    qDebug() << alterar.getDataAlterada();
}

void MainWindow::on_actionSalvar_triggered()
{
    QString filename;

    filename = QFileDialog::getSaveFileName(this,"Salvar Arquivo","","*.csv");

    l.salvarDados(filename);
}

void MainWindow::on_actionCarregar_triggered()
{
    QMessageBox::StandardButton resposta = QMessageBox::question(this, "Carregar Arquivo", "Existe um arquivo aberto! Caso não queira salvar, você perderá o documento atual.\n\nDeseja salvar antes de carregar outro arquivo?", QMessageBox::Close|QMessageBox::No|QMessageBox::Yes);
    if (resposta== QMessageBox::No){
        QString filename;
        filename = QFileDialog::getOpenFileName(this, "Abrir Arquivo","","*.csv");

        limparTudo();

        l.carregarDados(filename);

        if (l.size()>0){

            for(int i=0;i<l.size();i++){
                ui->tabela->insertRow(i);
                inserirNaTabela(l[i],i);
            }
        }

        atualizarEstatisticas();

        ui->inputNome->clear();
        ui->inputQuantidade->clear();
        ui->inputPreco->clear();
        ui->inputLocal->clear();
        ui->opcao->clear();
        ui->sugestao->clear();
        ui->info_sugestao->clear();
    }else{
        if(resposta == QMessageBox::Yes){
            on_actionSalvar_triggered();

            QString filename;
            filename = QFileDialog::getOpenFileName(this, "Abrir Arquivo","","*.csv");

            limparTudo();

            l.carregarDados(filename);

            for(int i=0;i<l.size();i++){
                ui->tabela->insertRow(i);
                inserirNaTabela(l[i],i);
            }

            atualizarEstatisticas();

            ui->inputNome->clear();
            ui->inputQuantidade->clear();
            ui->inputPreco->clear();
            ui->inputLocal->clear();
            ui->opcao->clear();
            ui->sugestao->clear();
            ui->info_sugestao->clear();
        }
    }
}

void MainWindow::limparTudo()
{
    l.limparVetor();

    int qtd_linhas = ui->tabela->rowCount();

    for(int i=0; i < qtd_linhas; i++){
        ui->tabela->removeRow(0);
    }

}

void MainWindow::on_actionNovo_triggered()
{
    QMessageBox::StandardButton resposta = QMessageBox::question(this, "Novo arquivo", "Existe um arquivo aberto! Caso não queira salvar, você perderá o documento atual.\n\nDeseja salvar antes de iniciar um novo arquivo?", QMessageBox::No|QMessageBox::Close|QMessageBox::Yes);
    if (resposta == QMessageBox::No){
        limparTudo();

        atualizarEstatisticas();

        ui->inputNome->clear();
        ui->inputQuantidade->clear();
        ui->inputPreco->clear();
        ui->inputLocal->clear();
        ui->opcao->clear();
        ui->sugestao->clear();
        ui->info_sugestao->clear();
    }else{
        if(resposta == QMessageBox::Yes){
            on_actionSalvar_triggered();

            limparTudo();

            atualizarEstatisticas();

            ui->inputNome->clear();
            ui->inputQuantidade->clear();
            ui->inputPreco->clear();
            ui->inputLocal->clear();
            ui->opcao->clear();
            ui->sugestao->clear();
            ui->info_sugestao->clear();
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    //bool ok;
    QString txt =  ui->opcao->text();

    if (!txt.isEmpty()){
        if (l.size()>0){
            if (l.verificarExistencia(txt)){
                if (l.contador_iguais>1){
                    Lista temp;

                    for (int i=0; i<l.contador_iguais; i++){
                        temp.inserirCompra(l[l.indices[i]]);
                    }

                    temp.ordenarPorPreco();

                    ui->info_sugestao->setText("Esse produto foi comprado mais de\numa vez e nós separamos a melhor opção\ndentre as que você cadastrou.");
                    ui->sugestao->setText("Lugar: " + temp[0].getLocal() + "\nPreço: R$ " + QString::number(temp[0].getPreco(), 'f', 2) + "\nDia da compra: " + temp[0].getData().toString());
                }else{
                    ui->info_sugestao->setText("Este produto só foi comprado uma vez.\nAo lado nós disponilizamos o lugar,\npreço e dia da sua compra.");
                    ui->sugestao->setText("Lugar: " + l[l.indices[0]].getLocal() + "\nPreço: R$ " + QString::number(l[l.indices[0]].getPreco(), 'f', 2) + "\nDia da compra: " + l[l.indices[0]].getData().toString());
                }
            }else{
                QMessageBox::information(this, "Atenção", "Você ainda não comprou esse produto, logo não temos como te dar uma opção.");
                ui->info_sugestao->setText("");
                ui->opcao->clear();
                ui->sugestao->clear();
                ui->info_sugestao->clear();
            }
        }else{
            QMessageBox::information(this, "Atenção", "Você ainda não cadastrou nenhuma compra, logo esta função ainda não pode ser usada.");
            ui->info_sugestao->setText("");
            ui->opcao->clear();
            ui->sugestao->clear();
            ui->info_sugestao->clear();
        }
    }else{
        QMessageBox::information(this, "Atenção", "Você não escreveu nada.");
        ui->info_sugestao->setText("");
        ui->opcao->clear();
        ui->sugestao->clear();
        ui->info_sugestao->clear();
    }
    l.contador_iguais = 0;
}
