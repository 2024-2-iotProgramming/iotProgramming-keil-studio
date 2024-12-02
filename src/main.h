/*
 / _____)             _              | |
( (____  _____ ____ _| |_ _____  ____| |__
 \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 _____) ) ____| | | || |_| ____( (___| | | |
(______/|_____)_|_|_| \__)_____)\____)_| |_|
    ( C )2014 Semtech

Description: Contains the callbacks for the IRQs and any application related details

License: Revised BSD License, see LICENSE.TXT file include in the project

Maintainer: Miguel Luis and Gregory Cristian
*/
#ifndef __MAIN_H__
#define __MAIN_H__
#define PHYMAC_PDUOFFSET_TYPE 0
#define PHYMAC_PDUOFFSET_SRCID 1
#define PHYMAC_PDUOFFSET_DSTID 2
#define PHYMAC_PDUOFFSET_DATA 4

#define PHYMAC_PDUTYPE_DATA 0

static uint8_t phymac_id;

#define ECHO_Pin GPIO_PIN_11
#define ECHO_GPIO_Port GPIOA
#define TRIG_Pin GPIO_PIN_12
#define TRIG_GPIO_Port GPIOA


/*
 * Callback functions prototypes
 */
/*!
 * @brief Function to be executed on Radio Tx Done event
 */
void OnTxDone(void);

/*!
 * @brief Function to be executed on Radio Rx Done event
 */
void OnRxDone(uint8_t *payload, uint16_t size, int16_t rssi, int8_t snr);

/*!
 * @brief Function executed on Radio Tx Timeout event
 */
void OnTxTimeout(void);

/*!
 * @brief Function executed on Radio Rx Timeout event
 */
void OnRxTimeout(void);

/*!
 * @brief Function executed on Radio Rx Error event
 */
void OnRxError(void);

/*!
 * @brief Function executed on Radio Fhss Change Channel event
 */
void OnFhssChangeChannel(uint8_t channelIndex);

/*!
 * @brief Function executed on CAD Done event
 */
void OnCadDone(void);

static void MX_GPIO_Init(void);

float get_distance_cm(void);

float pulse_in(GPIO_TypeDef *port, uint16_t pin, uint32_t state, uint32_t timeout);

#endif // __MAIN_H__
