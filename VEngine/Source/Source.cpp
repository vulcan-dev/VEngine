#include "Application/Application.h"

int main(int argc, char* argv[]) {
	Application App;
	App.Initialize();

	App.Update();

	return EXIT_SUCCESS;
}