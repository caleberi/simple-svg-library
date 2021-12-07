#include <stdio.h>
#include <math.h>
#include <time.h>

#include "../lib/svg.h"

void draw_rectangles(void);
void draw_all_shapes(void);
void i_want_to_believe(void);

int main()
{
    puts("----------------------");
    puts("| hebronacedrome.com |");
    puts("|     SVG Library    |");
    puts("----------------------\n");
    draw_rectangles();
    draw_all_shapes();
    i_want_to_believe();

    return EXIT_SUCCESS;
}

void draw_rectangles(){
    Svg* csvg = svg_create(512,512);
    if(csvg==NULL){
        puts("svg is null:)");
        return;
    }

    svg_rectangle(csvg,512,512, 0, 0, "white", "white", 0, 0, 0);
    svg_rectangle(csvg, 384, 384, 64, 64, "#00FF00", "#000000", 4, 0, 0);
    svg_rectangle(csvg, 320, 320, 96, 96, "#FFFF00", "#000000", 2, 8, 8);
    svg_rectangle(csvg, 256, 256, 128, 128, "#00FFFF", "#000000", 2, 8, 8);
    svg_rectangle(csvg, 192, 192, 160, 160, "#FF80FF", "#000000", 2, 8, 8);
    svg_set_done(csvg);
    svg_save(csvg,"rectangle.svg");
    svg_free(csvg);
}


void draw_all_shapes(void)
{
    Svg* csvg;
    csvg = svg_create(192, 320);

    if(csvg != NULL){
        svg_fill(csvg, "#DADAFF");

        svg_text(csvg, 32, 32, "sans-serif", 16, "#000000", "#000000", "draw_all_shapes");
        svg_circle(csvg, "#000080", 4, "#0000FF", 32, 64, 96);
        svg_ellipse(csvg, 64, 160, 32, 16, "#FF0000", "#800000", 4);

        svg_line(csvg, "#000000", 2, 32, 192, 160, 192);

        svg_rectangle(csvg, 64, 64, 32, 224, "#00FF00", "#008000", 4, 4, 4);

        svg_set_done(csvg);
        svg_print(csvg);
        svg_save(csvg, "all_shapes.svg");
        svg_free(csvg);
        return;
    }
     puts("svg is null:)");
}

void i_want_to_believe(void)
{
    Svg* csvg;
    csvg = svg_create(512, 768);

    if(csvg == NULL)
    {
        puts("csvg is NULL");
    }
    else
    {
        svg_fill(csvg, "#000010");

        srand(time(NULL));
        int x, y;
        for(int s = 0; s <= 512; s++)
        {
            x = (rand() % 512);
            y = (rand() % 768);

            svg_rectangle(csvg, 1, 1, x, y, "white", "white", 0, 0, 0);
        }

        svg_text(csvg, 96, 712, "sans-serif", 32, "#FFFFFF", "#FFFFFF", "I WANT TO BELIEVE");

        svg_circle(csvg, "silver", 2, "rgba(0,0,0,0)", 28, 256, 384);

        svg_ellipse(csvg, 256, 374, 8, 14, "#808080", "#808080", 0);
        svg_ellipse(csvg, 252, 372, 3, 2, "#000000", "#000000", 0);
        svg_ellipse(csvg, 260, 372, 3, 2, "#000000", "#000000", 0);
        svg_rectangle(csvg, 1, 1, 251, 371, "white", "white", 0, 0, 0);
        svg_rectangle(csvg, 1, 1, 259, 371, "white", "white", 0, 0, 0);
        svg_line(csvg, "black", 1, 254, 378, 258, 378);

        svg_line(csvg, "silver", 2, 234, 416, 226, 432);
        svg_line(csvg, "silver", 2, 278, 416, 286, 432);
        svg_ellipse(csvg, 256, 400, 64, 16, "silver", "silver", 4);

        svg_set_done(csvg);
        svg_save(csvg, "i_want_to_believe.svg");
        svg_free(csvg);
    }
}