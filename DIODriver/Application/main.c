#include "Std_types.h"
#include "Bit_Math.h"
#include "TM4C123GH6PM_HW.h"
#include "PORT.h"
#include "DIO.h"

int main()
{
  Port_Init(); 
DIO_uint8WritePort(DIO_PORTF,0xffffffff);
uint32 portValue = DIO_uint8ReadPort(DIO_PORTF); 
}
