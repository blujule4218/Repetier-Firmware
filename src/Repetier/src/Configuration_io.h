/*

This file defines io solutions used. This is the lowest level and is the base
for all higher level functions using io operations. At several places we need
subsets of these list of operations. To make configuration easy and easy to
understand, we use a technique called "x macros". This requires that only
predefined macro names for IO are used here. Do NOT add anything else here
or compilation/functionality will break.

Rules:
1. Each definition will create a class that is named like the first parameter.
This class is later used as input to templates building higher functions. By
convention the names should start with IO followed by something that helps you
identify the function.
2. Do not use a semicolon at the end. Macro definition gets different meanings
and will add the semicolon if required.

*/
/* Define motor pins here. Each motor needs a setp, dir and enable pin. */

ENDSTOP_NONE(endstopNone)
// For use when no output is wanted, but possible
IO_OUTPUT_FAKE(fakeOut)

// X Motor

IO_OUTPUT(IOX1Step, ORIG_X_STEP_PIN)
IO_OUTPUT_INVERTED(IOX1Dir, ORIG_X_DIR_PIN)
IO_OUTPUT_INVERTED(IOX1Enable, ORIG_X_ENABLE_PIN)


// Y Motor

IO_OUTPUT(IOY1Step, ORIG_Y_STEP_PIN)
IO_OUTPUT_INVERTED(IOY1Dir, ORIG_Y_DIR_PIN)
IO_OUTPUT_INVERTED(IOY1Enable, ORIG_Y_ENABLE_PIN)

// Z Motor

IO_OUTPUT(IOZ1Step, ORIG_Z_STEP_PIN)
IO_OUTPUT_INVERTED(IOZ1Dir, ORIG_Z_DIR_PIN)
IO_OUTPUT_INVERTED(IOZ1Enable, ORIG_Z_ENABLE_PIN)

// E0 Motor

IO_OUTPUT(IOE1Step, ORIG_E0_STEP_PIN)
IO_OUTPUT_INVERTED(IOE1Dir, ORIG_E0_DIR_PIN)
IO_OUTPUT_INVERTED(IOE1Enable, ORIG_E0_ENABLE_PIN)

// E1 Motor

IO_OUTPUT(IOE2Step, ORIG_E1_STEP_PIN)
IO_OUTPUT(IOE2Dir, ORIG_E1_DIR_PIN)
IO_OUTPUT_INVERTED(IOE2Enable, ORIG_E1_ENABLE_PIN)

// ZProbe Servo and trigger input and output

// Define your endstops inputs
IO_INPUT_PULLUP(IOEndstopZProbe, ORIG_Z_MIN_PIN)

 IO_INPUT_INVERTED(IOEndstopXMin, ORIG_X_MIN_PIN)
IO_INPUT_INVERTED(IOEndstopYMin, ORIG_Y_MIN_PIN)
IO_INPUT_INVERTED_PULLUP(IOEndstopZMax, ORIG_Z_MAX_PIN)
IO_INPUT_PULLUP(IOEndstopZMin, ORIG_Z_MIN_PIN)
//IO_INPUT_PULLUP(IOEndstopZMin, ORIG_Z_MIN_PIN)

IO_INPUT(IOJam1, 35)
IO_INPUT(IOJam2, 33)

// Controller input pins

#if defined(UI_ENCODER_CLICK) && UI_ENCODER_CLICK >= 0
IO_INPUT_INVERTED_PULLUP(ControllerClick, UI_ENCODER_CLICK)
#else
IO_INPUT_DUMMY(ControllerClick, false)
#endif
#if defined(UI_ENCODER_A) && UI_ENCODER_A >= 0
IO_INPUT_INVERTED_PULLUP(ControllerEncA, UI_ENCODER_A)
#else
IO_INPUT_DUMMY(ControllerEncA, false)
#endif
#if defined(UI_ENCODER_B) && UI_ENCODER_B >= 0
IO_INPUT_INVERTED_PULLUP(ControllerEncB, UI_ENCODER_B)
#else
IO_INPUT_DUMMY(ControllerEncB, false)
#endif
#if defined(UI_BACK_PIN) && UI_BACK_PIN >= 0
IO_INPUT_PULLUP(ControllerBack, UI_BACK_PIN)
#else
IO_INPUT_DUMMY(ControllerBack, false)
#endif
#if defined(UI_RESET_PIN) && UI_RESET_PIN >= 0
IO_INPUT_PULLUP(ControllerReset, UI_RESET_PIN)
#else
IO_INPUT_DUMMY(ControllerReset, false)
#endif

