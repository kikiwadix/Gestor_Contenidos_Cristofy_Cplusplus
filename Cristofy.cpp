

#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <sstream>
#include "Cristofy.h"
#include <stdio.h>



#define RED_COLOR "\033[1;31m"
#define GREEN_COLOR "\033[1;32m"
#define BLUE_COLOR "\033[1;34m"
#define RESTORE_DEFAULT_COLOR "\033[0m"


using namespace std;

Cristofy::Cristofy(){

	//Se crea el vector de punteros a usuario con 2 huecos. Se incrementará al doble cuando esté lleno
	this->listaUsuarios = new Usuario*[2];
	if (this->listaUsuarios == 0){
        cerr << "Error. El sistema operativo no tiene memoria suficiente. Se abortará la ejecución..." << endl;
        exit(-1);
    }
    
    this->usuariosTotales = 0;
    this->dimUsuarios = 2;

    this->listaContenidoMultimedia = new Multimedia*[2];
    if (this->listaContenidoMultimedia == 0){
        cerr << "Error. El sistema operativo no tiene memoria suficiente. Se abortará la ejecución..." << endl;
        exit(-1);
    }
    
    this->contenidosTotales = 0;
    this->dimMultimedia = 2;

	//DEBUG
    //cout << RED_COLOR << "DEBUG: Cristofy Construido Correctamente" << RESTORE_DEFAULT_COLOR  << endl;
}

Cristofy::~Cristofy(){

	for(int i=0;i<this->getUsuariosTotales();i++){
		delete this->listaUsuarios[i];
	}

	delete [] this->listaUsuarios;
    this->usuariosTotales = 0;
    this->dimUsuarios = 0;


	for(int i=0;i<this->getContenidosTotales();i++){
		delete this->listaContenidoMultimedia[i];
	}


    delete [] this->listaContenidoMultimedia;
    this->contenidosTotales = 0;
    this->dimMultimedia = 0;



	//DEBUG
    //cout << RED_COLOR << "DEBUG: Cristofy destruido Correctamente" << RESTORE_DEFAULT_COLOR  << endl;
}




/********************************************************************/

void Cristofy::sumarValoracion(int posicion, float valoracion){

	this->listaContenidoMultimedia[posicion]->setPuntuacionTotal(this->listaContenidoMultimedia[posicion]->getPuntuacionTotal() + valoracion);

	this->listaContenidoMultimedia[posicion]->setTotalUsuariosQueHanValorado(this->listaContenidoMultimedia[posicion]->getTotalUsuariosQueHanValorado() +1 );

	this->listaContenidoMultimedia[posicion]->setValoracionMediaActual(this->listaContenidoMultimedia[posicion]->getPuntuacionTotal() / this->listaContenidoMultimedia[posicion]->getTotalUsuariosQueHanValorado() );
}


void Cristofy::restarValoracion(int posicion, float valoracion){

	this->listaContenidoMultimedia[posicion]->setPuntuacionTotal(this->listaContenidoMultimedia[posicion]->getPuntuacionTotal() - valoracion);

	this->listaContenidoMultimedia[posicion]->setTotalUsuariosQueHanValorado(this->listaContenidoMultimedia[posicion]->getTotalUsuariosQueHanValorado() -1 );

	this->listaContenidoMultimedia[posicion]->setValoracionMediaActual(this->listaContenidoMultimedia[posicion]->getPuntuacionTotal() / this->listaContenidoMultimedia[posicion]->getTotalUsuariosQueHanValorado() );


}


void Cristofy::consultarValoracionMedia(int posicion){

	
}



void Cristofy::bienvenida(){


    system("clear");

    cout << BLUE_COLOR << "\n\n\n\n\n\n\t\t////////////" << GREEN_COLOR << "    Welcome to Cristofy    " 
	<< BLUE_COLOR << "\\\\\\\\\\\\\\\\\\\\\\\n\n\n\n\n" << RESTORE_DEFAULT_COLOR;



}

void Cristofy::despedida(){

	cout << RED_COLOR << "\n\n\n\n\n\n\t\t////////////" << GREEN_COLOR << "      See you soon!!      " 
	<< RED_COLOR << "\\\\\\\\\\\\\\\\\\\\\\\n\n\n\n\n" << RESTORE_DEFAULT_COLOR;

}

Usuario* Cristofy::rellenarDatosUsuarioNuevo(){
	string login, password, nombre, apellido1, apellido2;
	int edad = 0;
	int igual = 0;

	cout << GREEN_COLOR << "\n\t\tRellena los campos para crear el nuevo Usuario: " << RESTORE_DEFAULT_COLOR;

	do{
		igual = 0;
		cout << "\n\tIntroduce el login (servirá para registrarse): ";
		cin.ignore();
		getline(cin, login);
		for(int i=0;i<this->getUsuariosTotales();i++){
			if (login == this->listaUsuarios[i]->getLogin() ){
				cout << RED_COLOR << "\n\tError, login de Usuario ya en uso, pruebe otro." << RESTORE_DEFAULT_COLOR;
				igual = 1;
			}
		}
	}while(igual != 0);

	cout << "\n\tIntroduce el Password: ";
	getline(cin, password);
	cout << "\n\tIntroduce el Nombre: ";
	getline(cin, nombre);
	cout << "\n\tIntroduce el primer apellido: ";
	getline(cin, apellido1);
	cout << "\n\tIntroduce el segundo apellido: ";
	getline(cin, apellido2);
	do{
		cout << "\n\tIntroduce la edad: ";
		cin >> edad;
	}while(edad<1 || edad>120);
	return new Usuario (login, password, nombre, apellido1, apellido2, edad, 0);
	
}


Usuario** Cristofy::ampliarMemoriaUsuario(){



    Usuario **aux = new Usuario*[2*this->getDimUsuarios()]; //CREO EL NUEVO VECTOR AMPLIADO AL DOBLE
    if(aux == 0){
        cerr << "Error. Se abortará la ejecución porque el SO no tiene memoria." << endl;
        exit(-1);
    }
    for(int i=0;i<this->getUsuariosTotales();i++){ //COPIO LOS DATOS DE UN VECTOR A OTRO
        aux[i] = this->listaUsuarios[i];
    }

    this->setDimUsuarios(2*this->getDimUsuarios());

    
    delete [] this->listaUsuarios;  //BORRO EL VECTOR ANTIGUO

    return aux;

}

void Cristofy::anadirUsuarioASistema(Usuario* user){

	//Si no hay espacio, se crea un nuevo vector ampliado al doble
	if(this->getDimUsuarios() == this->getUsuariosTotales()){
		this->listaUsuarios = this->ampliarMemoriaUsuario();
	}

	this->setListaUsuarios(this->getUsuariosTotales(), user);
	
	this->setUsuariosTotales(this->getUsuariosTotales()+1); //se amplia en uno los usuarios totales
	

	//DEBUG
    //cout << RED_COLOR << "DEBUG: Usuario añadido al sistema Correctamente" << RESTORE_DEFAULT_COLOR  << endl;

}

