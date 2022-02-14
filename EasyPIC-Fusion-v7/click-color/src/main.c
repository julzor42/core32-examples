#include <core32.h>
#include <tcs3471/tcs3471.h>

#define RED _LATB8
#define GREEN _LATC2
#define BLUE _LATD0

#define TRIS_RED    _TRISB8
#define TRIS_GREEN  _TRISC2
#define TRIS_BLUE   _TRISD0

int nColor = 0;
__TCS3471_BUFFER tcsBuffer;

void Program(Task_t* task)
{
    Task_Switch(task)
    {
      case TASK_START:
      {
        TCS3471_Initialize(I2C_2, 0);

        TRIS_RED    = 0;
        TRIS_GREEN  = 0;
        TRIS_BLUE   = 0;
      }
      break;
      
      case TASK_IDLE:
      {
        nColor++;
        if (nColor > 7)
          nColor = 1;

        RED   =   HAS_BITS(nColor, 1);
        GREEN =   HAS_BITS(nColor, 2);
        BLUE  =   HAS_BITS(nColor, 4);

        TCS3471_Read(I2C_2, tcsBuffer);
        
        Task_SleepMs(task, 200);
      }
      break;
    }
}
