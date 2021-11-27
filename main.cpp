#include "list_func.h"
                                        //TO DO 27.11                                                            
                                                //1)SPEAK
                                        //2)RUSSIAN (wchar_t)
                                        //3)obrabotka multiple words (fwrite, fgets)
size_t EXIT_COND = 0;

int main (void) {
    
    setlocale (LC_ALL, "Russian");

    FILE *cleaner = fopen ("DUMP", "w");
    fclose (cleaner);

    node *node = nullptr;
    
    while (1) {
        
        txSpeak ("\vбшанп лндю:\n" 
        "1)ббнд депебю хг тюикю\n"
        "2)янгдюрэ ябн╗ депебн\n");
        $
        
        if (ch == '1') {
            
            struct node *head = nullptr;
            
            FILE *in = fopen ("tree.txt", "rb");
            get_tree_from_file (&head, in);
            fclose (in);
            graph (head);

            FILE *out = fopen ("test.txt", "w");
            print_tree (head, out);
            fclose (out);

            node = head;

            break;
        }
        
        else if (ch == '2') {
            struct node head = {};

            ctor (&head);


            while (1) {
                
                add_node (&head); 

                graph (&head);

                txSpeak ("\vопнднфхл?\tY/N");
                $      
                if (ch == 'N')
                    break;
            }

            FILE *out = fopen ("tree.txt", "w");
            print_tree (&head, out);
            fclose (out);

            node = &head;

            break;
        }

    }
    

        txSpeak ("\vбшанп пефхлю хцпш\n"
        "1)юйхмюрнп\n"
        "2)япюбмемхе дбсу\n"
        "3)уюпюйрепхярхйю\n");

        $
        switch (ch) {

            case ('0' + AKINATOR): {

                while (1) {
                    
                    add_node (node); 

                    graph (node);
                    
                    FILE *out = fopen ("tree.txt", "w");
                    print_tree (node, out);
                    fclose (out);
            
                    txSpeak ("\vопнднкфхл?\tY/N\n");
                    $      
                    if (ch == 'N')
                        break;
                }
            break;
            }
            
            case ('0' + COMPARE): {
                
                
                txSpeak ("\vббедхре хлемю 2 назейрнб\n");

                char obj1 [20] = {};
                char obj2 [20] = {};
                
                my_stack stk1 = {};  
                constructor (&stk1, 30);
              
                my_stack stk2 = {};                
                constructor (&stk2, 30);
   
                scanf (" %s", obj1);
                scanf (" %s", obj2);
                puts ("===============");
                
                find_obj_in_tree (node, obj1, &stk1);
                characteristic_print (node, obj1 ,&stk1);

                find_obj_in_tree (node, obj2, &stk2);
                characteristic_print (node, obj2, &stk2);

                srav (&stk1, &stk2, obj1, obj2, node);
                
            break;
            }
            
            case ('0' + CHARACTERISTIC): {

                txSpeak ("\vббедхре хлъ назейрю\n");

                char obj [20] = {};
                scanf (" %s", obj);
                puts ("===============");

                my_stack stk = {};
                constructor (&stk, 30);

                find_obj_in_tree     (node, obj, &stk);
                characteristic_print (node, obj, &stk);
                
            break;
            }

            default: {
                break;
            }
        }

    return 0;
}
