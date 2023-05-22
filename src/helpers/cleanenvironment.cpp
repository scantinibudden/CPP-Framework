#include "headers/cleanenvironment.h"
#include "headers/globalvariables.h"
#include "../helpers/headers/log.h"
#include <filesystem>

#define PROCESS_NAME "Clean Environment"

void cleanEnvironment (){
    try {
        // Start
        log(INFO, PROCESS_NAME, "Starting process");

        // Process
        for (const auto& entry : std::filesystem::directory_iterator(config["path_tmp"])) {
            std::filesystem::remove_all(entry.path());
        }
        // End
        log(INFO, PROCESS_NAME, "Finished process");
    }
    catch (...) {
        log(ERROR, PROCESS_NAME, "An error ocurred in this process");
        error = true;
    }
}