#include <iostream>
#include "Engine/Utilities.h"

int main(int argc, char* argv[]) {
	/* All test code */

	VEngine::Utilities::Log._logger->info("Main function called");

	if (VEngine::Utilities::GetLaunchOption(argc, argv, "-fullscreen")) {
		VEngine::Utilities::Log._logger->info("Launching with fullscreen");
	}

	std::cin.get(); // Pause the console (that's all it is as of right now)
	return EXIT_SUCCESS;
}