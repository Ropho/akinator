#include <stdio.h>
#include "string.h"
#include <malloc.h>
#include <locale.h>
#include <assert.h>

typedef struct node {

    char data[20] = {};

    node *left = nullptr;

    node *right = nullptr;

}node;

void add_node (node *node);
void ctor (node *head);
void graph (node* head);
void in_order_print (node *node, FILE* out);
