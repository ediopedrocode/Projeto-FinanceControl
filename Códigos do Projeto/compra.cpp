 #include "compra.h"

Compra::Compra()
{

}

QString Compra::getNome() const
{
    return nome;
}

bool Compra::setNome(const QString &value)
{
    if (value.size() >= 2){
        nome = value;
        return true;
    }else{
        return false;
    }
}

int Compra::getQuantidade() const
{
    return quantidade;
}

bool Compra::setQuantidade(const int &value)
{
    if (value>0){
        quantidade = value;
        return true;
    }else{
        return false;
    }
}

double Compra::getPreco() const
{
    return preco;
}

bool Compra::setPreco(const double &value)
{
    if (value>0){
        preco = value;
        return true;
    }else{
        return false;
    }
}

QString Compra::getLocal() const
{
    return local;
}

bool Compra::setLocal(const QString &value)
{
    if (value.size() >= 2){
        local = value;
        return true;
    }else{
        return false;
    }
}

QDate Compra::getData() const
{
    return data;
}

void Compra::setData(const QDate &value_data)
{
    data = value_data;
    qDebug() << value_data;
}

double Compra::getValorTotal()
{
    qDebug() << preco * quantidade;
    return preco * quantidade;
}
