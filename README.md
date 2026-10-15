# Gerenciador de Lista de Contatos - EDA1

> Projeto avaliativo desenvolvido para a disciplina de Estruturas de Dados 1 

# Sobre o Projeto
O programa implementa uma Lista Dinâmica Encadeada, garantindo a persistência dos dados entre diferentes sessões de trabalho através de gravação em arquivo binário.

# Decisões de Implementação e Arquitetura

* Lista Dinâmica Encadeada: O programa baseia-se em uma estrutura de lista dinâmica onde cada nó armazena os dados do cliente e um ponteiro para o próximo elemento (`struct cliente + ponteiro prox`).
* Ordenação por Código: Os elementos na lista são mantidos em ordem crescente com base no atributo `código`. A inserção e a remoção são feitas de forma ordenada, e o incremento automático do código não é utilizado.
* Validação de Duplicidade: Durante a inserção de novos clientes, o sistema realiza uma busca prévia para garantir que o código informado não seja duplicado.
* Dados salvos em bin: Ao iniciar o programa, os dados são carregados automaticamente de um arquivo binário para a memória (lista dinâmica). Ao encerrar o programa pela opção correta do menu, toda a lista é percorrida e salva novamente no arquivo, garantindo que não haja perda de informações.
* Modularização: O código foi totalmente modularizado em funções específicas para cada tarefa (leitura, manipulação da lista, buscas, relatórios, gravação e exibição de menu).

# Funcionalidades do Menu

O sistema conta com um menu interativo exibido de forma ininterrupta com as seguintes opções:

1. Inserção de novo contato: Coleta os dados, verifica se o código já existe e insere ordenadamente na lista[cite: 2].
2. Relatório - Lista Total: Exibe em tela todos os clientes cadastrados.
3. Relatório Individual (Busca por Código): Localiza e exibe os dados detalhados de um cliente específico através do seu identificador[cite: 3].
4. Busca por Nome: Pesquisa clientes por nome, exibindo todos os registros correspondentes.
5. Edição de Contato: Localiza o cliente por código, exibe seus dados atuais e permite a alteração das informações.
6. Remoção de Contato: Busca o cliente por código, solicita confirmação e o remove da lista dinâmica.
7. Sair e Encerrar: Executa a rotina de salvamento de toda a lista em arquivo binário e finaliza a aplicação com segurança.


# Estrutura de Arquivos

* `main.c` / Arquivos fonte (`.c` e `.h`): Contêm a lógica do programa, funções de manipulação da lista e o menu.
* `contatos.bin`: Arquivo binário gerado automaticamente para o armazenamento persistente dos registros.


# Como Compilar e Executar

1. Certifique-se de ter um compilador C instalado (como o GCC) ou abra o projeto diretamente na IDE Code::Blocks.
2. Clone este repositório:
   ```bash
   git clone [https://github.com/leticiavitoriapeoli/Lista-de-Contatos.git](https://github.com/leticiavitoriapeoli/Lista-de-Contatos.git)
