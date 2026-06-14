#include "logger.h"

int dynamic_log_level = LOG_LEVEL_INFO;

void print_timestamp(void) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char buffer[26];
    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    printf("[%s] ", buffer);
}