void Cristofy::mostrarMenuUsuario(Usuario *user){
	
	int opcion =0;
	char opcion2;
	bool permanecer = true;

	string nombreABuscar;
	int numMultimedia = -1;
	bool correcto = false;
	bool correcto3 = false;

	float valoracion = 0.0;

	float valoracion2 = 0.0;
	int posicion = 0;

	int posicionMulti = 0;
	

	do{
		do{
			cout << BLUE_COLOR << "\n\t\tOpciones de Usuario -> Por favor, elige: " << RESTORE_DEFAULT_COLOR << endl;
			cout << "\n\t\t\t1. Modificar Datos Personales";
			cout << "\n\t\t\t2. Consultar lista de Contenidos y valoraciones del Usuario";
			cout << "\n\t\t\t3. \"Me Gusta\": Asociar Contenido Multimedia a Usuario";
			cout << "\n\t\t\t4. \"Ya No me Gusta\": Desasociar Contenido Multimedia a Usuario";
			cout << "\n\t\t\t5. \"Votar\": Valorar Contenido Multimedia (Modificar)";
			cout << "\n\t\t\t6. Reproducir Contenido Multimedia";
			cout << "\n\t\t\t7. Salir";
			cin >> opcion;
		}while(opcion<1 || opcion>7);

		switch(opcion){

		    case 1:
		    		
		        	user->modificarDatosUsuario();
		        break;

		    case 2:

		    		user->imprimirListaContenidosAsociadosYValoraciones();
		        break;

		    case 3:

				cout << "\n\tDesea buscar contenido Multimedia por (T)itulo, o primero desea que le muestre la lista de (M)ultimedias?: ";
				cin >> opcion2;
				if (opcion2 == 'T' || opcion2 == 't'){
					cout << "\n\tIntroduzca el titulo del multimedia a asociar: ";
					cin.ignore();
					getline(cin, nombreABuscar);
					numMultimedia = this->buscarMultimediaEnSistema(nombreABuscar); //devuelve un int

					if(numMultimedia>=0){

						user->ampliarDosMemorias(); //AMPLIO LA MEMORIA EN UN HUECO


						correcto = user->asociarContenidoMultimedia(this->listaContenidoMultimedia[numMultimedia]); //devuelve un bool
						if(correcto){
							cout << GREEN_COLOR << "\n\tMultimedia Añadido con éxito a su lista de contenidos" << RESTORE_DEFAULT_COLOR << endl;
							correcto3 = true;
						}else
							cout << RED_COLOR << "\n\tError añadiendo el multimedia, pruebe otra vez" << RESTORE_DEFAULT_COLOR;
					}

					//ahora si o si ha de meter una valoracion del multimedia
					if(correcto3){
						do{
							cout << "\n\tPor favor, valore el Multimedia que acaba de asociar a su lista (de 1 a 10): ";
							cin >> valoracion;
						}while(valoracion<0.0 || valoracion>10.0);
						
						user->setListaValoraciones( (user->getUtilesCV()-1), valoracion);

						//aqui llamo al modulo sumarValoracion
						//Se le pasa el numero del multimedia a cambiar la valoracion total, y la valoracion del usuario
						this->sumarValoracion(numMultimedia, valoracion); 

						cout << GREEN_COLOR << "\n\tGracias por su voto!" << RESTORE_DEFAULT_COLOR << endl;

					}




				}else if (opcion2 == 'M' || opcion2 == 'm'){
					for(int i=0;i<getContenidosTotales();i++){
						this->listaContenidoMultimedia[i]->imprimirMultimedia();
					}
				}


		        break;

		    case 4:

		    	cout << "\n\tDesea buscar contenido Multimedia por (T)itulo, o primero desea que le muestre la lista de (M)ultimedias?: ";
				cin >> opcion2;
				if (opcion2 == 'T' || opcion2 == 't'){
					cout << "\n\tIntroduzca el titulo del Multimedia a desasociar: ";
					cin.ignore();
					getline(cin, nombreABuscar);
					numMultimedia = user->buscarContenidoAsociado(nombreABuscar); //devuelve un int

					if(numMultimedia>=0){

						//Antes de borrarlo, voy a sacar su valoracion, para restarla en el computo general
						valoracion = user->getListaValoraciones(numMultimedia);

						//y ahora realizaré una busqueda para buscarlo en el vector de contenidos de cristofy
						for(int i = 0;i<getContenidosTotales();i++){
							if(user->getListaContenidosUsuario(numMultimedia)->getTitulo() == this->listaContenidoMultimedia[i]->getTitulo() ){
								posicionMulti = i;
							}
						}

						//y ahora llamo al modulo de restar valoracion general
						this->restarValoracion(posicionMulti, valoracion);


						correcto = false;
						correcto = user->desasociarContenidoMultimedia(numMultimedia); //devuelve un bool
						if(correcto){
							cout << GREEN_COLOR << "\n\tMultimedia eliminado con éxito de su lista de contenidos" << RESTORE_DEFAULT_COLOR << endl;
							correcto3 = true;
						}else
							cout << RED_COLOR << "\n\tError desasociando el multimedia, pruebe otra vez" << RESTORE_DEFAULT_COLOR;
					}

					


				}else if (opcion2 == 'M' || opcion2 == 'm'){
					for(int i=0;i<user->getUtilesCV();i++){
						user->getListaContenidosUsuario(i)->imprimirMultimedia();
					}
				}


		        break;

		    case 5:

		    	cout << "\n\tIntroduzca el titulo del multimedia al que desea cambiar la valoracion: ";
				cin.ignore();
				getline(cin, nombreABuscar);
				numMultimedia = user->buscarContenidoAsociado(nombreABuscar); //devuelve un int

				if(numMultimedia>=0){

					//tengo que hace una busqueda en el vector de contenidos de cristofy, y encontrar el mismo multimedia, para sacar su ubicacion
					for(int i = 0;i<getContenidosTotales();i++){
						if(user->getListaContenidosUsuario(numMultimedia)->getTitulo() == this->listaContenidoMultimedia[i]->getTitulo() ){
							posicionMulti = i;
						}
					}


					//Llamo al modulo restarValoracion para que reste la valoracion anterior (antes de cambiarla) al total
					this->restarValoracion(posicionMulti, user->getListaValoraciones(numMultimedia) );

					do{
						cout << "\n\tPor favor, introduzca la nueva valoracion (antes " << user->getListaValoraciones(numMultimedia) << "): ";
						cin >> valoracion;
					}while(valoracion<0.0 || valoracion>10.0);

					user->votarContenidoMultimedia(valoracion, numMultimedia);

					//y ahora llamo al modulo sumarValoracin para que la sume la nueva valoracion
					this->sumarValoracion(posicionMulti, valoracion);

					cout << "\n\tValoración actualizada!" << endl;

				}
		        break;

		    case 6:

		    	numMultimedia = -1;
		    	cout << "\n\tDesea reproducir el contenido Multimedia por (T)itulo, o primero desea que le muestre la lista de (M)ultimedias?: ";
				cin >> opcion2;
				if (opcion2 == 'T' || opcion2 == 't'){
					cout << "\n\tIntroduzca el titulo del Multimedia a reproducir: ";
					cin.ignore();
					getline(cin, nombreABuscar);
					numMultimedia = user->buscarContenidoAsociado(nombreABuscar); //devuelve un int

					//aqui mando a reproducir el multimedia, si lo ha encontrado
					if(numMultimedia>=0){
						user->getListaContenidosUsuario(numMultimedia)->reproducir( user->getListaContenidosUsuario(numMultimedia)->getRuta() );
						system("clear");
					}


				}else if (opcion2 == 'M' || opcion2 == 'm'){
					for(int i=0;i<user->getUtilesCV();i++){
						user->getListaContenidosUsuario(i)->imprimirMultimedia();
					}
				}


		        break;

		    case 7:
		        permanecer = false;
		        break;

		}

	}while(permanecer);

}

