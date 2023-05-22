#include "headers/subprocesstemplate2.h"
#include "../helpers/headers/globalvariables.h"
#include "../helpers/headers/log.h"

void subprocess2 () {
    std::string process_name = "Subprocess2";
    try {
        // Start
        log(INFO, process_name, "Starting process");

        // Process

        // End
        log(INFO, process_name, "Finished process");
    }
    catch (...) {
        log(ERROR, process_name, "An error ocurred in this process");
        error = true;
    }
}

void subprocess3 () {
    std::string process_name = "Subprocess3";
    try {
        // Start
        log(INFO, process_name, "Starting process");

        // Process

        // End
        log(INFO, process_name, "Finished process");
    }
    catch (...) {
        log(ERROR, process_name, "An error ocurred in this process");
        error = true;
    }
}