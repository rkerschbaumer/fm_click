#ifndef OLED_TASK_H_
#define OLED_TASK_H_

#include"mb.h"
#include"reg.h"

/*! \fn oled_command
 *  \brief writes index register and value
 *
 *  The function awaits a register_index and a register value (0/1) to write.
 *
 *  \param reg_index the index in the register to write to
 *  \param reg_value the value to write to the regsiter, awaits 0 or 1.
 */
void oled_command(unsigned char reg, unsigned char value);

/*! \fn oled_init
 *  \brief Function to initialize the Oled Display.
 *
 *  Sends register values to configure the Display, like for example row_scan_mode
 */
void oled_init(void);

/*! \fn DDRAM_access
 *  \brief set next register to write to DDRAM
 *
 *  Function that sets next register to write to DDRAM. Here are the pixel information in there.
 *  Colorinformation for the pixel. e.g. 5bit 6 bit 4bit
 */
void DDRAM_access(void);

/*! \fn OLED_C_MermorySize
 *  \brief send information what to write to display
 *
 *  The function sends a square with the x and y information, what is to write to the display. building the pixel -> letter
 *
 *  \param char X1 x coordinate
 *  \param char X2 x coordinate
 *  \param char Y1 y coordinate
 *  \param char Y2 y coordinate
 */
void OLED_C_MemorySize(char X1, char X2, char Y1, char Y2);

/*! \fn oled_data
 *  \brief sends data to write
 *
 *  Function sends data to write via SPI to the Oled Display
 *  the function awaits data in form of a bitstream?
 *
 *	\param uint16_t data the data that is sent to the display
 */
void oled_data(uint16_t data);

/*! \fn Oled_C_Beckground
 *  \brief Sets Backgroundcolor and paints it
 *
 *  This function provides the background for the Oled Display.
 */
void OLED_C_Beckground(void);

/*! \fn buchstabensuppe
 *  \brief Sets Backgroundcolor and paints it
 *
 *  write to DDRAM with the last set memory size. loop in loop. 2 dimensional array,
 *  one runs down, one to the side, so that every pixel gets written (char to draw is parameter i get), 14=x -> font size
 *
 *	\param uint8_t x_coordinate value of the x coordinate
 *	\param uint8_t y_coordinate value of the y coordinate
 *	\param uint8_t font_width value of the font width
 *	\param uint8_t font_height value of the font height
 *	\param uint16_t font_color
 *	\param uint16_t background_color
 */
void buchstabensuppe(uint8_t x_coordinate, uint8_t y_coordinate, uint8_t font_width, uint8_t font_height, uint16_t font_color, uint16_t background_color, char char_to_draw);

/*! \fn setup_oled_task
 *  \brief sets up a task
 *
 *  This function creates a task with all of its necessary information such as task params, task handle, priority of the task...
 *
 *
 *	\param enum mb_type type of the messagebox. either frequency, volume or mode.
 *	\param int prio priority of the task
 *	\param xdc_String name
 */
void setup_oled_task(enum mb_type x, int prio, xdc_String name);

/*! \fn oled_function
 *  \brief prints selected function to display
 *
 *  This function prints the given parameters to the display. When the user switches the mb_function. the display is updated with the
 *  changed parameters.
 *
 *
 *	\param UArg arg0
 */
void oled_function(UArg arg0);

/*! \fn spi_write
 *  \brief writes data to spi
 *
 *  writes data to the SPI bus.
 *
 *
 *	\param uint16_t data data to write to the SPI bus
 */
void spi_write(uint16_t data);

/*! \fn to_string
 *  \brief converts
 *
 *  This function prints the given parameters to the display. When the user switches the mb_function. the display is updated with the
 *  changed parameters.
 *
 *
 *	\param uint16_t precomma
 *	\param uint8_t postcomma
 *	\param char* buffer buffer for the string
 *	\param enum mb_type mailbox type
 */
void to_string(uint16_t precomma, uint8_t postcomma, char* buffer, enum mb_type x);

#endif /* OLED_TASK_H_ */
