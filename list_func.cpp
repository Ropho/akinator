#include "list_func.h"


static void create_tree (node **node, char **ch) {

    assert (*ch  != nullptr);
    assert (node != nullptr);

    while (1) {

        while (1) {

            if (**ch == '{') {

                *ch += 3; // {\r\n skip
                char *srch = strchr (*ch, '\r');

                *srch = '\0';

                *node = (struct node*)calloc (1, sizeof (struct node));
                ctor (*node);
                strcpy ((*node)->data, *ch);              
            
                *ch = srch;
                *ch += 2;

                break;
            }
            else if (**ch == '}') {
                ++(*ch);

                if (**ch == '\0')
                    return;
                else {
                    (*ch) += 2;
                    return;
                }
            }
            else {
                return;
            }
        }

        if (**ch == '{') {

            if ((*node)->left == nullptr) {

                create_tree (&(*node)->left, ch);
                
                create_tree (&(*node)->right, ch);
            }
        }
    }
}


void print_tree (node *node, FILE *out) {

    assert (node != nullptr);
    assert (out  != nullptr);

    fputs ("{\n", out);

    fprintf (out, "%s\n", node->data);

    if (node->left != nullptr) {
        print_tree (node->left, out);
    }
    else {
        fputs ("}\n", out);
        return;
    }

    if (node->right != nullptr) {
        print_tree (node->right, out);
    }
    else {
        fputs ("}\n", out);
        return;
    }
    fputs ("}\n", out);

    return;
}


void get_tree_from_file (node** head, FILE *in) {

    assert (in != nullptr);

    int size = FILESIZE_FUNC_FSTAT (in);

    char buff[size] = {};

    fread (buff, sizeof (char), size, in);
    buff[size - 1] = '\0';

    char *ch = buff;

    create_tree (head, &ch);

    return;
}


void characteristic_print (node* node, char *obj, my_stack *stk) {
            
    printf ("%s === ", obj);

    for (int i = 0; i < stk->size_stack - 1; ++i) {

            if ((*(stk->arr + i))->left == *(stk->arr + i + 1))
                printf ("NE_%s ", (*(stk->arr + i))->data);
            else
                printf ("%s ", (*(stk->arr + i))->data);
    }

    puts ("\n");

    return;    
}


void find_obj_in_tree (node* node, char *obj, my_stack *stk) {
    
    assert (node != nullptr);

    push (stk, node);

    if (strcmp (node->data, obj) == 0) {
        stk->find = 1;
    }

    check_found;
    if (node->left != nullptr) {
        find_obj_in_tree (node->left, obj, stk);
    }

    check_found;
    if (node->right != nullptr) {
        find_obj_in_tree (node->right, obj, stk);
    }

    check_found;
    pop (stk);

    return;
}


void add_node (node *node) {

    assert (node != nullptr);

    while (1) {
        printf ("%s?", node->data);
        puts ("\tY/N?");
        $

        if (ch == 'N') {

            if (node->left != nullptr) {

                add_node (node->left);
                return;
            }

            else {
                    char tmp[20] = {};
                    strcpy (tmp, node->data);

                    node->right = (struct node*)calloc(1, sizeof (struct node));
                    node->left =  (struct node*)calloc(1, sizeof (struct node));

                    ctor (node->right);
                    ctor (node->left);
                    strcpy (node->left->data, tmp);                    
                    strcpy (tmp, "");

                    puts ("WRITE THE QUESTION");
                    scanf (" %s", tmp);
                    strcpy (node->data, tmp);
                    strcpy (tmp, "");

                    puts ("WRITE THE OBJECT");
                    scanf (" %s", tmp);
                    strcpy (node->right->data, tmp);
                    strcpy (tmp, "");

                }
            return;
        }

        else if (ch == 'Y') {

            if (node->right != nullptr) {
                add_node (node->right);
                return;
            }
            else {
                txSpeak ("\vPOBEDA\n");
                return;
            }
        }

        else {
            puts ("NOT RIGHT SYMBOL");
        }
    }
        
}


