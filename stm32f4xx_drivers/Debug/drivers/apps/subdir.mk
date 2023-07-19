################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/apps/usart_trial.c 

OBJS += \
./drivers/apps/usart_trial.o 

C_DEPS += \
./drivers/apps/usart_trial.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/apps/%.o drivers/apps/%.su drivers/apps/%.cyclo: ../drivers/apps/%.c drivers/apps/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -I"C:/Users/erdem/Desktop/STM32/workspace_course/stm32f4xx_drivers/drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-drivers-2f-apps

clean-drivers-2f-apps:
	-$(RM) ./drivers/apps/usart_trial.cyclo ./drivers/apps/usart_trial.d ./drivers/apps/usart_trial.o ./drivers/apps/usart_trial.su

.PHONY: clean-drivers-2f-apps

