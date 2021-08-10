#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct info
{
	long long cpf;
	char Nome[50];
	char Sexo[1];
	int Idade;
	int Pontos;
	char Ala[11];
};

void cabecalho();
struct info Cadastrar();
int Questionario();
void Encaminhamento(char *Ala, int Pontos);
void salvarcadastro();

int main()
{
	setlocale(LC_ALL,"Portuguese");
	struct info cadastro;
	int confcadastro;
	int loop;
	loop = 0;
	cabecalho();
	
	printf("Olá!\n\nCaro(a) paciente, seja bem vindo(a) ao Hospital Última Estação!\n\nDevido a atual crise de saúde do mundo, pedimos por gentileza preencher\nos dados solicitados a seguir para te encaminharmos à ala do hospital mais adequada às suas necessidades.\n\nSeja honesto nas respostas, assim podemos ser mais assertivos no seu tratamento e nos demais.");
	printf("\n\n");
	system("pause");
	confcadastro = 0;
	while(confcadastro == 0)
	{
	cadastro = Cadastrar();
	cabecalho();
	printf("Por favor verifique se as informações abaixo estão corretas.\n\n");
	printf("CPF: %lld\n", cadastro.cpf);
	printf("NOME: %s\n", cadastro.Nome);
	printf("Sexo: %s\n", cadastro.Sexo);
	printf("Idade: %d ANOS\n", cadastro.Idade);
	printf("\nPara confirmar digite 1, para corrigir digite 0.\n");
	scanf("%d", &confcadastro);
	fflush(stdin);
	}
	cadastro.Pontos = Questionario();
	Encaminhamento(cadastro.Ala, cadastro.Pontos);
	cabecalho();
	printf("\nFAVOR DIRIGIR-SE À ALA:\n************************* %s *************************\n\n", cadastro.Ala);
	salvarcadastro(cadastro);
	return 0;
}

void cabecalho()
{
	printf("----------------------------------------------------------\n HOSPITAL ÚLTIMA ESTAÇÃO!\n SEJA BEM VINDO!\n TRIAGEM covid-19\n----------------------------------------------------------\n\n");
}

struct info Cadastrar()
{
	struct info cadastro;
	system("cls");
	cabecalho();
	printf("Digite o seu CPF(somente números):\n");
	scanf("%lld", &cadastro.cpf);
	fflush(stdin);
	system("cls");
	cabecalho();
	printf("Digite seu nome completo:\n");
	gets(cadastro.Nome);
	strupr(cadastro.Nome);
	system("cls");
	cabecalho();
	printf("Digite a letra referente ao seu sexo: [M] [F]\n");
	gets(cadastro.Sexo);
	strupr(cadastro.Sexo);
	system("cls");
	cabecalho();
	printf("Digite sua idade:\n");
	scanf("%d", &cadastro.Idade);
	fflush(stdin);
	system("cls");
	return cadastro;
}

int Questionario()
{
	int soma, opcao;
	system("cls");
	cabecalho();
	printf("Tem febre?\nSim = 1\nNão = 0\n");
	scanf("%d", &opcao);
	fflush(stdin);
	if (opcao == 1)
	{
		soma = soma+5;
	}
	system("cls");
	
	cabecalho();
	printf("Tem dor de cabeça?\nSim = 1\nNão = 0\n");
	scanf("%d", &opcao);
	fflush(stdin);
	if (opcao == 1)
	{
		soma = soma+1;
	}
	system("cls");
	
	cabecalho();
	printf("Tem secreção nasal ou espirros?\nSim = 1\nNão = 0\n");
	scanf("%d", &opcao);
	fflush(stdin);
	if (opcao == 1)
	{
		soma = soma+1;
	}
	system("cls");
	
	cabecalho();
	printf("Tem dor/irritação na garganta?\nSim = 1\nNão = 0\n");
	scanf("%d", &opcao);
	fflush(stdin);
	if (opcao == 1)
	{
		soma = soma+1;
	}
	system("cls");
	
	cabecalho();
	printf("Tem tosse seca?\nSim = 1\nNão = 0\n");
	scanf("%d", &opcao);
	fflush(stdin);
	if (opcao == 1)
	{
		soma = soma+3;
	}
	system("cls");
	
	cabecalho();
	printf("Tem dificuldade respiratória?\nSim = 1\nNão = 0\n");
	scanf("%d", &opcao);
	fflush(stdin);
	if (opcao == 1)
	{
		soma = soma+10;
	}
	system("cls");	
		
	cabecalho();
	printf("Tem dores no corpo?\nSim = 1\nNão = 0\n");
	scanf("%d", &opcao);
	fflush(stdin);
	if (opcao == 1)
	{
		soma = soma+1;
	}
	system("cls");
		
	cabecalho();
	printf("Tem diarréia?\nSim = 1\nNão = 0\n");
	scanf("%d", &opcao);
	fflush(stdin);
	if (opcao == 1)
	{
		soma = soma+1;
	}
	system("cls");
		
	cabecalho();
	printf("Esteve em contato, nos últimos 14 dias, com um caso diagnosticado com COVID-19?\nSim = 1\nNão = 0\n");
		scanf("%d", &opcao);
	fflush(stdin);
	if (opcao == 1)
	{
		soma = soma+10;
	}
	system("cls");
	
	cabecalho();
	printf("Esteve em locais com grande aglomeração?\nSim = 1\nNão = 0\n");
	scanf("%d", &opcao);
	fflush(stdin);
	if (opcao == 1)
	{
		soma = soma+3;
	}
	system("cls");
	return soma;
}

void Encaminhamento (char *Ala, int Pontos)
{	
	if(Pontos < 10)
	{
		strcpy(Ala, "RISCO BAIXO");
	}
	else
	{
		if(Pontos > 19)
		{
			strcpy(Ala, "RISCO ALTO");
		}
		else
		{
			strcpy(Ala, "RISCO MÉDIO");
		}
	}

}

void salvarcadastro(struct info cad)
{
	FILE *arq;
	arq = fopen("triagem.txt", "a");
	fprintf(arq, "%lld, %s, %s, %d, %d, %s\n", cad.cpf, cad.Nome, cad.Sexo, cad.Idade, cad.Pontos, cad.Sexo);
	fclose(arq);	
}
