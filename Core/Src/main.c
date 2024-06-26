/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#define CONT_CNTRL_1_PORT   GPIO_PORT_D
#define LOCK_CNTRL_1_PORT   GPIO_PORT_D
#define FB1_PORT            GPIO_PORT_D

#define CONT_CNTRL_1_PIN   GPIO_PIN_8
#define LOCK_CNTRL_1_PIN   GPIO_PIN_9
#define FB1_PIN            GPIO_PIN_0

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim21;

UART_HandleTypeDef huart5;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM21_Init(void);
static void MX_USART5_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void solenoid_release (void)
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, SET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, SET);

    for(int i = 0; i<=100; i++)
    {
    	htim21.Instance->CCR1 = i;
        HAL_Delay(10);
    }

//    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, RESET);
//	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, RESET);
}

void solenoid_lock (void)
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, SET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, RESET);

    for(int i = 0; i<=100; i++)
    {
    	htim21.Instance->CCR1 = i;
        HAL_Delay(10);
    }

//	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, RESET);
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM21_Init();
  MX_USART5_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_PWM_Start(&htim21, TIM_CHANNEL_1);

//  solenoid_release ();
//  HAL_Delay(3000);
//  solenoid_lock ();
//  HAL_Delay(3000);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
//	  if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2) == GPIO_PIN_RESET)
//	  {
//		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, SET);
//		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, RESET);
//		  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, RESET);
//		  solenoid_release ();
//		  HAL_Delay(10);
//	  }
//	  else
//	  {
//		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, SET);
//		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, SET);
//		  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, SET);
//		  solenoid_lock ();
//		  HAL_Delay(10);
//	  }

	    solenoid_release ();
	    HAL_Delay(2000);
	    solenoid_lock ();
	    HAL_Delay(2000);


//
//	  solenoid_release ();
//	  HAL_Delay(3000);
//	  solenoid_lock ();
//	  HAL_Delay(3000);


//
//	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, SET);
//	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, SET);
//
//	  htim21.Instance->CCR1 = 95;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 90;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 85;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 80;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 75;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 70;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 65;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 60;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 55;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 50;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 45;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 40;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 35;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 30;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 25;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 20;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 15;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 10;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 5;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 0;
//	  HAL_Delay(100);
//
//	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, RESET);
//	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, RESET);
//
//	  HAL_Delay(5000);
//
//	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, SET);
//	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, SET);
//
//	  htim21.Instance->CCR1 = 5;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 10;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 15;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 20;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 25;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 30;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 35;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 40;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 45;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 50;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 55;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 60;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 65;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 70;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 75;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 80;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 85;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 90;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 95;
//	  HAL_Delay(100);
//	  htim21.Instance->CCR1 = 100;
//	  HAL_Delay(100);
//
//	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, RESET);
//	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, RESET);
//
//	  HAL_Delay(5000);

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLLMUL_4;
  RCC_OscInitStruct.PLL.PLLDIV = RCC_PLLDIV_2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM21 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM21_Init(void)
{

  /* USER CODE BEGIN TIM21_Init 0 */

  /* USER CODE END TIM21_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM21_Init 1 */

  /* USER CODE END TIM21_Init 1 */
  htim21.Instance = TIM21;
  htim21.Init.Prescaler = 32-1;
  htim21.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim21.Init.Period = 100-1;
  htim21.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim21.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim21) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim21, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim21) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim21, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim21, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM21_Init 2 */

  /* USER CODE END TIM21_Init 2 */
  HAL_TIM_MspPostInit(&htim21);

}

/**
  * @brief USART5 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART5_UART_Init(void)
{

  /* USER CODE BEGIN USART5_Init 0 */

  /* USER CODE END USART5_Init 0 */

  /* USER CODE BEGIN USART5_Init 1 */

  /* USER CODE END USART5_Init 1 */
  huart5.Instance = USART5;
  huart5.Init.BaudRate = 115200;
  huart5.Init.WordLength = UART_WORDLENGTH_8B;
  huart5.Init.StopBits = UART_STOPBITS_1;
  huart5.Init.Parity = UART_PARITY_NONE;
  huart5.Init.Mode = UART_MODE_TX_RX;
  huart5.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart5.Init.OverSampling = UART_OVERSAMPLING_16;
  huart5.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart5.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart5) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART5_Init 2 */

  /* USER CODE END USART5_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1|GPIO_PIN_2, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC2 */
  GPIO_InitStruct.Pin = GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PB1 PB2 */
  GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PE7 */
  GPIO_InitStruct.Pin = GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PD8 PD9 */
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : PC6 PC7 PC8 */
  GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
