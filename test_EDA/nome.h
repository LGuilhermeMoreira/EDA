#ifndef NOME_H
#define NOME_H
#include <string>
#include <iostream>

class Nome
{
public:
    std::string nome;
    Nome(std::string nome)
    {
        this->nome = nome;
    }

    Nome() = default;

    // sobrecarrega o operador + para somar dois nomes
    Nome operator+(const Nome &n)
    {
        Nome novoNome;
        novoNome.nome = this->nome + " " + n.nome;
        return novoNome;
    }

    friend std::ostream &operator<<(std::ostream &os, const Nome &n)
    {
        os << n.nome;
        return os;
    }
    friend bool operator==(const Nome &n1, const Nome &n2)
    {
        if (n1.nome == n2.nome)
        {
            return true;
        }

        int sizeNome1 = n1.nome.size();
        int sizeNome2 = n2.nome.size();

        for (int i = 0; i < sizeNome1; i++)
        {
            if (n1.nome[i] != n2.nome[i])
            {
                return false;
            }
        }
        return true;
    }
    friend bool operator<(const Nome &n1, const Nome &n2)
    {
        if (n1.nome < n2.nome)
        {
            return true;
        }
        return false;
    }
    friend bool operator>(const Nome &n1, const Nome &n2)
    {
        if (n1.nome > n2.nome)
        {
            return true;
        }
        return false;
    }
    friend bool operator<=(const Nome &n1, const Nome &n2)
    {
        if (n1.nome <= n2.nome)
        {
            return true;
        }
        return false;
    }
    friend bool operator>=(const Nome &n1, const Nome &n2)
    {
        if (n1.nome >= n2.nome)
        {
            return true;
        }
        return false;
    }
};

#endif