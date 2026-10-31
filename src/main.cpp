#include <grrlib.h>
#include <stdlib.h>
#include <wiiuse/wpad.h>
#include "../include/characters.h"

int main(int argc, char **argv) {
    // Inicializácia Wii hardvéru a grafiky
    GRRLIB_Init();
    WPAD_Init();

    // Herná slučka samostatnej hry Tesco Kart
    while(1) {
        WPAD_ScanPads();
        u32 pressed = WPAD_ButtonsDown(0);

        // Návrat do Homebrew Channel po stlačení HOME
        if (pressed & WPAD_BUTTON_HOME) {
            break;
        }

        GRRLIB_2dMode();
        
        // Nastavenie ikonickej Tesco modrej farby pozadia (HEX #005CA9)
        GRRLIB_SetBackgroundColour(0x00, 0x5C, 0xA9, 0xFF); 

        // Tu bude motor hry vykresľovať trať Nové Mesto nad Váhom a vozíky
        
        GRRLIB_Render();
    }

    GRRLIB_Exit();
    exit(0);
}
