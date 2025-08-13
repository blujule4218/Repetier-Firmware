/*
    This file is part of Repetier-Firmware.

    Repetier-Firmware is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Repetier-Firmware is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Repetier-Firmware.  If not, see <http://www.gnu.org/licenses/>.

*/


#define CONFIGURATION_H
// XYZ Stepper resolution. Due to TMC stepper smoothing higher values are not
// required! You can increase them by factor 2. Always change both!
#define MICROSTEPS 16
#define STEPS_FACTOR 1
// Comment to use TMC2130 instead of TMC2660 drivers
// #define USE_TMC2209
#define USE_TMC5160

// ------- No further changes required below --------
// ******* Model dependent changes ***********

/**************** READ FIRST ************************

   This configuration file was created with the configuration tool. For that
   reason, it does not contain the same informations as the original
   Configuration.h file. It misses the comments and unused parts. Open this file
   file in the config tool to see and change the data. You can also upload it to
   newer/older versions. The system will silently add new options, so
   compilation continues to work.

   This file is optimized for version 1.0.0dev
   generator: http://www.repetier.com/firmware/dev/

   If you are in doubt which named functions use which pins on your board,
   please check the pins.h for the used name->pin assignments and your board
   documentation to verify it is as you expect.

*/

// The follwing variables are required early to decide on the right modules.
// #define DEBUG_POS
#define NUM_TOOLS 2
#define NUM_EXTRUDER 2
#define NUM_SERVOS 1
#define MOTHERBOARD MOTHERBOARD_RUMBA32
#define EEPROM_MODE 2
#define RFSERIAL SerialUSB
#define BLUETOOTH_SERIAL -1
#define JSON_OUTPUT 1
#define FEATURE_SERVO 0
#define FEATURE_WATCHDOG 1
#define FEATURE_RETRACTION 1
#define USE_ADVANCE 1
#define NUM_AXES 4         // X,Y,Z and E for extruder A,B,C would be 5,6,7
#define STEPPER_FREQUENCY 200000 // Maximum stepper frequency.
// Update frequency for new blocks. Must be higher then
// PREPARE_FREQUENCY.
// Number of blocks with constant stepper rate per second.
#define PREPARE_FREQUENCY 2000
#define BLOCK_FREQUENCY 1000
#define VELOCITY_PROFILE 2      // 0 = linear, 1 = cubic, 2 = quintic velocity shape
#define SLOW_DIRECTION_CHANGE 1 // can be reason for lost steps on slow drivers
// Smaller segments reduce join speed to prevent vibrations causing lost steps
#define SMALL_SEGMENT_SIZE 0.4
#define Z_SPEED 10    // Z positioning speed
#define XY_SPEED 150 // XY positioning speed for normal operations
#define E_SPEED 2                    // Extrusion speed
// Speed for G0 moves. Independent from set F value! Set 0 to use F value.
#define G0_FEEDRATE 0
#define MAX_ROOM_TEMPERATURE 25 // No heating below this temperature!
// Start with controlling if temperature is +/- this value to target temperature
#define TEMPERATURE_CONTROL_RANGE 20
#define HOST_RESCUE 0 // Enable host rescue help system
// #define DEBUG_RESCUE                 // Uncomment to add power loss entry in debug menu while printing
#define POWERLOSS_LEVEL 2 // How much time do we have on powerloss, 0 = no move, 1 = short just raise Z, 2 = long full park move
#define POWERLOSS_UP 0    // How much to move up if mode 1 is active
// #################### Z-Probing #####################


#define Z_PROBE_Z_OFFSET_MODE 1
#define UI_BED_COATING 1
#define EXTRUDER_IS_Z_PROBE 0
#define Z_PROBE_DISABLE_HEATERS 1
#define Z_PROBE_REQUIRES_HEATING 1
#define Z_PROBE_MIN_TEMPERATURE 150
#define Z_PROBE_PAUSE_HEATERS 0         // Pause all heaters when probing to reduce EMI artifacts
#define Z_PROBE_PAUSE_BED_REHEAT_TEMP 5 // Stop and reheat the bed if we leave the target temp by this much.

