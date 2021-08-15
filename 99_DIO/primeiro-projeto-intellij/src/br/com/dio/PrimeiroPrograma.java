package br.com.dio;

import br.com.dio.model.Gato;

import java.util.Objects;

public class PrimeiroPrograma {
    public static void main(String[] args) {
        Gato gato = new Gato();
        System.out.println(gato);

        Livro livro1 = new Livro("O Problema dos 3 Corpos", 300);
        System.out.println(livro1);

        /*int a = 5;
        int b = 3;
        System.out.println("Hello World! " + (a+b));*/
    }
}
class Livro {
    private String nome;
    private Integer NumPag;

    public Livro(String nome, Integer numPag) {
        this.nome = nome;
        NumPag = numPag;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Integer getNumPag() {
        return NumPag;
    }

    public void setNumPag(Integer numPag) {
        NumPag = numPag;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Livro livro = (Livro) o;
        return Objects.equals(nome, livro.nome) && Objects.equals(NumPag, livro.NumPag);
    }

    @Override
    public int hashCode() {
        return Objects.hash(nome, NumPag);
    }

    @Override
    public String toString() {
        return "Livro{" +
                "nome='" + nome + '\'' +
                ", NumPag=" + NumPag +
                '}';
    }
}