// Define our endstops solutions
// You need to define all min and max endstops for all
// axes except E even if you have none!

ENDSTOP_SWITCH_HW(endstopXMin, IOEndstopXMin, X_AXIS, false)
ENDSTOP_SWITCH_HW(endstopYMin, IOEndstopYMin, Y_AXIS, false)
ENDSTOP_SWITCH_HW(endstopZMax, IOEndstopZMax, Z_AXIS, true)
ENDSTOP_SWITCH_HW(endstopZMin, IOEndstopZMin, ZPROBE_AXIS, false)
ENDSTOP_NONE(endstopXMax)
ENDSTOP_NONE(endstopYMax)
//ENDSTOP_NONE(endstopZMin)
ENDSTOP_SWITCH_HW(endstopZProbe, IOEndstopZProbe, ZPROBE_AXIS, false)
// Servo FOR Z-PROBE

IO_OUTPUT(Servo1Pin, 4)
SERVO_ANALOG(ZProbeServo, 0, Servo1Pin, 500, 2500, 1473)
#undef ZPROBE_ADDRESS
#define ZPROBE_ADDRESS &endstopZProbe &endstopZMin
// Define fans

IO_OUTPUT(IOFan1, ORIG_FAN2_PIN) //board fan control
IO_PWM_SOFTWARE(Fan1NoKSPWM, IOFan1, 0)
 IO_PWM_HARDWARE(Fan1PWM, 37,5000)
// IO_PDM_SOFTWARE(Fan1NoKSPWM, IOFan1) // alternative to PWM signals
//IO_PWM_KICKSTART(Fan1PWM, Fan1NoKSPWM, 20, 85)

IO_OUTPUT(IOBoardFan, ORIG_FAN_PIN)
IO_PWM_SOFTWARE(BoardFan, IOBoardFan, 4)
COOLER_MANAGER_MOTORS(BoardFanController, BoardFan, 90, 255, 120)

// Define temperature sensors
// Typically they require an analog input (12 bit) so define
// them first.

IO_ANALOG_INPUT(IOAnalogBed1, TEMP_1_PIN, 5)
IO_ANALOG_INPUT(IOAnalogExt1, TEMP_0_PIN, 5)
IO_ANALOG_INPUT(IOAnalogExt2, TEMP_2_PIN, 5)
IO_ANALOG_INPUT(IOAnalogChamber, TEMP_4_PIN, 5)
// Need a conversion table for epcos NTC
IO_TEMP_TABLE_NTC(TempTableatc, ATC_104GT)
IO_TEMP_TABLE_PTC(TemptablePT100, PT100_3_3V)
IO_TEMP_TABLE_PTC(TemptablePT1000, PT1000_4k7)

// Now create the temperature inputs

IO_TEMPERATURE_TABLE(TempBed1, IOAnalogBed1, TempTableatc)
IO_TEMPERATURE_TABLE(TempExt1, IOAnalogExt1, TemptablePT1000)
IO_TEMPERATURE_TABLE(TempExt2, IOAnalogExt2, TemptablePT1000)
IO_TEMPERATURE_TABLE(TempChamber, IOAnalogChamber, TemptablePT100)
// Use PWM outputs to heat. If using hardware PWM make sure
// that the selected pin can be used as hardware pwm otherwise
// select a software pwm model whcih works on all pins.