// How to correct rotated beds
// 0 = Software side by rotating coordinates
// 1 = Move bed physically using 2 motors
#define LEVELING_CORRECTOR 0
// Bed fixture coordinates for motor leveling
#define LC_P1_X 55
#define LC_P1_Y 130
#define LC_P2_X 137
#define LC_P2_Y 45
#define LC_P3_X 137
#define LC_P3_Y 210
#define LC_P2_MOTOR AL1Motor
#define LC_P3_MOTOR AL2Motor
#define LC_STEPS_PER_MM 3382
#define LC_Z_SPEED 0.2
// > 0 will move bed down and wait for removal (heater removed) and will pause another LC_WAIT_BED_REMOVE seconds
#define LC_WAIT_BED_REMOVE 2
// Uncomment to limit correction per autoleveling iteration. Value is the max. correction in mm
// #define LIMIT_MOTORIZED_CORRECTION 0.5
#define Z_PROBE_TYPE Z_PROBE_TYPE_BLTOUCH
#define Z_PROBE_HEIGHT 5        // Distance bed-nozzle when trigger switches
#define Z_PROBE_BED_DISTANCE 10 // Optimal starting distance
#define Z_PROBE_SPEED 5         // Speed fo z testing
#define Z_PROBE_X_OFFSET 30     // x offset relative to extruder 0,0 offset
#define Z_PROBE_Y_OFFSET -23    // y offset relative to extruder 0,0 offset
#define Z_PROBE_COATING 0       // Coating thickness if not detected by probe
// Extra delay before starting again. Only needed on electronic probes keeping
// state for a while
#define Z_PROBE_DELAY 0
#define Z_PROBE_REPETITIONS 1 // How often should we probe, 1 is minimum
// 0 = use average, 1 = use middle value after ordering z
#define Z_PROBE_USE_MEDIAN 1
// Minimum distance required to safely untrigger probe - used for faster
// repeated measurement
#define Z_PROBE_SWITCHING_DISTANCE 1
#define Z_PROBE_BORDER 5 // Safety border to ensure position is allowed
#define Z_PROBE_START_SCRIPT ""
#define Z_PROBE_FINISHED_SCRIPT ""
#define Z_PROBE_RUN_AFTER_EVERY_PROBE ""
#define LEVELING_METHOD 1 // Grid measurement
#define MAX_GRID_SIZE \
    6                                     // Maximum grid size allocation in memory, imported grid can be smaller
#define ENABLE_BUMP_CORRECTION 1          // CPU intensive, so only activate if required
#define BUMP_CORRECTION_START_DEGRADE 0.5 // Until this height we correct 100%
#define BUMP_CORRECTION_END_HEIGHT 2      // From this height on we do no correction
#define BUMP_LIMIT_TO 2                   // Maximum allowed correction up/down

// 0 = Cartesian, 1 = CoreXYZ, 2 = delta, 3 = Dual X-Axis
#define PRINTER_TYPE PRINTER_TYPE_CARTESIAN
// steps to include as babysteps per 1/BLOCK_FREQUENCY seconds. Must be lower
// then STEPPER_FREQUENCY/BLOCK_FREQUENCY and be low enough to not loose steps.
#define BABYSTEPS_PER_BLOCK \
    { 10, 10, 10 }
// If all axis end stops are hardware based we can skip the time consuming tests
// each step
#define NO_SOFTWARE_AXIS_ENDSTOPS
// Normally only a delta has motor end stops required. Normally you trigger
// using axis endstops.
#define NO_MOTOR_ENDSTOPS
#define FEATURE_CONTROLLER CONTROLLER_REPRAPDISCOUNT_GLCD
// Use more memory to speedup display updates
#define DISPLAY_FULL_BUFFER 1
// Direction 1 or -1
// #define ENCODER_DIRECTION -1
// Uncomment to hide toogle light menu entry in controls
// #define NO_LIGHT_CONTROL
// Encoder speed 0 = fastest, 1 or 2 = slowest - set so 1 click is one menu move
// Default is 2 if not set by controller. Us eonly to fix wrong setting
 #define ENCODER_SPEED 1
