/*
 * roboticscapemodule.h - Python bindings for Strawson Design's
 * libroboticscape
 * 
 * Copyright (C) 2017 Torsten Kurbad <beaglebone@tk-webart.de>
 *
 */

#include <Python.h>
#include <roboticscape.h>

// Constants
#define RED_LED 	66	// gpio2.2	P8.7
#define GRN_LED 	67	// gpio2.3	P8.8


// Method headers
static PyObject *rcInitialize(PyObject *self, PyObject *args);
static PyObject *rcCleanup(PyObject *self, PyObject *args);

static PyObject *rcGetState(PyObject *self, PyObject *args);
static PyObject *rcSetState(PyObject *self, PyObject *args);

static PyObject *rcGetLED(PyObject *self, PyObject *args);
static PyObject *rcSetLED(PyObject *self, PyObject *args);
static PyObject *rcBlinkLED(PyObject *self, PyObject *args);

static PyObject *rcGetButton(PyObject *self, PyObject *args);

static PyObject *rcEnableMotors(PyObject *self, PyObject *args);
static PyObject *rcDisableMotors(PyObject *self, PyObject *args);
static PyObject *rcSetMotor(PyObject *self, PyObject *args);
static PyObject *rcSetMotorAll(PyObject *self, PyObject *args);
static PyObject *rcSetMotorFreeSpin(PyObject *self, PyObject *args);
static PyObject *rcSetMotorFreeSpinAll(PyObject *self, PyObject *args);
static PyObject *rcSetMotorBrake(PyObject *self, PyObject *args);
static PyObject *rcSetMotorBrakeAll(PyObject *self, PyObject *args);

static PyObject *rcGetEncoderPos(PyObject *self, PyObject *args);
static PyObject *rcSetEncoderPos(PyObject *self, PyObject *args);

static PyObject *rcBatteryVoltage(PyObject *self, PyObject *args);
static PyObject *rcDCJackVoltage(PyObject *self, PyObject *args);

static PyObject *rcADCRaw(PyObject *self, PyObject *args);
static PyObject *rcADCVolt(PyObject *self, PyObject *args);

static PyObject *rcEnableServoPowerRail(PyObject *self, PyObject *args);
static PyObject *rcDisableServoPowerRail(PyObject *self, PyObject *args);
static PyObject *rcSendServoPulseUs(PyObject *self, PyObject *args);
static PyObject *rcSendServoPulseUsAll(PyObject *self, PyObject *args);
static PyObject *rcSendServoPulseNormalized(PyObject *self, PyObject *args);
static PyObject *rcSendServoPulseNormalizedAll(PyObject *self, PyObject *args);
static PyObject *rcSendESCPulseNormalized(PyObject *self, PyObject *args);
static PyObject *rcSendESCPulseNormalizedAll(PyObject *self, PyObject *args);
static PyObject *rcSendOneshotPulseNormalized(PyObject *self, PyObject *args);
static PyObject *rcSendOneshotPulseNormalizedAll(PyObject *self, PyObject *args);

static PyObject *rcInitializeDSM(PyObject *self, PyObject *args);
static PyObject *rcStopDSMService(PyObject *self, PyObject *args);
static PyObject *rcGetDSMChRaw(PyObject *self, PyObject *args);
static PyObject *rcGetDSMChNormalized(PyObject *self, PyObject *args);
static PyObject *rcIsDSMNewData(PyObject *self, PyObject *args);
static PyObject *rcIsDSMActive(PyObject *self, PyObject *args);
static PyObject *rcNanosSinceLastDSMPacket(PyObject *self, PyObject *args);
static PyObject *rcGetDSMResolution(PyObject *self, PyObject *args);
static PyObject *rcNumDSMChannels(PyObject *self, PyObject *args);
static PyObject *rcBindDSM(PyObject *self, PyObject *args);
static PyObject *rcCalibrateDSMRoutine(PyObject *self, PyObject *args);

// TODO: IMU methods

static PyObject *_rcInitializeBarometer(PyObject *self, PyObject *args);
static PyObject *rcPowerOffBarometer(PyObject *self, PyObject *args);
static PyObject *rcReadBarometer(PyObject *self, PyObject *args);
static PyObject *rcGetBMPTemperature(PyObject *self, PyObject *args);
static PyObject *rcGetBMPPressurePa(PyObject *self, PyObject *args);
static PyObject *rcGetBMPAltitudeM(PyObject *self, PyObject *args);
static PyObject *rcSetBMPSeaLevelPressurePa(PyObject *self, PyObject *args);

