/**
  ******************************************************************************
  * @file    General_Setup.h
  * @author  Antoine AUGAGNEUR, USMB LoRaWAN Team
  * @brief   Various definition for project setup
  * @Date    avr. 2022
  *
  * Macro definition linked with files: se-identity.h, lora_app.c, lora_app.h, sys_conf.h, soft-se.c
  *
  *
  * Logs:
  * --> Starting:		lora_app.c
  * --> Key printing:	soft-se.c
  * --> Frame sent:		lora_app.c
  * --> Frame received:	lora_app.c
  *
  *
  ******************************************************************************
*/
//#include "LoRaMacTypes.h"

#ifndef APPLICATION_USER_LORAWAN_GENERAL_SETUP_H_
#define APPLICATION_USER_LORAWAN_GENERAL_SETUP_H_


#define ABP				1
#define OTAA			2

#define true			1
#define false	 		0




/*---------------------------------------------------------------------------------------------------------------
 ACTIVATION_MODE     |    ABP or OTAA     |    # Selection of Activation Method                                  |
 CLASS               | CLASS_A or CLASS_C |    # Class selection
 SEND_BY_PUSH_BUTTON |   true or false    |    # Sending method (Time or Push Button)                            |
 FRAME_DELAY         |    Time in ms      |    # Time between 2 frames (Minimum 7000)                            |
 SPREADING_FACTOR    |   Number [7;12]    |    # 7=SF7, 8=SF8, ..., 12=SF12                                      |
 ADAPTIVE_DR         |  true or false     |    # Enable Aaptive Data Rate (if true)                              |
 CONFIRMED           |  true or false     |    # Frame Confirmed (if true) OR Frame Unconfirmed (if false)       |
 PORT                |   Number [0;199]   |    # Application Port number                                         |
 ENABLE_HUMIDITY     |  true or false     |    # Enable Humidity Sensor (if true)                                |
 CAYENNE_LPP         |  true or false     |    # Enable all sensor and use the CAYENNE LPP format (if true)      |
 LOW_POWER           |  true or false     |    # Enable Low Power mode between two frames (if true)              |
---------------------------------------------------------------------------------------------------------------*/


#define ACTIVATION_MODE     		OTAA
#define CLASS						CLASS_C
#define SEND_BY_PUSH_BUTTON 		false
#define FRAME_DELAY         		10000
#define SPREADING_FACTOR    		10
#define ADAPTIVE_DR         		true
#define CONFIRMED           		false
#define PORT                		10
#define ENABLE_TEMPERATURE     		true
#define CAYENNE_LPP_         		false
#define LOW_POWER           		false

#define devEUI_						{ 0x70, 0xB3, 0xD5, 0x7E, 0xD0, 0x04, 0xBD, 0x7C }

// Configuration for ABP Activation Mode
#define devAddr_ 					( uint32_t )0x12345678
#define nwkSKey_ 					F2,55,B7,74,8A,00,FF,7C,22,34,4C,34,02,F6,35,6F
#define appSKey_ 					F2,55,B7,74,8A,00,FF,7C,22,34,4C,34,02,F6,35,6F


// Configuration for OTAA Activation Mode
#define appKey_						D8,67,3F,C5,9F,DD,15,5F,A8,33,0D,91,4C,05,ED,0D
#define appEUI_						{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }



#if 		(SPREADING_FACTOR == 12)
#define ADMIN_DR	DR_0

#elif 		(SPREADING_FACTOR == 11)
#define ADMIN_DR	DR_1

#elif 		(SPREADING_FACTOR == 10)
#define ADMIN_DR	DR_2

#elif 		(SPREADING_FACTOR == 9)
#define ADMIN_DR	DR_3

#elif 		(SPREADING_FACTOR == 8)
#define ADMIN_DR	DR_4

#elif 		(SPREADING_FACTOR == 7)
#define ADMIN_DR	DR_5

#else
	#error "Wrong SPREADING_FACTOR definition in your General_Setup.h file"
#endif