// Set 1 if you want to replace the default themes and define them in
// configuration_io.h
#define CUSTOM_DEFAULT_THEMES 0

// Dynamically increase the speed at which we step through the menus/change values.
// Set ENCODER_MAX_REPEAT_STEPS to 1 to disable this. EEPROM/Runtime configurable. (Set to 0 to compile out entirely for extra RAM)
#define ENCODER_MAX_REPEAT_STEPS 5            // Max. extra steps we can gain.
#define ENCODER_MAX_REPEAT_TIME_MS 40         // Max. time we have before our extra steps reset.
#define ENCODER_MIN_REPEAT_TIME_MS 15         // At this repeat rate we accumulate to the max step speed.
#define ENCODER_APPLY_REPEAT_STEPS_IN_MENUS 1 // Set to 0 to only affect changing config values.

// Default materials in temperature menus. First value is extruder temp, then bed and chamber temperature. 0 = do not show.
#define DEFAULT_MATERIALS \
    DEFAULT_MATERIAL(Com::tMatPLA, 215, 60, 0) \
    DEFAULT_MATERIAL(Com::tMatPET, 230, 55, 0) \
    DEFAULT_MATERIAL(Com::tMatASA, 260, 105, 0) \
    DEFAULT_MATERIAL(Com::tMatPC, 275, 110, 0) \
    DEFAULT_MATERIAL(Com::tMatABS, 255, 100, 0) \
    DEFAULT_MATERIAL(Com::tMatHIPS, 220, 100, 0) \
    DEFAULT_MATERIAL(Com::tMatPP, 254, 100, 0) \
    DEFAULT_MATERIAL(Com::tMatFLEX, 240, 50, 0)
/* Ratios for core xyz. First index denotes motor and second axis.
For each motor you can set the ratio of x,y,z position that adds
to the position. 0 = no contribution. */
// X motor = x + y
#define COREXYZ_X_X 1
#define COREXYZ_X_Y 1
#define COREXYZ_X_Z 0
// Y motor = x - y
#define COREXYZ_Y_X 1
#define COREXYZ_Y_Y -1
#define COREXYZ_Y_Z 0
// Z motor = z
#define COREXYZ_Z_X 0
#define COREXYZ_Z_Y 0
#define COREXYZ_Z_Z 1

// Special geometry definition if printer type is delta
/*  =========== Parameter essential for delta calibration ===================

            C, Y-Axis
            |                        |___| Carriage horizontal offset
            |                        |
   \------------------------------------------
            |_________ X-axis        |    \ | / \                       |     \
   DELTA_DIAGONAL (length)    Each move this Rod Height /   \ \ is calculated /
   \                             \    Carriage is at printer center!   | A B
   \_____/--------------------------------
                                              |--| End effector horizontal
   offset (recommend set it to 0)
                                         |----| DELTA_HORIZONTAL_RADIUS
   (Horizontal rod pivot to pivot measure)

    Column angles are measured from X-axis counterclockwise
    "Standard" positions: alpha_A = 210, alpha_B = 330, alpha_C = 90
*/
#define DELTA_DIAGONAL 444.800f
#define DELTA_HORIZONTAL_RADIUS 209.900f
#define DELTA_PRINT_RADIUS 209.0f
#define DELTA_ANGLE_A 210.0f
#define DELTA_ANGLE_B 330.0f
#define DELTA_ANGLE_C 90.123f
#define DELTA_CORRECTION_A 0.0f
#define DELTA_CORRECTION_B 0.0f
#define DELTA_CORRECTION_C 0.0f
#define DELTA_RADIUS_CORRECTION_A 0.0f
#define DELTA_RADIUS_CORRECTION_B 0.0f
#define DELTA_RADIUS_CORRECTION_C -0.05f
#define DELTA_HOME_OFFSET_A 2.9f
#define DELTA_HOME_OFFSET_B 0.0f
#define DELTA_HOME_OFFSET_C 0.85f


