#ifndef CLASS_CPF_H
#define CLASS_CPF_H


#include <string>
#include <iostream>

// criando a classe CPF


class CPF{
public:
    // atributo
    std::string cpf;

    // Construtores
    CPF(std::string cpf){
        this->cpf = cpf;
    }

    CPF(const CPF &c){
        this->cpf = c.cpf;
    }

    CPF() = default;

    // sobrecarga de operadores
    CPF &operator=(const CPF &c){
        this->cpf = c.cpf;
        return *this;
    }

    bool operator==(const CPF &c) const{
        return this->cpf == c.cpf;
    }

    bool operator!=(const CPF &c) const{
        return !(*this == c);
    }

    bool operator<(const CPF &c) const{
        return this->cpf < c.cpf;
    }

    bool operator>(const CPF &c) const{
        return this->cpf > c.cpf;
    }

    bool operator<=(const CPF &c) const{
        return this->cpf <= c.cpf;
    }

    bool operator>=(const CPF &c) const{
        return this->cpf >= c.cpf;
    }

    friend std::ostream &operator<<(std::ostream &os, const CPF &c){
        os << c.cpf;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, CPF &c){
        is >> c.cpf;
        return is;
    }

};



#endif