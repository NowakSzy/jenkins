#include <stdio.h>
#include <stdlib.h>
#include "mongoose.h"
#include "logger.h"

int main(int argc, char *argv[]) {
    if (argc > 1) {
        dynamic_log_level = atoi(argv[1]);
        printf("--- ZMIANA DYNAMICZNA NA: %d ---\n", dynamic_log_level);
    }
    struct mg_mgr mgr;
    mg_mgr_init(&mgr);
    mg_mgr_free(&mgr);
    return 0;
}
