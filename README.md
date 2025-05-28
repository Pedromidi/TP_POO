Aplicação

 ![image](https://github.com/user-attachments/assets/98bb671e-86f3-4676-9fa1-856031e5a003)

A aplicação é composta por 3 áreas diferentes, Habitacao, Comandos e Notificacoes; é possível ver um histórico de 5 comandos antes da janela de comandos ser apagada e a janela de notificações recebe update a cada comando dado pelo utilizador.
No fundo do ecrã é possível ver o instante atual em que a habitação se encontra.


Classes

Foram criadas classes para: 
Habitacao: composta por um vector de zonas (já que podem existir várias zonas numa habitação), e o seu tamanho (linhas e colunas), existem métodos para aceder a dimensão da habitação e construir/destruir uma habitação, o construtor recebe o tamanho da nova habitação (linhas, colunas); 

Zona: composta por linhas e colunas (posição onde fica na habitação), o seu ID, e vectores para as propriedades, sensores, aparelhos e processadores da zona, tem métodos para adicionar esses componentes à zona e o seu construtor recebe o espaço que ela ocupa (linhas e colunas) e o seu ID;

Sensor: composto pelo seu ID e propriedade a monitorizar na zona, tem métodos para devolver essa propriedade, devolver o seu ID, construtor (que recebe a propriedade do sensor) e destrutor;

Processador: composta por um vetor de Regras e o ID do processador, tem métodos para adicionar regras ao vector, processar regras que estão no vector (por agora tem apenas as regras “igual_a”, “maior_que”, “menor_que”, “entre” e “fora”), um método que devolve o ID do processador e o seu destrutor e construtor, que como parâmetros recebe o ID o novo processador;

Aparelho: classe base para todos os tipos de aparelho, tem os métodos virtuais comuns aos diferentes aparelhos e o destrutor de aparelhos;

aquecedor: tem o ID do aquecedor, métodos para mudar de estado (ligado/desligado), receber comandos, processar a função do aquecedor (incrementar a temperatura) e devolver o seu ID e estado.

refrigerador: tem o ID do refrigerador, métodos para mudar de estado (ligado/desligado), receber comandos, processar a função do aquecedor (decrementar a temperatura) e devolver o seu ID e estado.

lampada: tem o ID da lampada, métodos para mudar de estado (ligado/desligado), receber comandos, processar a função do aquecedor (incrementar a luminosidade) e devolver o seu ID e estado.

aspersor: tem o ID do aspersor, métodos para mudar de estado (ligado/desligado), receber comandos, processar a função do aquecedor (incrementar a humidade/vibração) e devolver o seu ID e estado.

Regra:  composta por uma string, para a regra (por exemplo “entre”) e dois inteiros, para os valores da regra (por exemplo 10 e 20, a regra ficaria “entre 10 e 20”), tem ainda o destrutor e dois construtores, um para regras com um número (“maior_que”) e outro para regras com dois números (“entre”) e os métodos get para a string da regra e os respectivos valores da mesma;

Propriedades:  classe base para todos os tipos de propriedade, tem os métodos virtuais comums aos diferentes aparelhos e o destrutor de aparelhos;

Luz, Som, Fumo, Vibracao, Radiacao, Humidade e Temperatura são todas classes propriedades com os métodos para obter o nome e valor da propriedade e alterar esse valor.	


Relacionamento entre Classes

 ![image](https://github.com/user-attachments/assets/a8853ff6-f512-4a38-9bb7-95920eedecac)

A classe Habitacao tem um vetor de classes Zona, por sua vez Zona tem vetores para as classes Aparelho, Sensor, Propriedade e Processador.
As classes Luz, Som, Fumo, Vibracao, Radiacao, Humidade e Temperatura extendem da classe Propriedade, assim como as classes lâmpada, aspersor, aquecedor e refrigerador extendem da class Aparelho. 
A class Processador tem um vetor que armazena Regras.
Sensores têm acesso ao valor das propriedades e Aparelhos conseguem modificar esse valor.

