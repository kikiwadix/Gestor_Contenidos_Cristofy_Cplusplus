
#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <cstdlib>
#include "Multimedia.h"


#define RED_COLOR "\033[1;31m"
#define GREEN_COLOR "\033[1;32m"
#define BLUE_COLOR "\033[1;34m"
#define RESTORE_DEFAULT_COLOR "\033[0m"


using namespace std;


/************************************
 *  MODULOS DE LA CLASE MULTIMEDIA  *
 ************************************/


Multimedia::Multimedia(){

	this->id = "NULL"; //ver lo del id incremental unico....
    this->titulo = "NULL";
    this->compania = "NULL";
    this->anio = 0;
    this->puntuacionTotal = 0;
    this->totalUsuariosQueHanValorado = 0;
    this->valoracionMediaActual = 0;
    this->ruta = "NULL";
    this->formato = "NULL";
    this->rutaPrograma = "NULL";

	//DEBUG
    //cout << RED_COLOR << "DEBUG: Multimedia Construido Correctamente" << RESTORE_DEFAULT_COLOR  << endl;
}

Multimedia::Multimedia(string id, string titulo, string compania, int anio, string ruta, string formato, string rutaPrograma){

	this->id = id; //ver lo del id incremental unico....
    this->titulo = titulo;
    this->compania = compania;
    this->anio = anio;
    this->puntuacionTotal = 0; 
    this->totalUsuariosQueHanValorado = 0;
    this->valoracionMediaActual = 0;
    this->ruta = ruta;
    this->formato = formato;
    this->rutaPrograma = rutaPrograma;
}

Multimedia::~Multimedia(){

	this->id = "NULL";
    this->titulo = "NULL";
    this->compania = "NULL";
    this->anio = 0;
    this->puntuacionTotal = 0;
    this->totalUsuariosQueHanValorado = 0;
    this->valoracionMediaActual = 0;
    this->ruta = "NULL";
    this->formato = "NULL";
    this->rutaPrograma = "NULL";

	//DEBUG
    //cout << RED_COLOR << "DEBUG: Multimedia destruido Correctamente" << RESTORE_DEFAULT_COLOR  << endl;
}



