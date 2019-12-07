# FinanceControl

#### O FinanceControl é um projeto desenvolvido para a disciplina de Técnicas de Programação do 2º período do curso de Engenharia Elétrica do IFPB. O programa visa ajudar os usuários a ter uma vida financeira mais controlada através de estatísticas detalhadas e outras funcionalidades à medida em que você vai cadastrando os seus gastos diários.

# Manual

Seja bem vindo ao manual do FinanceControl. Ele possui uma interface de fácil uso e entendimento e aqui você irá entender o passo a passo de cada operação.  

## Cadastro

Conheça abaixo a página inicial do FinanceControl, a aba "Cadastro":

![](https://github.com/ediopedrocode/Projeto-FinanceControl/blob/master/Imagens%20do%20Manual/intro1.png)

## Adicionar uma compra 

Para começar, aqui você pode adicionar sua primeira compra com as informações de nome do produto, preço, quantidade, local de compra e data da compra.

Acompanhe o exemplo abaixo:

![](https://github.com/ediopedrocode/Projeto-FinanceControl/blob/master/Imagens%20do%20Manual/INSERIR.png)

Após inserir basta clicar no botão "Adicionar" e as informações aparecerão em uma tabela abaixo. Veja a seguir:

![](https://github.com/ediopedrocode/Projeto-FinanceControl/blob/master/Imagens%20do%20Manual/ADICIONAR.png)

Como se pode notar, uma informação extra é entregue na tabela, o "Valor Total". Ele é o cálculo total da compra, ou seja, o preço do produto, multiplicado pela quantidade que você comprou.

## Alterar

Caso você tenha errado alguma informação na hora de inserir uma compra, não se preocupe, pois o FinanceControl te permite fazer alterações em quaisquer das informações que você cadastrou.

Basta clicar duas vezes no dado que deseja alterar. Inicialmente você será perguntado se está certo de que deseja fazer a alteração. Confira:

![](https://github.com/ediopedrocode/Projeto-FinanceControl/blob/master/Imagens%20do%20Manual/alterar6.png)

Caso sim, aparecerá uma caixa a qual você pode inserir a nova informação. No exemplo abaixo foi solicitado a alteração da quantidade do produto "pelicula" que vai ser alterado de 1 para 2:

![](https://github.com/ediopedrocode/Projeto-FinanceControl/blob/master/Imagens%20do%20Manual/alterar8.png)

Após ser alterado, a lista será automaticamente atualizada e o produto alterado será levado ao final da lista, além da atualização do Valor Total. Perceba:

![](https://github.com/ediopedrocode/Projeto-FinanceControl/blob/master/Imagens%20do%20Manual/alterado9.png)

## Ordenar 

O FinanceControl tem dois critérios de ordenação de maneira crescente. Basta clicar no respectivo botão na parte inferior esquerda da pagina inicial. Acompanhe dois exemplos:

##### Ordenando por Preço:

![](https://github.com/ediopedrocode/Projeto-FinanceControl/blob/master/Imagens%20do%20Manual/ordPreco10.png)

##### Ordenando por Quantidade:

![](https://github.com/ediopedrocode/Projeto-FinanceControl/blob/master/Imagens%20do%20Manual/ordQtd11.png)

## Remover

Caso queira remover alguma das compras adicionadas, também é possível e fácil. 

Para começar, clique no botão "Remover" localizado na parte inferior direita da Página Inicial.
Uma caixa de mensagem irá aparecer e nela você pode inserir o nome do produto que deseja remover. Veja:

![](https://github.com/ediopedrocode/Projeto-FinanceControl/blob/master/Imagens%20do%20Manual/remover12.png)

Após inserir o nome do produto basta clicar "OK" e a operação será concluída.

Vale lembrar que é possível fazer duas compras diferentes de um mesmo produto em épocas diferentes. Nesse caso você pode se perguntar, "como poderei escolher qual compra eu desejo remover?". É muito fácil!
Caso o produto que você deseja remover se encontre em dois cadastros, aparecerá a seguinte mensagem:

![](https://github.com/ediopedrocode/Projeto-FinanceControl/blob/master/Imagens%20do%20Manual/remo2.png)

Logo, basta digitar o número o qual está relacionado a compra que deseja remover e clicar em "OK". A operação será concluída.

## Obter Sugestão

![](https://github.com/ediopedrocode/Projeto-FinanceControl/blob/master/Imagens%20do%20Manual/sugestao14.png)

Na aba "Obter Sugestão" há uma funcionalidade ímpar do FinanceControl. Aqui você pode pesquisar um produto e receber uma sugestão do estabelecimento de compra. Essa informação é calculada pegando o lugar mais barato que você comprou o produto.
Dessa forma é necessário você ter comprado o produto mais de uma vez para te darmos essa sugestão. Acompanhe um exemplo explicativo:

Inicialmente, é possível perceber que o produto "Bateria 9V" foi comprado mais de uma vez:

![](https://github.com/ediopedrocode/Projeto-FinanceControl/blob/master/Imagens%20do%20Manual/sugestao15.png)

Ao ir na aba "Obter Sugestão" e pesquisar por "Bateria 9V", o seguinte acontece:

![](https://github.com/ediopedrocode/Projeto-FinanceControl/blob/master/Imagens%20do%20Manual/sugestao17.png)

Caso o produto tenha sido comprado uma única vez, disponibilizamos algumas informações dessa compra. Veja:

![](https://github.com/ediopedrocode/Projeto-FinanceControl/blob/master/Imagens%20do%20Manual/sugestao18.png)

## Estatísticas

Nessa aba você tem acesso à compra de menor valor, considerando uma unidade do produto. Da mesma forma para a compra de maior valor, além de uma média de gastos totais por produto. Confira um exemplo:

![](https://github.com/ediopedrocode/Projeto-FinanceControl/blob/master/Imagens%20do%20Manual/stats19.png)

## Arquivo

Na opção "Arquivo" temos três opções: Novo, Salvar e Carregar.

![](https://github.com/ediopedrocode/Projeto-FinanceControl/blob/master/Imagens%20do%20Manual/arq20.png)

#### Novo

Ao selecionar "Novo", você será perguntado se deseja salvar o arquivo atual antes de começar um novo. 

![](https://github.com/ediopedrocode/Projeto-FinanceControl/blob/master/Imagens%20do%20Manual/novo1.png)

Caso não, o FinanceControl irá começar um cadastro do zero, sem salvar o que havia sido feito. Caso sim, você será encaminhado ao seu gerenciador de arquivos e irá poder selecionar a pasta e o nome do arquivo. 

É importante ressaltar que o FinanceControl já salva o arquivo em formato .csv automaticamente. Logo, você não precisa se preocupar em escrever a extensão do arquivo, basta pôr o nome.

#### Salvar

A ação "Salvar", diferentemente da ação "Novo", não recomeça o cadastro do zero. Ela apenas salva o arquivo em sua memória, após você selecionar a pasta e o nome, mas mantém os dados no FinanceControl. Lembrando que nessa ação o arquivo também é salvo automaticamente em .csv sem precisar digitar a extensão.

#### Carregar

A ação carregar irá abrir um arquivo já salvo em sua memória, pôr na tabela, e atualizar automaticamente as estatísticas.
Porém, para a sua segurança antes de carregá-lo, perguntaremos se você deseja salvar o cadastro em andamento. O processo é similar ao da função "Novo". A seguinte mensagem aparece: 

![](https://github.com/ediopedrocode/Projeto-FinanceControl/blob/master/Imagens%20do%20Manual/carrega20.png)

Caso não, você perderá o documento atual e irá diretamente para seu gerenciador de arquivos para poder escolher o que deseja abrir. Caso sim, antes de carregar, você poderá escolher a pasta e o nome do novo arquivo que está salvando dentro do seu gerenciador de arquivos. 


# Obrigado por usar o FinanceControl, seu assistente financeiro!


## Informações do desenvolvedor:

#### Desenvolvido por: Édio Pedro Belo de Melo

#### Ferramenta de desenvolvimento: Qt Creator

## Entre em contato e dê seu FeedBack:

#### E-mail: ediopedro22@gmail.com

#### Celular: (083) 98856-4102

#### João Pessoa - PB, Brasil.



