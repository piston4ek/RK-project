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
#include "spi.h"
#include "usart.h"
#include "gpio.h"
#include "nrf24l01p.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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

/* USER CODE BEGIN PV */
uint8_t tx_data[NRF24L01P_PAYLOAD_LENGTH] = {0, 1, 2, 3, 4, 5, 6, 7};
char str1[20]={0};

uint8_t buf1[20]={0};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */
		/*nrf24l01p_tx_init(2500, _1Mbps);
 
    while (1)
    {
        // change tx datas
        for(int i= 0; i < 8; i++)
            tx_data[i]++;

        // transmit
        nrf24l01p_tx_transmit(tx_data);
        HAL_Delay(100);
    }*/
	/*uint8_t dt_reg=0;
	HAL_Delay(1000);
  dt_reg = read_register(NRF24L01P_REG_CONFIG);
  sprintf(str1,"CONFIG: 0x%02Xrn",dt_reg);
  HAL_UART_Transmit(&huart1,(uint8_t*)str1,strlen(str1),0x1000);
  dt_reg = read_register(NRF24L01P_REG_EN_AA);
  sprintf(str1,"EN_AA: 0x%02Xrn",dt_reg);
  HAL_UART_Transmit(&huart1,(uint8_t*)str1,strlen(str1),0x1000);
  dt_reg = read_register(NRF24L01P_REG_EN_RXADDR);
  sprintf(str1,"EN_RXADDR: 0x%02Xrn",dt_reg);
  HAL_UART_Transmit(&huart1,(uint8_t*)str1,strlen(str1),0x1000);
  dt_reg = read_register(NRF24L01P_REG_STATUS);
  sprintf(str1,"STATUS: 0x%02Xrn",dt_reg);
  HAL_UART_Transmit(&huart1,(uint8_t*)str1,strlen(str1),0x1000);
  dt_reg = read_register(NRF24L01P_REG_RF_SETUP);
  sprintf(str1,"RF_SETUP: 0x%02Xrn",dt_reg);
  HAL_UART_Transmit(&huart1,(uint8_t*)str1,strlen(str1),0x1000);
  read_register(NRF24L01P_REG_TX_ADDR,buf1,3);
  sprintf(str1,"TX_ADDR: 0x%02X, 0x%02X, 0x%02Xrn",buf1[0],buf1[1],buf1[2]);
  HAL_UART_Transmit(&huart1,(uint8_t*)str1,strlen(str1),0x1000);
  read_register(NRF24L01P_REG_RX_ADDR_P1,buf1,3);
  sprintf(str1,"RX_ADDR: 0x%02X, 0x%02X, 0x%02Xrn",buf1[0],buf1[1],buf1[2]);
  HAL_UART_Transmit(&huart1,(uint8_t*)str1,strlen(str1),0x1000);*/
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
  MX_SPI2_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 12;
  RCC_OscInitStruct.PLL.PLLN = 96;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == NRF24L01P_IRQ_PIN_NUMBER)
		nrf24l01p_tx_irq(); // clear interrupt flag
}
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
