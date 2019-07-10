/*
 * Core.h
 *
 *  Created on: 13/04/2019
 *      Author: InDev
 */

#ifndef INCLUDE_CORE_H_
#define INCLUDE_CORE_H_


 //   _enable_interrupts();
 //   value=_disable_interrupts();
 //   _restore_interrupts(value);

#define   __I     volatile const       /*!< Defines 'read only' permissions */
#define   __O     volatile             /*!< Defines 'write only' permissions */
#define   __IO    volatile             /*!< Defines 'read / write' permissions */

/* following defines should be used for structure members */
#define     __IM     volatile const      /*! Defines 'read only' structure member permissions */
#define     __OM     volatile            /*! Defines 'write only' structure member permissions */
#define     __IOM    volatile            /*! Defines 'read / write' structure member permissions */


#endif /* INCLUDE_CORE_H_ */
