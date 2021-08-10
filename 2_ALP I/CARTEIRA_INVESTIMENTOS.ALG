Algoritmo "Carteira_Investimentos"

          Procedimento cabecalho()
          Var

          Inicio
            Escreval("---------------------------------------------------")
            Escreval("Corretora Você Na Linha!")
            Escreval("Controladora de Investimentos")
            Escreval("---------------------------------------------------")
          Fimprocedimento
          
          Procedimento opcoes()
          Var
          
          Inicio
            Escreval("Opções de Investimento:")
            EscrevaL("1 - CDBs")
            EscrevaL("2 - Ações")
            EscrevaL("3 - Fundos Imobiliários")
            EscrevaL("4 - Stocks")
            EscrevaL("5 - Reits")
          Fimprocedimento
          
          Função verificapretendido(soma: real): inteiro
          
          Var
             verificador: inteiro
          Inicio
             Se soma > 100 então
                verificador <- 1
                limpatela
                Escreval("Somatória percentual maior que 100, digite novamente")
             Senão
                  verificador <- 0
             Fimse
              Retorne verificador
          Fimfunção
Var

pretendido: Vetor[1..5] de real
valor: Vetor[1..5] de real
atual: Vetor[1..5] de real
compara: Vetor[1..5] de real
cont, contprox, repete: inteiro
a, b, c, d, soma, troca: real

Inicio

   repete <- 1
   Enquanto repete = 1  Faça
      cabecalho()
      opcoes()
      Escreval("")
      Para cont de 1 até 5 passo 1 faça
           Escreval("Digite o valor PERCENTUAL PRETENDIDO para o investimento:",cont)
           Leia(pretendido[cont])
      Fimpara
      soma <- 0
      Para cont de 1 até 5 passo 1 faça
           soma <- pretendido[cont] + soma
      Fimpara
      repete <- verificapretendido(soma)
   Fimenquanto
   limpatela
   
   cabecalho()
   opcoes()
   Escreval("")
   Para cont de 1 até 5 passo 1 faça
        Escreval("Digite o VALOR QUE JÁ POSSUI para o investimento:",cont)
        Leia(valor[cont])
   Fimpara
   limpatela
   
   a <- 0
   Para cont de 1 até 5 faça
        a <- valor[cont] + a
   Fimpara
   Para cont de 1 até 5 faça
        b <- valor[cont]
        c <- b * 100
        d <- c/a
        atual[cont] <- d
   Fimpara

   cabecalho()
   opcoes()
   Para cont de 1 até 5 passo 1 faça
        Escreval("Para Investimento", cont, " Pretendido:", pretendido[cont], "% ", "Atual:", atual[cont], "%")
   Fimpara
   
   Para cont de 1 até 5 passo 1 faça
        compara[cont] <- ABS(1 - (atual[cont]/pretendido[cont]))
   Fimpara

   Para cont de 1 até 4 passo 1 faça
        Para contprox de cont+1 até 5 faça
           Se compara[cont] < compara[contprox] então
              troca <- compara[cont]
              compara[cont] <- compara[contprox]
              compara[contprox] <- troca
           Fimse
        Fimpara
   Fimpara
        
   Para cont de 1 até 5 passo 1 faça
        Se (atual[cont] = ABS(compara[1]*pretendido[cont]-pretendido[cont])) ou (atual[cont] = compara[1]*pretendido[cont]+pretendido[cont])então
           Escreval("O Investimento:", cont, " é o mais desbalanceado")
        Fimse
   Fimpara
Fimalgoritmo