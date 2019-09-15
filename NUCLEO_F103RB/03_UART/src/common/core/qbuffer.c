/*
 * qbuffer.c
 *
<<<<<<< HEAD
 *  Created on: 2019. 9. 11.
 *      Author: Marshall
 */

#include "qbuffer.h"

=======
 *  Created on: 2018. 5. 19.
 *      Author: Baram
 */


#include "qbuffer.h"





>>>>>>> af0767fca0f1972362e5186eb10742e60df9d092
void qbufferInit(void)
{

}

bool qbufferCreate(qbuffer_t *p_node, uint8_t *p_buf, uint32_t length)
{
  bool ret = true;

<<<<<<< HEAD
  p_node->ptr_in  = 0;
  p_node->ptr_out = 0;
  p_node->length = length;
  p_node->p_buf  = p_buf;

  if(p_node->p_buf == NULL)
=======

  p_node->ptr_in  = 0;
  p_node->ptr_out = 0;
  p_node->length  = length;
  p_node->p_buf   = p_buf;

  if (p_node->p_buf == NULL)
>>>>>>> af0767fca0f1972362e5186eb10742e60df9d092
  {
    p_node->length = 0;
    ret = false;
  }

  return ret;
}

bool qbufferWrite(qbuffer_t *p_node, uint8_t *p_data, uint32_t length)
{
  bool ret = true;
  uint32_t index;
  uint32_t next_index;
  uint32_t i;

<<<<<<< HEAD
  if(p_node->p_buf == NULL) return false;

  for(i=0; i<length; i++)
  {
    index = p_node->ptr_in;
    next_index = p_node->ptr_in+1;

    if(next_index == p_node->length)
    {
      next_index = 0;
    }

    if(next_index != p_node->ptr_out)
    {
      p_node->p_buf[index] = p_data[i];
      p_node->ptr_in = next_index;
    }
    else
    {
      ret = false;  // ERR_FULL
=======
  if (p_node->p_buf == NULL) return false;


  for (i=0; i<length; i++)
  {
    index      = p_node->ptr_in;
    next_index = p_node->ptr_in + 1;

    if (next_index == p_node->length)
    {
      next_index = 0;;
    }

    if (next_index != p_node->ptr_out)
    {
      p_node->p_buf[index] = p_data[i];
      p_node->ptr_in       = next_index;
    }
    else
    {
      ret = false; // ERR_FULL
>>>>>>> af0767fca0f1972362e5186eb10742e60df9d092
      break;
    }
  }

  return ret;
}

<<<<<<< HEAD
bool  qbufferRead(qbuffer_t *p_node, uint8_t *p_data, uint32_t length)
=======
bool qbufferRead(qbuffer_t *p_node, uint8_t *p_data, uint32_t length)
>>>>>>> af0767fca0f1972362e5186eb10742e60df9d092
{
  bool ret = true;
  uint32_t index;
  uint32_t next_index;
  uint32_t i;

<<<<<<< HEAD
  if(p_node->p_buf == NULL) return false;

  for(i=0; i<length; i++)
  {
    index = p_node->ptr_out;
    next_index = p_node->ptr_out+1;

    if(next_index == p_node->length)
=======
  if (p_node->p_buf == NULL) return false;


  for (i=0; i<length; i++)
  {
    index      = p_node->ptr_out;
    next_index = p_node->ptr_out + 1;

    if (next_index == p_node->length)
>>>>>>> af0767fca0f1972362e5186eb10742e60df9d092
    {
      next_index = 0;
    }

<<<<<<< HEAD
    if(index != p_node->ptr_in)
    {
      p_data[i] = p_node->p_buf[index];
=======
    if (index != p_node->ptr_in)
    {
      p_data[i]       = p_node->p_buf[index];
>>>>>>> af0767fca0f1972362e5186eb10742e60df9d092
      p_node->ptr_out = next_index;
    }
    else
    {
<<<<<<< HEAD
      ret = false;  // ERR_EMPTY
=======
      ret = false; // ERR_EMPTY
>>>>>>> af0767fca0f1972362e5186eb10742e60df9d092
      break;
    }
  }

  return ret;
}

uint32_t qbufferAvailable(qbuffer_t *p_node)
{
  uint32_t length;

<<<<<<< HEAD
=======

>>>>>>> af0767fca0f1972362e5186eb10742e60df9d092
  length = (p_node->length + p_node->ptr_in - p_node->ptr_out) % p_node->length;

  return length;
}

<<<<<<< HEAD
void  qbufferFlush(qbuffer_t *p_node)
{
  p_node->ptr_in = 0;
=======
void qbufferFlush(qbuffer_t *p_node)
{
  p_node->ptr_in  = 0;
>>>>>>> af0767fca0f1972362e5186eb10742e60df9d092
  p_node->ptr_out = 0;
}