void srav (my_stack *stk1, my_stack *stk2, char *obj1, char *obj2, node* node) {

    assert (stk1 != nullptr);
    assert (stk2 != nullptr);
    assert (obj1 != nullptr);
    assert (obj2 != nullptr);
    assert (node != nullptr);

    int ar1[stk1->size_stack] = {};
    int ar2[stk2->size_stack] = {};

    for (int i = 0; i < stk1->size_stack - 1; ++i) {

        for (int j = 0; j < stk2->size_stack - 1; ++j) {
            if (*(stk1->arr + i) == *(stk2->arr + j) && *(stk1->arr + i + 1) == *(stk2->arr + j + 1)) {
                ar1[i] = 1;
                ar2[j] = 1;
                break;
            }
        }
    }

    printf ("%s and %s similar: ", obj1, obj2);

    for (int i = 0; i < stk1->size_stack - 1; ++i) {

        if (ar1[i] == 1) {
         
            if ((*(stk1->arr + i))->left == *(stk1->arr + i + 1))
                printf ("NE_%s ", (*(stk1->arr + i))->data);
            else
                printf ("%s ", (*(stk1->arr + i))->data);
        
        }
    }
    puts ("\n");
    
    printf ("%s and %s are not similar cause", obj1, obj2);
    puts ("\n");

    printf ("%s === ", obj1);
    for (int i = 0; i < stk1->size_stack - 1; ++i) {

        if (ar1[i] == 0) {
         
            if ((*(stk1->arr + i))->left == *(stk1->arr + i + 1))
                printf ("NE_%s ", (*(stk1->arr + i))->data);
            else
                printf ("%s ", (*(stk1->arr + i))->data);
        
        }
    }
    puts ("\n");

    printf ("%s === ", obj2);
    for (int i = 0; i < stk2->size_stack - 1; ++i) {

        if (ar2[i] == 0) {
         
            if ((*(stk2->arr + i))->left == *(stk2->arr + i + 1))
                printf ("NE_%s ", (*(stk2->arr + i))->data);
            else
                printf ("%s ", (*(stk2->arr + i))->data);
        
        }
    }
    puts ("\n");
    return;   
}


void graph (node* head) {

    assert (head != nullptr);

    FILE *out = fopen ("demo.txt", "wb");
    assert (out != nullptr);

    fputs ("digraph structs {\n", out);
    //fputs ("node [shape=record];\n", out);
    fputs ("node [style=filled,color=\"hotpink\"];\n", out);
    in_order_graph (head, out);
    fputs ("}", out);

    fclose (out);

    system (".\\graphviz\\bin\\dot -Tpng demo.txt -o graph.png");

    system ("graph.png");


    return;
}


static void in_order_graph (node *node, FILE *out) {
    
    assert (node != nullptr);
    assert (out  != nullptr);

    if (node->left != nullptr) {
        fprintf (out, "\"%s\" -> \"%s\" [label=N];\n", node->data, node->left->data);
        in_order_graph (node->left, out);
    }

    if (node->right != nullptr) {
        fprintf (out, "\"%s\" -> \"%s\" [label=Y];\n", node->data, node->right->data);
        in_order_graph (node->right, out);
    }
    
    if (node->left == nullptr && node->right == nullptr) {
        fprintf (out, "\"%s\";\n", node->data);
    }
    return;
}


void ctor (node *head) {

    assert (head != nullptr);

    (head)->left  = nullptr;
    (head)->right = nullptr;

    strcpy ((head)->data, "NOONE");

    return;
}

static size_t FILESIZE_FUNC_FSTAT (FILE *in) {

    assert (in != nullptr);

    struct stat buff = {};
    fstat (fileno (in), &buff);

    return buff.st_size;
}