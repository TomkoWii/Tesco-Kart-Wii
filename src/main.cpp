#include "../include/characters.h"
#include "../include/tracks.h"  // <--- TENTO RIADOK SEM PRIDAJ
#include <grrlib.h>
#include <stdlib.h>
#include <wiiuse/wpad.h>
#include "../include/characters.h"

// Definícia jednotlivých obrazoviek (stavov hry)
enum GameState {
    STATE_MAIN_MENU,
    STATE_CHARACTER_SELECT,
    STATE_MAP_SELECT,
    STATE_GAMEPLAY,
    STATE_SETTINGS,
    STATE_EXIT
};

int main(int argc, char **argv) {
    GRRLIB_Init();
    WPAD_Init();

    // Na začiatku hry nastavíme stav na Hlavné Menu
    GameState currentState = STATE_MAIN_MENU;
    int menuSelection = 0; // Pomocná premenná pre navigáciu v menu (0 = Play, 1 = Settings, 2 = Leave)

    while(1) {
        WPAD_ScanPads();
        u32 pressed = WPAD_ButtonsDown(0);

        // Ak hráč stlačí HOME kdekoľvek, hra sa ukončí
        if (pressed & WPAD_BUTTON_HOME) {
            currentState = STATE_EXIT;
        }

        // --- HLAVNÁ LOGIKA MENU A HRY ---
        switch (currentState) {
            
            case STATE_MAIN_MENU:
                // Ovládanie menu pomocou D-Padu (šípky hore/dole na Wii Remote)
                if (pressed & WPAD_BUTTON_DOWN) {
                    menuSelection = (menuSelection + 1) % 3;
                }
                if (pressed & WPAD_BUTTON_UP) {
                    menuSelection = (menuSelection - 1 + 3) % 3;
                }
                
                // Potvrdenie voľby tlačidlom A
                if (pressed & WPAD_BUTTON_A) {
                    if (menuSelection == 0) currentState = STATE_CHARACTER_SELECT;
                    else if (menuSelection == 1) currentState = STATE_SETTINGS;
                    else if (menuSelection == 2) currentState = STATE_EXIT;
                }
                break;

            case STATE_CHARACTER_SELECT:
                // Tu si hráč vyberie postavu (napr. stlačením šípky a potvrdením cez A)
                if (pressed & WPAD_BUTTON_A) {
                    currentState = STATE_MAP_SELECT;
                }
                if (pressed & WPAD_BUTTON_B) { // Krok späť
                    currentState = STATE_MAIN_MENU;
                }
                break;

            case STATE_MAP_SELECT:
                // Tu si hráč vyberie trať (napr. Nové Mesto nad Váhom)
                if (pressed & WPAD_BUTTON_A) {
                    currentState = STATE_GAMEPLAY;
                }
                if (pressed & WPAD_BUTTON_B) { // Krok späť
                    currentState = STATE_CHARACTER_SELECT;
                }
                break;

            case STATE_GAMEPLAY:
                // SEM PROGRAMÁTORI NAPÍŠU SAMOTNÉ PRETEKY S VOZÍKMI
                if (pressed & WPAD_BUTTON_B) { // Návrat z hry do menu pre testovanie
                    currentState = STATE_MAIN_MENU;
                }
                break;

            case STATE_SETTINGS:
                if (pressed & WPAD_BUTTON_B) {
                    currentState = STATE_MAIN_MENU;
                }
                break;

            case STATE_EXIT:
                // Ukončenie slučky a odchod z hry
                goto exit_game;
        }

        // --- VYKRESLOVANIE GRAFIKY (RENDERING) ---
        GRRLIB_2dMode();
        GRRLIB_SetBackgroundColour(0x00, 0x5C, 0xA9, 0xFF); // Tesco modrá

        // Poznámka pre tím: Sem sa doplnia GRRLIB_Printf príkazy pre zobrazenie textov menu na TV

        GRRLIB_Render();
    }

exit_game:
    GRRLIB_Exit();
    exit(0);
}
