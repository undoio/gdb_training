#include <stdio.h>
#include <stdlib.h>

typedef struct data {
    int type;
    unsigned count;
    size_t size;
    int **ptrs;
} data_t;

void data_init(data_t *data)
{
    data->count = 2;
    data->ptrs = malloc(20 * sizeof(int));
    for (unsigned i = 0; i < 20; i++)
    {
        data->ptrs[i] = malloc(20 * sizeof(int));
    }
}

void data_finalise(data_t *data)
{

   printf("data->ptrs[0][0]: %d\n", data->ptrs[0][0]);
   free(data->ptrs);
}

int main(void)
{
   data_t data;
   data_init(&data);
   data_finalise(&data);

   if (data.type || data.count)
   {
       puts("Hello World");
   }

   return EXIT_SUCCESS;
}
