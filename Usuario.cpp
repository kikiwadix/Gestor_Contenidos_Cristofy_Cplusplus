

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Usuario.h"


#define RED_COLOR "\033[1;31m"
#define GREEN_COLOR "\033[1;32m"
#define BLUE_COLOR "\033[1;34m"
#define RESTORE_DEFAULT_COLOR "\033[0m"


using namespace std;

Usuario::Usuario(){

	this->login = "NULL";
	this->password = "NULL";
	this->nombre = "NULL";
	this->apellido1 = "NULL";
	this->apellido2 = "NULL";
	this->edad = 0;

	this->listaContenidosUsuario = new Multimedia*[1];

	if (this->listaContenidosUsuario == 0){
        cerr << "Error. El sistema operativo no tiene memoria suficiente. Se abortará la ejecución..." << endl;
        exit(-1);
    }
    
	this->listaValoraciones = new float[1];
	if (this->listaValoraciones == 0){
        cerr << "Error. El sistema operativo no tiene memoria suficiente. Se abortará la ejecución..." << endl;
        exit(-1);
    }
    
	this->utilesCV = 0;

	//DEBUG
    //cout << RED_COLOR << "DEBUG: Usuario Construido Correctamente" << RESTORE_DEFAULT_COLOR  << endl;
}


Usuario::Usuario(string nuevoLogin, string nuevoPassword, string nuevoNombre, string nuevoApellido1, string nuevoApellido2, int nuevaEdad, int nuevasUtilesCV){

	this->login = nuevoLogin;
	this->password = nuevoPassword;
	this->nombre = nuevoNombre;
	this->apellido1 = nuevoApellido1;
	this->apellido2 = nuevoApellido2;
	this->edad = nuevaEdad;

	this->listaContenidosUsuario = new Multimedia*[10];
	
	if (this->listaContenidosUsuario == 0){
        cerr << "Error. El sistema operativo no tiene memoria suficiente. Se abortará la ejecución..." << endl;
        exit(-1);
    }
    
	this->listaValoraciones = new float[10];
	if (this->listaValoraciones == 0){
        cerr << "Error. El sistema operativo no tiene memoria suficiente. Se abortará la ejecución..." << endl;
        exit(-1);
    }
    
	this->utilesCV = nuevasUtilesCV;

	//DEBUG
    //cout << RED_COLOR << "DEBUG: Usuario Construido Correctamente" << RESTORE_DEFAULT_COLOR  << endl;
}


Usuario::Usuario(const Usuario &u){

	this->login = u.getLogin();
	this->password = u.getPassword();
	this->nombre = u.getNombre();
	this->apellido1 = u.getApellido1();
	this->apellido2 = u.getApellido2();
	this->edad = u.getEdad();
	this->utilesCV = u.getUtilesCV();

	//Creo el nuevo vector de contenidos con la dimension del que quiero hacer la copia
	this->listaContenidosUsuario = new Multimedia*[u.getUtilesCV()];
	
	if (this->listaContenidosUsuario == 0){
        cerr << "Error. El sistema operativo no tiene memoria suficiente. Se abortará la ejecución..." << endl;
        exit(-1);
    }

    //Copio los datos
    for(int i=0;i<u.getUtilesCV();i++){
    	this->listaContenidosUsuario[i] = u.listaContenidosUsuario[i];
    }


    //Creo el nuevo vector de valoraciones con la dimension del que quiero hacer la copia
	this->listaValoraciones = new float[u.getUtilesCV()];
	if (this->listaValoraciones == 0){
        cerr << "Error. El sistema operativo no tiene memoria suficiente. Se abortará la ejecución..." << endl;
        exit(-1);
    }
    
	//Copio los datos
    for(int i=0;i<u.getUtilesCV();i++){
    	this->listaValoraciones[i] = u.listaValoraciones[i];
    }

	//DEBUG
    //cout << RED_COLOR << "DEBUG: Usuario Construido por copia Correctamente" << RESTORE_DEFAULT_COLOR  << endl;
}





Usuario::~Usuario(){

	this->login = "NULL";
	this->password = "NULL";
	this->nombre = "NULL";
	this->apellido1 = "NULL";
	this->apellido2 = "NULL";
	this->edad = 0;
	delete [] this->listaContenidosUsuario;
	delete [] this->listaValoraciones;
	this->utilesCV = 0;


	//DEBUG
    //cout << RED_COLOR << "DEBUG: Usuario destruido Correctamente" << RESTORE_DEFAULT_COLOR  << endl;
}

bool Usuario::asociarContenidoMultimedia(Multimedia* m){

	this->listaContenidosUsuario[this->getUtilesCV()] = m;

	this->setUtilesCV(this->getUtilesCV()+1);

}

