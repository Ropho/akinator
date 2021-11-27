#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <locale.h>
#include <assert.h>
#include <sys\stat.h>
#include "functions.h"

#define TX_USE_SPEAK
#include "C:\Users\gon4a\Desktop\TXLIB\TX\TXLib.h"


#define $ char ch = 1; scanf (" %c", &ch);
#define check_found   do {if (stk->find) return;}while (0)

#ifndef tree
#define tree
    typedef struct node {

        char data[20] = {};

        node *left = nullptr;

        node *right = nullptr;

    }node;
#endif


enum MODS {

    AKINATOR       = 1,
    COMPARE        = 2,
    CHARACTERISTIC = 3,
};


void add_node              (node *node);
void ctor                  (node *head);
void graph                 (node* head);

static void create_tree    (node **node, char **ch);

void find_obj_in_tree      (node* node, char *obj, my_stack *stk);
void characteristic_print  (node* node, char *obj, my_stack *stk);

void print_tree            (node *node, FILE *out);
static void in_order_graph (node *node, FILE* out);

void get_tree_from_file    (node** node, FILE *in);

static size_t FILESIZE_FUNC_FSTAT (FILE *in);

void srav (my_stack *stk1, my_stack *stk2, char *obj1, char *obj2, node* node);