#define DISABLE_X 0
#define DISABLE_Y 0
#define DISABLE_Z 0


// Next 7 lines are required to make the following work, do not change!
#include "boards/pins.h"
#undef IO_TARGET
#define IO_TARGET IO_TARGET_CLASS_DEFINITION
#undef CONFIG_EXTERN
#define CONFIG_EXTERN extern
#include "drivers/drivers.h"
#include "io/redefine.h"

// Define ZProbe by referencing an endstop defined
CONFIG_VARIABLE_EQ(EndstopDriver, *ZProbe, &endstopZMin)
/** Axes are homed in order of priority (0..10) if homing direction is not 0. */
#define X_HOME_PRIORITY 0
#define Y_HOME_PRIORITY 1
#define Z_HOME_PRIORITY 2

// All fans in this list list become controllable with M106/M107
// by selecteing the fan number with P0..P<NUM_FANS-1>
#define NUM_FANS 1
#define FAN_LIST \
    { &Fan1PWM }

#define NUM_HEATED_BEDS 1
#define HEATED_BED_LIST \
    { &HeatedBed1 }

#define NUM_HEATED_CHAMBERS 1
#define HEATED_CHAMBER_LIST \
    { &HeatedChamber }

#define SERVO_LIST \
    { &ZProbeServo }
#define TOOLS \
    { &ToolExtruder1, &ToolExtruder2 }

// Heaters enumerate all heaters, so we can loop over them
// or call commands on a specific heater number.
// Suggested order: extruder heaters, heated beds, heated chambers, additional
// heaters
#define NUM_HEATERS 4
#define HEATERS \
    { &HeaterExtruder1, &HeaterExtruder2, &HeatedBed1, &HeatedChamber }

// Array to call motor related commands like microstepping/current if supported.
// Id's start at 0 and depend on position in this array.
#define NUM_MOTORS 3
#define MOTORS \
    { &XMotor, &YMotor, &ZMotor }
#define MOTOR_NAMES \
    { PSTR("X"), PSTR("Y"), PSTR("Z") }

// Define beeper list
#if BEEPER_PIN > -1
#define NUM_BEEPERS 1
#define BEEPER_LIST \
    { &MainBeeper }
#else
#define NUM_BEEPERS 0
#define BEEPER_LIST \
    { }
#endif

// Some common settings for trinamic driver settings
/**
 Chopper timing is an array with
 {toff, hend, hstrt}
 See TMC datasheets for more details. There are some predefined values to get
 you started: CHOPPER_TIMING_DEFAULT_12V = { 3, -1, 1 }
 CHOPPER_TIMING_DEFAULT_19V = { 4, 1, 1 }
 CHOPPER_TIMING_DEFAULT_24V = { 4, 2, 1 }
 CHOPPER_TIMING_DEFAULT_36V = { 5, 2, 4 }
 CHOPPER_TIMING_PRUSAMK3_24V = { 3, -2, 6 }

*/
#define TMC_CHOPPER_TIMING CHOPPER_TIMING_DEFAULT_24V
// true = interpolate to 256 microsteps for smoother motion
#define TMC_INTERPOLATE true
// Current used when motor stands still
#define TMC_HOLD_MULTIPLIER 0.5
// Reduce current on over temperature warnings by x milli ampere, 0 = disable
#define TMC_CURRENT_STEP_DOWN 50
// Define which data should be stored to eeprom
#define STORE_MOTOR_MICROSTEPPING 1
#define STORE_MOTOR_CURRENT 1
#define STORE_MOTOR_HYBRID_TRESHOLD 1
#define STORE_MOTOR_STEALTH 1
#define STORE_MOTOR_STALL_SENSITIVITY 1

