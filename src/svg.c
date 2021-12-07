#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <setjmp.h>
#include "../lib/svg.h"


static inline void append_string_to_svg(Svg* csvg,char* text){
    if(csvg==NULL)
        return;
    if(text==NULL)
        return;
    int l = strlen(csvg->_svg)+ strlen(text) + 1;
    char* new_string_arr = (char*) realloc(csvg->_svg,(size_t)l*sizeof(char));
    if(new_string_arr)
        csvg->_svg = new_string_arr;
    strcat(csvg->_svg,text);
};

static inline void append_number_to_svg(Svg* csvg,int number){
    if(csvg==NULL)
        return;
    char number_str[16];
    sprintf(number_str,"%d",number);
    append_string_to_svg(csvg,number_str);
};


Svg* svg_create(int height,int width){
    if(height<0)
        height=600;
    if(width<0)
        width= 600;
    Svg* csvg = malloc(sizeof(Svg));
    if(csvg!=NULL){
        (*csvg) = (Svg) {
            .done=false,
            .height=height,
            .width=width,
            ._svg=NULL
        };
        csvg->_svg = malloc(sizeof(char));
        sprintf(csvg->_svg,"%s","\0");
        append_string_to_svg(csvg,"<svg width='");
        append_number_to_svg(csvg,csvg->width);
        append_string_to_svg(csvg,"px' height='");
        append_number_to_svg(csvg,csvg->height);
        append_string_to_svg(csvg,
            "px' xmlns='http://www.w3.org/2000/svg' version='1.1' xmlns:xlink='http://www.w3.org/1999/xlink'>\n");
        return csvg;
    }
    return NULL;
}

void svg_set_done(Svg* csvg){
    if(csvg==NULL)
        return;
    append_string_to_svg(csvg,"</svg>");
    csvg->done = !csvg->done;
}


void svg_free(Svg* csvg){
    if(csvg==NULL)
        return;
    free(csvg->_svg);
    free(csvg);
}

void svg_rectangle(Svg* csvg,int width,int height,int x,int y,char* fill,char* stroke,int stroke_width,int radius_x,int radius_y){
    if(csvg==NULL)
        return;
    append_string_to_svg(csvg,"<rect x ='");
    append_number_to_svg(csvg,x);
    append_string_to_svg(csvg,"' y='");
    append_number_to_svg(csvg,y);
    append_string_to_svg(csvg,"' height='");
    append_number_to_svg(csvg,height);
    append_string_to_svg(csvg,"' width='");
    append_number_to_svg(csvg,width);
    append_string_to_svg(csvg,"' fill='");
    append_string_to_svg(csvg,fill);
    append_string_to_svg(csvg,"' stroke='");
    append_string_to_svg(csvg,stroke);
    append_string_to_svg(csvg,"' stroke-width='");
    append_number_to_svg(csvg,stroke_width);
    append_string_to_svg(csvg, "' ry='");
    append_number_to_svg(csvg, radius_y);
    append_string_to_svg(csvg, "' rx='");
    append_number_to_svg(csvg, radius_x);
    append_string_to_svg(csvg,"' />\n");
};


void svg_save(Svg* csvg,const char*  file_path){
    if(csvg==NULL)
        return;
    FILE* fptr = fopen(file_path,"w");
    if(fptr==NULL){
        printf("ERROR:: {%s}\n","could not create file to store svg data");
        return;
    }
    fprintf(fptr,"%s",csvg->_svg);
    fclose(fptr);
}

void svg_fill(Svg* csvg,char*  fill){
    svg_rectangle(csvg, csvg->width, csvg->height, 0, 0, fill, fill, 0, 0, 0);
}

void svg_print(Svg* csvg){
    printf("%s\n",csvg->_svg);
}


void svg_line(Svg* csvg, char* stroke, int stroke_width, int x1, int y1, int x2, int y2)
{
    append_string_to_svg(csvg, "<line stroke='");
    append_string_to_svg(csvg, stroke);
    append_string_to_svg(csvg, "' stroke-width='");
    append_number_to_svg(csvg, stroke_width);
    append_string_to_svg(csvg, "px' y2='");
    append_number_to_svg(csvg, y2);
    append_string_to_svg(csvg, "' x2='");
    append_number_to_svg(csvg, x2);
    append_string_to_svg(csvg, "' y1='");
    append_number_to_svg(csvg, y1);
    append_string_to_svg(csvg, "' x1='");
    append_number_to_svg(csvg, x1);
    append_string_to_svg(csvg, "' />\n");
}


void svg_text(Svg* csvg, int x, int y, char* fontfamily, int fontsize, char* fill, char* stroke, char* text)
{
    append_string_to_svg(csvg, "<text x='");
    append_number_to_svg(csvg, x);
    append_string_to_svg(csvg, "' y = '");
    append_number_to_svg(csvg, y);
    append_string_to_svg(csvg, "' font-family='");
    append_string_to_svg(csvg, fontfamily);
    append_string_to_svg(csvg, "' stroke='");
    append_string_to_svg(csvg, stroke);
    append_string_to_svg(csvg, "' fill='");
    append_string_to_svg(csvg, fill);
    append_string_to_svg(csvg, "' font-size='");
    append_number_to_svg(csvg, fontsize);
    append_string_to_svg(csvg, "px'>");
    append_string_to_svg(csvg, text);
    append_string_to_svg(csvg, "</text>\n");
}


void svg_circle(Svg* csvg, char* stroke, int stroke_width, char* fill, int r, int cx, int cy)
{
    append_string_to_svg(csvg, "<circle stroke='");
    append_string_to_svg(csvg, stroke);
    append_string_to_svg(csvg, "' stroke-width='");
    append_number_to_svg(csvg, stroke_width);
    append_string_to_svg(csvg, "px' fill='");
    append_string_to_svg(csvg, fill);
    append_string_to_svg(csvg, "' r='");
    append_number_to_svg(csvg, r);
    append_string_to_svg(csvg, "' cy='");
    append_number_to_svg(csvg, cy);
    append_string_to_svg(csvg, "' cx='");
    append_number_to_svg(csvg, cx);
    append_string_to_svg(csvg, "' />\n");
}

void svg_ellipse(Svg* csvg, int cx, int cy, int rx, int ry, char* fill, char* stroke, int stroke_width)
{
    append_string_to_svg(csvg, "<ellipse cx='");
    append_number_to_svg(csvg, cx);
    append_string_to_svg(csvg, "' cy='");
    append_number_to_svg(csvg, cy);
    append_string_to_svg(csvg, "' rx='");
    append_number_to_svg(csvg, rx);
    append_string_to_svg(csvg, "' ry='");
    append_number_to_svg(csvg, ry);
    append_string_to_svg(csvg, "' fill='");
    append_string_to_svg(csvg, fill);
    append_string_to_svg(csvg, "' stroke='");
    append_string_to_svg(csvg, stroke);
    append_string_to_svg(csvg, "' stroke-width='");
    append_number_to_svg(csvg, stroke_width);
    append_string_to_svg(csvg, "' />\n");
}