void Cristofy::mostrarMenuAdmin(){

	int opcion =0;
	bool permanecer = true;
	bool permanecer2 = true;
	int posicionUsuarioAModificar = 0;
	int posicionUsuarioAEliminar = 0;
	string loginABuscar;
	char opcion2;
	int numUsuario = -1;
	string nombreABuscar;
	int numMultimedia = -1;
	int DimString = 70;

	string nuevoTitulo;
	string nuevaCompania;
	int nuevoAnio;
	string nuevaRuta;
	string nuevoFormato;




	do{
		do{
		cout << BLUE_COLOR << "\n\t\tOpciones de Admin -> Por favor, elige: " << RESTORE_DEFAULT_COLOR << endl;
		cout << "\n\t\t\t1. Importar Datos al Sistema desde fichero *.crfy";
		cout << "\n\t\t\t2. Exportar Datos del Sistema a fichero *.crfy";
		cout << "\n\t\t\t3. Rankings";
		cout << "\n\t\t\t4. Contenidos Multimedia";
		cout << "\n\t\t\t5. Usuarios";
		cout << "\n\t\t\t6. Salir";
		cin >> opcion;
		}while(opcion<1 || opcion>6);

		switch(opcion){

	            case 1:
	            	break;
	            case 2:
	            	break;
	            case 3:
	            		do{
		            		do{
								cout << RED_COLOR << "\n\t\t\tRankings -> Por favor, elige: " << RESTORE_DEFAULT_COLOR << endl;
								cout << "\n\t\t\t\t1. Ranking Top 3 General";
								cout << "\n\t\t\t\t2. Ranking Top 3 por tipo de Multimedia";
								cout << "\n\t\t\t\t3. Ranking Usuarios";
								cout << "\n\t\t\t\t4. Salir";
								cin >> opcion;
							}while(opcion<1 || opcion>4);

							switch(opcion){

		            			case 1:

		            				informeTop3General();




		            				break;

		            			case 2:
		            				cout << "\n\tIntroduzca que tipo de Ranking desea ver, (M)usica, (V)ideo o (I)magen: ";
		            				cin >> opcion2;

		            				if(opcion2 == 'M' || opcion2 == 'm'){
		            					informeTop3Musica();
		            				}else if(opcion2 == 'V' || opcion2 == 'v'){
		            					informeTop3Videos();
		            				}else if(opcion2 == 'I' || opcion2 == 'i'){
		            					informeTop3Imagen();

		            				}else
										cout << RED_COLOR << "\n\tSelección no válida" << RESTORE_DEFAULT_COLOR << endl;


		            				break;

		            			case 3:

		            				this->UsuarioFreak();

		            				break;

		            			case 4:
		            				permanecer2 = false;
		            				break;

		            		}
		            	}while(permanecer2);

	            	break;
	            case 4:

	            	permanecer2 = true;
	            	do{
		            		do{
								cout << RED_COLOR << "\n\t\t\tContenidos Multimedia -> Por favor, elige: " << RESTORE_DEFAULT_COLOR<< endl;
								cout << "\n\t\t\t\t1. Agregar nuevo contenido Multimedia al Sistema";
								cout << "\n\t\t\t\t2. Eliminar contenido Multimedia del Sistema";
								cout << "\n\t\t\t\t3. Buscar contenido Multimedia en Sistema";
								cout << "\n\t\t\t\t4. Modificar datos contenido Multimedia del Sistema";
								cout << "\n\t\t\t\t5. Consultar valoración media Contenido Multimedia";
								cout << "\n\t\t\t\t6. Salir";
								cin >> opcion;
							}while(opcion<1 || opcion>6);

							switch(opcion){

		            			case 1:

		            					this->anadirMultimediaASistema(this->crearMultimediaParaAnadir()); 

		            				break;

		            			case 2:

		            				//Primero le pedimos al usuario ke nos diga cual quiere eliminar, con el tipico menu
		            				cout << "\n\tDesea buscar contenido Multimedia para eliminar por (T)itulo, o primero desea que le muestre la lista de (M)ultimedias?: ";
									cin >> opcion2;
									if (opcion2 == 'T' || opcion2 == 't'){
										cout << "\n\tIntroduzca el titulo del multimedia a eliminar: ";
										cin.ignore();
										getline(cin, nombreABuscar);
										numMultimedia = this->buscarMultimediaEnSistema(nombreABuscar); //devuelve un int

										if(numMultimedia>=0){
											//si lo ha encontrado, devuelve un numero mayor o igual que cero y ahora...
											//voy a buscarlo en los vectores de los usuario, a ver si está
										
											for(int i=0;i<this->getUsuariosTotales();i++){

												for(int j=0;j< this->listaUsuarios[i]->getUtilesCV();j++){//utilizo las utiles de cada usuario para buscar en su vector

													if( this->listaContenidoMultimedia[numMultimedia]->getTitulo() == this->listaUsuarios[i]->getListaContenidosUsuario(j)->getTitulo() ){
														//lo ha encontrado en el usuario, asi que lo borro de la lista del usuario
														this->listaUsuarios[i]->setListaContenidosUsuario(j, 0);
														//y tb de su lista de valoraciones
														this->listaUsuarios[i]->setListaValoraciones(j, -1);
														//ahora ordeno los vectores del usuario
														for(int k=j;k< this->listaUsuarios[i]->getUtilesCV();k++){
															this->listaUsuarios[i]->setListaContenidosUsuario(k, this->listaUsuarios[i]->getListaContenidosUsuario(k+1) );
															this->listaUsuarios[i]->setListaValoraciones(k, this->listaUsuarios[i]->getListaValoraciones(k+1) );

														}
														//ahora pongo las utiles a una menos
														this->listaUsuarios[i]->setUtilesCV( this->listaUsuarios[i]->getUtilesCV() -1);

														//ahora llamo al modulo de la clase usuario para que cree nuevos vectores con un hueco menos
														this->listaUsuarios[i]->desampliarMemoria();


													}
												}
											}

											//y ahora lo elimino del sistema totalmente

											
		            						this->eliminarMultimediaEnSistema(this->listaContenidoMultimedia[numMultimedia] );

										}

									}else if (opcion2 == 'M' || opcion2 == 'm'){
										for(int i=0;i<getContenidosTotales();i++){
											this->listaContenidoMultimedia[i]->imprimirMultimedia();
										}
									}


		            				break;

		            			case 3:
		            		

		            				cout << "\n\tDesea buscar contenido Multimedia por (T)itulo, o primero desea que le muestre la lista de (M)ultimedias?: ";
									cin >> opcion2;
									if (opcion2 == 'T' || opcion2 == 't'){
										cout << "\n\tIntroduzca el titulo del multimedia a buscar: ";
										cin.ignore();
										getline(cin, nombreABuscar);
										numMultimedia = this->buscarMultimediaEnSistema(nombreABuscar); //devuelve un int

										if(numMultimedia>=0){
											this->listaContenidoMultimedia[numMultimedia]->imprimirMultimedia();
										}

									}else if (opcion2 == 'M' || opcion2 == 'm'){
										for(int i=0;i<getContenidosTotales();i++){
											this->listaContenidoMultimedia[i]->imprimirMultimedia();
										}
									}

								
		            				break;

		            			case 4:

		            				cout << "\n\tPara modificar, desea buscar contenido Multimedia por (T)itulo, o primero desea que le muestre la lista de (M)ultimedias?: ";
									cin >> opcion2;
									if (opcion2 == 'T' || opcion2 == 't'){
										cout << "\n\tIntroduzca el titulo del multimedia a modificar: ";
										cin.ignore();
										getline(cin, nombreABuscar);
										numMultimedia = this->buscarMultimediaEnSistema(nombreABuscar); //devuelve un int

										if(numMultimedia>=0){

											cout << "\n\tModificar Titulo (Antiguo: " << this->listaContenidoMultimedia[numMultimedia]->getTitulo() << ") Nuevo Titulo: ";
											getline(cin, nuevoTitulo);

											cout << "\n\tModificar Compañia (Antiguo: " << this->listaContenidoMultimedia[numMultimedia]->getCompania() << ") Nueva Compañia: ";
											getline(cin, nuevaCompania);

											cout << "\n\tModificar Año (Antiguo: " << this->listaContenidoMultimedia[numMultimedia]->getAnio() << ") Nuevo Año: ";
											cin >> nuevoAnio;

											cout << "\n\tModificar Ruta del archivo (Antiguo: " << this->listaContenidoMultimedia[numMultimedia]->getRuta() << ") Nueva Ruta: ";
											cin.ignore();
											getline(cin, nuevaRuta);

											cout << "\n\tModificar Formato (Antiguo: " << this->listaContenidoMultimedia[numMultimedia]->getFormato() << ") Nuevo Formato: ";
											getline(cin, nuevoFormato);


											this->listaContenidoMultimedia[numMultimedia]->modificarMultimedia(nuevoTitulo, nuevaCompania, nuevoAnio, nuevaRuta, nuevoFormato);
										}

									}else if (opcion2 == 'M' || opcion2 == 'm'){
										for(int i=0;i<getContenidosTotales();i++){
											this->listaContenidoMultimedia[i]->imprimirMultimedia();
										}
									}

		            				break;

		            			case 5:

										for(int i=0;i<getContenidosTotales();i++){
											this->listaContenidoMultimedia[i]->imprimirMultimedia();
										}

		            				break;

		            			case 6:
		            				permanecer2 = false;
		            				break;

		            		}
		            	}while(permanecer2);


	            	break;
	            case 5:

	            	permanecer2 = true;
	            	do{
		            		do{
								cout << RED_COLOR << "\n\t\t\tUsuarios -> Por favor, elige: " << RESTORE_DEFAULT_COLOR << endl;
								cout << "\n\t\t\t\t1. Agregar nuevo Usuario al Sistema";
								cout << "\n\t\t\t\t2. Eliminar Usuario del Sistema";
								cout << "\n\t\t\t\t3. Buscar Usuario en Sistema";
								cout << "\n\t\t\t\t4. Modificar datos de Usuario del Sistema";
								cout << "\n\t\t\t\t5. Salir";
								cin >> opcion;
							}while(opcion<1 || opcion>5);

							switch(opcion){

		            			case 1:
		            					this->anadirUsuarioASistema(this->rellenarDatosUsuarioNuevo());
		            				

		            				break;

		            			case 2:

		            				cout << "\n\tQue Usuario de la lista desea eliminar? (introduzca el número de usuario)";
		            				for(int i=0; i<this->getUsuariosTotales(); i++){
		            					cout << GREEN_COLOR << "\n\tNúmero " << i+1 << " | " << this->listaUsuarios[i]->getNombre() << RESTORE_DEFAULT_COLOR; 
		            				}

		            				cin >> posicionUsuarioAEliminar;
		            				posicionUsuarioAEliminar = posicionUsuarioAEliminar-1;

		            				//y ahora, antes de eliminarlo, vamos a actualizar las valoraciones totales, dependiendo de sus votos



		            				this->eliminarUsuarioEnSistema(this->listaUsuarios[posicionUsuarioAEliminar]);

		            				break;

		            			case 3: 

		            				cout << "\n\tDesea buscar al usuario por (L)ogin, o primero desea que le muestre la lista de (U)suarios?: ";
									cin >> opcion2;
									if (opcion2 == 'L' || opcion2 == 'l'){
										cout << "\n\tIntroduzca el Login a buscar: ";
										cin >> loginABuscar;
										numUsuario = this->buscarUsuarioEnSistema(loginABuscar); //devuelve un int

										if(numUsuario>=0){
											this->listaUsuarios[numUsuario]->imprimirUsuario();
										}

									}else if (opcion2 == 'U' || opcion2 == 'u'){
										for(int i=0;i<getUsuariosTotales();i++){
											this->listaUsuarios[i]->imprimirUsuario();
										}
									}


		            				break;

		            			case 4:

		            				cout << "\n\tQue Usuario de la lista desea modificar? (introduzca el número de usuario)";
		            				for(int i=0; i<this->getUsuariosTotales(); i++){
		            					cout << GREEN_COLOR << "\n\tNúmero " << i+1 << " | " << this->listaUsuarios[i]->getNombre() << RESTORE_DEFAULT_COLOR; 
		            				}

		            				cin >> posicionUsuarioAModificar;
		            				posicionUsuarioAModificar = posicionUsuarioAModificar-1;

		            				this->listaUsuarios[posicionUsuarioAModificar]->modificarDatosUsuario();

		            				break;

		            			case 5:
		            				permanecer2 = false;
		            				break;

		            		}
		            	}while(permanecer2);



	            	break;
	            case 6:
	            	permanecer = false;
	            	break;
	               
	    }

	}while(permanecer);


}

