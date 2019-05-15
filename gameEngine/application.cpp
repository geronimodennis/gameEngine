#include "application.h"
#include "EGanesis.h"

int main() {
	std::cout << "Welcom to engine Genesis (eGen)";
	EGanesis* engine = new EGanesis();
	engine->gameLoop();

	return 0;
}