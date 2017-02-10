
#ifndef CRISTOFY_H
#define	CRISTOFY_H


#include <iostream>
#include <string>
#include <stdlib.h>
#include "Usuario.h"
#include "Multimedia.h"


using namespace std;

class Cristofy{
	private:
		Usuario** listaUsuarios;
        int usuariosTotales;
        int dimUsuarios;
        Multimedia** listaContenidoMultimedia;
        int contenidosTotales;
        int dimMultimedia;
        
    public:
        //Constructor y destructor
    	Cristofy();
    	~Cristofy();
    	//Los SETS
        inline void setListaUsuarios(int posicion, Usuario *user) { this->listaUsuarios[posicion] = user; }
        inline void setUsuariosTotales(int nuevosUsuariosTotales) { this->usuariosTotales = nuevosUsuariosTotales; }
        inline void setDimUsuarios(int nuevaDimension) { this->dimUsuarios = nuevaDimension; }
        inline void setListaContenidoMultimedia(int posicion, Multimedia *multimediaAInsertar) { this->listaContenidoMultimedia[posicion] = multimediaAInsertar; }
        inline void setContenidosTotales(int nuevosContenidosTotales) { this->contenidosTotales = nuevosContenidosTotales; }
        inline void setDimMultimedia(int nuevaDimMultimedia) { this->dimMultimedia = nuevaDimMultimedia; }
        //Los GETS
        inline Usuario* getListaUsuarios(int posicion) const { return this->listaUsuarios[posicion];}
        inline int getUsuariosTotales() const { return this->usuariosTotales; }
        inline int getDimUsuarios() const { return this->dimUsuarios; }
        inline Multimedia* getListaContenidoMultimedia(int posicion) { return this->listaContenidoMultimedia[posicion];}
        inline int getContenidosTotales() const { return this->contenidosTotales; }
        inline int getDimMultimedia() const { return this->dimMultimedia; }
        //Resto de Modulos

        //@brief: Modulo que muestra un mensaje de Bienvenida al arrancar el programa
        void bienvenida();
        //@brief: Modulo que muestra un mensaje de despedida al salir del programa 
        void despedida();
        //@brief: Modulo que pide los datos para crear un usuario nuevo, y devuelve un puntero a usuario
        //@return puntero a Usuario*
        Usuario* rellenarDatosUsuarioNuevo();
        //@brief: Modulo que autentica al usuario para determinar que tipo de usuario es (normal o admin)
        //@param: string login y string password
        int autenticacion(string login, string password);
        //@brief: Modulo que muestra el menu para elegir Admin o User
        void preMenu();
        //@brief: Modulo que muestra el menu del programa para usuarios normales
        //@param: Usuario *user
        void mostrarMenuUsuario(Usuario *user);
        //@brief: Modulo que muestra el menu del programa para administradores
        void mostrarMenuAdmin();
        //@brief: Modulo que importa un fichero al programa
        //@param: string rutaOrigen
        bool importarFichero(string rutaOrigen);
        //@brief: Modulo que exporta un archivo del programa
        //@param: string rutaDestino
        bool exportarFichero(string rutaDestino);
        //@brief: Modulo que busca un usuario en concreto del sistema
        //@param: const string login
        //@pos: devuelve un int, de 0 a inf si lo ha encontrado, sino devuelve -1
        int buscarUsuarioEnSistema(const string login);
        //@brief: Modulo que añade un usuario al sistema
        //@param: Usuario *user
        void anadirUsuarioASistema(Usuario* user);
        //@brief: Modulo que elimina un usuario del sistema
        //@param: Usuario *user
        void eliminarUsuarioEnSistema(Usuario* user);
        //@brief: Modulo que guarda un usuario en una base de datos
        //@param: const Usuario &user
        void guardarUsuarioEnBD(const Usuario &user);
        //@brief: Modulo que busca un archivo Multimedia en el sistema
        //@param: const string tituloABuscar
        //@pos: devuelve un int si lo ha encontrado, sino devuelve -1
        int buscarMultimediaEnSistema(const string tituloABuscar);
        //@brief: Modulo que añade un archivo Multimedia al sistema
        //@param: Multimedia *multi
        void anadirMultimediaASistema(Multimedia *multi);
        //@brief: Modulo que elimina un archivo Multimedia del sistema
        //@param: Multimedia *multi
        void eliminarMultimediaEnSistema(Multimedia *multi);
        //@brief: Modulo que saca un informe de los archivos de Musica más valorados
        void informeTop3Musica();
        //@brief: Modulo que saca un informe de los archivos de Video más valorados
        void informeTop3Videos();
        //@brief: Modulo que saca un informe de los archivos de Imagen más valorados
        void informeTop3Imagen();
        //@brief: Modulo que saca un informe de los archivos Multimedia más valorados
        void informeTop3General();
        //@brief: Modulo que saca un informe con el usuario que mas ha valorado
        void UsuarioFreak();
        //@brief: Modulo que amplia el vector de contenidos al doble
        //@pos: amplia memoria y devuelve un puntero a puntero de Multimedia
        Multimedia** ampliarMemoriaContenido();
        //@brief: Modulo que amplia el vector de usuarios al doble
        //@pos: amplia memoria y devuelve un puntero a puntero de Usuario
        Usuario** ampliarMemoriaUsuario();
        //@brief: Modulo que pide los datos de un nuevo multimedia, lo crea y lo devuelve
        //@pos: crea un multimedia y devuelve su puntero
        Multimedia* crearMultimediaParaAnadir();
        //@brief: Modulo que genera un id segun el tipo de archivo e incremental único
        //@param: string tipoMultimedia
        //@pos: devuelve un string generado unico para ponerselo de ID
        string generarId(string tipoMultimedia);
        //@brief: Modulo que, recibiendo una posicion de multimedia, consulta su valoracion media total de todos los usuarios
        //@param: int posicion
        void consultarValoracionMedia(int posicion);
        //@brief: Modulo que cambia la valoracion total de un multimedia
        //@param: int posicion y un float valoracion
        void sumarValoracion(int posicion, float valoracion);
        //@brief: Modulo que resta la valoracion antigua de un multimedia
        //@param: int posicion y float valoracion
        void restarValoracion(int posicion, float valoracion);
        
};



#endif	/* CRISTOFY_H */
