/*
Ejemplo de modulo de motor de juegos utilizando el modelo de singleton
*/
#include <iostream>

class RenderManager
{
private:
	//el constructor y destructor deben ser privados y no hacer nada
	RenderManager(){};
	~RenderManager(){};

	//Para evitar metodos que puedan copiar el singleton
	RenderManager(RenderManager const &copy);
	RenderManager & operator=(RenderManager const &copy);

public:
	static RenderManager * Instancia();  //get()
	int id;
	static void startUp();
	static void shutDown();
};