


#include <iostream>
#include <string>
#include <stdlib.h>
#include "Multimedia.h"
#include "Usuario.h"
#include "Cristofy.h"

#define RED_COLOR "\033[1;31m"
#define GREEN_COLOR "\033[1;32m"
#define BLUE_COLOR "\033[1;34m"
#define RESTORE_DEFAULT_COLOR "\033[0m"


using namespace std;


int main(){

	

	bool permanecer = true;

	//Creo el objeto Cristofy
	Cristofy *C = new Cristofy();

	//CREO CUATRO USUARIOS PREDEFINIDOS (UNO DE ELLOS ADMIN) Y LOS AÑADO AL SISTEMA
	Usuario *u1 = new Usuario ("Admin", "Admin", "Administrador", "Del", "Sistema", 33, 0);
	Usuario *u2 = new Usuario ("cholo", "daniestafeliz", "Cholo", "Simeone", "Crack", 50, 0);
	Usuario *u3 = new Usuario ("zizou", "thebest", "Zinedine", "Zidane", "God", 45, 0);
	Usuario *u4 = new Usuario ("pep", "soyunperdedor", "Josep", "Guardiola", "Perdedor", 47, 0);

    C->anadirUsuarioASistema(u1);
    C->anadirUsuarioASistema(u2);
    C->anadirUsuarioASistema(u3);
    C->anadirUsuarioASistema(u4);


	//CREO 5 OBJETOS MULTIMEDIA DIVERSOS Y LOS AÑADO AL SISTEMA DIRECTAMENTE


    C->anadirMultimediaASistema(new Musica("MUSICA-1", "El Sueño de Nono", "Nono Music S.L.", 2013, "/home/kiki/Escritorio/Cristofy/Media/Audio/cancion.mp3", "MP3", "/usr/bin/vlc", 3, "Nona La Loca", "Regueton"));
    C->anadirMultimediaASistema(new Video("VIDEO-2", "The Nono Moonwalker", "Nono Video S.L.", 2016, "/home/kiki/Escritorio/Cristofy/Media/Video/video.mp4", "MP4", "/usr/bin/vlc", 6, "VideoClip", "Nono Iglesias"));
    C->anadirMultimediaASistema(new Imagen("IMAGEN-3", "Tarek in the Country", "Tarek de Castilla Company S.L.", 2015, "/home/kiki/Escritorio/Cristofy/Media/Imagen/foto.JPG", "JPEG", "/usr/bin/gimp-2.8", "1024X768"));
    C->anadirMultimediaASistema(new Video("VIDEO-4", "Star Lolo: The Vegetables Return", "Green Onion S.L.", 2016, "/home/kiki/Escritorio/Cristofy/Media/Video/video.mp4", "AVI", "/usr/bin/vlc", 6, "Película Acción", "J.J. Abrams"));
	C->anadirMultimediaASistema(new Musica("MUSICA-5", "Angel Love Song", "Angel Music S.L.", 1975, "/home/kiki/Escritorio/Cristofy/Media/Audio/cancion.mp3", "WAV", "/usr/bin/vlc", 4, "Angel Prestley", "Rock"));


	system("clear");

    //Mensaje de Bienvenida
	C->bienvenida();

	//Entrada al Menu
	C->preMenu();

	//Mensaje de Despedida

	C->despedida();
	

	delete C;
}
