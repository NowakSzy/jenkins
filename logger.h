#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <time.h>

#define LOG_LEVEL_INFO    1
#define LOG_LEVEL_WARN    2
#define LOG_LEVEL_ERROR   3
#define LOG_LEVEL_NONE    4

extern int dynamic_log_level;

#ifndef STATIC_LOG_LEVEL
#define STATIC_LOG_LEVEL LOG_LEVEL_INFO 
#endif

void print_timestamp(void);

#define LOG_PRINT(level_num, level_str, module, loc, desc, ...) \
    do { \
        if (STATIC_LOG_LEVEL <= (level_num) && dynamic_log_level <= (level_num)) { \
            print_timestamp(); \
            printf("[%s] [%s:%d] Plik: %s:%d | %s", level_str, module, loc, __FILE__, __LINE__, desc); \
            printf(" " __VA_ARGS__); \
            printf("\n"); \
        } \
    } while(0)

#define LOG_INFO(module, loc, desc, ...)  LOG_PRINT(LOG_LEVEL_INFO,  "INFO ", module, loc, desc, ##__VA_ARGS__)
#define LOG_WARN(module, loc, desc, ...)  LOG_PRINT(LOG_LEVEL_WARN,  "WARN ", module, loc, desc, ##__VA_ARGS__)
#define LOG_ERR(module, loc, desc, ...)   LOG_PRINT(LOG_LEVEL_ERROR, "ERROR", module, loc, desc, ##__VA_ARGS__)

#endif
