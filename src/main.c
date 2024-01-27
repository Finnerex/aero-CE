#include <ti/getcsc.h>
#include <graphx.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gfx/gfx.h"

void begin(void);
void end(void);
bool step(void);
void draw(void);

int main() {
    begin();                // No rendering allowed!

    gfx_Begin();
    gfx_SetPalette(global_palette, sizeof_global_palette, 0);

    gfx_SetDrawBuffer();    // Draw to the buffer to avoid rendering artifacts

    while (step()) {        // No rendering allowed in step!
        draw();             // As little non-rendering logic as possible
        gfx_SwapDraw();     // Queue the buffered frame to be displayed
    }

    gfx_End();
    end();

    return 0;
}

bool step(void) {


    return true;
}

void draw(void) {

}


void begin(void) {

}

void end(void) {

}