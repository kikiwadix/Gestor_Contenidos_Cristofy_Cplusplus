

#ifndef MULTIMEDIA_H
#define	MULTIMEDIA_H


#include <iostream>
#include <string>
#include <stdlib.h>


using namespace std;

class Multimedia{
	protected:
        string id;
        string titulo;
        string compania;
        int anio;
        float puntuacionTotal;
        int totalUsuariosQueHanValorado;
        float valoracionMediaActual;
        string ruta;
        string formato;
        string rutaPrograma;
		
        
    public:
        //Constructores y destructor
    	Multimedia();
        Multimedia(string id, string titulo, string compania, int anio, string ruta, string formato, string rutaPrograma);
    	~Multimedia();
    	//Los SETS
        inline void setId(string nuevoId) { this->id = nuevoId; }
        inline void setTitulo(string nuevoTitulo) { this->titulo = nuevoTitulo; }
        inline void setCompania(string nuevaCompania) { this->compania = nuevaCompania; }
        inline void setAnio(int nuevoAnio) { this->anio = nuevoAnio; }
        inline void setPuntuacionTotal(float nuevaPuntuacionTotal) { this->puntuacionTotal = nuevaPuntuacionTotal; }
        inline void setTotalUsuariosQueHanValorado(int nuevoTotalUsuariosQueHanValorado) { this->totalUsuariosQueHanValorado = nuevoTotalUsuariosQueHanValorado; }
        inline void setValoracionMediaActual(float nuevaValoracionMediaActual) { this->valoracionMediaActual = nuevaValoracionMediaActual; }
        inline void setRuta(string nuevaRuta) { this->ruta = nuevaRuta; }
        inline void setFormato(string nuevoFormato) { this->formato = nuevoFormato; }
        //Los GETS
        inline string getId() const { return this->id; }
        inline string getTitulo() const { return this->titulo; }
        inline string getCompania() const { return this->compania; }
        inline int getAnio() const { return this->anio; }
        inline float getPuntuacionTotal() const { return this->puntuacionTotal; }
        inline int getTotalUsuariosQueHanValorado() const { return this->totalUsuariosQueHanValorado; }
        inline float getValoracionMediaActual() const { return this->valoracionMediaActual; }
        inline string getRuta() const { return this->ruta; }
        inline string getFormato() const { return this->formato; }
        //Resto de Modulos

        //@brief: Modulo que reproduce los contenidos multimedia, y al ser virtual, ejecuta el de cada tipo de multimedia
        //@param: string rutaArchivo
        virtual void reproducir(string rutaArchivo);
        //@brief: Modulo que permite modificar el contenido multimedia
        //@param: string titulo, string compania, int anio, string ruta, string formato
        void modificarMultimedia(string titulo, string compania, int anio, string ruta, string formato);
        //@brief: Modulo que permite, al estar virtualizado, que llame al metodo imprimir de cada subclase
        virtual void imprimirMultimedia();
	
};


class Musica : public Multimedia{
    private:
        int duracion;
        string autor;
        string estilo;
    public:
        Musica();
        Musica(string id, string titulo, string compania, int anio, string ruta, string formato, string rutaPrograma, int nuevaDuracion, string nuevoAutor, string nuevoEstilo);
        ~Musica();
        //los gets propios
        inline int getDuracion() const { return this->duracion; }
        inline string getAutor() const { return this->autor; }
        inline string getEstilo() const { return this->estilo; }
        //otros

        //@brief: Modulo que permite, al estar virtualizado, que se llame solo con los de tipo musica
        void imprimirMultimedia();
        //@brief: Modulo que reproduce los archivos de musica con su programa correspondiente
        //@param: string rutaArchivo
        void reproducir(string rutaArchivo);

};

class Video : public Multimedia{
    private:
        int duracion;
        string tematica;
        string autor;
    public:
        Video();
        Video(string id, string titulo, string compania, int anio, string ruta, string formato, string rutaPrograma, int nuevaDuracion, string nuevaTematica, string nuevoAutor);
        ~Video();
        //los gets propios
        inline int getDuracion() const { return this->duracion; }
        inline string getTematica() const { return this->tematica; }
        inline string getAutor() const { return this->autor; }
        //otros

        //@brief: Modulo que permite, al estar virtualizado, que se llame solo con los de tipo video
        void imprimirMultimedia();
        //@brief: Modulo que reproduce los archivos de video con su programa correspondiente
        //@param: string rutaArchivo
        void reproducir(string rutaArchivo);
};

class Imagen : public Multimedia{
    private:
        string resolucion;
    public:
        Imagen();
        Imagen(string id, string titulo, string compania, int anio, string ruta, string formato, string rutaPrograma, string nuevaResolucion);
        ~Imagen();
        //los gets propios
        inline string getResolucion() const { return this->resolucion; }
        //otros

        //@brief: Modulo que permite, al estar virtualizado, que se llame solo con los de tipo imagen
        void imprimirMultimedia();
        //@brief: Modulo que reproduce los archivos de imagen con su programa correspondiente
        //@param: string rutaArchivo
        void reproducir(string rutaArchivo);
};



#endif	/* MULTIMEDIA_H */
