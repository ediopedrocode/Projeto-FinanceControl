#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QInputDialog>
#include <QDateEdit>
#include <QFileDialog>

#include "janela2.h"
#include "compra.h"
#include "lista.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Adicionar_clicked();

    void on_tabela_cellDoubleClicked(int row, int column);

    void on_btn_ordenar_qtd_clicked();

    void on_btn_ordenar_preco_clicked();

    void on_btn_remover_2_clicked();

    void atualizarData();

    void on_actionSalvar_triggered();

    void on_actionCarregar_triggered();

    void limparTudo();

    void on_actionNovo_triggered();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    void inserirNaTabela(Compra a, int linha);

    void atualizarEstatisticas();

    Lista l;
    Compra c;
    Janela2 alterar;
    int linha;
    int coluna;

};
#endif // MAINWINDOW_H
