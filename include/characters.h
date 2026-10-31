#ifndef CHARACTERS_H
#define CHARACTERS_H

// Štruktúra pre pretekárov Tesco Kart
struct TescoPretekar {
    const char* meno;
    int rychlost;      // 1-10
    int zrychlenie;    // 1-10
    int ovladatelnost; // 1-10
    int vaha;          // 1-10
};

// Súpiska maskotov a Fera Jokea
static const TescoPretekar Zostava[] = {
    {"Henio",       7, 4, 5, 8},
    {"Krysia",      5, 8, 9, 3},
    {"Tadeusz",     6, 6, 7, 5},
    {"Bogusz",      8, 5, 4, 6},
    {"Pan Letak",   4, 9, 9, 2}, // Extrémne ľahký papierový leták
    {"Fero Joke",   6, 7, 6, 5}  // Vybalansovaná Maja na nákupoch
};

#endif
