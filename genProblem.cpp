#include "globals.h"

int randomInt(int low, int high) {
    randomSeed(analogRead(6));
    int num = random(low, high + 1);
    return num;
}

problem generateProblem(Grade grade) {
    // determine the lowerbound and upperbound of the operators, and the operator
    int op1 = 0, op2 = 0;
    int operation = ADDITION;
    int result = 0;

    switch (grade) {
    case Kindergarden:
        // Addition or subtraction
        // Within 0-10
        operation = randomInt(ADDITION, SUBTRACTION);
        op1 = randomInt(0, 9);
        op2 = randomInt(0, 9 - op1);
        if (operation == ADDITION) {
                result = op1 + op2;
            } else {
                if (op2 > op1) {
                    // swap subtraction to first operand to ensure no negative
                    int temp = op1;
                    op1 = op2;
                    op2 = temp;
                }
                result = op1 - op2;
            }
        break;
    case First:
        // Addition or subtraction
        // Within 0-20
        operation = randomInt(ADDITION, SUBTRACTION);
        op1 = randomInt(0, 9);
        op2 = randomInt(0, 9 - op1);
        if (operation == ADDITION) {
                result = op1 + op2;
            } else {
                if (op2 > op1) {
                    // swap subtraction to first operand to ensure no negative
                    int temp = op1;
                    op1 = op2;
                    op2 = temp;
                }
                result = op1 - op2;
            }
        break;
    case Second:
        // Addition or subtraction
        // Within 0-39 (max our board can do)
        operation = randomInt(ADDITION, MULTIPLICATION);
        if (operation == MULTIPLICATION) {
            op1 = randomInt(0,3);
            op2 = op1;
            result = op1 * op1;
            break;
        }
        op1 = randomInt(0, 9);
        op2 = randomInt(0, 9 - op1);
        if (operation == ADDITION) {
                result = op1 + op2;
        } else {
            if (op2 > op1) {
                // swap subtraction to first operand to ensure no negative
                int temp = op1;
                op1 = op2;
                op2 = temp;
            }
            result = op1 - op2;
        } 
        break;
    case Third:
        operation = randomInt(ADDITION, MULTIPLICATION);
        if (operation == MULTIPLICATION) {
            op1 = randomInt(0, 4);
            op2 = 0;
            do {
                op2 = randomInt(0, 4);
            } while (op1 * op2 >= 10);
            result = op1 * op2;
        } else {
            op1 = randomInt(0, 9);
            op2 = randomInt(0, 9 - op1);
            if (operation == ADDITION) {
                result = op1 + op2;
            } else {
                if (op2 > op1) {
                    // swap subtraction to first operand to ensure no negative
                    int temp = op1;
                    op1 = op2;
                    op2 = temp;
                }
                result = op1 - op2;
            }
        }
        break;
    default:
        // nothing, default problem already set to: 0 + 0 = 0
        break;
    }

    problem prob = {op1, operation, op2, result};
    return prob;
}

String probToString(problem prob) {
    String operation_s, op1_s, op2_s, result_s;

    op1_s = String(prob.arg1);
    op2_s = String(prob.arg2);
    result_s = String(prob.result);

    switch (prob.operation) {
    case ADDITION:
        operation_s = "+";
        break;
    case SUBTRACTION:
        operation_s = "-";
        break;
    case MULTIPLICATION:
        operation_s = "x";
        break;
    case DIVISION:
        operation_s = "÷";
        break;
    default:
        operation_s = "ERROR";
        break;
    }
    String out = "" + op1_s + operation_s + op2_s + "= _?";
    return out;
}

Grade cycleGrade(Grade g) {
  switch (g) {
    case Init:
      return Kindergarden;
    case Kindergarden:
        return First;
    case First:
        return Second;
    case Second:
        return Third;
    case Third:
        return Kindergarden;
        break;
    default:
        return Init;
        break;
  }
}

String currGradeToString(Grade g) {
  switch (g) {
    case Kindergarden:
      return "Kinder";
    case First:
      return "First";
    case Second:
      return "Second";
    case Third:
      return "Third";
    default:
      return "";
  }
}
