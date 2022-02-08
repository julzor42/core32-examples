#include <core32.h>
#include <il9341/il9341.h>

void Program(Task_t* task)
{
        TFT_Initialize();

                TFT_SetAddress(10, 10);
        TFT_Begin();

        for (int i = 0; i < 100; i++)
          TFT_RawShortRev(0xff00);

        TFT_End();

        while(1);

    Task_Switch(task)
    {
      case TASK_START:
      {
        TFT_Initialize();
      }
      break;
      
      case TASK_IDLE:
      {
        TFT_SetAddress(10, 10);
        TFT_Begin();

        for (int i = 0; i < 100; i++)
          TFT_RawShortRev(0xff00);

        TFT_End();
          
        Task_SleepMs(task, 500);
      }
      break;
    }
}