#define X_HOME_DIR -1
#define Y_HOME_DIR -1
#define Z_HOME_DIR 1
#define X_MAX_LENGTH 200
#define Y_MAX_LENGTH 194
#define Z_MAX_LENGTH 220
#define X_MIN_POS 0
#define Y_MIN_POS 0
#define Z_MIN_POS 0
#define BED_X_MIN X_MIN_POS
#define BED_X_MAX (X_MIN_POS + X_MAX_LENGTH)
#define BED_Y_MIN Y_MIN_POS
#define BED_Y_MAX (Y_MIN_POS + Y_MAX_LENGTH)

// Park position used when pausing from firmware side
#if PRINTER_TYPE == PRINTER_TYPE_DELTA
#define PARK_POSITION_X (0)
#define PARK_POSITION_Y (70)
#else
#define PARK_POSITION_X (X_MIN_POS)
#define PARK_POSITION_Y (Y_MIN_POS + Y_MAX_LENGTH)
#endif
#define PARK_POSITION_Z_RAISE 10
#define MAX_ACCELERATION_UNITS_PER_SQ_SECOND_X 1100
#define MAX_ACCELERATION_UNITS_PER_SQ_SECOND_Y 1100
#define MAX_ACCELERATION_UNITS_PER_SQ_SECOND_Z 40
#define MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_X 1000
#define MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_Y 1000
#define MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_Z 15
#define XAXIS_STEPS_PER_MM 80
#define YAXIS_STEPS_PER_MM 80
#define ZAXIS_STEPS_PER_MM 1600
#define MAX_FEEDRATE_X 200
#define MAX_FEEDRATE_Y 200
#define MAX_FEEDRATE_Z 25
//#define EXTERNALSERIAL  use Arduino serial library instead of build in.
// Requires more ram, has only 63 byte input buffer.
// Uncomment the following line if you are using Arduino compatible firmware
// made for Arduino version earlier then 1.0 If it is incompatible you will get
// compiler errors about write functions not being compatible!
//#define COMPAT_PRE1
// ################## EDIT THESE SETTINGS MANUALLY ################
// ################ END MANUAL SETTINGS ##########################



#define KILL_IF_SENSOR_DEFECT 0
#define RETRACT_ON_PAUSE 2
#define PAUSE_START_COMMANDS ""
#define PAUSE_END_COMMANDS ""

#define AUTORETRACT_ENABLED 0
#define RETRACTION_LENGTH 3
#define RETRACTION_LONG_LENGTH 13
#define RETRACTION_SPEED 40
#define RETRACTION_Z_LIFT 0
#define RETRACTION_UNDO_EXTRA_LENGTH 0
#define RETRACTION_UNDO_EXTRA_LONG_LENGTH 0
#define RETRACTION_UNDO_SPEED 25
#define FILAMENTCHANGE_X_POS 5
#define FILAMENTCHANGE_Y_POS 5
#define FILAMENTCHANGE_Z_ADD 2
#define FILAMENTCHANGE_REHOME 1
#define FILAMENTCHANGE_SHORTRETRACT 2.5
#define FILAMENTCHANGE_LONGRETRACT 50
#define JAM_ACTION 1

#define PID_CONTROL_RANGE 20
#define SKIP_M109_IF_WITHIN 5
#define TEMP_HYSTERESIS 0
#define EXTRUDE_MAXLENGTH 160

// ############# Heated bed configuration ########################

#define MIN_EXTRUDER_TEMP 150

// ################ Endstop/homing configuration #####################