static PyObject *rcInitializeI2C(PyObject *self, PyObject *args);
static PyObject *rcCloseI2C(PyObject *self, PyObject *args);
static PyObject *rcSetI2CDeviceAddress(PyObject *self, PyObject *args);
static PyObject *rcClaimI2CBus(PyObject *self, PyObject *args);
static PyObject *rcReleaseI2CBus(PyObject *self, PyObject *args);
static PyObject *rcGetI2CBusInUse(PyObject *self, PyObject *args);
static PyObject *rcReadI2CByte(PyObject *self, PyObject *args);
static PyObject *rcReadI2CBytes(PyObject *self, PyObject *args);
static PyObject *rcReadI2CWord(PyObject *self, PyObject *args);
static PyObject *rcReadI2CWords(PyObject *self, PyObject *args);
static PyObject *rcReadI2CBit(PyObject *self, PyObject *args);
static PyObject *rcWriteI2CByte(PyObject *self, PyObject *args);
static PyObject *rcWriteI2CBytes(PyObject *self, PyObject *args);
static PyObject *rcWriteI2CWord(PyObject *self, PyObject *args);
static PyObject *rcWriteI2CWords(PyObject *self, PyObject *args);
static PyObject *rcWriteI2CBit(PyObject *self, PyObject *args);
static PyObject *rcSendI2CByte(PyObject *self, PyObject *args);
static PyObject *rcSendI2CBytes(PyObject *self, PyObject *args);

// TODO: SPI, UART methods

static PyObject *rcSetCPUFreq(PyObject *self, PyObject *args);
static PyObject *rcGetCPUFreq(PyObject *self, PyObject *args);

static PyObject *rcGetBBModel(PyObject *self, PyObject *args);


