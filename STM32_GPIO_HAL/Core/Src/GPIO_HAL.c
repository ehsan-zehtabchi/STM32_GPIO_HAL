/*
 * GPIO_HAL.c
 *
 *  Created on: 2 Jul 2026
 *      Author: Zehta
 */

#include "stm32f4xx_hal.h"
#include "GPIO_HAL.h"

void LED_init(void)
{
GPIO_InitTypeDef GPIO_InitStruct = {0};

/* Enable GPIOA clock */
__HAL_RCC_GPIOA_CLK_ENABLE();

/* Configure GPIO pin : PA5 */
GPIO_InitStruct.Pin = GPIO_PIN_5;
GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
GPIO_InitStruct.Pull = GPIO_NOPULL;
GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void LED_init_D14(void)
{
GPIO_InitTypeDef GPIO_InitStruct = {0};

/* Enable GPIOB clock */
__HAL_RCC_GPIOB_CLK_ENABLE();

/* Configure GPIO pin : PB9 */
GPIO_InitStruct.Pin = GPIO_PIN_9;
GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
GPIO_InitStruct.Pull = GPIO_NOPULL;
GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

void LED_Blink_Fast(void)
{
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
  HAL_Delay(50);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
  HAL_Delay(1000);

  //or alternatively, you can use the HAL_GPIO_TogglePin function to toggle the LED state
  //HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
  //HAL_Delay(100);
}

void LED_Blink_Fast_D14(void)
{
  //HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);
  //HAL_Delay(2000);
  //HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);
  //HAL_Delay(500);

  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_9);
  HAL_Delay(2000);

}