#if MOTHERBOARD == 405
IO_PWM_HARDWARE(PWMExtruder1, HEATER_0_PIN, 1000)
IO_PWM_HARDWARE(PWMExtruder2, HEATER_2_PIN, 1000)
IO_PWM_HARDWARE(PWMBed1, HEATER_1_PIN, 1000)
#else
IO_OUTPUT(IOExtr1, HEATER_0_PIN)
IO_OUTPUT(IOExtr2, HEATER_2_PIN)
IO_OUTPUT(IOBed1, HEATER_1_PIN)
IO_OUTPUT(IOChamber, HEATER_3_PIN)
IO_PWM_SOFTWARE(PWMExtruder1, IOExtr1, 1)
IO_PWM_SOFTWARE(PWMExtruder2, IOExtr2, 1)
IO_PWM_SOFTWARE(PWMBed1, IOBed1, 1)
IO_PWM_SOFTWARE(PWMChamber, IOChamber, 1)
#endif
// IO_OUTPUT(IOCooler1, FAN2_PIN)
// IO_PWM_SOFTWARE(PWMCoolerExt1, FAN2_PIN, 0)
//#define STEPPER_TMC5160_SW_SPI(name, stepPin, dirPin, enablePin, mosiPin, misoPin, sckPin, csPin, rsense, chainPos, microsteps, currentMillis, stealth, hybridSpeed, stallSensitivity, fclk, minEndstop, maxEndstop)
//        STEPPER_TMC5160_SW_SPI(name, stepPin, dirPin, enablePin, mosiPin, misoPin, sckPin, csPin, rsense, chainPos, microsteps, currentMillis, stealth, hybridSpeed, stallSensitivity, fclk, minEndstop, maxEndstop)

// Define all stepper motors used
/*
STEPPER_TMC5160_SW_SPI(XMotor, IOX1Step, IOX1Dir, IOX1Enable, MOSI_PIN, MISO_PIN, SCK_PIN, ORIG_X_CS_PIN, 0.075, 1, 80, 900, false, 100, -128, 12500000, endstopNone, endstopNone)
STEPPER_TMC5160_SW_SPI(YMotor, IOY1Step, IOY1Dir, IOY1Enable, MOSI_PIN, MISO_PIN, SCK_PIN, ORIG_Y_CS_PIN, 0.075, 1, 80, 1000, false, 100, -128, 12500000, endstopNone, endstopNone)
STEPPER_TMC5160_SW_SPI(ZMotor, IOZ1Step, IOZ1Dir, IOZ1Enable, MOSI_PIN, MISO_PIN, SCK_PIN, ORIG_Z_CS_PIN, 0.075, 1, 1600, 900, false, 100, -128, 12500000, endstopNone, endstopNone)
STEPPER_TMC5160_SW_SPI(E1Motor, IOE1Step, IOE1Dir, IOE1Enable, MOSI_PIN, MISO_PIN, SCK_PIN, ORIG_E0_CS_PIN, 0.075, 1, 32, 900, false, 100, -128, 12500000, endstopNone, endstopNone)
STEPPER_TMC5160_SW_SPI(E2Motor, IOE2Step, IOE2Dir, IOE2Enable, MOSI_PIN, MISO_PIN, SCK_PIN, ORIG_E2_CS_PIN, 0.075, 1, 32, 900, false, 100, -128, 12500000, endstopNone, endstopNone)
*/
STEPPER_TMC5160_HW_SPI(XMotor, IOX1Step, IOX1Dir, IOX1Enable,  ORIG_X_CS_PIN, 0.075, 1, 16, 1100, false, 0, -128, 12500000, endstopNone, endstopNone)
STEPPER_TMC5160_HW_SPI(YMotor, IOY1Step, IOY1Dir, IOY1Enable, ORIG_Y_CS_PIN, 0.075, 1, 16, 1100, false, 0, -128, 12500000, endstopNone, endstopNone)
STEPPER_TMC5160_HW_SPI(ZMotor, IOZ1Step, IOZ1Dir, IOZ1Enable, ORIG_Z_CS_PIN, 0.075, 1, 8, 1100, false, 0, -128, 12500000, endstopNone, endstopNone)
STEPPER_TMC5160_HW_SPI(E1Motor, IOE1Step, IOE1Dir, IOE1Enable, ORIG_E0_CS_PIN, 0.075, 1, 16, 900, false, 0, -128, 12500000, endstopNone, endstopNone)
STEPPER_TMC5160_HW_SPI(E2Motor, IOE2Step, IOE2Dir, IOE2Enable, ORIG_E1_CS_PIN, 0.075, 1, 16, 900, false, 0, -128, 12500000, endstopNone, endstopNone)



// Heat manages are used for every component that needs to
// control temperature. Higher level classes take these as input
// and simple heater like a heated bed use it directly.