void Multimedia::reproducir(string rutaArchivo) {
    pid_t pid = fork(), w;
	int status;
	string rutaPrograma = "/usr/bin/vlc";
    
    if (pid == -1){
        cerr << "No hay memoria..." << endl;
       	exit(EXIT_FAILURE);
    } else if (pid == 0) {
    	cout << "Child process: My process id = " << getpid() << endl;
    	cout << "Child process: Value returned by fork() = " << pid << endl;
       	execl(rutaPrograma.c_str(), rutaPrograma.c_str(), rutaArchivo.c_str(), (char *) 0);
    } 

    do {
        w = waitpid(pid, &status, WUNTRACED | WCONTINUED);
        if (w == -1)  {
            exit(EXIT_FAILURE);
        }

        if (WIFEXITED(status)) {
            cout << "exited, status:" << WEXITSTATUS(status) << endl;
        } else if (WIFSIGNALED(status)) {
            cout << "killed by signal" << WTERMSIG(status) << endl;
        } else if (WIFSTOPPED(status)) {
        	cout << "stopped by signal" << WSTOPSIG(status) << endl;
        } else if (WIFCONTINUED(status)) {
            cout << "continua ..." << endl;
        }
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
}



void Multimedia::modificarMultimedia(string nuevoTitulo, string nuevaCompania, int nuevoAnio, string nuevaRuta, string nuevoFormato){

	this->titulo = nuevoTitulo;
	this->compania = nuevaCompania;
	this->anio = nuevoAnio;
	this->ruta = nuevaRuta;
	this->formato = nuevoFormato;

	//DEBUG
    //cout << RED_COLOR << "DEBUG: Multimedia modificado Correctamente" << RESTORE_DEFAULT_COLOR  << endl;
}



void Multimedia::imprimirMultimedia(){

	cout << BLUE_COLOR <<  endl << "\t********************************************" << RESTORE_DEFAULT_COLOR << endl;
	cout << GREEN_COLOR << "\n\tID: " << this->getId();
	cout << "\n\tTitulo: " << this->getTitulo();
	cout << "\n\tCompañia: " << this->getCompania();
	cout << "\n\tAño: " << this->getAnio();
	cout << "\n\tRuta: " << this->getRuta();
	cout << "\n\tFormato: " << this->getFormato();
	cout << "\n\tValoracion media: " << this->getValoracionMediaActual();
	cout << "\n\tUsuarios que han valorado: " << this->getTotalUsuariosQueHanValorado();
	cout << BLUE_COLOR <<  endl << endl << "\t********************************************" << RESTORE_DEFAULT_COLOR << endl;


}



/************************************
 *   MODULOS DE LA CLASE MUSICA     *
 ************************************/


Musica::Musica(){

	this->duracion = 0;
    this->autor = "NULL";
    this->estilo = "NULL";

    //DEBUG
    //cout << RED_COLOR << "DEBUG: Musica Construido Correctamente" << RESTORE_DEFAULT_COLOR  << endl;


}

Musica::Musica(string id, string titulo, string compania, int anio, string ruta, string formato, string rutaPrograma, int nuevaDuracion, string nuevoAutor, string nuevoEstilo) : Multimedia(id, titulo, compania, anio, ruta, formato, rutaPrograma){

	this->duracion = nuevaDuracion;
    this->autor = nuevoAutor;
    this->estilo = nuevoEstilo;

    //DEBUG
    //cout << RED_COLOR << "DEBUG: Musica Construido Correctamente" << RESTORE_DEFAULT_COLOR  << endl;


}

Musica::~Musica(){

	this->duracion = 0;
    this->autor = "NULL";
    this->estilo = "NULL";

    //DEBUG
    //cout << RED_COLOR << "DEBUG: Musica destruido Correctamente" << RESTORE_DEFAULT_COLOR  << endl;

}

void Musica::imprimirMultimedia(){
	

	cout << BLUE_COLOR <<  endl << "\t********************************************" << RESTORE_DEFAULT_COLOR << endl;
	cout << GREEN_COLOR << "\n\tID: " << this->getId();
	cout << "\n\tTitulo: " << this->getTitulo();
	cout << "\n\tCompañia: " << this->getCompania();
	cout << "\n\tAño: " << this->getAnio();
	cout << "\n\tRuta: " << this->getRuta();
	cout << "\n\tFormato: " << this->getFormato();
	//atributos propios de Musica
	cout << "\n\tDuración: " << this->getDuracion();
	cout << "\n\tAutor: " << this->getAutor();
	cout << "\n\tEstilo: " << this->getEstilo();

	cout << endl << "\n\tValoracion media: " << this->getValoracionMediaActual();
	cout << "\n\tUsuarios que han valorado: " << this->getTotalUsuariosQueHanValorado();
	cout << BLUE_COLOR <<  endl << endl << "\t********************************************" << RESTORE_DEFAULT_COLOR << endl;


}

void Musica::reproducir(string rutaArchivo){

	pid_t pid = fork(), w;
	int status;
	string rutaPrograma = "/usr/bin/vlc";
    
    if (pid == -1){
        cerr << "No hay memoria..." << endl;
       	exit(EXIT_FAILURE);
    } else if (pid == 0) {
    	cout << "Child process: My process id = " << getpid() << endl;
    	cout << "Child process: Value returned by fork() = " << pid << endl;
       	execl(rutaPrograma.c_str(), rutaPrograma.c_str(), rutaArchivo.c_str(), (char *) 0);
    } 

    do {
        w = waitpid(pid, &status, WUNTRACED | WCONTINUED);
        if (w == -1)  {
            exit(EXIT_FAILURE);
        }

        if (WIFEXITED(status)) {
            cout << "exited, status:" << WEXITSTATUS(status) << endl;
        } else if (WIFSIGNALED(status)) {
            cout << "killed by signal" << WTERMSIG(status) << endl;
        } else if (WIFSTOPPED(status)) {
        	cout << "stopped by signal" << WSTOPSIG(status) << endl;
        } else if (WIFCONTINUED(status)) {
            cout << "continua ..." << endl;
        }
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
}


/************************************
 *   MODULOS DE LA CLASE VIDEO      *
 ************************************/


Video::Video(){

	this->duracion = 0;
    this->tematica = "NULL";
    this->autor = "NULL";

    //DEBUG
    //cout << RED_COLOR << "DEBUG: Video Construido Correctamente" << RESTORE_DEFAULT_COLOR  << endl;


}

Video::Video(string id, string titulo, string compania, int anio, string ruta, string formato, string rutaPrograma, int nuevaDuracion, string nuevaTematica, string nuevoAutor) : Multimedia(id, titulo, compania, anio, ruta, formato, rutaPrograma){

	this->duracion = nuevaDuracion;
    this->tematica = nuevaTematica;
    this->autor = nuevoAutor;

    //DEBUG
    //cout << RED_COLOR << "DEBUG: Video Construido Correctamente" << RESTORE_DEFAULT_COLOR  << endl;

}

Video::~Video(){

	this->duracion = 0;
    this->tematica = "NULL";
    this->autor = "NULL";

    //DEBUG
    //cout << RED_COLOR << "DEBUG: Video destruido Correctamente" << RESTORE_DEFAULT_COLOR  << endl;

}

void Video::imprimirMultimedia(){


	cout << BLUE_COLOR <<  endl << "\t********************************************" << RESTORE_DEFAULT_COLOR << endl;
	cout << GREEN_COLOR << "\n\tID: " << this->getId();
	cout << "\n\tTitulo: " << this->getTitulo();
	cout << "\n\tCompañia: " << this->getCompania();
	cout << "\n\tAño: " << this->getAnio();
	cout << "\n\tRuta: " << this->getRuta();
	cout << "\n\tFormato: " << this->getFormato();
	//atributos propios de Video
	cout << "\n\tDuración: " << this->getDuracion();
	cout << "\n\tTemática: " << this->getTematica();
	cout << "\n\tAutor: " << this->getAutor();

	cout << endl << "\n\tValoracion media: " << this->getValoracionMediaActual();
	cout << "\n\tUsuarios que han valorado: " << this->getTotalUsuariosQueHanValorado();
	cout << BLUE_COLOR <<  endl << endl << "\t********************************************" << RESTORE_DEFAULT_COLOR << endl;


}


void Video::reproducir(string rutaArchivo){

	pid_t pid = fork(), w;
	int status;
	string rutaPrograma = "/usr/bin/vlc";
    
    if (pid == -1){
        cerr << "No hay memoria..." << endl;
       	exit(EXIT_FAILURE);
    } else if (pid == 0) {
    	cout << "Child process: My process id = " << getpid() << endl;
    	cout << "Child process: Value returned by fork() = " << pid << endl;
       	execl(rutaPrograma.c_str(), rutaPrograma.c_str(), rutaArchivo.c_str(), (char *) 0);
    } 

    do {
        w = waitpid(pid, &status, WUNTRACED | WCONTINUED);
        if (w == -1)  {
            exit(EXIT_FAILURE);
        }

        if (WIFEXITED(status)) {
            cout << "exited, status:" << WEXITSTATUS(status) << endl;
        } else if (WIFSIGNALED(status)) {
            cout << "killed by signal" << WTERMSIG(status) << endl;
        } else if (WIFSTOPPED(status)) {
        	cout << "stopped by signal" << WSTOPSIG(status) << endl;
        } else if (WIFCONTINUED(status)) {
            cout << "continua ..." << endl;
        }
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));

}

/************************************
 *   MODULOS DE LA CLASE IMAGEN     *
 ************************************/


Imagen::Imagen(){

    this->resolucion = "NULL";

    //DEBUG
    //cout << RED_COLOR << "DEBUG: Imagen Construido Correctamente" << RESTORE_DEFAULT_COLOR  << endl;


}

Imagen::Imagen(string id, string titulo, string compania, int anio, string ruta, string formato, string rutaPrograma, string nuevaResolucion) : Multimedia(id, titulo, compania, anio, ruta, formato, rutaPrograma){

    this->resolucion = nuevaResolucion;

    //DEBUG
    //cout << RED_COLOR << "DEBUG: Imagen Construido Correctamente" << RESTORE_DEFAULT_COLOR  << endl;


}

Imagen::~Imagen(){

    this->resolucion = "NULL";

    //DEBUG
    //cout << RED_COLOR << "DEBUG: Imagen destruido Correctamente" << RESTORE_DEFAULT_COLOR  << endl;

}

void Imagen::imprimirMultimedia(){


	cout << BLUE_COLOR <<  endl << "\t********************************************" << RESTORE_DEFAULT_COLOR << endl;
	cout << GREEN_COLOR << "\n\tID: " << this->getId();
	cout << "\n\tTitulo: " << this->getTitulo();
	cout << "\n\tCompañia: " << this->getCompania();
	cout << "\n\tAño: " << this->getAnio();
	cout << "\n\tRuta: " << this->getRuta();
	cout << "\n\tFormato: " << this->getFormato();
	//atributos propios de Imagen
	cout << "\n\tResolución: " << this->getResolucion();

	cout << endl << "\n\tValoracion media: " << this->getValoracionMediaActual();
	cout << "\n\tUsuarios que han valorado: " << this->getTotalUsuariosQueHanValorado();
	cout << BLUE_COLOR <<  endl << endl << "\t********************************************" << RESTORE_DEFAULT_COLOR << endl;


}

void Imagen::reproducir(string rutaArchivo){

	pid_t pid = fork(), w;
	int status;
	string rutaPrograma = "/usr/bin/gimp-2.8";
    
    if (pid == -1){
        cerr << "No hay memoria..." << endl;
       	exit(EXIT_FAILURE);
    } else if (pid == 0) {
    	cout << "Child process: My process id = " << getpid() << endl;
    	cout << "Child process: Value returned by fork() = " << pid << endl;
       	execl(rutaPrograma.c_str(), rutaPrograma.c_str(), rutaArchivo.c_str(), (char *) 0);
    } 

    do {
        w = waitpid(pid, &status, WUNTRACED | WCONTINUED);
        if (w == -1)  {
            exit(EXIT_FAILURE);
        }

        if (WIFEXITED(status)) {
            cout << "exited, status:" << WEXITSTATUS(status) << endl;
        } else if (WIFSIGNALED(status)) {
            cout << "killed by signal" << WTERMSIG(status) << endl;
        } else if (WIFSTOPPED(status)) {
        	cout << "stopped by signal" << WSTOPSIG(status) << endl;
        } else if (WIFCONTINUED(status)) {
            cout << "continua ..." << endl;
        }
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));

}

