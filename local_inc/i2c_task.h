/*
 * i2c_task.h
 *
 *  Created on: 07. J�n. 2017
 *      Author: Raphael
 */

#ifndef I2C_TASK_H_
#define I2C_TASK_H_

#include <stdbool.h>
#include <stdint.h>
#include "xdc/std.h"

/*! \fn i2c_task_fct
 *  \brief Execute i2c Task
 */
void i2c_task_fct(void);

/*! \fn setup_i2c_task
 *  \brief Setup i2c task
 *
 *  Setup i2c task
 *
 *  \param prio the priority of the task
 *  \param name the name of the task
 *
 *  \return always zero. In case of error the system halts.
 */
int setup_i2c_task(int prio, xdc_String name);

/*! \fn modify_shadow_reg
 *  \brief modifies the shadow register
 *
 *  Modifies bits of the shadow register with either setting or resetting specified bits
 *
 *  \param reg_addr the address of the register to modify
 *  \param reg_hi_val bitmask for bits to set/unset in the higher register addresses
 *  \param reg_lo_val bitmask for bits to set/unset in the lower register addresses
 *  \param set_reset defines to set or reset the specified bits in reg_hi_val and reg_lo_val
 */
void modify_shadow_reg(uint8_t reg_addr, uint8_t reg_hi_val, uint8_t reg_lo_val, uint8_t set_reset);

/*! \fn read_register
 *  \brief reads all the registers from the FM module
 */
void read_register(void);

/*! \fn write_register
 *  \brief writes into register of board
 *
 *  Register could not be written separately,
 *  therefore we need to write all registers up to the one we actually want to modify
 *
 *  \param reg_addr writes until the end of the given register address
 */
void write_register(uint8_t reg_addr);

/*! \fn init_i2c_fm
 *  \brief sets all the needed register of the FM module that it is up and running
 */
void init_i2c_fm(void);

/*! \fn frequency_change
 *  \brief changes frequency
 *
 *  increments/decrements, depending on the direction, the current frequency
 *
 *  \param direction change frequency in UP or DOWN direction
 */
void frequency_change(uint8_t direction);

/*! \fn fm_tune
 *  \brief tunes the module to the given frequency
 *
 *  \param frequ given frequency which should be configured on the module
 */
void fm_tune(uint16_t frequ);

/*! \fn fm_seek
 *  \brief starts the seek-procedure
 *
 *  \param direction change seek-bit in UP or DOWN direction
 */
void fm_seek(uint8_t direction);

/*! \fn change_volume
 *  \brief changes volume
 *
 *  increments/decrements, depending on the direction, the current volume
 *
 *  \param direction change the volume UP or DOWN
 */
void change_volume(uint8_t direction);

/*! \fn do_favourites_stuff
 *  \brief saves and selects a channel as favorite
 *
 *  \param mode either FAV_SAVE to save the current frequency or FAV_SELECT to select between the saved favorites
 */
void do_favourites_stuff(uint8_t mode);

/*! \fn set_led_on
 *  \brief sets and resets LEDs (D1 - D4), depending on the current mode
 *
 *  \param ledval specifies which leds should be turned on and which should be turned off
 */
void set_led_on(uint8_t ledval);

#endif /* I2C_TASK_H_ */
