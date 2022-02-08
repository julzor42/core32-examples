#include <core32.h>

// Some LEDs are not connected to the MCU (RB13, RB12, RB11, RD15, RD11, ...)

void InitializePort(volatile Port_t* port)
{
  GPIO_SetOutput(port, PINS_ALL);
  GPIO_ClearBits(port, PINS_ALL);
}

void Program(Task_t* task)
{
    Task_Switch(task)
    {
      case TASK_START:
      {
        ADC_SetDigital(PINS_ALL);
        InitializePort(PortA);
        InitializePort(PortB);
        InitializePort(PortC);
        InitializePort(PortD);
        InitializePort(PortF);
        InitializePort(PortG);
      }
      break;
      
      case TASK_IDLE:
      {
        GPIO_ToggleBits(PortA, PINS_ALL);
        GPIO_ToggleBits(PortB, PINS_ALL);
        GPIO_ToggleBits(PortC, PINS_ALL);
        GPIO_ToggleBits(PortD, PINS_ALL);
        GPIO_ToggleBits(PortF, PINS_ALL);
        GPIO_ToggleBits(PortG, PINS_ALL);

        Task_SleepMs(task, 200);
      }
      break;
    }
}
