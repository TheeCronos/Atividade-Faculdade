#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define max 200

struct projetos{
    int code;
    char title[30];
    char descri[500]; 
    int year;
    int prediction;
    int status;
    char manager[30];
    char supervisor[30];
    char platform[30];
};

struct projetos project[max];

int i = 0;

void cadastrar();
void modificar();
void listar();
void busca_codigo();
void busca_status();

int main(){
    setlocale(LC_ALL, "portuguese");
    struct projetos project[max];

    int y;

    system("cls");
    do{
        system("cls");
        printf(" _______________________________________________________\n");
        printf("|                                                       |\n");
        printf("|                           Menu                        |\n");
        printf("|                 1 - Cadastrar projeto                 |\n");
        printf("|                 2 - Modificar projeto                 |\n");
        printf("|                 3 - Lista de projetos                 |\n");
        printf("|                 4 - Buscar por código                 |\n");
        printf("|                 5 - Buscar por status                 |\n");
        printf("|                 6 - Sair                              |\n");
        printf("|                                                       |\n");
        printf("|_______________________________________________________|\n");
        printf("\n");
        printf("Selecione a opção desejada: ");
        fflush(stdin);
        scanf("%d", &y);

        switch (y){
            case 1:
                cadastrar();
                break;
            case 2:
                modificar();
                break;
            case 3:
                lista();
                break;
            case 4:
                busca_codigo();
                break;
            case 5:
                busca_status();
                break;
            case 6:
                printf("\nFinalizando...\n");
                printf("\n");
                system("pause");
                break;
            default:
                printf("\nOpção inválida\n");
                system("pause");
        }
    }while(y != 6);
    return 0;
}

void cadastrar(){
    system("cls");
    printf(" _______________________________________________________\n");
    printf("|                                                       |\n");
    printf("|                                                       |\n");
    printf("|                  CADASTRO DE PROJETO                  |\n");
    printf("|                                                       |\n");
    printf("|_______________________________________________________|\n");
    char resp = 's';

    while(resp == 's' && i < max){
        i++;

        printf("\nCódigo: %d \n", i);
        project[i].code = i;

        printf("Informe o titulo: ");
        fflush(stdin);
        gets(project[i].title);

        printf("Descrição do projeto: ");
        fflush(stdin);
        gets(project[i].descri);

        printf("Informe o ano: ");
        fflush(stdin);
        scanf("%i", &project[i].year);

        printf("Informe a previsão de término: ");
        fflush(stdin);
        scanf("%i", &project[i].prediction);

        do{
            printf(" _______________________________________________________\n");
            printf("|                   Informe o status                    |\n");
            printf("| 1: Aguardando inicio - 2: Em andamento - 3: Concluído |\n");
            printf("|_______________________________________________________|\n");
            printf("Status: ");
            fflush(stdin);
            scanf("%i", &project[i].status);
        }while((project[i].status == 0) || (project[i].status > 3));
        
        printf("Gerente Responsável: ");
        fflush(stdin);
        gets(project[i].manager);

        printf("Supervisor: ");
        fflush(stdin);
        gets(project[i].supervisor);

        printf("Plataforma utilizada: ");
        fflush(stdin);
        gets(project[i].platform);

        printf("________________________________________________________\n");

        if (i < max){
            printf("\nDeseja cadastrar outro projeto? (s/n): ");
            fflush(stdin);
            scanf("%c", &resp);
        }else{
            resp = 'n';
        }
    }
    if (i >= max){
        printf("\nLimite de cadastro atingido!\n");
        printf("\n");
        system("pause");
    }
}

void modificar(){
    system("cls");
    printf(" _______________________________________________________\n");
    printf("|                                                       |\n");
    printf("|                                                       |\n");
    printf("|                   MODIFICAR PROJETO                   |\n");
    printf("|                                                       |\n");
    printf("|_______________________________________________________|\n");
    printf("\n");

    int i = 0;
    printf("\nDigite o código do projeto que deseja modificar: ");
    fflush(stdin);
    scanf("%d", &i);

    printf("\nCódigo: %d \n", i);
    project[i].code = i;

    printf("Informe o titulo: ");
    fflush(stdin);
    gets(project[i].title);

    printf("Descrição do projeto: ");
    fflush(stdin);
    gets(project[i].descri);

    printf("Informe o ano: ");
    fflush(stdin);
    scanf("%i", &project[i].year);

    printf("Informe a previsão de término: ");
    fflush(stdin);
    scanf("%i", &project[i].prediction);

    do{
        printf(" _______________________________________________________\n");
        printf("|                   Informe o status                    |\n");
        printf("| 1: Aguardando inicio - 2: Em andamento - 3: Concluído |\n");
        printf("|_______________________________________________________|\n");
        printf("Status: ");
        fflush(stdin);
        scanf("%i", &project[i].status);
    }while((project[i].status == 0) || (project[i].status > 3));

    printf("Gerente Responsável: ");
    fflush(stdin);
    gets(project[i].manager);

    printf("Supervisor: ");
    fflush(stdin);
    gets(project[i].supervisor);

    printf("Plataforma utilizada: ");
    fflush(stdin);
    gets(project[i].platform);

    system("pause");
}

