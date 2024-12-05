/* This is free and unencumbered software released into the public domain. */

/* Tries to find the shortest path to G */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 20
#define HEIGHT 20

const char grid[][WIDTH] =
{
    {' ','#','#','#','#','#','#','#','#','#',' ','#','#','#','#','#','#','#','G','#'},
    {' ','#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ',' ','#','G','#','#'},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#','G','#','#'},
    {'#','#',' ','#','#',' ','#','#','#',' ','#','#','#','#',' ','#','#','#','#','#'},
    {'#','#',' ','#','#',' ','#','#','#',' ','#','#','#','#',' ','#','#','#','#','#'},
    {'#',' ',' ',' ',' ',' ','#','G','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {'#',' ','#','#',' ','#','#','#','#','#',' ','#','#','#',' ','#','#','#','#','#'},
    {'#','#','#','#',' ','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ','G','#','#'},
    {'#','G','#','#',' ','#','#','G','#','#','#','#','#','#',' ','#','#','#','#','#'},
    {'#','#','#','#',' ','#','#','#','#','#','#','#','#','#',' ','#','#','#','#','#'},
    {' ','#','#','#','#','#','#','#','#','#',' ','G','#','#','#','#','#','#','G','#'},
    {' ','#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ',' ','#','G','#','#'},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#','G','#','#'},
    {'#','#',' ','#','#',' ','#','#','#',' ','#','#','#','#',' ','#','#','#','#','#'},
    {'#','#',' ','#','#',' ','#','#','#',' ','#','#','#','#',' ','#','#','#','#','#'},
    {'#',' ',' ',' ',' ',' ','#','G','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {'#',' ','#','#',' ','#','#','#','#','#',' ','#','#','#','#','#','#','#','#','#'},
    {'#','#','#','#',' ','#','#','#','#','#','#',' ',' ',' ',' ',' ','#','G','#','#'},
    {'#','G','#','#',' ','#','#','G','#','#','#','#','#','#',' ','#','#','#','#','#'},
    {'#','#','#','#',' ','#','#','#','#','#','#','#','#','#',' ','#','#','#','#','#'}
};

const int start_x = 4;
const int start_y = 9;

static char read_grid(int x, int y)
{
    return grid[y][x];
}
static bool is_open(int x, int y)
{
    if(y <= -1 || y >= HEIGHT || x <= -1 || x >= WIDTH) return false;
    char c = read_grid(x,y);
    return c == ' ' || c == 'G';
}


struct path_link_t
{
    int x, y;
    struct path_link_t *prev;
};


bool is_in_path(struct path_link_t *path, int x, int y)
{
    bool in_path = false;
    while(path)
    {
	if(y == path->y && x == path->x)
	{
	    return true;
	}
	path = path->prev;
    }
    return false;
}

/* Grid + Path pretty-printer */
static void print_grid(struct path_link_t *path)
{
    for(int i = HEIGHT-1; i >= 0; i--)
    {
        printf(" %02d ", i);
        for(int j = 0; j < WIDTH; j++)
        {
	    char c = read_grid(j,i);

            if((path && path->x == j && path->y == i) ||
	       (!path && i == start_y && j == start_x))
            {
                printf(" ☺ ");
            }
            else if(is_in_path(path,j,i) && c != 'G' )
	    {
		printf(" * ");
	    }
	    else
            {
		if(c == '#') printf("###");
		else printf(" %c ", c);
            }
        }
        putchar('\n');
    }
    printf("    ");
    for(int i = 0; i < WIDTH; i++)
    {
        printf("%02d ", i); 
    }
    putchar ('\n');
}


bool explore(struct path_link_t *prev, int x, int y)
{
    /* Check that we can be here */
    if(!is_open(x, y))
	return false;

    /* Check that we haven't been here before */
    if(is_in_path(prev,x,y))
       return false;
        
    struct path_link_t link;
    link.x = x;
    link.y = y;
    link.prev = prev;
        
    /* Check for a win */
    if(read_grid(x,y) == 'G')
    {
	printf("Found goal! Path:\n");

	print_grid(&link);
	return true;
    }

    return  explore(&link, x, y - 1) ||
	explore(&link, x, y + 1) ||
	explore(&link, x - 1, y) ||
	explore(&link, x + 1, y);
}


int main(int argc, char *argv[])
{
    printf("Grid:\n");

    print_grid(NULL);

    printf("\n");
    
    explore(NULL, start_x, start_y);
        
    return 0;
}
