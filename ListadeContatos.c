//ARQUIVO C: LISTA DE CONTATOS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ListadeContatos.h"


    struct elemento{             //Nó da lista onde guarda os dados do cliente
    CLIENTE dados;                 //e o ponteiro para o próximo
    struct elemento *prox;

    };
    typedef struct elemento ELEM;


    Lista* criaLista(){

    Lista *li;
    li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
    }



    void apagaLista(Lista *li){
     if(li == NULL){
        return;
    }
    ELEM *no;
    // Percorre a lista liberando a memória de cada nó.
    while((*li) != NULL){
        no = *li;
        *li = no->prox;
            free(no);
        }
    free(li);
    }



    int listaVazia(Lista *li){
     if(li == NULL){
        return 1;
        }

    if(*li == NULL){
        return 1;
    }
    return 0;
   }



    //funcao para coletar os dados apos o usuario
    //escolher a opcao 1

    CLIENTE coletaDados(){
        CLIENTE c;
        printf("\nCodigo: ");
        scanf("%d",&c.codigo);
    // O getchar para tirar o buffer do scanf
    // e fgets para ler o nome direto
        getchar();

        printf("Nome: ");
        fgets(c.nome,30,stdin);
        c.nome[strcspn(c.nome,"\n")] = '\0';

        // usei strcspn para o ultimo enter e substituir por '\0'.

        printf("Empresa: ");
        fgets(c.empresa,20,stdin);
        c.empresa[strcspn(c.empresa,"\n")] = '\0';

        printf("Departamento: ");
        fgets(c.departamento,20,stdin);
        c.departamento[strcspn(c.departamento,"\n")] = '\0';

        printf("Telefone: ");
        fgets(c.telefone,15,stdin);
        c.telefone[strcspn(c.telefone,"\n")] = '\0';

        printf("Celular: ");
        fgets(c.celular,15,stdin);
        c.celular[strcspn(c.celular,"\n")] = '\0';

        printf("Email: ");
        fgets(c.email,50,stdin);
        c.email[strcspn(c.email,"\n")] = '\0';

        return c;
    }



    int insereOrdenado(Lista *li, CLIENTE c){
      if(li == NULL){
        return 0;
      }

    //Alocagem de memória para o novo nó
    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    no->dados = c;


    ELEM *aux = *li;

    // Verifica se já existe um contato com o mesmo código
    while(aux != NULL){
        if(aux->dados.codigo == c.codigo){
            return 0;    // Se existir, não é inserido
            }
            aux = aux->prox;
        }

    if(listaVazia(li)){
        no->prox = NULL;
        *li = no;
        return 1;
    }
    //Cria ponteiro elem anterior, do elem atual
    ELEM *ant = NULL;
    ELEM *atual = *li;

    // Percorre a lista até encontrar a posição correta
    // para manter os contatos ordenados pelo código
    while(atual != NULL && atual->dados.codigo < c.codigo){
        ant = atual;
        atual = atual->prox;
    }

    //Se for o primeiro elem, insere o novo contato no começo da lista
    if(ant == NULL){
     no->prox = *li;
     *li = no;
        }else{               // Liga o novo elemento entre o anterior e o atual
        no->prox = atual;
        ant->prox = no;
            }
        return 1;
    }



    int removeOrdenado(Lista *li, int codigo){
     if(li == NULL){
      return 0;
     }

    ELEM *ant = NULL;
    ELEM *no = *li;

    // Procura o contato que tem o código digitado
    while(no != NULL && no->dados.codigo != codigo){
     ant = no;
     no = no->prox;
        }

    if(no == NULL){
     return 0;
    }

    // Ajusta os ponteiros para remover o elemento da lista
    if(ant == NULL){
    *li = no->prox;
        }else{
            ant->prox = no->prox;
            }
         free(no);

        return 1;
    }



    // Para procurar um contato pelo código
    int consultaCodigo(Lista *li, int codigo, CLIENTE *c){
     if(li == NULL){
        return 0;
        }

    ELEM *no = *li;

    while(no != NULL && no->dados.codigo != codigo){
    no = no->prox;
        }

    if(no == NULL){
     return 0;
    }

     *c = no->dados;
     return 1;
    }

    void consultaNome(Lista *li, char *nome){
     ELEM *no = *li;

    //criação da váriavel de encontro do nome
    int encontrou = 0;
    while(no != NULL){

    // Usei strcmp para comparar as duas strings. Se for 0, são exatamente iguais.
    if(strcmp(no->dados.nome,nome)==0){
     printf("\nCodigo: %d", no->dados.codigo);

        printf("\nNome: %s\n", no->dados.nome);
        encontrou = 1;
    }
    no = no->prox;
    }

    if(!encontrou)
        printf("Contato não encontrado.\n");
    }


    void imprimirLista(Lista *li){
    ELEM *no = *li;

    while(no != NULL){
    printf("\nCodigo: %d",no->dados.codigo);
    printf("\nNome: %s",no->dados.nome);
    printf("\nEmpresa: %s",no->dados.empresa);
    printf("\nDepartamento: %s",no->dados.departamento);
    printf("\nTelefone: %s",no->dados.telefone);
    printf("\nCelular: %s",no->dados.celular);
    printf("\nEmail: %s\n",no->dados.email);
    no = no->prox;
        }
    }

    void editarContato(Lista *li, int codigo){
    ELEM *no = *li;
    // Procurar o contato que a pessoa quer editar.
        while(no != NULL && no->dados.codigo != codigo){
            no = no->prox;
        }

        if(no == NULL){
            printf("Contato nao encontrado.\n");
            return;
        }

        getchar();
        // getchar para limpar o buffer antes do fgets.
        printf("Novo nome: ");
        fgets(no->dados.nome,30,stdin);

        no->dados.nome[strcspn(no->dados.nome,"\n")] = '\0';
    }

    void salvarArquivo(Lista *li){
    FILE *arq = fopen("contatos.bin","wb");

     if(arq == NULL){
        return;
    }

    ELEM *no = *li;

    while(no != NULL){
        // Grava 1 contato por vez no arq binario
        fwrite(&no->dados, sizeof(CLIENTE), 1, arq);
        no = no->prox;
        }
    fclose(arq);
    }

    void carregarArquivo(Lista *li){
     FILE *arq = fopen("contatos.bin","rb");

     if(arq == NULL){
        return;
    }
      // Variável que recebe os contatos inseridos
    CLIENTE c;

    //le um contato por vez e se conseguir continua
    while(fread(&c, sizeof(CLIENTE),1, arq) == 1){
    insereOrdenado(li,c);
        // Aproveitei a função de inserir ordenado

        }
        fclose(arq);
    }
