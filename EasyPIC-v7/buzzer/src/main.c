#include <core32.h>

#define F(x) (1000000 / (x))

int currentFreqId = 0;
int freqs[] = {440, 494, 523, 587, 659, 698, 783, 880, 987, 1046, 1174};
int nFreq = 0;

void Buzz(Task_t* task)
{
  Task_Switch(task)
  {
    case TASK_START:
      GPIO_SetOutput(PortD, PIN_3);
      GPIO_ClearBits(PortD, PIN_3);
    break;

    case TASK_IDLE:
      // Toggle the buzzer's bit
      GPIO_ToggleBits(PortD, PIN_3);
      Task_Sleep(task, nFreq);
    break;
  }
}

void Program(Task_t* task)
{
    Task_Switch(task)
    {
      case TASK_START:
      {
        ADC_SetDigital(PINS_ALL);
        GPIO_SetOutput(PortA, PINS_ALL);

        nFreq = freqs[0];
        Task_Create(Buzz, NULL);
      }
      break;
      
      case TASK_IDLE:
      {
        // Move on to the next frequency
        currentFreqId++;
        currentFreqId = currentFreqId % sizeof(freqs) / sizeof(freqs[0]);
        nFreq = F(freqs[currentFreqId]);

        // Toggle some leds
        GPIO_ToggleBits(PortA, PINS_ALL);

        Task_SleepMs(task, 200);
      }
      break;
    }
}
