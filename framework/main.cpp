#include "helpers/headers/readconfig.h"
#include "helpers/headers/log.h"
#include "helpers/headers/cleanenvironment.h"
#include "helpers/headers/globalvariables.h"
#include "../src/headers/process.h"

#define PATH_CONFIG "config/config.csv"
#define PATH_LOGS "logs"

bool error = false;

void init() {
    try{
        std::string process_name = "Init";
        std::string subprocess_name;

        //Init Logs
        log_init(PATH_LOGS);
        if(error)
            return;
        
        //Read Config
        subprocess_name = "Read Config";
        log(INFO, process_name, "Executing Read Config");
        readConfig(PATH_CONFIG);
        if(error) {
            log(ERROR, process_name, subprocess_name + " couldn't finish successfully");
            return;
        }
        else {
            log(INFO, process_name, subprocess_name + " finished successfully");
        }
        
        //Clean Environment
        subprocess_name = "Clean Environment";
        log(INFO, process_name, "Verifying if " + subprocess_name + " is configured to execute = " + config["execute_cleanenvironment_init"]);
        if(config["execute_cleanenvironment_init"] == "YES") {
            cleanEnvironment();
            if(error) {
                log(ERROR, process_name, subprocess_name + " couldn't finish properly");
            }
        }
        else {
            log(WARN, process_name, subprocess_name + " is not configured for execution");
        }
    }
    catch(...) {
        error = true;
    }
}

void end() {
    std::string process_name = "End";
    std::string subprocess_name;

    //Clean Environment
    error = false;
    subprocess_name = "Clean Environment";
    log(INFO, process_name, "Verifying if " + subprocess_name + " is configured to execute = " + config["execute_cleanenvironment_end"]);
    if(config["execute_cleanenvironment_end"] == "YES") {
        log(INFO, process_name, subprocess_name + " is configured for execution");
        cleanEnvironment();
        if(error) {
            log(ERROR, process_name, subprocess_name + " couldn't finish successfully");
        }
        else {
            log(INFO, process_name, subprocess_name + " finished successfully");
        }
    }
    else {
        log(WARN, process_name, subprocess_name + " is not configured for execution");
    }

    log_end();
}

int main(int argc, char** argv) {
    init();
    if(!error)
        process(argc, argv);
    end();
}