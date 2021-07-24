#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
    /*Declaração de variáveis e idioma*/
    setlocale(LC_ALL,"Portuguese");
    int cartela[10];
    int i, j,cont, troca, posi, num, TAM;
      
    /*Comando números randômicos*/
      
      
    /*Solicita quantas cartelas imprimir*/ 
    cont = 1;
    printf("\nDigite o número de cartelas desejadas:\n");
    scanf("%d", &TAM);
    fflush(stdin);
    srand(time(NULL));
    /*Bloco de elaboração da cartela*/
    while (cont<=TAM)
    {
        system("cls");
      
      /*Gera números randômicos da cartela corrente e confere se não está repetido na mesma cartela*/
        for (i=0; i<10; i++)
        {
            if (i == 0)
            {
                cartela[i] = (1+(rand()%98));
            }
            else
            {
                num = (1+(rand()%98));
                for(j=0; j<i; j++)
                {
                    if(num == cartela[j])
                    {
                        num = (1+(rand()%98));
                        cartela[i] = num;
                    }
                    else
                    {
                        cartela[i] = num;
                    }
                }
            }

        }
        
        /*Ordena os número da cartela em ordemcrescente*/
        for (i=0; i<9; i++)
        {
        	for (j=i+1; j<10; j++)
        	{
        		if(cartela[i] > cartela[j])
        		{
        			troca = cartela[i];
        			cartela[i] = cartela[j];
        			cartela[j] = troca;
				}
			}
		}  
        /*Imprimi a cartela corrente*/
        for (i=1; i<11; i++)
        {
            posi = i-1;
            printf("O número %d da cartela %d é: %d\n", i, cont, cartela[posi]);
        }
        cont++;
        system("pause");
    }
    system("cls");
    printf("Fim");
    return 0;
}
