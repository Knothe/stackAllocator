
#include "RenderManager.h"

void RenderManager::startUp()
{
	Instancia()->id = rand() * 100;
	std::cout << "Creando manejador de render. " << Instancia()->id << std::endl;
}

void RenderManager::shutDown()
{

}

RenderManager * RenderManager::Instancia()
{
	static RenderManager inst;
	return &inst;
}

