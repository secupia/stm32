/*
 * button.h
 *
 *  Created on: 2018. 5. 15.
 *      Author: Baram
 */

#ifndef SRC_HW_CORE_BUTTON_H_
#define SRC_HW_CORE_BUTTON_H_

#include "hw_def.h"


void buttonInit(void);

bool buttonGetPressed(uint8_t ch);


#endif /* SRC_HW_CORE_BUTTON_H_ */
