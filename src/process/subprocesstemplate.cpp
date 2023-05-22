#include "headers/subprocesstemplate.h"
#include "../helpers/headers/globalvariables.h"
#include "../helpers/headers/log.h"

#define PROCESS_NAME "Subprocess Template"

void subprocess() {
    try {
        // Start
        log(INFO, PROCESS_NAME, "Starting process");

        // Process

        // End
        log(INFO, PROCESS_NAME, "Finished process");
    }
    catch (...) {
        log(ERROR, PROCESS_NAME, "An error ocurred in this process");
        error = true;
    }
}