void lista(){
    system("cls");
    printf(" _______________________________________________________\n");
    printf("|                                                       |\n");
    printf("|                                                       |\n");
    printf("|                   LISTA DE PROJETOS                   |\n");
    printf("|                                                       |\n");
    printf("|_______________________________________________________|\n");
    int j;

    for (j = 1; j <= max; j++){
        if (project[j].code != 0){
            printf("\n");
            printf("Código: %i\n", project[j].code);
            printf("Titulo: %s\n", project[j].title);
            printf("Descrição: %s\n", project[j].descri);
            printf("Ano: %i\n", project[j].year);
            printf("Previsão de término: %i\n", project[j].prediction);
            if(project[j].status == 1){
                printf("Status: %i - Aguardando início.\n", project[j].status);
            }if(project[j].status == 2){
                printf("Status: %i - Em andamento.\n", project[j].status);
            }if(project[j].status == 3){
                printf("Status: %i - Concluído.\n", project[j].status);
            }
            printf("Gerente responsável: %s\n", project[j].manager);
            printf("Supervisor: %s\n", project[j].supervisor);
            printf("Plataforma: %s\n", project[j].platform);
            printf("_____________________________\n");
            }
        }
    system("pause");
}

void busca_codigo(){
    system("cls");
    printf(" _______________________________________________________\n");
    printf("|                                                       |\n");
    printf("|                                                       |\n");
    printf("|                    BUSCA POR CÓDIGO                   |\n");
    printf("|                                                       |\n");
    printf("|_______________________________________________________|\n");

    int cont, again;
    int w = 0;
    again = 0;
    printf("\nInforme o código do projeto: ");
    fflush(stdin);
    scanf("%d", &cont);
    printf("\n");

    while((again == 0) && (w <= i)){
        if(cont == project[w].code){
            printf("Código: %d\n", project[w].code);
            printf("Titulo: %s\n", project[w].title);
            printf("Descrição: %s\n", project[w].descri);
            printf("Ano: %i\n", project[w].year);
            printf("Previsão de término: %i\n", project[w].prediction);
            if(project[w].status == 1){
                printf("Status: %i - Aguardando início.\n", project[w].status);
            }if(project[w].status == 2){
                printf("Status: %i - Em andamento.\n", project[w].status);
            }if(project[w].status == 3){
                printf("Status: %i - Concluído.\n", project[w].status);
            }
            printf("Gerente responsável: %s\n", project[w].manager);
            printf("Supervisor: %s\n", project[w].supervisor);
            printf("Plataforma: %s\n", project[w].platform);            
            printf("\n");
            again = 1;
            system("pause");
        }
        w++;
    }
        if(again == 0){
            printf("\nRegistro nao encontrado.\n");
            printf("\n");
            system("pause");
        }
}

void busca_status(){
    system("cls");
    printf(" _______________________________________________________\n");
    printf("|                                                       |\n");
    printf("|                                                       |\n");
    printf("|                    BUSCA POR STATUS                   |\n");
    printf("|                                                       |\n");
    printf("|_______________________________________________________|\n");

    int cont;
    int z = 1;
    printf(" _______________________________________________________\n");
    printf("|                   Informe o status                    |\n");
    printf("| 1: Aguardando inicio - 2: Em andamento - 3: Concluído |\n");
    printf("|_______________________________________________________|\n");
    printf("\nStatus do projeto: ");
    fflush(stdin);
    scanf("%d", &cont);
    printf("\n");

    while(z <= max){
        if(cont == project[z].status){
            printf("Código: %d\n", project[z].code);
            printf("Titulo: %s\n", project[z].title);
            printf("Descrição: %s\n", project[z].descri);
            printf("Ano: %i\n", project[z].year);
            printf("Previsão de término: %i\n", project[z].prediction);
            if(project[z].status == 1){
                printf("Status: %i - Aguardando início.\n", project[z].status);
            }if(project[z].status == 2){
                printf("Status: %i - Em andamento.\n", project[z].status);
            }if(project[z].status == 3){
                printf("Status: %i - Concluído.\n", project[z].status);
            }
            printf("Gerente responsável: %s\n", project[z].manager);
            printf("Supervisor: %s\n", project[z].supervisor);
            printf("Plataforma: %s\n", project[z].platform); 
            printf("\n");
        }
        z++;
    }
    system("pause");
}