HEAT_MANAGER_PID(HeatedBed1, 'B', 0, TempBed1, PWMBed1, 120, 255, 1000, 5, 30000, 56.93, 10.04, 80.74, 80, 255, true)
HEAT_MANAGER_PID(HeaterExtruder1, 'E', 0, TempExt1, PWMExtruder1, 330, 255, 1000, 10, 20000, 18.61, 2.15, 40.19, 40, 220, false)
HEAT_MANAGER_PID(HeaterExtruder2, 'E', 1, TempExt2, PWMExtruder2, 330, 255, 1000, 10, 20000, 20.0, 0.6, 65.0, 40, 220, false)
HEAT_MANAGER_PID(HeatedChamber, 'C', 0, TempChamber, PWMChamber, 100, 255, 1000, 10, 30000, 174.17, 32.2, 235.55, 40, 220, false)

// HEAT_MANAGER_DYN_DEAD_TIME(HeaterExtruder1, 'E', 0, TempExt1, PWMExtruder1, 260, 255, 100, 10, 20000, 150, 7, 7, 200, 7, 7, false)
// HEAT_MANAGER_DYN_DEAD_TIME(HeaterExtruder2, 'E', 1, TempExt2, PWMExtruder2, 260, 255, 100, 10, 20000, 150, 7, 7, 200, 7, 7, false)

// Coolers are stand alone functions that allow it to control
// a fan with external sensors. Many extruders require a cooling
// fan pointer to the extruder to prevent heat rising up.
// These can be controlled by the cooler. Since it is
// independent you just tell what part needs cooling.
// Other use cases are board cooling and heated chambers.

// Define tools. They get inserted into a tool array in configuration.h
// Typical tools are:
// TOOL_EXTRUDER(name, offx, offy, offz, heater, stepper, resolution, yank, maxSpeed, acceleration, advance, startScript, endScript)

TOOL_EXTRUDER(ToolExtruder1, 0, 0, 0, HeaterExtruder1, /*AL1Motor */ E1Motor, 2.85, 824.0, 5, 30, 5000, 0, "M117 Extruder 1", "", &Fan1PWM)
TOOL_EXTRUDER(ToolExtruder2, 16.775, 0.615, -0.97, HeaterExtruder2, /*AL2Motor */ E2Motor, 2.85, 824.0, 5, 30, 5000, 0, "M117 Extruder 2\nM400\nM340 P0 S1500 R600\nG4 P300", "M340 P0 S800 R600\nG4 P300", &Fan1PWM)
TOOL_LASER(Laser3, 0, 0, 0, Fan1NoKSPWM, fakeOut, fakeOut, 3000, 1, 100, 150.0, 1.5, "", "")
TOOL_CNC(CNC4, 0, 0, 0, Fan1NoKSPWM, fakeOut, fakeOut, fakeOut, 7000, 3000, "", "")

// Use a signal that changes while extruder moves
#ifdef UI_NEOPIXEL_PIN
// We have a display with neopixel
LIGHT_STATE_RGB_PRESET(uiBacklight, 255, 0, 0, UI_NEOPIXEL_BRIGHTNESS)
LIGHT_SOURCE_NEOPIXEL(uiBacklightDriver, UI_NEOPIXEL_PIN, NEO_GRBW, 1, uiBacklight)
#endif

// IO_INPUT_LOG(IOJam1Mon, IOJam1, true)
// IO_INPUT_LOG(IOJam2Mon, IOJam2, true)
// FILAMENT_DETECTOR(JamDetector1, IOJam1, ToolExtruder1)

// IO_OUTPUT(caseLightPin, LED_PIN)
// IO_PWM_HARDWARE(caseLightPWM, LED_PIN, 500)
// LIGHT_STATE_PWM(caseLightState)
// LIGHT_COND(caseLightState, true, Printer::caseLightMode, 255, 255, 255,           Printer::caseLightBrightness)
// LIGHT_COND(caseLightState, GUI::statusLevel == GUIStatusLevel::ERROR,        LIGHT_STATE_BLINK_SLOW, 255, 255, 255, Printer::caseLightBrightness)
// LIGHT_SOURCE_PWM(caseLightDriver, caseLightPWM, caseLightState)

// Define beeper output
#if BEEPER_PIN > -1
IO_OUTPUT(IOBeeperMain, BEEPER_PIN)
BEEPER_SOURCE_IO(MainBeeper, IOBeeperMain)
#endif
