/* Generates the problem given a specific grade level */

#include "globals.h"

#ifndef GENPROBLEM_H
#define GENPROBLEM_H

/**
 * @brief Returns a problem for a specific gradde
 * 
 * @param grade the level of difficulty for the problem
 * @return problem the specific problem
 */
problem generateProblem(Grade grade);

#endif