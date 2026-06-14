#include <stdio.h>

void bubble_sort(signed char arr[], int n) {
    int i, j;
    signed char temp;
    
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void generuj_test(const char* nazwa_pliku, const char* opis, signed char wektor[], int rozmiar) {
    FILE *plik = fopen(nazwa_pliku, "w");
    if (plik == NULL) {
        printf("Blad otwarcia pliku %s\n", nazwa_pliku);
        return;
    }

    fprintf(plik, "--- OPIS TESTU ---\n%s\n\n", opis);

    fprintf(plik, "Wektor wejściowy (przed sortowaniem):\n");
    for(int i = 0; i < rozmiar; i++) {
        fprintf(plik, "%d ", wektor[i]);
    }
    fprintf(plik, "\n\n");

    bubble_sort(wektor, rozmiar);

    fprintf(plik, "Wektor wyjściowy (po sortowaniu):\n");
    for(int i = 0; i < rozmiar; i++) {
        fprintf(plik, "%d ", wektor[i]);
    }
    fprintf(plik, "\n");

    fclose(plik);
    printf("Wygenerowano plik: %s\n", nazwa_pliku);
}

int main(void) {
    signed char test1[] = { 42 };
    generuj_test("test1_jeden_element.txt", 
                 "Test graniczny rozmiaru: Tablica zawierajaca tylko jeden element. Sprawdza, czy petle algorytmu nie wyjda poza zakres pamieci i nie spowoduja bledu (np. segmentation fault) przy najmniejszym mozliwym do wejscia w petle zestawie danych.", 
                 test1, 1);

    signed char test2[] = { 127, -128, 0, -128, 127 };
    generuj_test("test2_ekstrema.txt", 
                 "Test wartosci granicznych: Tablica zawiera maksymalna (127) i minimalna (-128) mozliwa wartosc dla typu 'signed char' oraz zero. Sprawdza poprawnosc dzialania operatorow porownania na fizycznych granicach pojemnosci zmiennej (brak tzw. underflow/overflow).", 
                 test2, 5);

    signed char test3[] = { 127, 100, 50, 0, -50, -100, -128 };
    generuj_test("test3_odwrotna.txt", 
                 "Test najgorszego przypadku (Worst-case scenario): Tablica jest posortowana scisle malejaco. Jest to graniczny przypadek obciazeniowy dla sortowania babelkowego, wymuszajacy absolutnie maksymalna liczbe zamian (swapow) miejsc w pamieci.", 
                 test3, 7);

    signed char test4[] = { -5, -5, -5, -5, -5 };
    generuj_test("test4_identyczne.txt", 
                 "Test braku zmian / wartosci brzegowych logiki: Wszystkie elementy sa dokladnie takie same. Algorytm sprawdza tu swoja stabilnosc - powinien przeanalizowac tablice, ale nie wykonac ani jednej operacji zapisu/zamiany.", 
                 test4, 5);

    signed char test5[] = { -128, -10, 0, 15, 127 };
    generuj_test("test5_posortowana.txt", 
                 "Test najlepszego przypadku (Best-case scenario): Tablica jest juz poprawnie posortowana rosnaco przed uruchomieniem algorytmu. Sprawdza granice optymalizacji algorytmu (czy nie "psuje" prawidlowego szyku).", 
                 test5, 5);

    return 0;
}
