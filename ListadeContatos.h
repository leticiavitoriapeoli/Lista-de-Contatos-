//ARQUIVO H: LISTA DE CONTATOS


typedef struct cliente{

    int codigo;
    char nome[30];
    char empresa[20];
    char departamento[20];
    char telefone[15];
    char celular[15];
    char email[50];

}CLIENTE;

typedef struct elemento* Lista;


Lista* criaLista();

void apagaLista(Lista *li);

int listaVazia(Lista *li);

CLIENTE coletaDados();

int insereOrdenado(Lista *li, CLIENTE c);

int removeOrdenado(Lista *li, int codigo);

int consultaCodigo(Lista *li, int codigo, CLIENTE *c);

void consultaNome(Lista *li, char *nome);

void imprimirLista(Lista *li);

void editarContato(Lista *li, int codigo);

void salvarArquivo(Lista *li);

void carregarArquivo(Lista *li);
