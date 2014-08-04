#include "RenderManager.h"
#include "StackAllocator.h"

#include <ctime>

int main(int argc, char** argv)
{
	clock_t t = clock();

	//asignar 32 MB de memoria dinamica
	StackAllocator *stackAllocator = new StackAllocator(1024 * 1024 * 512);
	clock_t dt = clock() - t;
	printf("Tomo %f segundos inicializar StackAllocator.\n", ((float)dt) / CLOCKS_PER_SEC);

	int n = 100000;
	//crear n strings con asignacion heap y medir tiempo
	t = clock();
	for (int i = 0; i < n; i++)
	{
		std::string *str = new std::string("hola mundo");
	}
	t = clock() - t;
	printf("Tomo %f segundos asignar con memoria dinamica.\n", ((float)t) / CLOCKS_PER_SEC);

	//crear n strings con asignacion stack y medir el tiempo
	t = clock();
	for (int i = 0; i < n; i++)
	{
		void *buf = stackAllocator->alloc(sizeof(std::string));
		std::string *str = new(buf) std::string("hola mundo");    // placement new
	}
	t = clock() - t;
	printf("Tomo %f segundos asignar con StackAllocator.\n", ((float)t) / CLOCKS_PER_SEC);

	getchar();
}

