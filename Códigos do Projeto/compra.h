#ifndef COMPRA_H
#define COMPRA_H

#include <QString>
#include <ctype.h>
#include <QDebug>
#include <QDateEdit>

class Compra
{
private:
    QString nome;
    int quantidade;
    double preco;
    QString local;
    QDate data;
public:
    Compra();

    QString getNome() const;
    bool setNome(const QString &value);

    int getQuantidade() const;
    bool setQuantidade(const int &value);

    double getPreco() const;
    bool setPreco(const double &value);

    QString getLocal() const;
    bool setLocal(const QString &value);

    QDate getData() const;
    void setData(const QDate &value_data);

    double getValorTotal();
};

#endif // COMPRA_H
