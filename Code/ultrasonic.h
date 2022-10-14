 /******************************************************************************
 *
 * Module: UltraSonic sensor(HC-SR04)
 *
 * File Name: ultrasonic.h
 *
 * Description: Header file for the ultraSonic sensor
 *
 * Author: Nouran Gamal
 *
 *******************************************************************************/

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include"std_types.h"
#include "gpio.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ULTRASONIC_TRIGGER_PORT PORTB_ID
#define ULTRASONIC_TRIGGER_PIN  PIN5_ID

//as we in atmega16/32 there is only one input capture unit through PD6/ICP1
#define ULTRASONIC_ECHO_PORT PORTD_ID
#define ULTRASONIC_ECHO_PIN  PIN6_ID

#define ULTRASONIC_TRIGGER_PULSE_DURATION 10


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description: function responsible for initialization of ultrasonic
 * 1-initialize ICU
 * 2-Setup the ICU call back function.
 * 3-Setup the direction for the trigger pin as output pin through the GPIO driver
 */
void Ultrasonic_init(void);

/*
 * Description : function responsible for Send the Trigger pulse to the ultrasonic
 */
void Ultrasonic_Trigger(void);

/*
 * Function description: function responsible for reading distance using ultrasonic
 *  1- send the trigger pulse by using Ultrasonic_Trigger function.so ultrasonic start to produce echo pulse
 *	2- Start the measurements by the ICU from this moment.
 *
 *	Return: The measured distance in Centimeter
 */
uint16 Ultrasonic_readDistance(void);


/*
 * Function description:
 * This is the call back function called by the ICU driver,
 * we initialize the call back in Ultrasonic_init()
 * the function used to calculate the high time (pulse time) generated by the ultrasonic sensor
 * */
void Ultrasonic_edgeProcessing(void);

#endif /* ULTRASONIC_H_ */