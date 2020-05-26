#ifndef PELICULA_H
#define PELICULA_H

#include <Persona.h>


class Pelicula : public Persona
{
    public:
        Pelicula();
        Pelicula(char[],Persona,int,char[],char[],int);
        void getDirector();
        void toString();

    private:
        char titulo[100];
        Persona director;
        int annio;
        char genero[100];
        char productora[100];
        int minutos;
};

#endif // PELICULA_H
