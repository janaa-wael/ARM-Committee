/*********************************************************************************/
/* Author    : ARM Committee, SemiColon Team                                     */
/* Version   : V01                                                               */
/* Date      : 13 February 2025                                                  */
/*********************************************************************************/

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#define ADC_CONTINUOUS_MODE   0                  // 1: Continuous,0: Single
#define ADC_SAMPLE_TIME       ADC_SMP_239_CYCLES5
#define ADC_SCAN_MODE         0                  // 1: Scan , 0: Single channel
#define ADC_ENABLE_INTERRUPT  0                  // 1: Enable EOC interrupt, 0: Polling Mode
#define ADC_CHANNEL           16
#define Number_Of_Conversion  1
#define ADC_NUM_CHANNELS      1
#define ADC_EXTERNAL_TRIGGER  0
#define ADC_TRIGGER_SOURCE    ADC_EXT_TRIG_EXTI_LINE11
#define ADC_PRESCALER         ADC_PCLK2_DIV_4
#define ADC_ENABLE_WATCHDOG   0  				 // 1: Enable,0: Disable
#define ADC_WATCHDOG_HIGH     3000               // Upper Threshold
#define ADC_WATCHDOG_LOW      1000               // Lower Threshold

/* ADC Sampling Time */
typedef enum
{
    ADC_SMP_1_CYCLE5    = 0,  // 1.5 cycles
    ADC_SMP_7_CYCLES5   = 1,  // 7.5 cycles
    ADC_SMP_13_CYCLES5  = 2,  // 13.5 cycles
    ADC_SMP_28_CYCLES5  = 3,  // 28.5 cycles
    ADC_SMP_41_CYCLES5  = 4,  // 41.5 cycles
    ADC_SMP_55_CYCLES5  = 5,  // 55.5 cycles
    ADC_SMP_71_CYCLES5  = 6,  // 71.5 cycles
    ADC_SMP_239_CYCLES5 = 7   // 239.5 cycles (Maximum Precision)
} ADC_samplingTime;

/* ADC Prescaler */
typedef enum
{
    ADC_PCLK2_DIV_2 = 0,
    ADC_PCLK2_DIV_4 = 1,
    ADC_PCLK2_DIV_6 = 2,
    ADC_PCLK2_DIV_8 = 3
} ADC_prescaler;

/* ADC External Trigger Sources */
typedef enum
{
    ADC_EXT_TRIG_TIM1_CC1    = 0,  // Timer 1 CC1
    ADC_EXT_TRIG_TIM1_CC2    = 1,  // Timer 1 CC2
    ADC_EXT_TRIG_TIM1_CC3    = 2,  // Timer 1 CC3
    ADC_EXT_TRIG_TIM2_CC2    = 3,  // Timer 2 CC2
    ADC_EXT_TRIG_TIM3_TRGO   = 4,  // Timer 3 TRGO
    ADC_EXT_TRIG_TIM4_CC4    = 5,  // Timer 4 CC4
    ADC_EXT_TRIG_EXTI_LINE11 = 6   // Software Start (EXTI Line 11)
} ADC_triggerSource;

#endif /* ADC_CONFIG_H_ */
