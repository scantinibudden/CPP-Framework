#ifndef LOG_HH
#define LOG_HH

#include <string>

//log_types
#define INFO "INFO"
#define WARN "WARN"
#define ERROR "ERROR"

void log_init(std::string log_folder);
void log(std::string process_name, std::string log_type, std::string message);
void log_end();

#endif