// Method definitions
static PyMethodDef RoboticsCapeMethods[] = {
    {"rcInitialize", rcInitialize, METH_NOARGS,
        "Initialize RoboticsCape hard- and software."},
    {"rcCleanup", rcCleanup, METH_NOARGS,
        "Shut down RoboticsCape library and functions."},
    {"rcGetState", rcGetState, METH_NOARGS,
        "Get high level robot state."},
    {"rcSetState", rcSetState, METH_VARARGS,
        "Set high level robot state."},
    {"rcGetLED", rcGetLED, METH_VARARGS,
        "Get state of green or red LED (0 = off, 1 = on)."},
    {"rcSetLED", rcSetLED, METH_VARARGS,
        "Turn on/off green or red LED (0 = off, 1 = on)."},
    {"rcBlinkLED", rcBlinkLED, METH_VARARGS,
        "Blink green or red LED with a given frequency (Hz) for a finite period (s)."},
    {"rcGetButton", rcGetButton, METH_VARARGS,
        "Get state of pause (0) or mode (1) button (0 = released, 1 = pressed)."},
    {"rcEnableMotors", rcEnableMotors, METH_NOARGS,
        "Enable motor controller."},
    {"rcDisableMotors", rcDisableMotors, METH_NOARGS,
        "Disable motor controller."},
    {"rcSetMotor", rcSetMotor, METH_VARARGS,
        "Set direction and power of a single motor."},
    {"rcSetMotorAll", rcSetMotorAll, METH_VARARGS,
        "Set direction and power of all motors."},
    {"rcSetMotorFreeSpin", rcSetMotorFreeSpin, METH_VARARGS,
        "Let a single motor spin freely."},
    {"rcSetMotorFreeSpinAll", rcSetMotorFreeSpinAll, METH_NOARGS,
        "Let all motors spin freely."},
    {"rcSetMotorBrake", rcSetMotorBrake, METH_VARARGS,
        "Engage brake on a single motor."},
    {"rcSetMotorBrakeAll", rcSetMotorBrakeAll, METH_NOARGS,
        "Engage brake on all motors."},
    {"rcGetEncoderPos", rcGetEncoderPos, METH_VARARGS,
        "Get quadrature encoder position for given channel (1-4)."},
    {"rcSetEncoderPos", rcSetEncoderPos, METH_VARARGS,
        "Set quadrature encoder position for given channel (1-4)."},
    {"rcBatteryVoltage", rcBatteryVoltage, METH_NOARGS,
        "Get LiPo battery voltage."},
    {"rcDCJackVoltage", rcDCJackVoltage, METH_NOARGS,
        "Get DC jack voltage."},
    {"rcADCRaw", rcADCRaw, METH_VARARGS,
        "Get raw ADC value for given channel (0-6)."},
    {"rcADCVolt", rcADCVolt, METH_VARARGS,
        "Get ADC voltage for given channel (0-6)."},
    {"rcEnableServoPowerRail", rcEnableServoPowerRail, METH_NOARGS,
        "Enable servo 6V power rail."},
    {"rcDisableServoPowerRail", rcDisableServoPowerRail, METH_NOARGS,
        "Disable servo 6V power rail."},
    {"rcSendServoPulseUs", rcSendServoPulseUs, METH_VARARGS,
        "Send a single pulse with duration as milliseconds to the given servo channel."},
    {"rcSendServoPulseUsAll", rcSendServoPulseUsAll, METH_VARARGS,
        "Send a single pulse with duration as milliseconds to all servo channels."},
    {"rcSendServoPulseNormalized", rcSendServoPulseNormalized, METH_VARARGS,
        "Send a normalized pulse (range -1.5 ~ 1.5) to the given servo channel."},
    {"rcSendServoPulseNormalizedAll", rcSendServoPulseNormalizedAll, METH_VARARGS,
        "Send a normalized pulse (range -1.5 ~ 1.5) to all servo channels."},
    {"rcSendESCPulseNormalized", rcSendESCPulseNormalized, METH_VARARGS,
        "Send a normalized pulse (range -0.1 ~ 1.0) to the given ESC channel."},
    {"rcSendESCPulseNormalizedAll", rcSendESCPulseNormalizedAll, METH_VARARGS,
        "Send a normalized pulse (range -0.1 ~ 1.0) to all ESC channels."},
    {"rcSendOneshotPulseNormalized", rcSendOneshotPulseNormalized, METH_VARARGS,
        "Send a normalized oneshot pulse (range -0.1 ~ 1.0) to the given ESC channel."},
    {"rcSendOneshotPulseNormalizedAll", rcSendOneshotPulseNormalizedAll, METH_VARARGS,
        "Send a normalized oneshot pulse (range -0.1 ~ 1.0) to all ESC channels."},
    {"rcInitializeDSM", rcInitializeDSM, METH_NOARGS,
        "Start the DSM reception background service."},
    {"rcStopDSMService", rcStopDSMService, METH_NOARGS,
        "Stop the DSM reception background service."},
    {"rcGetDSMChRaw", rcGetDSMChRaw, METH_VARARGS,
        "Get the pulse width send by the transmitter to the given channel."},
    {"rcGetDSMChNormalized", rcGetDSMChNormalized, METH_VARARGS,
        "Get normalized values (range -1.0 ~ 1.0) of the given channel according to (mandatory) calibration."},
    {"rcIsDSMNewData", rcIsDSMNewData, METH_NOARGS,
        "Check whether new DSM data is available (1 - true | 0 - false)."},
    {"rcIsDSMActive", rcIsDSMActive, METH_NOARGS,
        "Check DSM packet health (1 - no errors | 0 - timeouts and/or packet errors)."},
    {"rcNanosSinceLastDSMPacket", rcNanosSinceLastDSMPacket, METH_NOARGS,
        "Get nanoseconds since last DSM packet has been received."},
    {"rcGetDSMResolution", rcGetDSMResolution, METH_NOARGS,
        "Get DSM resolution (returns 10 or 11 [bits], 0 if unknown)."},
    {"rcNumDSMChannels", rcNumDSMChannels, METH_NOARGS,
        "Get number of channels currently being sent (0 if no packet received yet)."},
    {"rcBindDSM", rcBindDSM, METH_NOARGS,
        "Put DSM receiver in bind mode."},
    {"rcCalibrateDSMRoutine", rcCalibrateDSMRoutine, METH_NOARGS,
        "Start DSM calibration routine."},

    {"_rcInitializeBarometer", _rcInitializeBarometer, METH_VARARGS,
        "Power on and initialize barometer with the given oversample and filter settings."},
    {"rcPowerOffBarometer", rcPowerOffBarometer, METH_NOARGS,
        "Power off barometer."},
    {"rcReadBarometer", rcReadBarometer, METH_NOARGS,
        "Trigger reading new barometer values to be retrieved by the rcGetBMP* methods."},
    {"rcGetBMPTemperature", rcGetBMPTemperature, METH_NOARGS,
        "Get temperature transmitted during last rcReadBarometer call."},
    {"rcGetBMPPressurePa", rcGetBMPPressurePa, METH_NOARGS,
        "Get pressure in pascal transmitted during last rcReadBarometer call."},
    {"rcGetBMPAltitudeM", rcGetBMPAltitudeM, METH_NOARGS,
        "Get altitude in meters transmitted during last rcReadBarometer call."},
    {"rcSetBMPSeaLevelPressurePa", rcSetBMPSeaLevelPressurePa, METH_VARARGS,
        "Set current sea level pressure to correct altitude reading."},
    {"rcInitializeI2C", rcInitializeI2C, METH_VARARGS,
        "Initialize I²C bus with given bus number and device address."},
    {"rcCloseI2C", rcCloseI2C, METH_VARARGS,
        "Close I²C bus with given bus number and release file descriptors."},
    {"rcSetI2CDeviceAddress", rcSetI2CDeviceAddress, METH_VARARGS,
        "Switch to another device address on an initialized I²C bus."},
    {"rcClaimI2CBus", rcClaimI2CBus, METH_VARARGS,
        "Convenience method to mark I²C bus as being in use."},
    {"rcReleaseI2CBus", rcReleaseI2CBus, METH_VARARGS,
        "Convenience method to mark I²C bus as not being in use."},
    {"rcGetI2CBusInUse", rcGetI2CBusInUse, METH_VARARGS,
        "Convenience method to check whether I²C bus is in use."},
    {"rcReadI2CByte", rcReadI2CByte, METH_VARARGS,
        "Read one byte from a particular I²C device and register."},
    {"rcReadI2CBytes", rcReadI2CBytes, METH_VARARGS,
        "Read a given number of bytes from a particular I²C device and register."},
    {"rcReadI2CWord", rcReadI2CWord, METH_VARARGS,
        "Read one word from a particular I²C device and register."},
    {"rcReadI2CWords", rcReadI2CWords, METH_VARARGS,
        "Read a given number of words from a particular I²C device and register."},
    {"rcReadI2CBit", rcReadI2CBit, METH_VARARGS,
        "Read one bit from a particular I²C device and register."},
    {"rcWriteI2CByte", rcWriteI2CByte, METH_VARARGS,
        "Write one byte to a particular I²C device and register."},
    {"rcWriteI2CBytes", rcWriteI2CBytes, METH_VARARGS,
        "Write a given number of bytes to a particular I²C device and register."},
    {"rcWriteI2CWord", rcWriteI2CWord, METH_VARARGS,
        "Write one word to a particular I²C device and register."},
    {"rcWriteI2CWords", rcWriteI2CWords, METH_VARARGS,
        "Write a given number of words to a particular I²C device and register."},
    {"rcWriteI2CBit", rcWriteI2CBit, METH_VARARGS,
        "Write one bit to a particular I²C device and register."},
    {"rcSendI2CByte", rcSendI2CByte, METH_VARARGS,
        "Write one byte to the I²C bus (= I²C broadcast)."},
    {"rcSendI2CBytes", rcSendI2CBytes, METH_VARARGS,
        "Write a given number of bytes to the I²C bus (= I²C broadcast)."},

    {"rcSetCPUFreq", rcSetCPUFreq, METH_VARARGS,
        "Set CPU frequency."},
    {"rcGetCPUFreq", rcGetCPUFreq, METH_NOARGS,
        "Get CPU frequency setting."},
    {"rcGetBBModel", rcGetBBModel, METH_NOARGS,
        "Get the BeagleBone model."},

    {NULL, NULL, 0, NULL}        /* Sentinel */
};


// Module defintion
static struct PyModuleDef RoboticsCapeModule = {
    PyModuleDef_HEAD_INIT,
    "RoboticsCape",         /* m_name */
                            /* m_doc */
    "This module defines the Python bindings for libroboticscape.\n"
    "libroboticscape is a collection of methods to interact with the\n"
    "BeagleBone Robotics Cape by Strawson Design or the BeagleBone Blue.\n",
    -1,                     /* m_size */
    RoboticsCapeMethods,    /* m_methods */
    NULL,                   /* m_reload */
    NULL,                   /* m_traverse */
    NULL,                   /* m_clear */
    NULL,                   /* m_free */
};
