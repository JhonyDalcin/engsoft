Algoritmo "Carteira_Investimentos"

          Procedimento cabecalho()
          Var

          Inicio
            Escreval("---------------------------------------------------")
            Escreval("Corretora Voc� Na Linha!")
            Escreval("Controladora de Investimentos")
            Escreval("---------------------------------------------------")
          Fimprocedimento
          
          Procedimento opcoes()
          Var
          
          Inicio
            Escreval("Op��es de Investimento:")
            EscrevaL("1 - CDBs")
            EscrevaL("2 - A��es")
            EscrevaL("3 - Fundos Imobili�rios")
            EscrevaL("4 - Stocks")
            EscrevaL("5 - Reits")
          Fimprocedimento
          
          Fun��o verificapretendido(soma: real): inteiro
          
          Var
             verificador: inteiro
          Inicio
             Se soma > 100 ent�o
                verificador <- 1
                limpatela
                Escreval("Somat�ria percentual maior que 100, digite novamente")
             Sen�o
                  verificador <- 0
             Fimse
              Retorne verificador
          Fimfun��o
Var

pretendido: Vetor[1..5] de real
valor: Vetor[1..5] de real
atual: Vetor[1..5] de real
compara: Vetor[1..5] de real
cont, contprox, repete: inteiro
a, b, c, d, soma, troca: real

Inicio

   repete <- 1
   Enquanto repete = 1  Fa�a
      cabecalho()
      opcoes()
      Escreval("")
      Para cont de 1 at� 5 passo 1 fa�a
           Escreval("Digite o valor PERCENTUAL PRETENDIDO para o investimento:",cont)
           Leia(pretendido[cont])
      Fimpara
      soma <- 0
      Para cont de 1 at� 5 passo 1 fa�a
           soma <- pretendido[cont] + soma
      Fimpara
      repete <- verificapretendido(soma)
   Fimenquanto
   limpatela
   
   cabecalho()
   opcoes()
   Escreval("")
   Para cont de 1 at� 5 passo 1 fa�a
        Escreval("Digite o VALOR QUE J� POSSUI para o investimento:",cont)
        Leia(valor[cont])
   Fimpara
   limpatela
   
   a <- 0
   Para cont de 1 at� 5 fa�a
        a <- valor[cont] + a
   Fimpara
   Para cont de 1 at� 5 fa�a
        b <- valor[cont]
        c <- b * 100
        d <- c/a
        atual[cont] <- d
   Fimpara

   cabecalho()
   opcoes()
   Para cont de 1 at� 5 passo 1 fa�a
        Escreval("Para Investimento", cont, " Pretendido:", pretendido[cont], "% ", "Atual:", atual[cont], "%")
   Fimpara
   
   Para cont de 1 at� 5 passo 1 fa�a
        compara[cont] <- ABS(1 - (atual[cont]/pretendido[cont]))
   Fimpara

   Para cont de 1 at� 4 passo 1 fa�a
        Para contprox de cont+1 at� 5 fa�a
           Se compara[cont] < compara[contprox] ent�o
              troca <- compara[cont]
              compara[cont] <- compara[contprox]
              compara[contprox] <- troca
           Fimse
        Fimpara
   Fimpara
        
   Para cont de 1 at� 5 passo 1 fa�a
        Se (atual[cont] = ABS(compara[1]*pretendido[cont]-pretendido[cont])) ou (atual[cont] = compara[1]*pretendido[cont]+pretendido[cont])ent�o
           Escreval("O Investimento:", cont, " � o mais desbalanceado")
        Fimse
   Fimpara
Fimalgoritmo