#ifndef PRESTAMO_H
#define PRESTAMO_H


class Prestamo
{
    public:
        Prestamo();
		Prestamo(int,int,char[]);
		void devolucion(char[]);
		int getUsuario();
		int getPelicula();
		void toString();
		int getEstatus();

    private:
        int usuario;
        int pelicula;
        char fechaInicial[100];
        char fechaFinal[100];
        int estatus;
};

#endif // PRESTAMO_H
