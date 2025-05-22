#include "g2.h"

//---------------------------------------------------------------------------
#define RAND_A 9301
#define RAND_C 49297
#define RAND_M 233280
static uint32 seed=0x12345678;

float crap_rand(void)
{
    // small delay...
    volatile uint32 i;
    for(i=0; i<0xFFF; i++) {}

    seed = (seed*RAND_A+RAND_C) % RAND_M;
    return((float)seed / (float)RAND_M);
}

void random_draw(void)
{
    int i;
    g2_set_fill_color(51, 76, 76);
    g2_fill_rect(0, 0, g2_get_max_x(), g2_get_max_y());

    // random points
    for(i=0; i<0x1000; i++)
    {
        g2_set_color(
            (uint8)(crap_rand()*255), 
            (uint8)(crap_rand()*255), 
            (uint8)(crap_rand()*255));

        g2_put_pixel(
            (uint16)(crap_rand()*g2_get_max_x()), 
            (uint16)(crap_rand()*g2_get_max_y()));
    }

    g2_set_fill_color(51, 76, 76);
    g2_fill_rect(0, 0, g2_get_max_x(), g2_get_max_y());

    // random lines
    for(i=0; i<0x1000; i++)
    {
        g2_set_color(
            (uint8)(crap_rand()*255), 
            (uint8)(crap_rand()*255), 
            (uint8)(crap_rand()*255));

        g2_line(
            (uint16)(crap_rand()*g2_get_max_x()), 
            (uint16)(crap_rand()*g2_get_max_y()),
            (uint16)(crap_rand()*g2_get_max_x()), 
            (uint16)(crap_rand()*g2_get_max_y()));
    }

    g2_set_fill_color(51, 76, 76);
    g2_fill_rect(0, 0, g2_get_max_x(), g2_get_max_y());

    // random rects
    for(i=0; i<0x1000; i++)
    {
        g2_set_color(
            (uint8)(crap_rand()*255), 
            (uint8)(crap_rand()*255), 
            (uint8)(crap_rand()*255));

        g2_rect(
            (uint16)(crap_rand()*g2_get_max_x()), 
            (uint16)(crap_rand()*g2_get_max_y()),
            (uint16)(crap_rand()*g2_get_max_x()), 
            (uint16)(crap_rand()*g2_get_max_y()));
    }

    g2_set_fill_color(51, 76, 76);
    g2_fill_rect(0, 0, g2_get_max_x(), g2_get_max_y());

    // random filled rects
    for(i=0; i<0x1000; i++)
    {
        g2_set_fill_color(
            (uint8)(crap_rand()*255), 
            (uint8)(crap_rand()*255), 
            (uint8)(crap_rand()*255));

        g2_fill_rect(
            (uint16)(crap_rand()*g2_get_max_x()), 
            (uint16)(crap_rand()*g2_get_max_y()),
            (uint16)(crap_rand()*g2_get_max_x()),
            (uint16)(crap_rand()*g2_get_max_y()));
    }
}

//---------------------------------------------------------------------------
int main(int argc, char **argv)
{
    argc=argc;
    argv=argv;

    // g2_init(PAL_512_256_32);
    g2_init(NTSC_640_224_32);

    // clear the screen
    // 0.2f, 0.3f, 0.3f, the same as learnopenGL clear color
    g2_set_fill_color(51, 76, 76);
    g2_fill_rect(0, 0, g2_get_max_x(), g2_get_max_y());

    while(1)
    {
        random_draw();
    }

    // ok...it will never get here...
    g2_end();
    return(0);
}


