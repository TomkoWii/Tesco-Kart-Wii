#include <grrlib.h>
#include <stdlib.h>
#include <wiiuse/wpad.h>
#include <math.h>
#include "../include/characters.h"
#include "../include/tracks.h"

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

    GameState currentState = STATE_MAIN_MENU;
    int menuSelection = 0; 
    
    // Fyzika vozika pre top-down preteky
    float playerX = 320.0f; 
    float playerY = 240.0f;
    float kartRotacia = 0.0f; 
    float rychlost = 0.0f;

    while(1) {
        WPAD_ScanPads();
        u32 pressed = WPAD_ButtonsDown(0);
        u32 held = WPAD_ButtonsHeld(0);

        if (pressed & WPAD_BUTTON_HOME) {
            currentState = STATE_EXIT;
        }

        // --- HLENA LOGIKA HRI (STATE MACHINE) ---
        switch (currentState) {
            
            case STATE_MAIN_MENU:
                if (pressed & WPAD_BUTTON_DOWN) menuSelection = (menuSelection + 1) % 3;
                if (pressed & WPAD_BUTTON_UP)   menuSelection = (menuSelection - 1 + 3) % 3;
                
                if (pressed & WPAD_BUTTON_A) {
                    if (menuSelection == 0) currentState = STATE_CHARACTER_SELECT;
                    else if (menuSelection == 1) currentState = STATE_SETTINGS;
                    else if (menuSelection == 2) currentState = STATE_EXIT;
                }
                break;

            case STATE_CHARACTER_SELECT:
                if (pressed & WPAD_BUTTON_A) currentState = STATE_MAP_SELECT;
                if (pressed & WPAD_BUTTON_B) currentState = STATE_MAIN_MENU;
                break;

            case STATE_MAP_SELECT:
                if (pressed & WPAD_BUTTON_A) currentState = STATE_GAMEPLAY;
                if (pressed & WPAD_BUTTON_B) currentState = STATE_CHARACTER_SELECT;
                break;

            case STATE_GAMEPLAY:
                if (held & WPAD_BUTTON_LEFT)  kartRotacia -= 3.0f;
                if (held & WPAD_BUTTON_RIGHT) kartRotacia += 3.0f;
                
                if (held & WPAD_BUTTON_2) { 
                    rychlost = 3.0f;
                } else if (held & WPAD_BUTTON_1) { 
                    rychlost = -1.5f;
                } else {
                    rychlost *= 0.95f; 
                }

                playerX += rychlost * sin(kartRotacia * M_PI / 180.0f);
                playerY -= rychlost * cos(kartRotacia * M_PI / 180.0f);

                if (pressed & WPAD_BUTTON_B) currentState = STATE_MAIN_MENU;
                break;

            case STATE_SETTINGS:
                if (pressed & WPAD_BUTTON_B) currentState = STATE_MAIN_MENU;
                break;

            case STATE_EXIT:
                goto exit_game;
        }

        // --- VYKRESLOVANIE (ČISTÝ TEXTOVÝ REŽIM PRE KOMPILÁCIU) ---
        GRRLIB_2dMode();
        GRRLIB_SetBackgroundColour(0x00, 0x5C, 0xA9, 0xFF); // Tesco modra

        // Zobrazenie textu podla stavu hry (Wii font je zabudovany v GRRLIB)
        if (currentState == STATE_MAIN_MENU) {
            GRRLIB_Printf(200, 150, NULL, 0xFFFFFFFF, 2, "TOMKOWII MENU");
            GRRLIB_Printf(200, 220, NULL, (menuSelection == 0) ? 0xFF0000FF : 0xFFFFFFFF, 1.5, "[ PLAY ]");
            GRRLIB_Printf(200, 260, NULL, (menuSelection == 1) ? 0xFF0000FF : 0xFFFFFFFF, 1.5, "[ SETTINGS ]");
            GRRLIB_Printf(200, 300, NULL, (menuSelection == 2) ? 0xFF0000FF : 0xFFFFFFFF, 1.5, "[ LEAVE TO WII ]");
        } 
        else if (currentState == STATE_CHARACTER_SELECT) {
            GRRLIB_Printf(150, 200, NULL, 0xFFFFFFFF, 1.5, "VYBER POSTAVU (Stlac A)");
            GRRLIB_Printf(150, 240, NULL, 0xFFFFFFFF, 1.2, "Fero Joke / Henio / Pan Letak");
        }
        else if (currentState == STATE_MAP_SELECT) {
            GRRLIB_Printf(150, 200, NULL, 0xFFFFFFFF, 1.5, "VYBER TRAT (Stlac A na start)");
            GRRLIB_Printf(150, 240, NULL, 0xFFFFFFFF, 1.2, "1. Nove Mesto nad Vahom");
        }
        else if (currentState == STATE_GAMEPLAY) {
            GRRLIB_Printf(20, 20, NULL, 0xFFFFFFFF, 1.2, "PRETEKY BEZIA! Tlacitko B = Menu");
            // Vykreslime hraca zatial ako biely stvorec (stvorec nepotrebuje PNG subor!)
            GRRLIB_Rectangle(playerX, playerY, 20, 20, 0xFFFFFFFF, 1);
        }
        else if (currentState == STATE_SETTINGS) {
            GRRLIB_Printf(150, 200, NULL, 0xFFFFFFFF, 1.5, "NASTAVENIA (Tlacitko B = Spat)");
        }

        GRRLIB_Render();
    }

exit_game:
    GRRLIB_Exit();
    exit(0);
}
