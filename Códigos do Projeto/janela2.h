#ifndef JANELA2_H
#define JANELA2_H

#include <QWidget>
#include <QDate>
#include "complex.h"
#include "lista.h"
//#include "mainwindow.h"

#include <QDebug>

namespace Ui {
class Janela2;
}

class Janela2 : public QWidget
{
    Q_OBJECT

public:
    explicit Janela2(QWidget *parent = nullptr);
    ~Janela2();
    void setDataAlterada(const QDate &value);
    QDate getDataAlterada();

private slots:
    void on_ok_data_clicked();

    void on_cancela_data_clicked();

private:
    Ui::Janela2 *ui;
    QDate data_alterada;

    signals:
    void dataObtida();
};

#endif // JANELA2_H
