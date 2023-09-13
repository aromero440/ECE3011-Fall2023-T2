/* Generates the problem given a specific grade level */

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

/**
 * @brief Returns a problem for a specific gradde
 * 
 * @param grade the level of difficulty for the problem
 * @return problem the specific problem
 */
problem generateProblem(Grade grade);