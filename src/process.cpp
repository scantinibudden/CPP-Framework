#include "../framework/framework.h"
#include "headers/process.h"
#include "headers/subprocesstemplate.h"
#include "headers/subprocesstemplate2.h"

#define PROCESS_NAME "Process"

void process() {
    try {
        std::string subprocess_name;
        // Start
        log(INFO, PROCESS_NAME, "Starting process");

        // Sub process
        subprocess_name = "Subprocess Template";
        log(INFO, PROCESS_NAME, "Verifying if " + subprocess_name + " is configured to execute = " + config["execute_subprocess"]);
        if(config["execute_subprocess"] == "YES") {
            log(INFO, PROCESS_NAME, subprocess_name + " is configured for execution");
            subprocess();
            if(error) {
                log(ERROR, PROCESS_NAME, subprocess_name + " couldn't finish properly");
                return;
            }
            else {
                log(INFO, PROCESS_NAME, subprocess_name + " finished successfully");
            }
        }
        else {
            log(WARN, PROCESS_NAME, subprocess_name + " is not configured for execution");
        }

        // Sub process 2
        subprocess_name = "Subprocess Template 2";
        log(INFO, PROCESS_NAME, "Verifying if " + subprocess_name + " is configured to execute = " + config["execute_subprocess2"]);
        if(config["execute_subprocess2"] == "YES") {
            log(INFO, PROCESS_NAME, subprocess_name + " is configured for execution");
            subprocess2();
            if(error) {
                log(ERROR, PROCESS_NAME, subprocess_name + " couldn't finish properly");
                return;
            }
            else {
                log(INFO, PROCESS_NAME, subprocess_name + " finished successfully");
            }
        }
        else {
            log(WARN, PROCESS_NAME, subprocess_name + " is not configured for execution");
        }

        // Sub process 3
        subprocess_name = "Subprocess Template 3";
        log(INFO, PROCESS_NAME, "Verifying if " + subprocess_name + " is configured to execute = " + config["execute_subprocess3"]);
        if(config["execute_subprocess3"] == "YES") {
            log(INFO, PROCESS_NAME, subprocess_name + " is configured for execution");
            subprocess3();
            if(error) {
                log(ERROR, PROCESS_NAME, subprocess_name + " couldn't finish properly");
                return;
            }
            else {
                log(INFO, PROCESS_NAME, subprocess_name + " finished successfully");
            }
        }
        else{
            log(WARN, PROCESS_NAME, subprocess_name + " is not configured for execution");
        }

        // End
        log(INFO, PROCESS_NAME, "Finished process");
    }
    catch (...) {
        log(ERROR, PROCESS_NAME, "An error ocurred in this process");
        error = true;
    }
}