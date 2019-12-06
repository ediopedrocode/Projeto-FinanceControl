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

bool Compra::setQuantidade(const int value)
{
    if (value>0){
        quantidade = value;
        return true;
    }else{
        return false;
    }
}

double Compra::getPreco()
{
    return preco;
}

bool Compra::setPreco(double value)
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

/*bool Compra::setDataComplexo(int value_dia, int value_mes, int value_ano)
{
    if (value_mes>=1 and value_mes<=12){
        if (value_mes!=2){
            if ((value_mes == 4 || value_mes == 6 || value_mes == 9 || value_mes == 11) and (value_dia <1 or value_dia>30)){
                return false;
            }else{
                if(value_dia<1 or value_dia>31){
                    return false;
                }else{
                    data = QString::number(value_dia) + "/" + QString::number(value_mes) + "/" + QString::number(value_ano);
                    return true;
                }
            }
        }else{
            if ((value_ano % 4 == 0 && (value_ano % 400 == 0 || value_ano % 100 != 0) and (value_dia>29 or value_dia<1))){
                return false;
            }else{
                if (value_dia<1 or value_dia>28){
                    return false;
                }else{
                    data = QString::number(value_dia) + "/" + QString::number(value_mes) + "/" + QString::number(value_ano);
                    return true;
                }
            }
        }
    }else{
        return false;
    }

            }else{
            if ((value_ano % 4 == 0 && (value_ano % 400 == 0 || value_ano % 100 != 0)) and (value_dia == "30" || value_dia == "31")){
                return false;
           }else{
                if (value_dia == "29" || value_dia == "30" || value_dia == "31"){
                   return false;
                }else{
                    data = QString::number(value_dia) + "/" + QString::number(value_mes) + "/" + QString::number(value_ano);
                    return true;
                }}
            }
        }
    }else{
                    return false;
}
*/

QDate Compra::getData() const
{
    return data;
}

bool Compra::setData(const QDate &value_data)
{
    data = value_data;
    qDebug() << value_data;
    return true;
}

double Compra::getValorTotal()
{
    return preco * quantidade;
}
