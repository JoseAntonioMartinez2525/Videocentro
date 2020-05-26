#include <iostream>
#include <math.h>
#include <cstring>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <time.h>

#include "Persona.h"
#include "Pelicula.h"
#include "Prestamo.h"
using namespace std;

Pelicula registrarP(){
        char titulo[100];
        char nombreD[100];
        char apellidoD[100];
        char nacionalidadD[100];
        int annio;
        char genero[100];
        char productora[100];
        int minutos;

    cout << "Ingrese el titulo de la pelicula"<<endl;
    cin >> titulo;
    cout << "Ingrese le nombre del director"<<endl;
    cin >> nombreD;
    cout << "Ingrese los apellidos del director"<<endl;
    cin >> apellidoD;
    cout << "Nacionalidad del director"<< endl;
    cin >> nacionalidadD;
    cout << "Annio del la pelicula"<<endl;
    cin >> annio;
    cout << "Genero de la pelicula"<<endl;
    cin >> genero;
    cout << "Productora de la pelicula"<<endl;
    cin >> productora;
    cout << "Duracion de la pelicula"<<endl;
    cin >> minutos;
    return Pelicula(titulo,Persona(nombreD,apellidoD,nacionalidadD),annio,genero,productora,minutos);
}
Persona registrarUsuario(){
    /*Datos del Usuario*/
    char nombres[100];
    char apellidos[100];
    char nacionalidad[100];

    /*Datos del Usuario*/

    cout << "Ingrese le nombre del usuario"<<endl;
    cin >> nombres;
    cout << "Ingrese los apellidos del usuario"<<endl;
    cin >> apellidos;
    cout << "Nacionalidad del usuario"<< endl;
    cin >> nacionalidad;

    Persona usuario =Persona(nombres,apellidos,nacionalidad);

    return usuario;
}
Prestamo registrarPrestamo(int pelicula){
	int usuario;
	char fechaInicial[100];
	cout<<"Ingrese el numero de usuario: ";cin>>usuario;
	cout<<"Ingrese la fecha inicial: "<<endl;cin>>fechaInicial;

	Prestamo nuevoPrestamo=Prestamo(usuario,pelicula,fechaInicial);
	return nuevoPrestamo;
}
void mostrarPeliculas(Pelicula peliculas[10],int peliculasC){
	for(int i=0;i<peliculasC;i++){
		cout<<"<==Pelicula # "<<(i)<<endl;
		peliculas[i].toString();
	}
}
void menuPeliculas(){
    cout << "<========= MENU ==============>"<<endl;
    cout << "<=== 1.- Registrar pelicula =====>"<<endl;
    cout << "<=== 2.- Editar pelicula ========>"<<endl;
    cout << "<=== 3.- Eliminar pelicula ======>"<<endl;
    cout << "<=== 4.- Consultar pelicula =====>"<<endl;
    cout << "<=== 5.- Detalles de pelicula ===>"<<endl;
    cout << "<=============================>"<<endl;
}
void menuUsuarios(){
    cout << "<========= MENU ================>"<<endl;
    cout << "<=== 1.- Registrar usuario =====>"<<endl;
    cout << "<=== 2.- Editar usuario ========>"<<endl;
    cout << "<=== 3.- Eliminar usuario ======>"<<endl;
    cout << "<=== 4.- Consultar usuario =====>"<<endl;
    cout << "<=== 5.- Detalles de usuario ===>"<<endl;
    cout << "<===============================>"<<endl;
}
void menuPrestamos(){
    cout << "<========= MENU ================>"<<endl;
    cout << "<=== 1.- Realizar prestamo======>"<<endl;
    cout << "<=== 2.- Devolver pelicula ========>"<<endl;
    cout << "<===============================>"<<endl;

}
void menu(){
    cout << "<========= MENU ================>"<<endl;
    cout << "<=== 1.- Administrar Usuarios ==>"<<endl;
    cout << "<=== 2.- Administrar peliculas =====>"<<endl;
    cout << "<=== 3.- Administrar Prestamos =>"<<endl;
    cout << "<=== 6.- Salir =================>"<<endl;
    cout << "<===============================>"<<endl;
}
int main()
{
    Pelicula peliculas[10];
    Persona usuarios[10];
    Prestamo prestamos[100];
        char fechaFinal[100];
    bool pw = true, t=true;
    int op = 0, peliculasC = 0, no = 0, prestamosC=0, usuariosC=0,tB;

    while (pw&&op<6){
            menu();cin>>op;
        switch (op)
        {
            case 1: menuUsuarios();
            cin>>op;

            switch (op)
            {
            	case 1:
					usuarios[usuariosC]= registrarUsuario();
					usuariosC++;
					break;
				case 2: cout<<"Ingrese el numero de usuario";cin>>no;
					usuarios[no].toString();
					usuarios[no]=registrarUsuario();
					break;
				case 3:cout<<"Ingrese el numero de usuario";cin>>no;
					usuarios[no].toString();
					usuarios[no]=Persona();
					cout<<"Usuario eliminado"<<endl;
					break;
				case 4:cout<<"Ingrese el numero de usuario";cin>>no;
					usuarios[no].toString();
					break;

            default:
                break;
            }
            case 2: menuPeliculas();
            cin>>op;
            switch (op)
            {
                case 1:
                    peliculas[peliculasC] = registrarP();
                    peliculasC++;
                    break;
                case 2:
                    cout << "Ingrese el numero de la pelicula"<<endl;
                    cin >> no;

                    peliculas[no].toString();
                    peliculas[no] = registrarP();
                    break;
                case 3:
                    cout << "Ingrese el numero de la pelicula"<<endl;
                    cin >> no;

                    peliculas[no].toString();
                    peliculas[no] = Pelicula();

                    break;
                case 4:
                    cout << "Ingrese el numero de la pelicula"<<endl;
                    cin >> no;

                    peliculas[no].getDirector();
						usuarios[prestamos[no].getUsuario()].toString();
						tB=prestamos[no].getPelicula();
						peliculas[tB].toString();
						prestamos[no].toString();
                    break;
                case 5:
                    cout << "Ingrese el numero de la pelicula"<<endl;
                    cin >> no;

                    peliculas[no].toString();
                    break;
            default:
            break;
            }
            case 3:
                menuPrestamos();
				cin>>op;
				switch (op)
				{
                    case 1:
					mostrarPeliculas(peliculas,peliculasC);

					cout<<"Ingrese el numero de pelicula: ";cin>>no;
					t=true;
					for(int i=0;i<prestamosC;i++){
						if(no==prestamos[i].getPelicula()&&prestamos[i].getEstatus()==1){
							t=false;
						}
					}
					if(t==true){
						prestamos[prestamosC]=registrarPrestamo(no);
						prestamosC++;
					}else{
						cout<<" La pelicula ya esta prestada"<<endl;
					}
					break;
                    case 2:cout<<"Ingrese el numero de prestamo: ";cin>>no;
						usuarios[prestamos[no].getUsuario()].toString();
						tB=prestamos[no].getPelicula();
						peliculas[tB].toString();
						prestamos[no].toString();

						if(prestamos[no].getEstatus()==1){
						cout<<"Ingrese la fecha de devolucion: "<<endl;cin>>fechaFinal;

						prestamos[no].devolucion(fechaFinal);
						cout<<"Pelicula devuelta"<<endl;
						}else{
							cout<<"El prestamo ha sido finalizado anteriormente"<<endl;
						}

					break;
				default:
				    break;
				}


        }

    }

    return 0;
}
