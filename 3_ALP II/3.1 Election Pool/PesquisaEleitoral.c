#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
	int votar_pref, votar_vere, vere_nulo, pref_nulo, vere_111, vere_222, vere_333, pref_11, pref_22, vere_invalido, pref_invalido, menu, password, password1;
	
	setlocale(LC_ALL, "Portuguese");
	password = 123456;
	vere_nulo = 0;
	pref_nulo = 0;
	vere_111 = 0;
	vere_222 = 0;
	vere_333 = 0;
	pref_11 = 0;
	pref_22 = 0;
	vere_invalido = 0;
	pref_invalido = 0;
	
	INICIO:
	printf("\nEscolha uma das opções abaixo digitando o número correspondente:\n\n 1 - Votar\n 2 - Apuração dos Votos (Com Senha)\n 3 - Sair (Com Senha)\n\n");
	scanf("%d", &menu);
	fflush(stdin);
	system("cls");
	switch(menu)
	{
		case 1:
			printf("\nDigite o número do candidato a vereador escolhido:\n\n 111 - João do Frete\n 222 - Maria da Pamonha\n 333 - Zé da Farmácia\n 444 - Nulo\n\n");
			scanf("%d", &votar_vere);
			fflush(stdin);
			switch(votar_vere)
			{
				case 111:
					vere_111++;
					break;
				case 222:
					vere_222++;
					break;
				case 333:
					vere_333++;
					break;
				case 444:
					vere_nulo++;
					break;
				default:
					vere_invalido++;
					break;
			}
			system("cls");					
			printf("\nDigite o número do candidato a prefeito escolhido:\n\n 11 - Dr. Zureta\n 22 - Senhor Gomes\n 44 - Nulo\n\n");
			scanf("%d", &votar_pref);
			fflush(stdin);
			switch(votar_pref)
			{
				case 11:
					pref_11++;
					break;
				case 22:
					pref_22++;
					break;
				case 44:
					pref_nulo++;
					break;
				default:
					pref_invalido++;
					break;
			}
			system("cls");
			printf("\nObrigado pelo seu voto.\n\n");
			system("pause");
			system("cls");
	  		goto INICIO;;
	  		
	  	case 2:
	  		printf("\nDigite a senha:\n");
			scanf("%d", &password1);
			fflush(stdin);
			if (password1 == password)
			{
				system("cls");
				printf("\nTotal de votos válidos: %d\n", vere_111 + vere_222 + vere_333 + pref_11 + pref_22 + vere_nulo + pref_nulo + vere_invalido + pref_invalido);
				printf("\nTotal de Votos para Vereadores:\n111 - %d\n222 - %d\n333 - %d\n444 - %d\n", vere_111, vere_222, vere_333, vere_nulo);
				printf("\nTotal de Votos para Prefeitos:\n11 - %d\n22 - %d\n44 - %d\n", pref_11, pref_22, pref_nulo);
				printf("\nTotal Votos Inválidos:\n%d\n\n", vere_invalido + pref_invalido);
				system("pause");
				system("cls");
				goto INICIO;
			}
			else
			{
				system("cls");
				printf("\nSenha Incorreta.\n\n");
				system("pause");
				system("cls");
				goto INICIO;
			}
			break;
		case 3:
	  		printf("\nDigite a senha:\n");
			scanf("%d", &password1);
			fflush(stdin);
			if (password1 != password)
			{
				system("cls");
				printf("\nSenha Incorreta.\n\n");
				system("pause");
				system("cls");
				goto INICIO;
			}
			printf("\nSistema Encerrado!\n");
			break;
	}	
	return (0);
}