Multimedia* Cristofy::crearMultimediaParaAnadir(){

	char opcion;

	Multimedia *nuevoMultimediaCreado;

	//ATRIBUTOS DE MULTIMEDIA Y MUSICA
	string id = "NULL";
	string titulo = "NULL";
	string compania = "NULL";
	int anio = 0;
	string ruta = "NULL";
	string formato = "NULL";
	string rutaPrograma = "NULL";
	int duracion = 0;
	string autor = "NULL";
	string estilo = "NULL";

	//ATRIBUTOS DE VIDEO
	//int duracion = 0;  //LA COMPARTE CON MUSICA
    string tematica = "NULL";
    //string autor = "NULL"; //LO COMPARTE CON MUSICA

	//ATRIBUTOS DE IMAGEN
	string resolucion = "NULL";


	cout << "\n\tQuiere añadir un nuevo Multimedia de tipo (M)usica, (V)ideo o (I)magen?";
	cin >> opcion;

	if(opcion == 'M' || opcion == 'm'){
		cout << "\n\tIntroduzca el Titulo: ";
		cin.ignore();
		getline(cin, titulo);
		cout << "\n\tIntroduzca la Compañia: ";
		getline(cin, compania);
		cout << "\n\tIntroduzca el Año: ";
		cin >> anio;
		cout << "\n\tIntroduzca la Ruta del archivo: ";
		cin.ignore();
		getline(cin, ruta);
		cout << "\n\tIntroduzca el formato: ";
		getline(cin, formato);
		cout << "\n\tIntroduzca la duración: ";
		cin >> duracion;
		cout << "\n\tIntroduzca el Autor: ";
		cin.ignore();
		getline(cin, autor);
		cout << "\n\tIntroduzca el estilo: ";
		getline(cin, estilo);

		id = generarId("M"); //este modulo devolvera un string generado

		nuevoMultimediaCreado = new Musica(id, titulo, compania, anio, ruta, formato, "/usr/bin/vlc", duracion, autor, estilo);

		


	}else if(opcion == 'V' || opcion == 'v'){
		cout << "\n\tIntroduzca el Titulo: ";
		cin.ignore();
		getline(cin, titulo);
		cout << "\n\tIntroduzca la Compañia: ";
		getline(cin, compania);
		cout << "\n\tIntroduzca el Año: ";
		cin >> anio;
		cout << "\n\tIntroduzca la Ruta del archivo: ";
		cin.ignore();
		getline(cin, ruta);
		cout << "\n\tIntroduzca el formato: ";
		getline(cin, formato);
		cout << "\n\tIntroduzca la duración: ";
		cin >> duracion;
		cout << "\n\tIntroduzca la temática: ";
		cin.ignore();
		getline(cin, tematica);
		cout << "\n\tIntroduzca el autor: ";
		getline(cin, autor);

		id = generarId("V"); //este modulo devolvera un string generado

		nuevoMultimediaCreado = new Video(id, titulo, compania, anio, ruta, formato, "/usr/bin/vlc", duracion, tematica, autor);

	}else if(opcion == 'I' || opcion == 'i'){
		cout << "\n\tIntroduzca el Titulo: ";
		cin.ignore();
		getline(cin, titulo);
		cout << "\n\tIntroduzca la Compañia: ";
		getline(cin, compania);
		cout << "\n\tIntroduzca el Año: ";
		cin >> anio;
		cout << "\n\tIntroduzca la Ruta del archivo: ";
		cin.ignore();
		getline(cin, ruta);
		cout << "\n\tIntroduzca el formato: ";
		getline(cin, formato);
		cout << "\n\tIntroduzca la resolución: ";
		getline(cin, resolucion);

		id = generarId("I"); //este modulo devolvera un string generado

		nuevoMultimediaCreado = new Imagen(id, titulo, compania, anio, ruta, formato, "/usr/bin/vlc", resolucion);


	}else
		cout << RED_COLOR << "\n\tSelección no válida" << RESTORE_DEFAULT_COLOR << endl;

	return nuevoMultimediaCreado;

}

string Cristofy::generarId(string tipoMultimedia){

	string devuelvoGenerado;

	//Esto me genera, según el tipo de multimedia, el principio del nombre del multimedia
	int nuevoNumFinal = this->getContenidosTotales()+1;
	
	if(tipoMultimedia == "M"){
		devuelvoGenerado = "MUSICA-"; 

	}else if(tipoMultimedia == "V"){
		devuelvoGenerado = "VIDEO-";

	}else if(tipoMultimedia == "I"){
		devuelvoGenerado = "IMAGEN-";

	}

	//Convertir un entero a un string llamadao NSTR
	//Me sirve para añadir al final del nombre, el número del multimedia por donde va
	int a = nuevoNumFinal;
	stringstream ss;
	ss << a;
	string nstr = ss.str(); //aqui guardo en el string nstr, el int pasado a string
	string resultado = devuelvoGenerado + nstr; //el operador está sobrecargado, nos quita trabajo



	 //devuelvo el resultado de la suma de los 2 strings, para generar el Id alfanumérico ascendente único
	return resultado;
}


