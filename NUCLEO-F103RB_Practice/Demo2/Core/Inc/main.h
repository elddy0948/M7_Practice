/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define B1_EXTI_IRQn EXTI15_10_IRQn
#define CLCD_D0_Pin GPIO_PIN_2
#define CLCD_D0_GPIO_Port GPIOC
#define CLCD_D1_Pin GPIO_PIN_3
#define CLCD_D1_GPIO_Port GPIOC
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define LED0_Pin GPIO_PIN_6
#define LED0_GPIO_Port GPIOA
#define LED1_Pin GPIO_PIN_7
#define LED1_GPIO_Port GPIOA
#define CLCD_D2_Pin GPIO_PIN_4
#define CLCD_D2_GPIO_Port GPIOC
#define CLCD_D3_Pin GPIO_PIN_5
#define CLCD_D3_GPIO_Port GPIOC
#define SW0_Pin GPIO_PIN_1
#define SW0_GPIO_Port GPIOB
#define SW0_EXTI_IRQn EXTI1_IRQn
#define SW1_Pin GPIO_PIN_2
#define SW1_GPIO_Port GPIOB
#define SW1_EXTI_IRQn EXTI2_IRQn
#define ENCODER_SW_Pin GPIO_PIN_8
#define ENCODER_SW_GPIO_Port GPIOA
#define ENCODER_SW_EXTI_IRQn EXTI9_5_IRQn
#define LED2_Pin GPIO_PIN_11
#define LED2_GPIO_Port GPIOA
#define LED3_Pin GPIO_PIN_12
#define LED3_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define ENCODER_B_SIG_Pin GPIO_PIN_15
#define ENCODER_B_SIG_GPIO_Port GPIOA
#define ENCODER_B_SIG_EXTI_IRQn EXTI15_10_IRQn
#define CLCD_EN_Pin GPIO_PIN_10
#define CLCD_EN_GPIO_Port GPIOC
#define CLCD_RS_Pin GPIO_PIN_11
#define CLCD_RS_GPIO_Port GPIOC
#define ENCODER_A_SIG_Pin GPIO_PIN_12
#define ENCODER_A_SIG_GPIO_Port GPIOC
#define ENCODER_A_SIG_EXTI_IRQn EXTI15_10_IRQn
#define SW2_Pin GPIO_PIN_4
#define SW2_GPIO_Port GPIOB
#define SW2_EXTI_IRQn EXTI4_IRQn
#define SW3_Pin GPIO_PIN_5
#define SW3_GPIO_Port GPIOB
#define SW3_EXTI_IRQn EXTI9_5_IRQn
#define SERVO_Pin GPIO_PIN_7
#define SERVO_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
