#include <core32.h>

void Program(Task_t* task)
{
    Task_Switch(task)
    {
      case TASK_START:
      {
        ADC_SetDigital(PINS_ALL);
        Console_WriteLine("Hello world");
      }
      break;
      
      case TASK_IDLE:
      {
        Console_WriteLine("Ping!");
        Task_SleepMs(task, 1000);
      }
      break;
    }
}
