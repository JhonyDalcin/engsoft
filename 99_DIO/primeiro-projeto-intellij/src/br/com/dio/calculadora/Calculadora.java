package br.com.dio.calculadora;

import java.util.Scanner;

public class Calculadora
{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        float a, b;

        System.out.println("Digite o primeiro número: ");
        a = scan.nextInt();
        System.out.println("Digite o segundo número: ");
        b = scan.nextInt();

        float somar = somar(a, b);
        float subtrair = subtrair(a, b);
        float multiplicar = multiplicar(a, b);
        float dividir = dividir(a, b);

        System.out.println("A soma dos números é: " + somar);
        System.out.println("A subtração dos números é: " + subtrair);
        System.out.println("A multiplicação dos números é: " + multiplicar);
        System.out.println("A divisão dos números é: " + dividir);

    }

    public static float somar(float a, float b)
    {
        return a + b;
    }
    public static float subtrair(float a, float b)
    {
        return a - b;
    }
    public static float multiplicar(float a, float b)
    {
        return a * b;
    }
    public static float dividir(float a, float b)
    {
        return a / b;
    }

}
