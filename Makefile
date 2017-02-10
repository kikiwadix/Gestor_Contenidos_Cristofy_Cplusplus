all: Cristofy

Cristofy: Main.cpp Cristofy.cpp Usuario.cpp Multimedia.cpp
	g++ Main.cpp Cristofy.cpp Usuario.cpp Multimedia.cpp -o Cristofy

borraYcrea:
	rm Cristofy
	g++ Main.cpp Cristofy.cpp Usuario.cpp Multimedia.cpp -o Cristofy