void Usuario::desampliarMemoria(){

	//Creo los nuevos vectores con una casilla menos (ya esta actualizado, asi que con el getUtiles va bien)

	Multimedia **auxMul = new Multimedia*[this->getUtilesCV()];

	if (this->listaContenidosUsuario == 0){
        cerr << "Error. El sistema operativo no tiene memoria suficiente. Se abortará la ejecución..." << endl;
        exit(-1);
    }
    
	float *auxVal = new float[this->getUtilesCV()];
	if (this->listaValoraciones == 0){
        cerr << "Error. El sistema operativo no tiene memoria suficiente. Se abortará la ejecución..." << endl;
        exit(-1);
    }

    //copio el contenido de los vectores antiguos a los nuevos

    for(int i=0;i<this->getUtilesCV();i++){ 
        auxMul[i] = this->listaContenidosUsuario[i];
        auxVal[i] = this->listaValoraciones[i];

    }

    //elimino los vectores antiguos y pongo a cero las direcciones... 

    delete [] this->listaContenidosUsuario;
    delete [] this->listaValoraciones;

    this->listaContenidosUsuario = 0;
    this->listaValoraciones = 0;

    //y por ultimo asigno la direccion de los nuevos vectores a su sitio

    this->listaContenidosUsuario = auxMul;
    this->listaValoraciones = auxVal;

   

}

        
bool Usuario::desasociarContenidoMultimedia(int numMultimedia){

	bool exito = false;

	
	//Lo primero es restar la valoracion, a la valoracion general





	//2º 

	//A partir del multimedia a desasociar, cambio la posicion de los multimedia a una menos
	for(int i=numMultimedia;i<getUtilesCV();i++){
		this->listaContenidosUsuario[i] = this->listaContenidosUsuario[i+1];
	}

	//Lo mismo con las valoraciones
	for(int i=numMultimedia;i<getUtilesCV();i++){
		this->listaValoraciones[i] = this->listaValoraciones[i+1];
	}


	//Elimino el ultimo puntero a Multimedia que estará repetido y la ultima valoracion
	this->listaContenidosUsuario[getUtilesCV()-1] = 0;
	this->listaValoraciones[getUtilesCV()-1] = 0;

	//Actualizo las utiles a una menos
	this->setUtilesCV(this->getUtilesCV()-1);

	//Creo los nuevos vectores con una casilla menos (ya esta actualizado, asi que con el getUtiles va bien)

	Multimedia **auxMul = new Multimedia*[getUtilesCV()];

	if (this->listaContenidosUsuario == 0){
        cerr << "Error. El sistema operativo no tiene memoria suficiente. Se abortará la ejecución..." << endl;
        exit(-1);
    }
    
	float *auxVal = new float[getUtilesCV()];
	if (this->listaValoraciones == 0){
        cerr << "Error. El sistema operativo no tiene memoria suficiente. Se abortará la ejecución..." << endl;
        exit(-1);
    }

    //copio el contenido de los vectores antiguos a los nuevos

    for(int i=0;i<this->getUtilesCV();i++){ 
        auxMul[i] = this->listaContenidosUsuario[i];
        auxVal[i] = this->listaValoraciones[i];

    }

    //elimino los vectores antiguos y pongo a cero las direcciones... para el if de mas abajo

    delete [] this->listaContenidosUsuario;
    delete [] this->listaValoraciones;

    this->listaContenidosUsuario = 0;
    this->listaValoraciones = 0;

    //y por ultimo asigno la direccion de los nuevos vectores a su sitio

    this->listaContenidosUsuario = auxMul;
    this->listaValoraciones = auxVal;

    //compruebo que se haya copiado bien la direccion
    if(this->listaContenidosUsuario != 0)
    	exito = true;


	return exito;
}
      
void Usuario::votarContenidoMultimedia(float valoracion, int posicion){

	this->setListaValoraciones(posicion,valoracion);
}
       
void Usuario::modificarDatosUsuario(){

	string nuevoLogin;
	string nuevoPass;
	string nuevoNombre;
	string nuevoApellido1;
	string nuevoApellido2;
	int nuevaEdad;

	cout << "\n\tModificar Login (Antiguo: " << this->getLogin() << ") Nuevo Login: ";
	cin >> nuevoLogin;
	this->setLogin(nuevoLogin);

	cout << "\n\tModificar Password (Antiguo: " << this->getPassword() << ") Nuevo Password: ";
	cin >> nuevoPass;
	this->setPassword(nuevoPass);

	cout << "\n\tModificar Nombre (Antiguo: " << this->getNombre() << ") Nuevo Nombre: ";
	cin >> nuevoNombre;
	this->setNombre(nuevoNombre);

	cout << "\n\tModificar Primer Apellido (Antiguo: " << this->getApellido1() << ") Nuevo Primer Apellido: ";
	cin >> nuevoApellido1;
	this->setApellido1(nuevoApellido1);

	cout << "\n\tModificar Segundo Apellido (Antiguo: " << this->getApellido2() << ") Nuevo Segundo Apellido: ";
	cin >> nuevoApellido2;
	this->setApellido2(nuevoApellido2);

	cout << "\n\tModificar edad (Antiguo: " << this->getEdad() << ") Nueva Edad: ";
	cin >> nuevaEdad;
	this->setEdad(nuevaEdad);

	cout << "\n\tDatos de Usuario modificados con éxito" << endl;
}
       
