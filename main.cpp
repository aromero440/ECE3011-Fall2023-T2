/* Main file to control all robot functionality */

#include "genProblem.h"
#include "hardware.h"
#include "globals.h"
#include "test.cpp"

#define DEBUG 0

using namespace std;

int main(int argc, char const *argv[])
{
    //initialize all hardware

    /* Mainloop 
    
    */

    #if DEBUG == 1
        testGenProblem();
    #endif // DEBUG

    return 0;
}