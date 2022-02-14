#include <core32.h>
#include <tasks/console.h>

void Program(Task_t* task)
{
    Task_Switch(task)
    {
      case TASK_START:
      {
        Console_Attach(EPF7_UART_A, ConsoleHandler, &console);
      }
      break;
      
      case TASK_IDLE:
      {
        Task_SleepMs(task, 1000);
      }
      break;
    }
}
