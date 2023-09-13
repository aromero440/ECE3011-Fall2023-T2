#ifndef GLOBALS_H
#define GLOBALS_H

/* Holds all the information for a problem*/
typedef struct _problem {
    int arg1;
    int arg2;
    int correctAnswer;
} problem;

/**
 * @brief Describes which grade difficulty
 */
enum Grade
{
    Kindergarden, First, Second, Third, Fourth, Fifth
};

#endif // GLOBALS_H