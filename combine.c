#include <stdio.h>
#include <stdlib.h>
#include "mongoose.h" // Pobierane automatycznie z drugiego Gita
#include "logger.h"

int main(int argc, char *argv[]) {
    struct mg_mgr mgr;

    // Obsługa wariantu dynamicznego przez argument linii poleceń
    if (argc > 1) {
        dynamic_log_level = atoi(argv[1]);
        printf("[SYSTEM] Zmiana DYNAMICZNA poziomu logow na: %d\n", dynamic_log_level);
    }

    LOG_INFO("MONGOOSE_SERVER", 101, "Uruchamianie serwera Mongoose...", "");
    mg_mgr_init(&mgr);

    // Symulacja zdarzeń sieciowych
    LOG_WARN("MONGOOSE_SERVER", 102, "Ostrzezenie: Wykryto wolne polaczenie", "Klient_ID=45");
    LOG_ERR("MONGOOSE_SERVER", 103, "Blad krytyczny odczytu z gniazda!", "Socket_Error_Code=104");

    mg_mgr_free(&mgr);
    LOG_INFO("MONGOOSE_SERVER", 104, "Menedzer sieciowy zostal zamkniety.", "");

    return 0;
}
