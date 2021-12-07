#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>


struct svg{
    char* _svg; // contains the svg details
    int height; // set the svg's image width
    int width; // set the svg's image heigh
    bool done; // flag to specify if the svg is built completely
};

typedef struct svg Svg;

/**
 * @brief appends a string to an existing string
 * @param   svg object to build
 * @param  text to add to `svg->_svg's` string
 */
static inline void append_string_to_svg(Svg* ,char*);


/**
 * @brief appends a number to an existing string
 * @param svg  svg object to build
 * @param text text to add to `svg->_svg's` string
 */
static inline void append_number_to_svg(Svg* ,int );



/**
 * @brief creates a representation of an svg image
 * @return Svg* {struct svg}
 */
Svg* svg_create(int,int);

/**
 * @brief specify if the image is completely built
 */
void svg_set_done(Svg*); 

/**
 * @brief return the svg representation of struct
 * in char* by extracting it from the struct svg
 */
void svg_print(Svg*);

/**
 * @brief saves the constructed svg into a file 
 * depending on the specified filename
 */
void svg_save(Svg*,const char*);

/**
 * @brief free the svg from memory
 */
void svg_free(Svg*);

/**
 * @brief creates an svg circle
 */
void svg_circle(Svg*,char*,int,char*,int,int,int);

/**
 * @brief creates an svg line
 */
void svg_line(Svg*,char*,int,int,int,int,int);

/**
 * @brief creates an svg rectangle
 */
void svg_rectangle(Svg*,int,int,int,int,char*,char*,int,int,int);

/**
 * @brief creates color filling property on the
 * svg object
 */
void svg_fill(Svg*,char*);

/**
 * @brief creates an svg image
 */
void svg_text(Svg*,int,int,char*,int,char*,char*,char*);


/**
 * @brief creates an ellipse  object
 */
void svg_ellipse(Svg*,int,int,int,int,char*,char*,int);



