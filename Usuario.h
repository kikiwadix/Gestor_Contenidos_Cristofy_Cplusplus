

#ifndef USUARIO_H
#define	USUARIO_H


#include <iostream>
#include <string>
#include <stdlib.h>
#include "Multimedia.h"

using namespace std;

class Usuario{
	private:
		string login;
		string password;
		string nombre;
		string apellido1;
		string apellido2;
		int edad;
		Multimedia **listaContenidosUsuario;
		float *listaValoraciones;
		int utilesCV;
		Multimedia **listaDeResultadosDeBusqueda;
		int utilesDeResultadosDeBusqueda;
        
    public:
    	//Constructores y destructor
    	Usuario();
    	Usuario(string login, string password, string nombre, string apellido1, string apellido2, int edad, int utilesCV);
    	Usuario(const Usuario &u);
    	~Usuario();
    	//Los SETS
        inline void setLogin(string nuevoLogin) { this->login = nuevoLogin; }
        inline void setPassword(string nuevoPassword) { this->password = nuevoPassword; }
        inline void setNombre(string nuevoNombre) { this->nombre = nuevoNombre; }
        inline void setApellido1(string nuevoApellido1) { this->apellido1 = nuevoApellido1; }
        inline void setApellido2(string nuevoApellido2) { this->apellido2 = nuevoApellido2; }
        inline void setEdad(int nuevaEdad) { this->edad = nuevaEdad; }
        inline void setListaContenidosUsuario(int posicion, Multimedia *nuevoMultimedia) { this->listaContenidosUsuario[posicion] = nuevoMultimedia; }
        inline void setListaValoraciones(int posicion, float nuevoValor) { this->listaValoraciones[posicion] = nuevoValor;}
        inline void setUtilesCV(int nuevasUtilesCV) { this->utilesCV = nuevasUtilesCV; }
        inline void setUtilesDeResultadosDeBusqueda(int nuevasUtiles) { this->utilesDeResultadosDeBusqueda = nuevasUtiles;}
        //Los GETS
        inline string getLogin() const { return this->login; }
        inline string getPassword() const { return this->password; }
        inline string getNombre() const { return this->nombre; }
        inline string getApellido1() const { return this->apellido1; }
        inline string getApellido2() const { return this->apellido2; }
        inline int getEdad() const { return this->edad; }
        inline Multimedia* getListaContenidosUsuario(int posicion) { return this->listaContenidosUsuario[posicion]; }
        inline float getListaValoraciones(int posicion) { return this->listaValoraciones[posicion];}
        inline int getUtilesCV() const { return this->utilesCV; }
        inline int getUtilesDeResultadosDeBusqueda() { return this->utilesDeResultadosDeBusqueda;}
        //Resto de Modulos

        //@brief: Modulo que añade un contenido multimedia al vector de contenidos del usuario
        //@param: Multimedia *m
        //@pos: devuelve un bool si se ha realizado bien la asociacion
        bool asociarContenidoMultimedia(Multimedia* m);
        //@brief: Modulo que quita un contenido multimedia del vector de contenidos del usuario
        //@param: int numMultimedia
        //@pos: devuelve un bool si se ha realizado bine la desasociacion
        bool desasociarContenidoMultimedia(int numMultimedia);
        //@brief: Modulo que pregunta por la valoracion de ese multimedia y lo mete en el vector de valoraciones
        //@param: float valoracion e int posicion
        void votarContenidoMultimedia(float valoracion, int posicion);
        //@brief: Modulo que modifica los datos del usuario
        void modificarDatosUsuario();
        //@brief: Modulo que busca contenidos mulimedia dentro del vector de contenidos del usuario
        //@param: string titulo
        //@pos: devuelve un int con el numero de multimedia en el vector de contenidos asociados
        int buscarContenidoAsociado(string titulo);
        //@brief: Modulo que imprime la lista de nombres de los contenidos asociados
        void imprimirListaContenidosAsociadosYValoraciones();
        //@brief: Modulo que imprime la lista de nombres de los contenidos multimedia encontrados
        void imprimirListaResultadosBusqueda();
        //@brief: Modulo que pasándole un id, busca la posicion en la que está, si está.
        //@param: int id
        //@pos: devuelve un int con la posicion buscada, sino devuelve -1
        int buscarPosicionEnListaAsociados(int id);
        //@brief: Modulo que pasándole un id, busca la posicion en la que está dentro del vector de resultados
        //@param: int id
        //@pos: devuelve un int con la posicion buscada, sino devuelve -1
        int buscarPosicionEnListaDeResultados(int id);
        //@brief: Modulo que imprime la informacion de un usuario
        void imprimirUsuario();
        //@brief: Modulo que amplia la memoria del vector de contenidos del usuario en uno, y tb llama a ampliar memoria de validaciones
        //@pos: Devuelve un nuevo vector de punteros a multimedia ampliado
        Multimedia** ampliarMemoriaListaContenidos();
        //@brief: Modulo que amplia la memoria del vector de valoraciones en uno
        //@pos: devuelve un nuevo vector de floats ampliado
        float* ampliarMemoriaListaValoraciones();
		//@brief: Modulo que llama a los otros dos modulos de ampliar memoria
        void ampliarDosMemorias();
        //@brief: Modulo que al quitar un contenido multimedia a un usuario, crea nuevos vectores de una posicion mas pequeños
        void desampliarMemoria();
	
};



#endif	/* USUARIO_H */
