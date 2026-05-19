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

static void setupVbatt() {
	// 5.6k high side/10k low side = 1.56 ratio divider
	engineConfiguration->analogInputDividerCoefficient = 1.56f;

	// 82k high side/10k low side = 9.2
	engineConfiguration->vbattDividerCoeff = (92.0f / 10.0f);

	// Battery sense on PA7
	engineConfiguration->vbattAdcChannel = EFI_ADC_7;

	
}
stsitc void setupCAN() {
	
	engineConfiguration->canTxPin = Gpio::D1;
	engineConfiguration->canRxPin = Gpio::D0;
	
}

static void setupDefaultSensorInputs() {
	// trigger inputs
	// Digital channel 1 as default - others not set
	engineConfiguration->triggerInputPins[0] = Gpio::E8;
	engineConfiguration->camInputs[0] = Gpio::Unassigned;

	engineConfiguration->triggerInputPins[1] = Gpio::Unassigned;


	engineConfiguration->clt.adcChannel = EFI_ADC_12;
	engineConfiguration->iat.adcChannel = EFI_ADC_14;
	engineConfiguration->tps1_1AdcChannel = EFI_ADC_0;
	engineConfiguration->map.sensor.hwChannel = EFI_ADC_11;

    // see also enableAemXSeries
	// pin #28 WBO AFR "Analog Volt 10"
	engineConfiguration->afr.hwChannel = EFI_ADC_10;
}

static void customBoardDefaultConfiguration() {
    setupCAN();
	setupVbatt();
	setupDefaultSensorInputs();
	
    engineConfiguration->analogInputDividerCoefficient = 1.47f;

	engineConfiguration->adcVcc = 3.3f;
	engineConfiguration->is_enabled_spi_3 = false;
	

}

void setup_custom_board_overrides() {
    custom_board_DefaultConfiguration = customBoardDefaultConfiguration;
}
