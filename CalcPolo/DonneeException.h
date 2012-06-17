#ifndef DONNEEEXCEPTION_H
#define DONNEEEXCEPTION_H

#include <stdexcept>
#include <string>
#include <QString>

/// \file DonneeException.h
/// \author Clémence BLOT, Benoît GAVALDA
/// \brief DonneException classe qui gère les exceptions
///
/// \param info string qui contient les informations sur l'erreur
///

class DonneeException :public std::exception
{
    std::string info;
public:
    DonneeException(const char * s=""):info(s){}
    const char* what() const throw(){return info.c_str();}   //informations sur l'erreur
    ~DonneeException() throw(){}
};

#endif // DONNEEEXCEPTION_H
