#include "spin.h"
#include "calculateWinnings_Unit_Test.h"
#include "spin_Unit_Tests.h"
#include "startSpinModule_Unit_Tests.h"
#include <time.h>

int main() {
    srand((unsigned int)time(NULL));
    
    simulateStartSpinModule();
    testSpin1();
    testCalculateWinnings();
    
    return 0;
}