# Campeonato Brasileiro CBF
A CBF está precisando de uma ferramenta para gerenciar o Campeonato Brasileiro, registrando os placares dos jogos e apresentando a classificação do torneio.

Seu programa deve interagir com um dos membros da organização (usuário) e permitir as seguintes funcionalidades:

1) Cadastro de uma equipe
* Ao cadastrar um equipe, é necessário fornecer o nome da equipe, uma sigla de três letras, a ser utilizada na apresentação das tabelas, e a sigla de seu estado de origem;
* Não pode haver duas equipes com o mesmo nome ou com a mesma sigla;
** Caso um novo cadastro seja feito e o nome já esteja cadastrado, o sistema deve, após confirmação do usuário, atualizar os dados da equipe com esse nome;
** Caso a sigla fornecida já esteja em uso, o sistema deverá solicitar ao usuário uma nova sigla;
* Para cada equipe, o sistema deve registrar o desempenho dela na competição atual (ver item 3).

2) Busca por estado
* O usuário pode fornecer a sigla de um estado e obter a lista de todas as equipes deste estado, ordenadas pelo nome da equipe, e apresentadas junto com a sigla associada à mesma;

3) Gerência da competição

3.1) Registro de partidas
* Toda partida envolve duas equipes distintas, sendo uma mandante e outra visitante, e um placar associado, formado pela quantidade de gols que cada uma das duas equipes marcou na partida;
** Ao registrar uma partida, o usuário deve fornecer estas informações no formato MMM X-Y VVV, onde AAA e BBB são as siglas das equipes mandante e visitante, respectivamente, e X e Y são os gols marcados pelas respectivas equipes;
* O sistema deve registrar as partidas que foram realizadas, na ordem em que foram registradas, e permitir a apresentação da lista de partidas realizadas até o momento, na ordem de realização;
* Uma equipe vence uma partida caso tenha marcado mais gols do que o adversário; caso ambas tenham marcado a mesma quantidade de gols, o resultado é um empate;
* Uma partida só pode ser registrada se as duas equipes participantes já tiverem sido cadastradas; se alguma equipe não tiver sido registrada, um erro deve ser apresentado e o registro deve ser ignorado;
* Não há restrições quanto à realização de múltiplas partidas entre as mesmas equipes ou à realização de diferentes quantidade de partidas para cada equipe.

3.2) Desempenho das equipes
* Para cada equipe, o sistema deve manter as seguintes quantidades, computadas a partir das partidas registradas: número de vitórias, empates, e derrotas, número de gols marcados e gols sofridos, pontos obtidos, e saldo de gols;
** Uma equipe obtém 3 pontos para cada vitória, 1 ponto para cada empate, e 0 pontos para cada derrota;
** O saldo de gols é a diferença entre a quantidade de gols marcados e a quantidade de gols sofridos;

3.3) Placar da competição
* O sistema deve imprimir, quando solicitado, o placar atual da competição, com as equipes ordenadas pelo total de pontos obtidos até o momento;
** Em caso de empate nos pontos obtidos, os critérios de desempate, nesta ordem, serão: quantidade de vitórias, saldo de gols, gols marcados, e ordem alfabética do nome da equipe;
* O placar deve ser apresentado como uma tabela, apresentando, para cada equipe, as seguintes informações, nesta ordem: colocação, nome da equipe, pontos obtidos, número de vitórias, número de empates, número de derrotas, gols marcados, gols sofridos, saldo de gols;

Restrições técnicas:

1) Nomes de equipes devem possuir até 30 caracteres, incluindo letras, dígitos, espaços em branco, hífen, e apóstrofos (vocês podem supôr que o usuário nunca fornece um nome de equipe que não satisfaz esta regra);

2) A sigla de estado deve ser uma sigla padrão de uma UF brasileira, formada por duas letras maiúsculas (o sistema deve validar que a sigla corresponde a um estado brasileiro existente);

3) O sistema deve apresentar um menu para o usuário poder realizar as operações descritas anteriormente: cadastro de equipe, busca por estado, registro de partida, apresentação do placar atual;

4) Cada uma das informações fornecidas nas operações anteriores deve ser validada pelo programa no momento que o usuário a fornece, com uma mensagem e um pedido de nova informação sendo apresentadas caso a informação digitada não seja válida;

5) A competição deve permitir o cadastro de até 40 equipes;

Regras adicionais do trabalho:

1) Seu programa deve utilizar (de forma adequada) funções e structs, e implementar ao menos um algoritmo de ordenação entre os vistos em aula;

2) Seu programa não pode utilizar variáveis ou arrays globais;

3) Seu programa deve conter apenas código produzido diretamente pelos membros do grupo, não sendo permitido uso de códigos fornecidos em aulas, materiais online, ou ferramentas de IA generativa;

Dicas (ou fortes recomendações):

1) Antecipem-se ao prazo de entrega para elaborar o trabalho, pois ao final do período teremos menos aulas para poder tirar dúvidas. Não deixe de interagir com o professor (via mural no Classroom) e com os monitores para tirar dúvidas ou trocar ideias sobre estratégias para construir seu programa;

2) Utilizem funções separadas para cada funcionalidade, incluindo interações bem-delimitadas com o usuário (por exemplo, para apresentar ao usuário um menu de seleção e coletar a escolha dele, para coletar dados de uma equipe no ato do cadastro, ou para ler e validar um dado específico fornecido pelo usuário) e ordenações das informações a serem apresentadas;

3) Para reordenar as equipes cadastradas, em vez de manipulá-las diretamente na lista de equipes, em um vetor separado, identifiquem as equipes através do índice em que eles estão armazenados na lista de equipes cadastradas, e ordene esse vetor mudando apenas a função de comparação;

4) Organizem bem seu código e utilizem boas práticas de programação, incluindo uso extenso de comentários, manutenção de indentação e espaçamento entre blocos de código, nomes adequados para variáveis, etc.;

5) Utilizem alguma ferramenta online para compartilhar código entre os membros do grupo (seja uma ferramenta simples como um diretório compartilhado no Google Drive da UNIRIO, seja uma ferramenta avançada como um repositório privado no Github);

6) Interajam em grupo com frequência, pois todos deverão entender o que cada trecho do código faz e por que ele foi construído da forma que foi.
