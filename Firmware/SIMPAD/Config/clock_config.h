/* Auto-generated config file clock_config.h */
#ifndef CLOCK_CONFIG_H
#define CLOCK_CONFIG_H

// <<< Use Configuration Wizard in Context Menu >>>

#ifndef F_CPU
#define F_CPU 16000000
#endif
// <h> ADC Clock Settings
// <y> ADC Clock source
// <CLKadc"> CLKadc
// <i> This defines the clock source for the ADC module
// <id> adc_clock_source
#define CONF_ADC_SRC CLKadc

// </h>

// <h> TC0 Clock Settings
// <y> TC0 Clock source
// <CLKio"> CLKio
// <i> This defines the clock source for the TC0 module
// <id> tc8_clock_source
#define CONF_TC0_SRC CLKio

// </h>

// <h> USART Clock Settings
// <y> USART Clock source
// <CLKio"> CLKio
// <i> This defines the clock source for the USART module
// <id> usart_clock_source
#define CONF_USART_SRC CLKio

// </h>

// <<< end of configuration section >>>

#endif // CLOCK_CONFIG_H
