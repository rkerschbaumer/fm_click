/*
 * test_task.h
 *
 *  Created on: 19. J�n. 2017
 *      Author: Raphael
 */

#ifndef TEST_TASK_H_
#define TEST_TASK_H_

#include <stdbool.h>
#include <stdint.h>
#include "xdc/std.h"

/*! \fn make_frequency_comma_again
 *  \brief splits the frequency to a comma value in MHz
 *
 *  parses the frequency (in 100kHz) to a pre- and postcomma value which gives the value in MHz
 *
 *  \param input is the 100kHz value
 *  \param precomma a pointer to where the precomma value is stored
 *  \param postcomma a pointer to where the postcomma value is stored
 */
void make_frequency_comma_again(uint16_t input, uint16_t* precomma, uint8_t* postcomma);

/*! \fn test_function
 *  \brief Execute test task
 */
void test_function(void);

/*! \fn setup_test_Task
 *  \brief Setup Test task
 *
 *  Setup Test task
 *
 *  \return always zero. In case of error the system halts.
 */
int setup_test_task(void);


#endif /* TEST_TASK_H_ */
