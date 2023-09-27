/* Generates the problem given a specific grade level */

#include "globals.h"
#include <string>

#ifndef GENPROBLEM_H
#define GENPROBLEM_H

/**
 * @brief Returns a problem for a specific gradde
 * 
 * @param grade the level of difficulty for the problem
 * @return problem the specific problem
 */
problem generateProblem(Grade grade);

/**
 * @brief Generates a random number
 * 
 * @param low lower bound inclusive
 * @param high upper bound inclusive
 * @return int random number
 */
int randomInt(int low, int high);

/**
 * @brief Converts the problem structure into a string
 * 
 * @param prob problem to convert
 * @return string problem formatted
 */
std::string probToString(problem prob);

#endif