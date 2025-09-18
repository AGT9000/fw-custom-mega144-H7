#include "pch.h"
#include "board_overrides.h"

Gpio getCommsLedPin() {
	return Gpio::Unassigned;
}

Gpio getRunningLedPin() {
	return Gpio::Unassigned;
}

Gpio getWarningLedPin() {
	return Gpio::Unassigned;
}

static void customBoardDefaultConfiguration() {
    engineConfiguration->analogInputDividerCoefficient = 1.47f;

	engineConfiguration->adcVcc = 3.3f;
	engineConfiguration->is_enabled_spi_3 = true;

	engineConfiguration->map.sensor.hwChannel = EFI_ADC_11;
	engineConfiguration->clt.adcChannel = EFI_ADC_15;
	engineConfiguration->iat.adcChannel = EFI_ADC_14;
	engineConfiguration->afr.hwChannel = EFI_ADC_6;
	//engineConfiguration->tps
	engineConfiguration->tps1_1AdcChannel = EFI_ADC_0;
	//engineConfiguration->tps1_2AdcChannel = tps2;

	

}

void setup_custom_board_overrides() {
    custom_board_DefaultConfiguration = customBoardDefaultConfiguration;
}