#define DOOR_PIN -1
#define DOOR_PULLUP 1
#define DOOR_INVERTING 1
#define ENDSTOP_X_BACK_MOVE 3
#define ENDSTOP_Y_BACK_MOVE 3
#define ENDSTOP_Z_BACK_MOVE 25
#define ENDSTOP_X_RETEST_REDUCTION_FACTOR 2
#define ENDSTOP_Y_RETEST_REDUCTION_FACTOR 2
#define ENDSTOP_Z_RETEST_REDUCTION_FACTOR 2
#define ENDSTOP_X_BACK_ON_HOME 0.5
#define ENDSTOP_Y_BACK_ON_HOME 0.5
#define ENDSTOP_Z_BACK_ON_HOME 0
#define ALWAYS_CHECK_ENDSTOPS 0
#define HOMING_FEEDRATE_X 25
#define HOMING_FEEDRATE_Y 25
#define HOMING_FEEDRATE_Z 25
#define HOMING_FEEDRATE_A 25
#define ZHOME_PRE_RAISE 1
#define ZHOME_PRE_RAISE_DISTANCE 10
#define RAISE_Z_ON_TOOLCHANGE 1
#define ZHOME_MIN_TEMPERATURE 0
#define ZHOME_HEAT_ALL 0
#define ZHOME_HEIGHT 210
// Need to ensure we are above bed when using z probe
#define FIXED_Z_HOME_POSITION 1
#define ZHOME_X_POS 50
#define ZHOME_Y_POS 75

// ################# XYZ movements ###################

#define PREVENT_Z_DISABLE_ON_STEPPER_TIMEOUT 0

// ##########################################################################################
// ##                           Movement settings ##
// ##########################################################################################
#define FEATURE_BABYSTEPPING 1
#define BABYSTEP_MULTIPLICATOR 64
// Delta settings
#define DELTA_HOME_ON_POWER 0

#define STEPPER_INACTIVE_TIME 360L
#define MAX_INACTIVE_TIME 1200L

#define ENABLE_BACKLASH_COMPENSATION 0
#define X_BACKLASH 0
#define Y_BACKLASH 0
#define Z_BACKLASH 0
#define MAX_JERK 10
#define MAX_ZJERK 0.5
#define PRINTLINE_CACHE_SIZE 32

// ################# Misc. settings ##################

#define BAUDRATE 250000
#define ENABLE_POWER_ON_STARTUP 1
#define POWER_INVERTING 0
#undef PS_ON_PIN
#define PS_ON_PIN -1

#define FEATURE_AXISCOMP 0
#define AXISCOMP_TANXY 0
#define AXISCOMP_TANYZ 0
#define AXISCOMP_TANXZ 0

// Some boards have sd support on board. These define the
// values already in pins.h
#ifndef SDSUPPORT
#define SDSUPPORT 1
#undef SDCARDDETECT
#define SDCARDDETECT ORIG_SDCARDDETECT
#define SDCARDDETECTINVERTED 0
#endif
/** Show extended directory including file length. Don't use this with
         Pronterface! */
#define SD_EXTENDED_DIR 1
#define SD_RUN_ON_STOP ""
#define SD_STOP_HEATER_AND_MOTORS_ON_STOP 1
#define ARC_SUPPORT 0
#define FEATURE_MEMORY_POSITION 1
#define FEATURE_CHECKSUM_FORCED 0
#define UI_PRINTER_NAME "K8200 MAX"
#define UI_PRINTER_COMPANY "3D ADDITIVES"
#define UI_PAGES_DURATION 4000
#define UI_SPEEDDEPENDENT_POSITIONING 0
#define UI_DISABLE_AUTO_PAGESWITCH 1
#define UI_AUTORETURN_TO_MENU_AFTER 30000
#define FEATURE_UI_KEYS 0
#define UI_ENCODER_SPEED 2
#define UI_REVERSE_ENCODER 0
#define UI_KEY_BOUNCETIME 10
#define UI_KEY_FIRST_REPEAT 500
#define UI_KEY_REDUCE_REPEAT 50
#define UI_KEY_MIN_REPEAT 50
#define CASE_LIGHTS_PIN 25
#define CASE_LIGHT_DEFAULT_ON 1
#define UI_START_SCREEN_DELAY 2000

//#define CUSTOM_EVENTS

