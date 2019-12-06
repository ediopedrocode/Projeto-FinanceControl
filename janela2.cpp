#include "janela2.h"
#include "ui_janela2.h"

Janela2::Janela2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Janela2)
{
    ui->setupUi(this);
}

Janela2::~Janela2()
{
    delete ui;
}

void Janela2::setDataAlterada(const QDate &value)
{
    data_alterada = value;
    emit dataObtida();
    close();
}

QDate Janela2::getDataAlterada()
{
    return data_alterada;
}

void Janela2::on_ok_data_clicked()
{
    setDataAlterada(ui->altera_data->date());
}

void Janela2::on_cancela_data_clicked()
{
    close();
}
