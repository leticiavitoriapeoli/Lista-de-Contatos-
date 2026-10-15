//ARQUIVO MAIN: LISTA DE CONTATOS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListadeContatos.h"

int main(){

     // Cria a lista na memória e carrega os contatos
    // que já estavam salvos no arquivo.
    Lista *li = criaLista();
    carregarArquivo(li);

    int escolher;
    int codigo;
    char nome[30];
    CLIENTE c;

    //Menu ficará repetindo até o usuário  pedir escolher a opcao 7.
    do{
        printf("\n\tLISTA DE CONTATOS ACME S.A\n\n");
        printf("1: Inserir contato\n");
        printf("2: Listar contatos\n");
        printf("3: Buscar por codigo\n");
        printf("4: Buscar por nome\n");
        printf("5: Editar contato\n");
        printf("6: Remover contato\n");
        printf("7: Sair\n");
        printf("\nDigite qual opcao: ");

        scanf("%d",&escolher);

        switch(escolher){

         //Inserir Contato
        case 1:
        c = coletaDados();

        if(insereOrdenado(li,c)){
            printf("\nContato Inserido.\n");
        }else{
            printf("Codigo duplicado.\n");
        }
        break;

        //Imprimir Lista de Contatos
        case 2:
        imprimirLista(li);
        break;

         //Busca pelo Codigo
        case 3:
        printf("Codigo: ");
        scanf("%d",&codigo);

        if(consultaCodigo(li, codigo, &c)){
            printf("\nNome: %s\n", c.nome);
        }else{
            printf("Contato nao encontrado.\n");
        }
        break;

        //Busca pelo nome
        case 4:
        getchar();  // Limpa o /n deixado pelo scanf na opcao "escolha"
        printf("Nome: ");
        fgets(nome,30,stdin);

        nome[strcspn(nome,"\n")] = '\0';
        consultaNome(li,nome);
        break;

        //Editar contato
        case 5:
        printf("Codigo: ");
        scanf("%d",&codigo);
        editarContato(li,codigo);
        break;

         //Remover contato
        case 6:
        printf("Codigo: ");
        scanf("%d",&codigo);

        if(removeOrdenado(li,codigo)){
            printf("\nContato removido.\n");
            }else{
                printf("\nNao encontrado.\n");
        }
        break;

         //Encerrar programa e salva todos os contatos
        case 7:            // que estão na lista dentro do arquivo
        salvarArquivo(li);
        printf("Dados salvos em clientes.bin.\n");
        break;
        }
        //para reinicializar o programa
        printf("\nENTER para voltar ao menu.");
        getchar(); // apaga o \n
        getchar(); //enter do usuario
        system("cls");

        }while(escolher != 7);


    //ultimo código do main
    apagaLista(li);

    return 0;
}
