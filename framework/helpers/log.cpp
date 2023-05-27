#include "headers/log.h"
#include "headers/globalvariables.h"
#include <fstream>
#include <chrono>
#include <iomanip>

#define PROCESS_NAME "Log"

std::ofstream log_file;

void printHeader(){
    log_file << "*******************************************************" << std::endl;
    log_file << "*                                                     *" << std::endl;
    log_file << "*       Project Name: CPP-Framework                   *" << std::endl;
    log_file << "*       Created By: Sebastian Cantini Budden          *" << std::endl;
    log_file << "*                                                     *" << std::endl;
    log_file << "*******************************************************" << std::endl;
}

void log_init(std::string log_folder) {
    try{
        std::string log_path;

        if(config["log_constantfile"] == "YES") {
            log_path = log_folder + "/" + config["log_constantfile_name"];
        }
        else {
            // Get the current timestamp
            std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
            std::time_t timestamp = std::chrono::system_clock::to_time_t(now);

            // Create path with timestamp
            log_path = log_folder + "/log_" + std::ctime(&timestamp);
        }

        // Open file
        log_file.open(log_path + ".txt");
        if(!log_file.is_open() || log_file.bad()) {
            error = true;
            return;
        }

        // Print header
        printHeader();

        // Print starter log
        log(INFO, PROCESS_NAME, "Start of log");
        log(INFO, PROCESS_NAME, config["log_constantfile"]); 
    }
    catch (...) {
        error = true;
    }
}

// timestamp | log_type | process_name | message
void log(std::string log_type, std::string process_name, std::string message) {
    if(!log_file.is_open()) {
        return;
    }

    // Get the current system time
    auto currentTime = std::chrono::system_clock::now();

    // Convert the system time to a timestamp
    std::time_t timeStamp = std::chrono::system_clock::to_time_t(currentTime);

    log_file << "Timestamp: " << std::put_time(std::localtime(&timeStamp), "%H:%M:%S") << " | " << log_type << " | " << process_name << " | " << message << std::endl;
}

void log_end() {
    log(INFO, PROCESS_NAME, "End of log");
    if(log_file.is_open()) {
        log_file.close();
    }
}