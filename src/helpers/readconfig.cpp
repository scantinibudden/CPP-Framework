#include "headers/readconfig.h"
#include "headers/globalvariables.h"
#include "headers/log.h"
#include <fstream>

#define PROCESS_NAME "Read Config"

std::map<std::string, std::string> config;

void readConfig (std::string config_file_path) {
    try {
        // Start
        log(INFO, PROCESS_NAME, "Starting process");

        // Process
        // Opening file
        log(INFO, PROCESS_NAME, "Opening config file");
        std::ifstream config_file (config_file_path);

        // Check if the file was successfully opened
        log(INFO, PROCESS_NAME, "Validating config file opened successfuly");
        if (!config_file.is_open()) {
            log(ERROR, PROCESS_NAME, "Error opening config file");
            error = true;
            return;
        }
        else if (config_file.bad()) {
            log(ERROR, PROCESS_NAME, "Badbit detected");
            error = true;
            return;
        }

        // Extracting config data
        log(INFO, PROCESS_NAME, "Reading config file...");
        while(!config_file.eof()){
            std::string csv_line;
            std::string config_key;
            std::string config_value;
            
            config_file >> csv_line;
            
            if(csv_line[0] == '-'){
                // Invalid key or config title
                continue;
            }
            if (config_file.fail()) {
                log(ERROR, PROCESS_NAME, "Failbit detected");
                error = true;
                return;
            }

            // Extract Key and Value from line
            std::string::size_type delimiter_position = csv_line.find(',');
            config_key = csv_line.substr(0, delimiter_position);
            config_value = csv_line.substr(delimiter_position+1, csv_line.length());
            config[config_key] = config_value;
        }
        log(INFO, PROCESS_NAME, "Reading config file... DONE");

        // Close the file
        log(INFO, PROCESS_NAME, "Closing config file");
        config_file.close();

        // End
        log(INFO, PROCESS_NAME, "Finished process");
    }
    catch (...) {
        log(ERROR, PROCESS_NAME, "An error ocurred in this process");
        error = true;
    }
}