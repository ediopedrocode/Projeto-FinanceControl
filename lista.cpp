#include "lista.h"

Lista::Lista()
{

}

void Lista::inserirCompra(Compra a)
{
    lista.push_back(a);
}

Compra Lista::operator[](int indice)
{
    return lista[indice];
}

void Lista::removerCompra(int pos)
{
    lista.erase(lista.begin()+(pos));
}

void Lista::ordenarPorQuantidade()
{
    std::sort(lista.begin(), lista.end(), [](Compra a, Compra b){
        return a.getQuantidade()<b.getQuantidade();
    });
}

void Lista::ordenarPorPreco()
{
    std::sort(lista.begin(), lista.end(), [](Compra a, Compra b){
        return a.getPreco()<b.getPreco();
    });
}

int Lista::size()
{
    return lista.size();
}

bool Lista::verificarExistencia(QString t)
{
    indices.clear();
    for(int i = 0; i<lista.size(); i++){
        if(lista[i].getNome() == t){
            contador_iguais++;
            indices.push_back(i);
        }
    }

    if (contador_iguais>0){
        return true;
    }else{
        return false;
    }
}

void Lista::removerCompra(int a, Lista b)
{
       b.removerCompra(indices[a]);
}

QString Lista::getText(Lista a)
{
    QString aviso = "Você comprou este produto mais de uma vez! Veja a seguir:\n\n";
    QString pergunta = "\nEscolha a opção que deseja remover digitando o número relacionado:";
    QString opcoes;
    for (int i=0; i<contador_iguais; i++){
        opcoes = opcoes +
                 QString::number(i+1) +
                 " - Nome: " + a[indices[i]].getNome() +
                 " - Preço: " + QString::number(a[indices[i]].getPreco()) +
                 " - Quantidade: " + QString::number(a[indices[i]].getQuantidade()) +
                 " - Local: " + a[indices[i]].getLocal() +
                 " - Data: " + a[indices[i]].getData().toString() +
                 "\n";
    }
    qDebug() << aviso + opcoes + pergunta;
    return aviso + opcoes + pergunta;
}

void Lista::salvarDados(QString file)
{
    QFile arquivo(file + ".csv");

    arquivo.open(QIODevice::WriteOnly);

    for(auto a:lista){
          QString linha = a.getNome() + "," + QString::number(a.getPreco()) + "," + QString::number(a.getQuantidade()) + "," + a.getLocal() + "," + a.getData().toString() + "\n";
          arquivo.write(linha.toLocal8Bit());
    }
    arquivo.close();
}

void Lista::carregarDados(QString file)
{
    QFile arquivo(file);
    arquivo.open(QIODevice::ReadOnly);

    QString line;
    QStringList dados;
    while(!arquivo.atEnd()){
        Compra temp;
        line = arquivo.readLine();
        dados = line.split(",");
        temp.setNome(dados[0]);
        temp.setPreco(dados[1].toDouble());
        temp.setQuantidade(dados[2].toInt());
        temp.setLocal(dados[3]);
        temp.setData(QDate::fromString(dados[4]));
        inserirCompra(temp);
    }
    arquivo.close();
}

void Lista::limparVetor()
{
    lista.clear();
    qDebug() << lista.size();
}

double Lista::getMaiorPreco()
{
    if (lista.size()>0){
        Compra *a = std::max_element(lista.begin(), lista.end(), compararPorPreco);
        return a->getPreco();
    }else{
        return 0;
    }
}

double Lista::getMenorPreco()
{
    if (lista.size()){
        Compra *a = std::min_element(lista.begin(), lista.end(), compararPorPreco);
        return a->getPreco();
    }else{
        return 0;
    }
}

double Lista::getMedia()
{
    if (lista.size()>0){

        double gastos = 0;
        int qtd_total = 0;

        for(auto e : lista){
            gastos+=(e.getPreco()*e.getQuantidade());
            qtd_total+=e.getQuantidade();
        }

        return gastos/qtd_total;

    }else{
        return 0;
    }
}

bool compararPorPreco(Compra a, Compra b)
{
    return a.getPreco()<b.getPreco();
}
