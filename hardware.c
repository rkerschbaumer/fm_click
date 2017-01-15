#include <stdbool.h>
#include <stdint.h>
#include <driverlib/gpio.h>
#include <driverlib/pin_map.h>
#include <driverlib/sysctl.h>
#include <inc/hw_memmap.h>



#include"hardware.h"

/* set GP1 = PC6 to 1, set RST = PC7 to 0 */
void fm_busmode_selection(void){
    uint32_t ui32Strength;
    uint32_t ui32PinType;

    uint32_t ui32_intStr_in;
    uint32_t ui32_intPinType_in;


    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC); //RST=PIN7 & GP1=PIN6
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOH); //SEN=PIN2
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD); //CLK=PIN0 & SDIO=PIN1
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOJ); //US1=PIN0

    GPIOPadConfigGet(GPIO_PORTJ_BASE, GPIO_PIN_0|GPIO_PIN_1, &ui32_intStr_in, &ui32_intPinType_in);
    GPIOPadConfigSet(GPIO_PORTJ_BASE, GPIO_PIN_0|GPIO_PIN_1, ui32_intStr_in, GPIO_PIN_TYPE_STD_WPU);
    GPIODirModeSet(GPIO_PORTJ_BASE, GPIO_PIN_0|GPIO_PIN_1,GPIO_DIR_MODE_IN);


    GPIOPadConfigGet(GPIO_PORTC_BASE, GPIO_PIN_7, &ui32Strength, &ui32PinType);
    GPIOPadConfigSet(GPIO_PORTC_BASE, GPIO_PIN_7,ui32Strength,GPIO_PIN_TYPE_STD);

//    GPIOPadConfigGet(GPIO_PORTC_BASE, GPIO_PIN_6, &ui32Strength, &ui32PinType);
//    GPIOPadConfigSet(GPIO_PORTC_BASE, GPIO_PIN_6,ui32Strength,GPIO_PIN_TYPE_STD);

    GPIOPadConfigGet(GPIO_PORTH_BASE, GPIO_PIN_2, &ui32Strength, &ui32PinType);
    GPIOPadConfigSet(GPIO_PORTH_BASE, GPIO_PIN_2,ui32Strength,GPIO_PIN_TYPE_STD);

    GPIOPadConfigGet(GPIO_PORTD_BASE, GPIO_PIN_1, &ui32Strength, &ui32PinType);
    GPIOPadConfigSet(GPIO_PORTD_BASE, GPIO_PIN_1,ui32Strength,GPIO_PIN_TYPE_STD);

    GPIOPadConfigGet(GPIO_PORTD_BASE, GPIO_PIN_0, &ui32Strength, &ui32PinType);
    GPIOPadConfigSet(GPIO_PORTD_BASE, GPIO_PIN_0,ui32Strength,GPIO_PIN_TYPE_STD);

    GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE,GPIO_PIN_7);
//    GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE,GPIO_PIN_6);
    GPIOPinTypeGPIOOutput(GPIO_PORTH_BASE,GPIO_PIN_2);
    GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE,GPIO_PIN_1);
    GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE,GPIO_PIN_0);



    /* write on the specified pins */
//    GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_2, 0x04);
//    GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 0x01);
    GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_2, 0xFF);
    GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 0xFF);
    GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, 0x00);
//   GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 0x40);
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 0x00);

    SysCtlDelay(100000);

//    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 0x80);
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 0xFF);
}