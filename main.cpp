#include "list_func.h"
                                        //TO DO 22.11
                                        //1)доделать построение дерева по вопросам
                                        //2)считывание дерева и его печатание файл
                                        //3)сделать доп режимы
int main (void) {

    node head = {};

    ctor (&head);

    //graph (&head);

    while (1) {
        
        add_node (&head); 
        // node *tmp = &head;
        // puts (tmp->data);

        graph (&head);

        puts ("CONTINUE? Y/N");
        char ch = 1;
        scanf (" %c", &ch);
        
        if (ch == 'N')
            break;
    }

    puts ("ALL GOOD PROGRAM END");
    return 0;
}
