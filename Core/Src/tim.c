#include "stm32f4xx.h"


#define GPIOAEN			(1U<<0)
#define AFR5_TIM		(1U<<20)
#define TIM2EN			(1U<<0)
#define OC_PMW_MODE1	((1U<<6) | (1U<<5))
#define CCER_CC1E		(1U<<0)
#define CR1_CEN			(1U<<0)

void tim2_pa5_pmw(void)
{
	/*======= Configure GPIOA =======*/
	/* Enable clock access to GPIOA */
	RCC->AHB1ENR |= GPIOAEN;

	/* Set PA5 mode to alternate function */
	GPIOA->MODER &=~ (1U<<10);
	GPIOA->MODER |= (1U<<11);

	/* Set PA5 alternate function type to TIM2_CH1 (AF01) */
	GPIOA->AFR[0] |= AFR5_TIM;

	/*======= Configure TIM2 =======*/
	/* Enable clock access to tim2 */
	RCC->APB1ENR |= TIM2EN;

	/* Set prescalar value */
	TIM2->PSC = 4 - 1;		// 16 000 000 / 4 = 4 000 000 Hz

	/* Set auto-reload value */
	TIM2->ARR = 4096 - 1;	// 4 000 000 / 4096 = 976.56 Hz PMW signal

	/* Start with 0% duty cycle */
	TIM2->CCR1 = 0;

	/* Set output compare pmw mode 1 */
	TIM2->CCMR1 = OC_PMW_MODE1;

	/* Enable tim2 ch1 in compare mode */
	TIM2->CCER |= CCER_CC1E;

	/* Enable timer */
	TIM2->CR1 |= CR1_CEN;
}
