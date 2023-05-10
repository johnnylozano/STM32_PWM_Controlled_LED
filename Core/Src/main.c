#include <stdint.h>
#include "stm32f4xx.h"
#include "adc.h"
#include "tim.h"


uint16_t pot_value;

int main(void)
{
	pa1_adc_init();
	start_continuous_conversion();
	tim2_pa5_pmw();

	while(1)
	{
		pot_value = adc_read();
		TIM2->CCR1 = pot_value;
	}


	return 0;
}
