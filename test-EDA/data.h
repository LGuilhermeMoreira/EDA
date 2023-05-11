#ifndef DATA_H
#define DATA_H

#include <vector>
#include <string>
#include <iostream>
#include "functions.h"

// todo: testar toda essa classe
class Data
{
public:
    int dia, mes, ano;
    
    Data(std::string dataCompleta)
    {
        std::vector<std::string> data = split(dataCompleta, '/');
        dia = std::stoi(data[0]);
        mes = std::stoi(data[1]);
        ano = std::stoi(data[2]);        
    }
    Data(const Data &d)
    {
        this->dia = d.dia;
        this->mes = d.mes;
        this->ano = d.ano;
    }
    Data &operator=(const Data &d)
    {
        this->dia = d.dia;
        this->mes = d.mes;
        this->ano = d.ano;
        return *this;
    }
    Data() = default;
    bool operator==(const Data &d) const
    {
        return this->dia == d.dia && this->mes == d.mes && this->ano == d.ano;
    }
    bool operator!=(const Data &d) const
    {
        return !(*this == d);
    }
    bool operator<(const Data &d) const
    {
        if (this->ano < d.ano)
        {
            return true;
        }
        else if (this->ano == d.ano)
        {
            if (this->mes < d.mes)
            {
                return true;
            }
            else if (this->mes == d.mes)
            {
                if (this->dia < d.dia)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool operator>(const Data &d) const
    {
        return !(*this < d) && !(*this == d);
    }
    bool operator<=(const Data &d) const
    {
        return (*this < d) || (*this == d);
    }
    bool operator>=(const Data &d) const
    {
        return (*this > d) || (*this == d);
    }
    friend std::ostream &operator<<(std::ostream &os, const Data &d)
    {
        os << d.dia << "/" << d.mes << "/" << d.ano;
        return os;
    }
    friend std::istream &operator>>(std::istream &is, Data &d)
    {
        is >> d.dia >> d.mes >> d.ano;
        return is;
    }
    ~Data() = default;
};

#endif