#include <stdio.h>
#include <stdbool.h>

/* line styles     */
#define SOLID 0
#define DOTTED 1
#define DASHED 2

/* PRIMERY COLORS     */

#define RED 1
#define GREEN 2
#define BLUE 4

/* mixed colors    */
#define BLACK 0
#define YELLOW (RED | GREEN) // is 001|010 = 011 = 3
#define MAGENTA (RED | BLUE)// is 001|100 = 101 = 5
#define CYAN (GREEN | BLUE)// is 010|100 = 110 = 6
#define WHITE   (RED | GREEN | BLUE)// is 001|010|100 = 111 =7

const char *colors[8] = {"black","red","green","yellow","blue","magenta","cyan","white"};

struct box_props
{
    bool opaque               : 1;
    unsigned int fill_color   : 3;
    unsigned int              : 4;
    bool    show_border       : 1;
    unsigned int border_color : 3;
    unsigned int border_style : 3;
    unsigned int              : 2;
};

void show_settings(const struct box_props *pb);




int main(){

    /* create and initialize box_props structure */
    struct box_props box = {true,YELLOW,true,GREEN,DASHED};

    printf("Original box settings :\n");
    show_settings(&box);

    // change settings

    box.opaque == false;
    box.fill_color == BLACK;
    box.show_border == false;
    box.border_color == WHITE;
    box.border_style == SOLID;

    printf("\nModified box settings:\n");
    show_settings(&box);



return 0;
}

void show_settings(const struct box_props *pb)
{
    printf("Box is %s.\n",pb->opaque == true ? "opaque" : "transparent");
    printf("The fill color is %s.\n",colors[pb->fill_color]);
    printf("Border %s.\n", pb->show_border == true ? "shown" : "not shown");
    printf("The border color is %s.\n",colors[pb->border_color]);
    printf("The border style is ");

    switch(pb->border_style)
    {
        case SOLID  : printf("solid.\n"); break;
        case DOTTED : printf("dotted.\n"); break;
        case DASHED : printf("dashed.\n"); break;
        default     : printf("unknown type.\n");
    }
}





