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
}pessoa;


typedef struct
{
    char NumPatricipante[5];
    char Data[11];
    char Hora[5];
    char NomeAtividade[20];
    int Duraçao;
    int Distançia;
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
        pessoa* Pessoa = (pessoa*)data;
        while (i < max_data && fscanf(file, "4[^;];%99[^;];%10[^;];%d\n", Pessoa[i].NumPatricipante, Pessoa[i].Nome, Pessoa[i].Telefone, &Pessoa[i].Idade) == 4)
        {

        }

    }

}



/*


    // Read the data from the file
    size_t i = 0;
    if (strcmp(data_type, "person") == 0) // AQUIII   {
        // Read data from the file as person data
        person* people = (person*)data;
        while (i < max_data && fscanf(file, "%4[^;];%99[^;];%10[^;];%d\n", people[i].id, people[i].name, people[i].phone, &people[i].age) == 4) {
            i++;
        }
    }
    else if (strcmp(data_type, "atividade") == 0) {
        // Read data from the file as atividade data
        atividade* atividades = (atividade*)data;
        while (i < max_data && fscanf(file, "%4[^;];%10[^;];%5[^;];%99[^;];%d;%d;%2s\n", atividades[i].id, atividades[i].data, atividades[i].hora, atividades[i].nome, &atividades[i].duracao, &atividades[i].distancia, atividades[i].unim) == 7) {
            i++;
        }
    }
    else if (strcmp(data_type, "dadosp") == 0) {
        // Read data from the file as dadosp data
        dadosp* dadop = (dadosp*)data;
        while (i < max_data && fscanf(file, "%4[^;];%10[^;];%5[^;];%10[^;];%5[^;];%99[^;];%d;%2s\n", dadop[i].id, dadop[i].data, dadop[i].hora, dadop[i].dataf, dadop[i].horaf, dadop[i].nome, &dadop[i].distancia, dadop[i].unim) == 8) {
            i++;
        }
    }

    // Close the file
    fclose(file);
}


int ex1() {

    // Read the file and store the data in an array of people
    const char* filename = "dados_praticantes.txt";
    person people[100];
    read_file(filename, "person", people, 100);

    // Print the data to standard output
    for (size_t i = 0; i < 100; i++) {
        if (strlen(people[i].id) == 0) {
            break;
        }

        printf("ID: %s, Nome: %s, Telefone: %s, Idade: %d\n", people[i].id, people[i].name, people[i].phone, people[i].age);

    }
    printf("\n");

    return 0;
}

int ex2() {

    // Read the file and store the data in an array of atividade
    const char* filename = "ativ_praticantes.txt";
    atividade atividade[100];
    read_file(filename, "atividade", atividade, 100);
    */
