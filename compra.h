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
    float preco;
    QString local;
    int dia, mes, ano;
    QDate data;
public:
    Compra();

    QString getNome() const;
    bool setNome(const QString &value);

    int getQuantidade() const;
    bool setQuantidade(const int value);

    double getPreco();
    bool setPreco(double value);

    QString getLocal() const;
    bool setLocal(const QString &value);

    bool setDataComplexo(int value_dia, int value_mes, int value_ano);
    QString getDataComplexo();

    QDate getData() const;
    bool setData(const QDate &value_data);

    double getValorTotal();
};

#endif // COMPRA_H
