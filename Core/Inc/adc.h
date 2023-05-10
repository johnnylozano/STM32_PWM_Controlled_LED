#ifndef ADC_H_
#define ADC_H_

void pa1_adc_init(void);
void start_continuous_conversion(void);
uint16_t adc_read(void);

#endif /* ADC_H_ */
