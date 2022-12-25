#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char NumPatricipante[5];
    char Nome[50];
    char Telefone[9];
    int Idade;
}Pessoa;


typedef struct
{
    char NumPatricipante[5];
    char Data[11];
    char Hora[5];
    char NomeAtividade[20];
    int Duraçao;
    int Distancia;
    char Medida[2];
}Atividade;

typedef struct
{
    char NumPatricipante[5];
    char DataInicio;
    char HoraInicio;
    char DataFim;
    char HoraFim;
    char NomeAtvidade;
    int Distancia;
    char Medida;
}PlanoTreino;


void File(const char* fileNome, char* data_type, void* data, size_t max_data)
{
    FILE* file = fopen(fileNome, "r");

    if (!file)
    {
        fprintf(stderr, "Erro ao abrir o Ficheiro %s\n", fileNome);
        return;
    }

    size_t i = 0;
    if (strcmp(data_type, "Pessoa") == 0)
    {
        Pessoa* pessoa = (Pessoa*)data;
        while (i < max_data && fscanf(file, "4[^;];%99[^;];%10[^;];%d\n", pessoa[i].NumPatricipante, pessoa[i].Nome, pessoa[i].Telefone, &pessoa[i].Idade) == 4)
        {
            i++;
        }

    }
    else if (strcmp(data_type, "Atividade") == 0)
    {
        Atividade* atividade = (Atividade*)data;
        while (i < max_data && fscanf(file, "%4[^;];%10[^;];%5[^;];%99[^;];%d;%d;%2s\n", atividade[i].NumPatricipante, atividade[i].Data, atividade[i].Hora, atividade[i].NomeAtividade, &atividade[i].Duraçao
            , &atividade[i].Distancia, atividade[i].Medida) == 7)
        {
            i++;
        }
    }
    else if (strcmp(data_type, "Plano de Treino") == 0)
    {
        PlanoTreino* planotreino = (PlanoTreino*)data;
        while (i < max_data && fscanf(file, "%4[^;];%10[^;];%5[^;];%99[^;];%d;%d;%2s\n", planotreino[i].NumPatricipante, planotreino[i].DataInicio, planotreino[i].HoraInicio, planotreino[i].DataFim, planotreino[i].HoraFim, planotreino[i].NomeAtvidade, planotreino[i].Medida) == 8)
        {
            i++;
        }
    }
    fclose(file);
}

int ex1()
{
    const char* fileNome = "Praticantes.txt";
    Pessoa pessoa[100];
    File(fileNome, "pessoa", pessoa, 100);

    for (size_t i = 0; i < 100; i++)
    {
        if (strlen(pessoa[i].NumPatricipante) == 0)
        {
            break;
        }

        printf("NumPatricipante: %s, Telefone: %s, Idade:%d\n", pessoa[i].NumPatricipante, pessoa[i].Nome, pessoa[i].Telefone, pessoa[i].Idade);
    }

    printf("\n");
    return 0;


}

/*int ex2()
{
    const char* fileNome = "Atividade.txt";
    Atividade atividade[100];
    read_file(fileNome, "Atividade", atividade, 100);
}
*/
  
