#ifndef PESSOA_H
#define PESSOA_H

#include "data.h"
#include "cpf.h"
#include "nome.h"
#include <string>
#include <iostream>

class Pessoa
{
public:
    //* Atributos
    Data nascimento;
    Nome nome;
    CPF cpf;
    std::string endereco;

    //* Metodos
    // construtor
    Pessoa(std::string cpf,std::string nome, std::string sobrenome, std::string nascimento, std::string endereco){
        this->nascimento = Data(nascimento);
        this->nome = Nome(nome + " " + sobrenome);
        this->cpf = CPF(cpf);
        this->endereco = endereco; 

    }

    // mostra os dados da pessoa
    void print()
    {
        std::cout << "Nome: " << nome << std::endl;
        std::cout << "CPF: " << cpf << std::endl;
        std::cout << "Endereco: " << endereco << std::endl;
        std::cout << "Data de nascimento: " << nascimento.dia << "/" << nascimento.mes << "/" << nascimento.ano << std::endl;
    }
};

#endif