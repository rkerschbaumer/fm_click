/*
 * mb.h
 *
 *  Created on: Jan 18, 2017
 *      Author: raphael
 */

#ifndef MB_H_
#define MB_H_

#include <stdbool.h>
#include <stdint.h>

enum mb_type{ frq, vol, mode };

/*! \fn setup_mb
 *  \brief Setup Mailboxes
 *
 *  Setup all mailboxes
 *  initialize config for the frequency, volume and mode mailboxes
 *
 *  \return always zero. In case of error the system halts.
 */
int setup_mb(void);

/*! \fn pend_mb
 *  \brief wrapper for MailboxPend
 *
 *  blocks a task until a value is stored in the mailbox
 *
 *  \param output pointer to where the pending parameter is stored
 *  \param x verifies for which mailbox to wait
 */
void pend_mb(uint16_t* output, enum mb_type x);

/*! \fn post_mb
 *  \brief wrapper for MailboxPost
 *
 *  stores a value in the mailbox
 *
 *  \param value value which is stored in the mailbox
 *  \param x verifies in which mailbox to post
 */
void post_mb(uint16_t value, enum mb_type x);

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


#endif /* MB_H_ */