int Usuario::buscarContenidoAsociado(string titulo){

	bool exito = false;
	int numMultimedia = -1;

	
		for(int i=0;i<this->getUtilesCV();i++){
			if (titulo == this->listaContenidosUsuario[i]->getTitulo()){
				cout << GREEN_COLOR << "\n\t1 resultado obtenido: " << RESTORE_DEFAULT_COLOR << endl;
				exito = true;
				numMultimedia = i;
			}
				
		}

		if(exito==false){
			cout << GREEN_COLOR << "\n\tNingún resultado obtenido." << RESTORE_DEFAULT_COLOR << endl;
		}

	return numMultimedia;
}
       
void Usuario::imprimirListaContenidosAsociadosYValoraciones(){

	cout << GREEN_COLOR <<  endl << "\t********************************************" << RESTORE_DEFAULT_COLOR << endl << endl;
	cout << RED_COLOR << "\tContenido Multimedia de " << this->getNombre() << " " << this->getApellido1() << RESTORE_DEFAULT_COLOR << endl;

	if(this->getUtilesCV() > 0){
		for(int i=0;i<getUtilesCV();i++){
			cout << BLUE_COLOR << "\t\t" << i+1 << "º " << this->listaContenidosUsuario[i]->getTitulo() << "  formato: " << this->listaContenidosUsuario[i]->getFormato() << "  Valoracion Usuario: " << this->listaValoraciones[i] << endl;
		}
	}
	
	cout << GREEN_COLOR <<  endl << "\t********************************************" << RESTORE_DEFAULT_COLOR << endl;

}
        
void Usuario::imprimirListaResultadosBusqueda(){

}
    
int Usuario::buscarPosicionEnListaAsociados(int id){

}
      
int Usuario::buscarPosicionEnListaDeResultados(int id){

}
        
void Usuario::imprimirUsuario(){

	cout << GREEN_COLOR <<  endl << "\t********************************************" << RESTORE_DEFAULT_COLOR << endl;
	cout << BLUE_COLOR << "\n\tLogin: " << this->getLogin();
	cout << "\n\tPassword: " << this->getPassword();
	cout << "\n\tNombre: " << this->getNombre();
	cout << "\n\tPrimer Apellido: " << this->getApellido1();
	cout << "\n\tSegundo Apellido: " << this->getApellido2();
	cout << "\n\tEdad: " << this->getEdad();
	cout << "\n\tNúmero de contenidos Multimedia: " << this->getUtilesCV() << RESTORE_DEFAULT_COLOR << endl;
	

	//Imprimo el nombre de sus contenidos multimedia, si existen
	if(this->getUtilesCV() > 0){
		for(int i=0;i<getUtilesCV();i++){
			cout << RED_COLOR << "\t\t" << i+1 << "º " << this->listaContenidosUsuario[i]->getTitulo() << "  formato: " << this->listaContenidosUsuario[i]->getFormato() << "  Valoracion Usuario: " << this->listaValoraciones[i] << endl;
		}
	}

	cout << GREEN_COLOR <<  endl << "\t********************************************" << RESTORE_DEFAULT_COLOR << endl;
}


Multimedia** Usuario::ampliarMemoriaListaContenidos(){

    Multimedia **aux = new Multimedia*[this->getUtilesCV()+1]; //CREO EL NUEVO VECTOR AMPLIADO UN HUECO
    if(aux == 0){
        cerr << "Error. Se abortará la ejecución porque el SO no tiene memoria." << endl;
        exit(-1);
    }
    
    for(int i=0;i<this->getUtilesCV();i++){ //COPIO LOS DATOS DE UN VECTOR A OTRO
        aux[i] = this->listaContenidosUsuario[i];
    }
    
    //NO AMPLIO LAS UTILES TODAVIA, PQ EL MODULO DE ASOCIAR CONTENIDO MULTIMEDIA YA LO HACE

    this->listaValoraciones = this->ampliarMemoriaListaValoraciones(); //aqui amplio el vector de valoraciones tambien en 1 hueco
    
    delete [] this->listaContenidosUsuario;  //BORRO EL VECTOR ANTIGUO

    return aux;

}

float* Usuario::ampliarMemoriaListaValoraciones(){

	float *aux = new float[this->getUtilesCV()+1]; //CREO EL NUEVO VECTOR AMPLIADO UN HUECO
    if(aux == 0){
        cerr << "Error. Se abortará la ejecución porque el SO no tiene memoria." << endl;
        exit(-1);
    }
    for(int i=0;i<this->getUtilesCV();i++){ //COPIO LOS DATOS DE UN VECTOR A OTRO
        aux[i] = this->listaValoraciones[i];
    }

    //NO AMPLIO LAS UTILES TODAVIA, PQ EL MODULO DE ASOCIAR CONTENIDO MULTIMEDIA YA LO HACE

    
    delete [] this->listaValoraciones;  //BORRO EL VECTOR ANTIGUO

    return aux;

}

void Usuario::ampliarDosMemorias(){

	this->listaContenidosUsuario = this->ampliarMemoriaListaContenidos();
}
