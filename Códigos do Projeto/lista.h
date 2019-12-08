#ifndef LISTA_H
#define LISTA_H

#include <QVector>
#include <algorithm>
#include <QFile>
#include <QStringList>
#include <QDebug>

#include "compra.h"

class Lista
{
private:
    QVector<Compra> lista;
public:
    Lista();

    void inserirCompra(Compra a);

    Compra operator[](int indice);

    void removerCompra(int pos);

    void ordenarPorQuantidade();

    void ordenarPorPreco();

    int size();

    bool jaExiste(Compra a);

    bool verificarExistencia(QString t);

    void removerCompra(int a, Lista b);

    QString getText(Lista a);

    void salvarDados(QString file);

    void carregarDados(QString file);

    void limparVetor();

    double getMaiorPreco();

    double getMenorPreco();

    double getMedia();

    QVector<int> indices;
    int contador_iguais = 0;
};

bool compararPorPreco(Compra a, Compra b);

#endif // LISTA_H
