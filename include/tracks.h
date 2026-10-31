#ifndef TRACKS_H
#define TRACKS_H

// Štruktúra pre pretekárske trate v TomkoWii
struct TomkoWiiTrat {
    const char* nazov;
    const char* lokalita;
    int obtiaznost;    // 1-5 hviezdičiek
    int pocet_kol;     // Štandardný počet kôl pre trať
    const char* popis;
};

// Databáza tratí pre obrazovku Map Selection
static const TomkoWiiTrat ZoznamTrati[] = {
    {
        "Hypermarket Trencianska", 
        "Nove Mesto nad Vahom", 
        2, // Stredne ľahká
        3, 
        "Start na parkovisku, ostra zakruta okolo Posty 3 a rychly sprint cez regalovu zonu akcii."
    },
    {
        "Nonstop Megastore Petrzalka", 
        "Bratislava", 
        4, // Ťažká
        3, 
        "Obrovsky hypermarket! Jazda cez nocne, zahmlene skladiska a nebezpecnu zonu samoobsluznych pokladni."
    },
    {
        "Zvolenska Distribucia", 
        "Zvolen", 
        5, // Najtazsia - Master
        2, 
        "Preteky v centralnom distribucnom sklade Tesca. Kuckovanie medzi vysokozdvižnymi vozikmi a padajucimi paletami."
    }
};

#endif