/* LoRaWAN Activation Mode ----------------------------------------------------*/
#define ADMIN_ACTIVATION_TYPE							ACTIVATION_MODE		// possible values: ACTIVATION_TYPE_OTAA / ACTIVATION_TYPE_ABP - lora_app.h


/* LoRaWAN Credentials --------------------------------------------------------*/

// OTAA Keys --
#define ADMIN_OTAA_DEV_EUI								devEUI_ 	// se-identity.h
#define ADMIN_OTAA_APP_EUI								appEUI_ 	// se-identity.h
#define ADMIN_OTAA_APP_KEY								appKey_ 	// se-identity.h


// ABP Keys --
#define ADMIN_ABP_DEV_ADDR								devAddr_ 	// se-identity.h
#define ADMIN_ABP_NWK_S_KEY								nwkSKey_ 	// se-identity.h
#define ADMIN_ABP_APP_S_KEY								appSKey_ 	// se-identity.h


/* LoRaWAN Class --------------------------------------------------------------*/
#define ADMIN_DEFAULT_CLASS								CLASS							// possible values: CLASS_A / CLASS_B / CLASS_C - lora_app.h


/* LoRaWAN Transmission Parameters --------------------------------------------*/
#define ADMIN_DEFAULT_DATA_RATE_IF_NOT_ADR				ADMIN_DR						// possible values: DR_0 / DR_1 / DR_2 / DR_3 / DR_4 / DR_5 - lora_app.h
#define ADMIN_DEFAULT_DATA_RATE_IF_ADR					ADMIN_DR						// possible values: DR_0 / DR_1 / DR_2 / DR_3 / DR_4 / DR_5 - RegionEU868.h
#define ADMIN_ADR_STATE									ADAPTIVE_DR						// possible values: LORAMAC_HANDLER_ADR_ON / LORAMAC_HANDLER_ADR_OFF


/* LoRaWAN Application --------------------------------------------------------*/

// Uplink Mode
#define ADMIN_TX_TYPE									SEND_BY_PUSH_BUTTON				// possible values: 0 (by timer, every TxDutyCycleTime) / 1 (by button) - lora_app.c
#define ADMIN_TxDutyCycleTime							FRAME_DELAY						// in ms - lora_app.h
#define ADMIN_TX_CONFIRMED_TYPE							CONFIRMED						// possible values: LORAMAC_HANDLER_UNCONFIRMED_MSG / LORAMAC_HANDLER_CONFIRMED_MSG - lora_app.h

// Uplink Profile
#define ADMIN_USER_APP_PORT								PORT							//  lora_app.h
#define ADMIN_APP_PERSO									0								// 1 (send 0x010203 static) / 0 (none) // CAYENNE must be set to 1 - lora_app.h
#define ADMIN_CAYENNE									CAYENNE_LPP_					// 0 or 1. If defined, cayenne LPP is enable - lora_app.h
#define ADMIN_ENABLE_TEMPERATURE						ENABLE_TEMPERATURE				// 1 (send various temperature) / 0 (none) - General_Setup.h

// Power
#define ADMIN_LOW_POWER									!LOW_POWER						// 0 (Low Power enabled) / 1 (Low Power disabled)


/* Device LOGs ----------------------------------------------------------------*/
#define ADMIN_VERBOSE									VLEVEL_L						// possible values: VLEVEL_H / VLEVEL_M / VLEVEL_L - Utilities-Conf.h
#define ADMIN_KEY_EXTRACT								1								// possible values: 1 (display all keys), 0 (none) - lorawan_conf.h


/* LoRaWAN Multicast ----------------------------------------------------------*/
#define ADMIN_GEN_APP_KEY								F2,55,B7,74,8A,00,FF,7C,22,34,4C,34,02,F6,35,6F 		// se-identity.h


/* LoRaWAN transmission Settings -------------------------------------------------------------*/
#define ADMIN_RECEIVE_DELAY1		1000						// RegionCommon.h
#define ADMIN_RX2_DR				DR_0						// possible values: DR_0 to DR_5 - RegionEU868.h



#endif /* APPLICATION_USER_LORAWAN_GENERAL_SETUP_H_ */




