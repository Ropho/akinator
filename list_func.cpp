#include "list_func.h"


void in_order_print (node *node, FILE *out) {
    
    assert (node != nullptr);
    assert (out != nullptr);

    if (node->left != nullptr) {
        
        fprintf (out, "%s -> %s [label=N];\n", node->data, node->left->data);
        in_order_print (node->left, out);
    }

    if (node->right != nullptr) {

        //puts (node->data);
        fprintf (out, "%s -> %s [label=Y];\n", node->data, node->right->data);
        in_order_print (node->right, out);
    }
    
    if (node->left == nullptr && node->right == nullptr) {
        fprintf (out, "%s;\n", node->data);
    }
    return;
}

void graph (node* head) {

    assert (head != nullptr);
    FILE *out = fopen ("demo.txt", "wb"); //Я УСТАЛ!!!!!!!!!!!!!!!!!!!

    assert (out != nullptr);

    fputs ("digraph structs {\n", out);
    //fputs ("node [shape=record];\n", out);
    fputs ("node [style=filled,color=\"hotpink\"];\n", out);
    in_order_print (head, out);
    
    fputs ("}", out);

    fclose (out);

    system (".\\graphviz\\bin\\dot -Tpng demo.txt -o graph.png");

    system ("graph.png");


    return;
}

void ctor (node *head) {

    assert (head != nullptr);

    (head)->left = nullptr;

    (head)->right = nullptr;

    strcpy ((head)->data, "NOONE");

    return;
}

void add_node (node *node) {

    assert (node != nullptr);

        printf ("%s?", node->data);
        puts ("\nY/N?");

        char ch = 0;
        scanf (" %c", &ch);
        
        if (ch == 'N') {

            if (node->left != nullptr) {

                add_node (node->left);
                return;
            }
            else {
                    char tmp[20] = {};
                    strcpy (tmp, node->data);

                    node->right = (struct node*)calloc(1, sizeof (struct node));
                    node->left = (struct node*)calloc(1, sizeof (struct node));

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

                    // puts (node->data);
                    // puts (node->right->data);
                    // puts (node->left->data);
                }
            return;
            
        }
        else if (ch == 'Y') {

            if (node->right != nullptr) {
                add_node (node->right);
                return;
            }
            else {
                puts ("POBEDA\n");
                return;
            }

        }
        else {
            puts ("NOT RIGHT SYMBOL");
            add_node (node);
            return;
        }
        
}