int Cristofy::autenticacion(string login, string password){

	int numUser = -1;


	for(int i=1;i<getUsuariosTotales();i++){
		if( (login == this->listaUsuarios[i]->getLogin() ) &&  ( password == this->listaUsuarios[i]->getPassword()) ){
			cout << RED_COLOR << "\n\tAutentificacion correcta, Sr. " << this->listaUsuarios[i]->getApellido1() << RESTORE_DEFAULT_COLOR << endl;
			numUser = i;
		}
	}

	return numUser;
}

void Cristofy::preMenu(){

	int opcion = 0;
	string login, pass;
	bool correcto = false, permanecer = true;
	Usuario *user;
	int numUser = -1;

	do{	
		do{
		cout << GREEN_COLOR << "\n\tInicio -> Por favor, elige: " << RESTORE_DEFAULT_COLOR << endl;
		cout << "\n\t\t1. Administración del Sistema";
		cout << "\n\t\t2. Acciones del usuario";
		cout << "\n\t\t3. Salir";
		cin >> opcion;
		}while(opcion<1 || opcion>3);

		switch(opcion){

	            case 1:
	               
	                cout << "\n\tIntroduce el Login: ";
	                cin >> login;
	                cout << "\n\tIntroduce la contraseña: ";
	                cin >> pass;
	                if(login==this->listaUsuarios[0]->getLogin() && pass==this->listaUsuarios[0]->getPassword()){
	                	cout << RED_COLOR << "\n\tUsuario Admin logueado con éxito" << RESTORE_DEFAULT_COLOR << endl;
	                	this->mostrarMenuAdmin();
	                }else
	                	cout << RED_COLOR << "\n\tLo sentimos, el Usuario o la contraseña no son correctos." << RESTORE_DEFAULT_COLOR << endl;
	               
	                break;

	            case 2:
	            	cout << "\n\tIntroduce el Login: ";
	                cin >> login;
	                cout << "\n\tIntroduce la contraseña: ";
	                cin >> pass;

	                numUser = this->autenticacion(login, pass);

	                if(numUser>=0){ 
	                	this->mostrarMenuUsuario(this->listaUsuarios[numUser]);
	                }else
	                	cout << RED_COLOR << "\n\tLo sentimos, el Usuario o la contraseña no son correctos." << RESTORE_DEFAULT_COLOR << endl;

	            	break;
	            case 3:
	            	permanecer = false;
	            	break;

	    }

	}while(permanecer);
}




bool Cristofy::importarFichero(string rutaOrigen){

}

bool Cristofy::exportarFichero(string rutaDestino){

}


int Cristofy::buscarUsuarioEnSistema(const string loginABuscar){

	
	bool exito = false;
	int numUsuario = -1;

	
		for(int i=0;i<this->getUsuariosTotales();i++){
			if (loginABuscar == this->listaUsuarios[i]->getLogin()){
				cout << GREEN_COLOR << "\n\t1 resultado obtenido: " << RESTORE_DEFAULT_COLOR << endl;
				exito = true;
				numUsuario = i;
			}
				
		}

		if(exito==false){
			cout << GREEN_COLOR << "\nNingún resultado obtenido." << RESTORE_DEFAULT_COLOR << endl;
		}


	return numUsuario;

}



void Cristofy::eliminarUsuarioEnSistema(Usuario *user){

	int casillaNumero = 0;
	int posicionMulti = 0;

	//cout << "debug: usuarios totales: " << this->getUsuariosTotales() << endl;

	//este if es para que, sólo si tiene algun contenido multimedia asociado, restar las valoraciones pertinentes
	if(user->getUtilesCV() != 0){


		//y antes de borrar sus vectores internos, saco las valoraciones de sus contenidos multimedia, para restarlas del general
		//hay que tener cuidado pq he de hacerlo para cada multimedia que tenga asociado

		for(int i=0; i<user->getUtilesCV();i++){
			
			//y ahora realizaré una busqueda para buscarlo en el vector de contenidos de cristofy
			for(int j = 0;j<getContenidosTotales();j++){
				if(user->getListaContenidosUsuario(i)->getTitulo() == this->listaContenidoMultimedia[j]->getTitulo() ){
					posicionMulti = j;
					this->restarValoracion(j, user->getListaValoraciones(i) );
				}
			}

		}


	}

	//Busco el usuario en el vector y lo elimino
	for(int i=0;i<this->getUsuariosTotales();i++){
		if(this->listaUsuarios[i]->getLogin() == user->getLogin() ){
			delete this->listaUsuarios[i]; //no? seria asi?
			//delete user;
			casillaNumero = i;
		}
	}

	//A partir del usuario eliminado, cambio la posicion de los usuarios a una menos
	for(int i=casillaNumero;i<getUsuariosTotales();i++){
		this->listaUsuarios[i] = this->listaUsuarios[i +1];
	}

	//Elimino el ultimo usuario que estará repetido
	this->listaUsuarios[getUsuariosTotales()-1] = 0;

	//Actualizo los usuarios totales
	this->setUsuariosTotales( this->getUsuariosTotales()-1 );

	cout << "\nUsuario Eliminado del sistema correctamente" << endl;
}

void Cristofy::guardarUsuarioEnBD(const Usuario &user){

}

