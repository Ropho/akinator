#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#define NDEBUG
//#define D_1
//#define D_2                   //uslovnaya compilyatsya
//#define D_3

// TO DO
// 1) Умное выделение памяти реалоком (если выдает нулл, то просить меньше)
// 2) Сделать побайтовый хэш (принимает void*)
// 3) Возможность всех типов
// 4) переименовать названия условной компиляции

#include "stdio.h"
#include "malloc.h"
#include "assert.h"
#include "string.h"

#define kotik(out) fprintf(out, "\
                  　　　　　／＞　 フ   \n\
　　                　　　 | 　_　 _|   \n\
　 　　                 　／`ミ _x 彡   \n\
                　　 　 /　　　 　 |    \n\
                　　　 /　 ヽ　　 ﾉ     \n\
                　／￣|　　 |　|　|     \n\
                　| (￣ヽ＿_ヽ_)_)      \n\
                　＼二つ                \n\
                DEAD INSIDE 1000-7     \n\n");


#ifndef NDEBUG
    #define alive 0xDEAD
    #define EX_VER  {if (EXIT_COND) {printf ("u've been crashed (%x)", alive); return 0;}}
#endif

#ifndef tree
#define tree
    typedef struct node {

        char data[20] = {};

        node *left = nullptr;

        node *right = nullptr;

    }node;
#endif

#define stack_t node*

const int SIZE_CONSTRUCTOR = 20;
const size_t MULTIPLIER = 2;
const size_t DIVISOR = 3;
#define MUSOR 0


enum ERRORS {

    NO_ERROR                 = 0,
    MEMMORY_ALLOCATION_ERROR = 1,
    STACK_OVERFLOW           = 2,
    STACK_UNDERFLOW          = 3,
    NAS_VZLOMALI             = 4
};


typedef struct my_stack {

// #if (DEBUG_LEVEL >= 2)

#if defined D_2 || defined D_3
    long long left_canary;
#endif

    int size_array;
    int    size_stack;
    stack_t   *arr;

    bool find = 0;  //можно сделать структуры стека и bool find (EZ)

#ifndef NDEBUG
    int error;
    char stack_name[10];
    char func_name[10];
    char file_name[20];
    int  line;
#endif


#ifdef D_3
    long long hash;
#endif

#if defined D_2 || defined D_3
    long long right_canary;
#endif
} my_stack;



void cur_inf (my_stack *head, const int line, const char *func, const char *file);

void constructor (my_stack *head, int size_array);

void delete_stack (my_stack **head);

static void destructor (my_stack *head);

void push (my_stack *head, stack_t value);

stack_t pop (my_stack *head);

static void verificator (my_stack *head);

static void dump (my_stack *head);

long long hash_calc (my_stack *head);

#endif // FUNCTIONS_H_INCLUDED