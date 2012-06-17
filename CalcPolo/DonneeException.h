#ifndef DONNEEEXCEPTION_H
#define DONNEEEXCEPTION_H

#include <stdexcept>
#include <string>
#include <QString>


class DonneeException :public std::exception
{
    std::string info;
public:
    DonneeException(const char * s=""):info(s){}
    const char* what() const throw(){return info.c_str();}   //informations sur l'erreur
    ~DonneeException() throw(){}
};

#endif // DONNEEEXCEPTION_H
