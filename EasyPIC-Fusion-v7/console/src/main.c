#include <core32.h>
#include <tasks/console.h>

Console_t console;

void ConsoleHandler(const char* s, uint32_t len)
{
  Console_Write("Recv: ");
  Console_WriteLine(s);
}

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
