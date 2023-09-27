#ifndef GLOBALS_H
#define GLOBALS_H

/* Holds all the information for a problem*/
typedef struct _problem {
    int arg1;
    int operation;
    int arg2;
    int result;
} problem;

/**
 * @brief Describes which grade difficulty
 */
enum Grade
{
    Kindergarden, First, Second, Third, Fourth, Fifth
};

#define ADDITION 0
#define SUBTRACTION 1
#define MULTIPLICATION 2
#define DIVISION 3

#define CALCFORRESULT 0
#define CALCFOROPERAND 1

#endif // GLOBALS_H