/*
 * qbuffer.h
 *
<<<<<<< HEAD
 *  Created on: 2019. 9. 11.
 *      Author: Marshall
=======
 *  Created on: 2018. 5. 19.
 *      Author: Baram
>>>>>>> af0767fca0f1972362e5186eb10742e60df9d092
 */

#ifndef SRC_COMMON_CORE_QBUFFER_H_
#define SRC_COMMON_CORE_QBUFFER_H_

<<<<<<< HEAD
#include "def.h"

typedef struct
{
  uint32_t ptr_in;
  uint32_t ptr_out;
  uint32_t length;
  uint8_t *p_buf;
}qbuffer_t;

void qbufferInit(void);

bool  qbufferCreate(qbuffer_t *p_node, uint8_t *p_buf, uint32_t length);
bool  qbufferWrite(qbuffer_t *p_node, uint8_t *p_data, uint32_t length);
bool  qbufferRead(qbuffer_t *p_node, uint8_t *p_data, uint32_t length);
uint32_t qbufferAvailable(qbuffer_t *p_node);
void  qbufferFlush(qbuffer_t *p_node);
=======

#include "def.h"


typedef struct
{
  uint32_t   ptr_in;
  uint32_t   ptr_out;
  uint32_t   length;
  uint8_t   *p_buf;
} qbuffer_t;


void qbufferInit(void);

bool     qbufferCreate(qbuffer_t *p_node, uint8_t *p_buf, uint32_t length);
bool     qbufferWrite(qbuffer_t *p_node, uint8_t *p_data, uint32_t length);
bool     qbufferRead(qbuffer_t *p_node, uint8_t *p_data, uint32_t length);
uint32_t qbufferAvailable(qbuffer_t *p_node);
void     qbufferFlush(qbuffer_t *p_node);

>>>>>>> af0767fca0f1972362e5186eb10742e60df9d092

#endif /* SRC_COMMON_CORE_QBUFFER_H_ */
