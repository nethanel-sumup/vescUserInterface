/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
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
#include "stm32f4xx_hal.h"

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define OLED_CS_Pin GPIO_PIN_13
#define OLED_CS_GPIO_Port GPIOC
#define OLED_DC_Pin GPIO_PIN_14
#define OLED_DC_GPIO_Port GPIOC
#define BUTTON1_Pin GPIO_PIN_0
#define BUTTON1_GPIO_Port GPIOA
#define OLED_RST_Pin GPIO_PIN_1
#define OLED_RST_GPIO_Port GPIOA
#define ACCELERATOR_Pin GPIO_PIN_4
#define ACCELERATOR_GPIO_Port GPIOA
#define BUTTON2_Pin GPIO_PIN_5
#define BUTTON2_GPIO_Port GPIOA
#define PHOTO_RESISTOR_Pin GPIO_PIN_6
#define PHOTO_RESISTOR_GPIO_Port GPIOA
#define BRAKE_Pin GPIO_PIN_7
#define BRAKE_GPIO_Port GPIOA
#define BUTTON3_Pin GPIO_PIN_13
#define BUTTON3_GPIO_Port GPIOB
#define BUTTON4_Pin GPIO_PIN_14
#define BUTTON4_GPIO_Port GPIOB
#define EXT_FLASH_CS_Pin GPIO_PIN_15
#define EXT_FLASH_CS_GPIO_Port GPIOA
#define LIGHT_SW_Pin GPIO_PIN_8
#define LIGHT_SW_GPIO_Port GPIOB
#define BUZZER_Pin GPIO_PIN_9
#define BUZZER_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
