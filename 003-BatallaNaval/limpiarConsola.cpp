#include <cstdlib>

void limpiarConsola() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}