int Cristofy::buscarMultimediaEnSistema(const string tituloABuscar){

	bool exito = false;
	int numMultimedia = -1;

	
		for(int i=0;i<this->getContenidosTotales();i++){
			if (tituloABuscar == this->listaContenidoMultimedia[i]->getTitulo()){
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



Multimedia** Cristofy::ampliarMemoriaContenido(){



    Multimedia **aux = new Multimedia*[2*this->getDimMultimedia()]; //CREO EL NUEVO VECTOR AMPLIADO AL DOBLE
    if(aux == 0){
        cerr << "Error. Se abortará la ejecución porque el SO no tiene memoria." << endl;
        exit(-1);
    }
    for(int i=0;i<this->getContenidosTotales();i++){ //COPIO LOS DATOS DE UN VECTOR A OTRO
        aux[i] = this->listaContenidoMultimedia[i];
    }

    this->setDimMultimedia(2*this->getDimMultimedia());

    
    delete [] this->listaContenidoMultimedia;  //BORRO EL VECTOR ANTIGUO

    return aux;

}

void Cristofy::anadirMultimediaASistema(Multimedia *multi){

	//Si no hay espacio, se crea un nuevo vector ampliado al doble
	if(this->getDimMultimedia() == this->getContenidosTotales()){
		this->listaContenidoMultimedia = this->ampliarMemoriaContenido();
	}

	this->setListaContenidoMultimedia(this->getContenidosTotales(), multi);

	this->setContenidosTotales(this->getContenidosTotales()+1); //se amplia en uno los contenidos totales


	//DEBUG
    //cout << RED_COLOR << "DEBUG: Multimedia añadido al sistema Correctamente" << RESTORE_DEFAULT_COLOR  << endl;
}

void Cristofy::eliminarMultimediaEnSistema(Multimedia *multi){
	
	//busco el multimedia en el sistema para borrarlo
	int numMultimedia = 0;
	

		for(int i=0;i<this->getContenidosTotales() ;i++){
			if (multi->getId() == this->listaContenidoMultimedia[i]->getId() ){
				
				//delete this->listaContenidoMultimedia[i]; no se puede eliminar asi, pq solo tiene variables estaticas
				//asi que lo pongo a 0
				this->listaContenidoMultimedia[i] = 0;
				numMultimedia = i;

				
			}
				
		}

		//A partir del multimedia eliminado, cambio la posicion a una menos
			for(int j=numMultimedia;j<getContenidosTotales();j++){
				this->listaContenidoMultimedia[j] = this->listaContenidoMultimedia[j+1];
			}

		//y ahora actualizo las utiles
		this->setContenidosTotales(this->getContenidosTotales() -1);

		cout << GREEN_COLOR << "\n\tMultimedia Eliminado del sistema correctamente" << RESTORE_DEFAULT_COLOR << endl;
	
}

void Cristofy::informeTop3Musica(){

	int max1 = 0; //meteré el numero del multimedia
	int max2 = 0;
	int max3 = 0;
	
	float aux = 0.0;

	int count = 0; //me va a servir para contar los multimedias musica

	int estrella = 0;
	int catalanufo = 0;
	int numUsuariosHanValorado = 0;

	cout << BLUE_COLOR << "\n\tContenidos Musicales Mejor Valorados: " << RESTORE_DEFAULT_COLOR << endl;

	//este primer for solo me cuenta cuantos hay y lo mete en count
	for(int i=0;i<this->getContenidosTotales();i++){
		if( this->listaContenidoMultimedia[i] == dynamic_cast<Musica*>(this->listaContenidoMultimedia[i]) ){
			count++;
		}
	}	



	if(count>0){

		cout << GREEN_COLOR << "\n\t\t1er Clasificado: " << RESTORE_DEFAULT_COLOR << endl;

		for(int i=0;i<this->getContenidosTotales();i++){
			 if( (this->listaContenidoMultimedia[i] == dynamic_cast<Musica*>(this->listaContenidoMultimedia[i]) ) && this->listaContenidoMultimedia[i]->getValoracionMediaActual() >= aux){
			 	aux = this->listaContenidoMultimedia[i]->getValoracionMediaActual();
			 	max1 = i;
			 }
		}

		cout << "\t\t\t" << this->listaContenidoMultimedia[max1]->getTitulo() << "\n\t\t\tMedia: " << this->listaContenidoMultimedia[max1]->getValoracionMediaActual() << endl;

		aux = 0.0;
		
	}

	if(count>1){

		cout << GREEN_COLOR << "\n\t\t2º Clasificado: " << RESTORE_DEFAULT_COLOR << endl;

		for(int j=0;j<this->getContenidosTotales();j++){
			 if( (this->listaContenidoMultimedia[j] == dynamic_cast<Musica*>(this->listaContenidoMultimedia[j]) ) &&  this->listaContenidoMultimedia[j]->getValoracionMediaActual() >= aux && max1 != j){
			 	aux = this->listaContenidoMultimedia[j]->getValoracionMediaActual();
			 	max2 = j;
			 }
		}

		cout << "\t\t\t" << this->listaContenidoMultimedia[max2]->getTitulo() << "\n\t\t\tMedia: " << this->listaContenidoMultimedia[max2]->getValoracionMediaActual() << endl;

		aux = 0.0;
	
	}

	if(count>2){


		cout << GREEN_COLOR << "\n\t\t3er Clasificado: " << RESTORE_DEFAULT_COLOR << endl;

		for(int k=0;k<this->getContenidosTotales();k++){
			 if( (this->listaContenidoMultimedia[k] == dynamic_cast<Musica*>(this->listaContenidoMultimedia[k]) ) &&  this->listaContenidoMultimedia[k]->getValoracionMediaActual() >= aux && max1 != k && max2 !=k){
			 	aux = this->listaContenidoMultimedia[k]->getValoracionMediaActual();
			 	max3 = k;
			 }
		}

		cout << "\t\t\t" << this->listaContenidoMultimedia[max3]->getTitulo() << "\n\t\t\tMedia: " << this->listaContenidoMultimedia[max3]->getValoracionMediaActual() << endl;

		aux = 0.0;

	}


	//ahora el ranking Contenido Estrella

		cout << BLUE_COLOR << "\n\n\tContenido Estrella: " << RESTORE_DEFAULT_COLOR << endl;


		for(int i=0;i<this->getContenidosTotales();i++){
			if( this->listaContenidoMultimedia[i] == dynamic_cast<Musica*>(this->listaContenidoMultimedia[i] ) ){
				 if( this->listaContenidoMultimedia[i]->getValoracionMediaActual() >= aux && this->listaContenidoMultimedia[i]->getTotalUsuariosQueHanValorado() >= numUsuariosHanValorado ){
				 	aux = this->listaContenidoMultimedia[i]->getValoracionMediaActual();
				 	estrella = i;
				 	numUsuariosHanValorado = this->listaContenidoMultimedia[i]->getTotalUsuariosQueHanValorado();
				 }
			}
		}

		cout << "\t\t" << this->listaContenidoMultimedia[estrella]->getTitulo() << "\n\t\tMedia: " << this->listaContenidoMultimedia[estrella]->getValoracionMediaActual() << "\n\t\tUsuarios que han Valorado: " << this->listaContenidoMultimedia[estrella]->getTotalUsuariosQueHanValorado() << endl;

		aux = 0.0;



		//ahora el contenido Catalanufo

		cout << BLUE_COLOR << "\n\n\tContenido Catalanufo: " << RESTORE_DEFAULT_COLOR << endl;

		aux = 10.1;

		for(int i=0;i<this->getContenidosTotales();i++){
			if( this->listaContenidoMultimedia[i] == dynamic_cast<Musica*>(this->listaContenidoMultimedia[i] ) ){
				 if( this->listaContenidoMultimedia[i]->getValoracionMediaActual() <= aux && this->listaContenidoMultimedia[i]->getTotalUsuariosQueHanValorado() <= numUsuariosHanValorado ){
				 	aux = this->listaContenidoMultimedia[i]->getValoracionMediaActual();
				 	catalanufo = i;
				 	numUsuariosHanValorado = this->listaContenidoMultimedia[i]->getTotalUsuariosQueHanValorado();
				 }
			}
		}

		cout << "\t\t" << this->listaContenidoMultimedia[catalanufo]->getTitulo() << "\n\t\tMedia: " << this->listaContenidoMultimedia[catalanufo]->getValoracionMediaActual() << "\n\t\tUsuarios que han Valorado: " << this->listaContenidoMultimedia[catalanufo]->getTotalUsuariosQueHanValorado() << endl << endl;

		


}
        
void Cristofy::informeTop3Videos(){

	int max1 = 0; //meteré el numero del multimedia
	int max2 = 0;
	int max3 = 0;
	
	float aux = 0.0;

	int count = 0;

	int estrella = 0;
	int catalanufo = 0;
	int numUsuariosHanValorado = 0;

	cout << BLUE_COLOR << "\n\tContenidos de Video Mejor Valorados: " << RESTORE_DEFAULT_COLOR << endl;


	//este primer for solo me cuenta cuantos hay y lo mete en count
	for(int i=0;i<this->getContenidosTotales();i++){
		if( this->listaContenidoMultimedia[i] == dynamic_cast<Video*>(this->listaContenidoMultimedia[i]) ){
			count++;
		}
	}	


	if(count>0){

		cout << GREEN_COLOR << "\n\t\t1er Clasificado: " << RESTORE_DEFAULT_COLOR << endl;

		for(int i=0;i<this->getContenidosTotales();i++){
			 if( (this->listaContenidoMultimedia[i] == dynamic_cast<Video*>(this->listaContenidoMultimedia[i]) ) && this->listaContenidoMultimedia[i]->getValoracionMediaActual() >= aux){
			 	aux = this->listaContenidoMultimedia[i]->getValoracionMediaActual();
			 	max1 = i;
			 }
		}

		cout << "\t\t\t" << this->listaContenidoMultimedia[max1]->getTitulo() << "\n\t\t\tMedia: " << this->listaContenidoMultimedia[max1]->getValoracionMediaActual() << endl;

		aux = 0.0;
		
	}

	if(count>1){


		cout << GREEN_COLOR << "\n\t\t2º Clasificado: " << RESTORE_DEFAULT_COLOR << endl;

		for(int j=0;j<this->getContenidosTotales();j++){
			 if( (this->listaContenidoMultimedia[j] == dynamic_cast<Video*>(this->listaContenidoMultimedia[j]) ) &&  this->listaContenidoMultimedia[j]->getValoracionMediaActual() >= aux && max1 != j){
			 	aux = this->listaContenidoMultimedia[j]->getValoracionMediaActual();
			 	max2 = j;
			 }
		}

		cout << "\t\t\t" << this->listaContenidoMultimedia[max2]->getTitulo() << "\n\t\t\tMedia: " << this->listaContenidoMultimedia[max2]->getValoracionMediaActual() << endl;

		aux = 0.0;
	
	}

	if(count>2){


		cout << GREEN_COLOR << "\n\t\t3er Clasificado: " << RESTORE_DEFAULT_COLOR << endl;

		for(int k=0;k<this->getContenidosTotales();k++){
			 if( (this->listaContenidoMultimedia[k] == dynamic_cast<Video*>(this->listaContenidoMultimedia[k]) ) &&  this->listaContenidoMultimedia[k]->getValoracionMediaActual() >= aux && max1 != k && max2 !=k){
			 	aux = this->listaContenidoMultimedia[k]->getValoracionMediaActual();
			 	max3 = k;
			 }
		}

		cout << "\t\t\t" << this->listaContenidoMultimedia[max3]->getTitulo() << "\n\t\t\tMedia: " << this->listaContenidoMultimedia[max3]->getValoracionMediaActual() << endl;

		aux = 0.0;

	}


	//ahora el ranking Contenido Estrella

		cout << BLUE_COLOR << "\n\n\tContenido Estrella: " << RESTORE_DEFAULT_COLOR << endl;


		for(int i=0;i<this->getContenidosTotales();i++){
			if( this->listaContenidoMultimedia[i] == dynamic_cast<Video*>(this->listaContenidoMultimedia[i] ) ){
				 if( this->listaContenidoMultimedia[i]->getValoracionMediaActual() >= aux && this->listaContenidoMultimedia[i]->getTotalUsuariosQueHanValorado() >= numUsuariosHanValorado ){
				 	aux = this->listaContenidoMultimedia[i]->getValoracionMediaActual();
				 	estrella = i;
				 	numUsuariosHanValorado = this->listaContenidoMultimedia[i]->getTotalUsuariosQueHanValorado();
				 }
			}
		}

		cout << "\t\t" << this->listaContenidoMultimedia[estrella]->getTitulo() << "\n\t\tMedia: " << this->listaContenidoMultimedia[estrella]->getValoracionMediaActual() << "\n\t\tUsuarios que han Valorado: " << this->listaContenidoMultimedia[estrella]->getTotalUsuariosQueHanValorado() << endl;

		aux = 0.0;



		//ahora el contenido Catalanufo

		cout << BLUE_COLOR << "\n\n\tContenido Catalanufo: " << RESTORE_DEFAULT_COLOR << endl;

		aux = 10.1;

		for(int i=0;i<this->getContenidosTotales();i++){
			if( this->listaContenidoMultimedia[i] == dynamic_cast<Video*>(this->listaContenidoMultimedia[i] ) ){
				 if( this->listaContenidoMultimedia[i]->getValoracionMediaActual() <= aux && this->listaContenidoMultimedia[i]->getTotalUsuariosQueHanValorado() <= numUsuariosHanValorado ){
				 	aux = this->listaContenidoMultimedia[i]->getValoracionMediaActual();
				 	catalanufo = i;
				 	numUsuariosHanValorado = this->listaContenidoMultimedia[i]->getTotalUsuariosQueHanValorado();
				 }
			}
		}

		cout << "\t\t" << this->listaContenidoMultimedia[catalanufo]->getTitulo() << "\n\t\tMedia: " << this->listaContenidoMultimedia[catalanufo]->getValoracionMediaActual() << "\n\t\tUsuarios que han Valorado: " << this->listaContenidoMultimedia[catalanufo]->getTotalUsuariosQueHanValorado() << endl << endl;


}

        
void Cristofy::informeTop3Imagen(){

	int max1 = 0; //meteré el numero del multimedia
	int max2 = 0;
	int max3 = 0;
	
	float aux = 0.0;

	int count = 0;

	int estrella = 0;
	int catalanufo = 0;
	int numUsuariosHanValorado = 0;

	cout << BLUE_COLOR << "\n\tContenidos de Imagen Mejor Valorados: " << RESTORE_DEFAULT_COLOR << endl;


	//este primer for solo me cuenta cuantos hay y lo mete en count
	for(int i=0;i<this->getContenidosTotales();i++){
		if( this->listaContenidoMultimedia[i] == dynamic_cast<Imagen*>(this->listaContenidoMultimedia[i]) ){
			count++;
		}
	}	



	if(count>0){

		cout << GREEN_COLOR << "\n\t\t1er Clasificado: " << RESTORE_DEFAULT_COLOR << endl;

		for(int i=0;i<this->getContenidosTotales();i++){
			 if( (this->listaContenidoMultimedia[i] == dynamic_cast<Imagen*>(this->listaContenidoMultimedia[i]) ) && this->listaContenidoMultimedia[i]->getValoracionMediaActual() >= aux){
			 	aux = this->listaContenidoMultimedia[i]->getValoracionMediaActual();
			 	max1 = i;
			 }
		}

		cout << "\t\t\t" << this->listaContenidoMultimedia[max1]->getTitulo() << "\n\t\t\tMedia: " << this->listaContenidoMultimedia[max1]->getValoracionMediaActual() << endl;

		aux = 0.0;
		
	}

	if(count>1){


		cout << GREEN_COLOR << "\n\t\t2º Clasificado: " << RESTORE_DEFAULT_COLOR << endl;

		for(int j=0;j<this->getContenidosTotales();j++){
			 if( (this->listaContenidoMultimedia[j] == dynamic_cast<Imagen*>(this->listaContenidoMultimedia[j]) ) &&  this->listaContenidoMultimedia[j]->getValoracionMediaActual() >= aux && max1 != j){
			 	aux = this->listaContenidoMultimedia[j]->getValoracionMediaActual();
			 	max2 = j;
			 }
		}

		cout << "\t\t\t" << this->listaContenidoMultimedia[max2]->getTitulo() << "\n\t\t\tMedia: " << this->listaContenidoMultimedia[max2]->getValoracionMediaActual() << endl;

		aux = 0.0;
	
	}


	if(count>2){

		cout << GREEN_COLOR << "\n\t\t3er Clasificado: " << RESTORE_DEFAULT_COLOR << endl;

		for(int k=0;k<this->getContenidosTotales();k++){
			 if( (this->listaContenidoMultimedia[k] == dynamic_cast<Imagen*>(this->listaContenidoMultimedia[k]) ) &&  this->listaContenidoMultimedia[k]->getValoracionMediaActual() >= aux && max1 != k && max2 !=k){
			 	aux = this->listaContenidoMultimedia[k]->getValoracionMediaActual();
			 	max3 = k;
			 }
		}

		cout << "\t\t\t" << this->listaContenidoMultimedia[max3]->getTitulo() << "\n\t\t\tMedia: " << this->listaContenidoMultimedia[max3]->getValoracionMediaActual() << endl;

		aux = 0.0;
	}


	//ahora el ranking Contenido Estrella

		cout << BLUE_COLOR << "\n\n\tContenido Estrella: " << RESTORE_DEFAULT_COLOR << endl;


		for(int i=0;i<this->getContenidosTotales();i++){
			if( this->listaContenidoMultimedia[i] == dynamic_cast<Imagen*>(this->listaContenidoMultimedia[i] ) ){
				 if( this->listaContenidoMultimedia[i]->getValoracionMediaActual() >= aux && this->listaContenidoMultimedia[i]->getTotalUsuariosQueHanValorado() >= numUsuariosHanValorado ){
				 	aux = this->listaContenidoMultimedia[i]->getValoracionMediaActual();
				 	estrella = i;
				 	numUsuariosHanValorado = this->listaContenidoMultimedia[i]->getTotalUsuariosQueHanValorado();
				 }
			}
		}

		cout << "\t\t" << this->listaContenidoMultimedia[estrella]->getTitulo() << "\n\t\tMedia: " << this->listaContenidoMultimedia[estrella]->getValoracionMediaActual() << "\n\t\tUsuarios que han Valorado: " << this->listaContenidoMultimedia[estrella]->getTotalUsuariosQueHanValorado() << endl;

		aux = 0.0;



		//ahora el contenido Catalanufo

		cout << BLUE_COLOR << "\n\n\tContenido Catalanufo: " << RESTORE_DEFAULT_COLOR << endl;

		aux = 10.1;

		for(int i=0;i<this->getContenidosTotales();i++){
			if( this->listaContenidoMultimedia[i] == dynamic_cast<Imagen*>(this->listaContenidoMultimedia[i] ) ){
				 if( this->listaContenidoMultimedia[i]->getValoracionMediaActual() <= aux && this->listaContenidoMultimedia[i]->getTotalUsuariosQueHanValorado() <= numUsuariosHanValorado ){
				 	aux = this->listaContenidoMultimedia[i]->getValoracionMediaActual();
				 	catalanufo = i;
				 	numUsuariosHanValorado = this->listaContenidoMultimedia[i]->getTotalUsuariosQueHanValorado();
				 }
			}
		}

		cout << "\t\t" << this->listaContenidoMultimedia[catalanufo]->getTitulo() << "\n\t\tMedia: " << this->listaContenidoMultimedia[catalanufo]->getValoracionMediaActual() << "\n\t\tUsuarios que han Valorado: " << this->listaContenidoMultimedia[catalanufo]->getTotalUsuariosQueHanValorado() << endl << endl;


}

     
void Cristofy::informeTop3General(){

	int max1 = 0; //meteré el numero del multimedia
	int max2 = 0;
	int max3 = 0;
	
	float aux = 0.0;

	int estrella = 0;
	int numUsuariosHanValorado = 0;

	int catalanufo = 0;



		cout << BLUE_COLOR << "\n\tContenidos Mejor Valorados: " << RESTORE_DEFAULT_COLOR << endl;


		cout << GREEN_COLOR << "\n\t\t1er Clasificado: " << RESTORE_DEFAULT_COLOR << endl;

		for(int i=0;i<this->getContenidosTotales();i++){
			 if( this->listaContenidoMultimedia[i]->getValoracionMediaActual() >= aux){
			 	aux = this->listaContenidoMultimedia[i]->getValoracionMediaActual();
			 	max1 = i;
			 }
		}

		cout << "\t\t\t" << this->listaContenidoMultimedia[max1]->getTitulo() << "\n\t\t\tMedia: " << this->listaContenidoMultimedia[max1]->getValoracionMediaActual() << endl;

		aux = 0.0;
		



		cout << GREEN_COLOR << "\n\t\t2º Clasificado: " << RESTORE_DEFAULT_COLOR << endl;

		for(int j=0;j<this->getContenidosTotales();j++){
			 if( this->listaContenidoMultimedia[j]->getValoracionMediaActual() >= aux && max1 != j){
			 	aux = this->listaContenidoMultimedia[j]->getValoracionMediaActual();
			 	max2 = j;
			 }
		}

		cout << "\t\t\t" << this->listaContenidoMultimedia[max2]->getTitulo() << "\n\t\t\tMedia: " << this->listaContenidoMultimedia[max2]->getValoracionMediaActual() << endl;

		aux = 0.0;
	



		cout << GREEN_COLOR << "\n\t\t3er Clasificado: " << RESTORE_DEFAULT_COLOR << endl;

		for(int k=0;k<this->getContenidosTotales();k++){
			 if( this->listaContenidoMultimedia[k]->getValoracionMediaActual() >= aux && max1 != k && max2 !=k){
			 	aux = this->listaContenidoMultimedia[k]->getValoracionMediaActual();
			 	max3 = k;
			 }
		}

		cout << "\t\t\t" << this->listaContenidoMultimedia[max3]->getTitulo() << "\n\t\t\tMedia: " << this->listaContenidoMultimedia[max3]->getValoracionMediaActual() << endl;

		aux = 0.0;
		

		//ahora el ranking Contenido Estrella

		cout << BLUE_COLOR << "\n\n\tContenido Estrella: " << RESTORE_DEFAULT_COLOR << endl;


		for(int i=0;i<this->getContenidosTotales();i++){
			 if( this->listaContenidoMultimedia[i]->getValoracionMediaActual() >= aux && this->listaContenidoMultimedia[i]->getTotalUsuariosQueHanValorado() >= numUsuariosHanValorado ){
			 	aux = this->listaContenidoMultimedia[i]->getValoracionMediaActual();
			 	estrella = i;
			 	numUsuariosHanValorado = this->listaContenidoMultimedia[i]->getTotalUsuariosQueHanValorado();
			 }
		}

		cout << "\t\t" << this->listaContenidoMultimedia[estrella]->getTitulo() << "\n\t\tMedia: " << this->listaContenidoMultimedia[estrella]->getValoracionMediaActual() << "\n\t\tUsuarios que han Valorado: " << this->listaContenidoMultimedia[estrella]->getTotalUsuariosQueHanValorado() << endl;

		aux = 0.0;



		//ahora el contenido Catalanufo

		cout << BLUE_COLOR << "\n\n\tContenido Catalanufo: " << RESTORE_DEFAULT_COLOR << endl;

		aux = 10.1;

		for(int i=0;i<this->getContenidosTotales();i++){
			 if( this->listaContenidoMultimedia[i]->getValoracionMediaActual() <= aux && this->listaContenidoMultimedia[i]->getTotalUsuariosQueHanValorado() <= numUsuariosHanValorado ){
			 	aux = this->listaContenidoMultimedia[i]->getValoracionMediaActual();
			 	catalanufo = i;
			 	numUsuariosHanValorado = this->listaContenidoMultimedia[i]->getTotalUsuariosQueHanValorado();
			 }
		}

		cout << "\t\t" << this->listaContenidoMultimedia[catalanufo]->getTitulo() << "\n\t\tMedia: " << this->listaContenidoMultimedia[catalanufo]->getValoracionMediaActual() << "\n\t\tUsuarios que han Valorado: " << this->listaContenidoMultimedia[catalanufo]->getTotalUsuariosQueHanValorado() << endl << endl;

		





}
     
void Cristofy::UsuarioFreak(){
	
	int max = 0;
	int user = 0;
	float med = 0.0;

	cout << BLUE_COLOR << "\n\tUsuario Freak: " << RESTORE_DEFAULT_COLOR << endl;

	for(int i=0;i<this->getUsuariosTotales();i++){
		if(this->listaUsuarios[i]->getUtilesCV() >= max ){
			max = this->listaUsuarios[i]->getUtilesCV();
			user = i;
		}
	}

	cout << "\t\t" << this->listaUsuarios[user]->getNombre() << " " << this->listaUsuarios[user]->getApellido1() << "\n\t\tContenidos asociados y valorados: " << this->listaUsuarios[user]->getUtilesCV() << endl;


	max = 0;
	user = 0;


	cout << BLUE_COLOR << "\n\tUsuario Mr. Exigente: " << RESTORE_DEFAULT_COLOR << endl;

	for(int i=0;i<this->getUsuariosTotales();i++){
		if(this->listaUsuarios[i]->getUtilesCV() >= max ){
			max = this->listaUsuarios[i]->getUtilesCV();
			user = i;
		}
	}

	cout << "\t\t" << this->listaUsuarios[user]->getNombre()  << " " << this->listaUsuarios[user]->getApellido1()  << "\n\t\tContenidos asociados y valorados: " << this->listaUsuarios[user]->getUtilesCV() << endl;


	max = 0;
	user = 0;
	med = 0.0;



	cout << BLUE_COLOR << "\n\tUsuario Facilón: " << RESTORE_DEFAULT_COLOR << endl;

	for(int i=0;i<this->getUsuariosTotales();i++){
		if(this->listaUsuarios[i]->getUtilesCV() >= max ){
			max = this->listaUsuarios[i]->getUtilesCV();
			user = i;
		}
	}

	cout << "\t\t" << this->listaUsuarios[user]->getNombre()  << " " << this->listaUsuarios[user]->getApellido1()  << "\n\t\tContenidos asociados y valorados: " << this->listaUsuarios[user]->getUtilesCV() << endl << endl;


}