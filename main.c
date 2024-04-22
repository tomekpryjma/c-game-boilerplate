#include "core/core.h"

int main()
{
    Core core = Core_Init();
    Core_Loop(&core);
    Core_Down(&core);
    return 0;
}