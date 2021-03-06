#
# __init__.py - Python bindings for Strawson Design's libroboticscape
# Copyright (C) 2017 Torsten Kurbad <beaglebone@tk-webart.de>
#

import atexit
from enum import IntEnum

from _roboticscape import *
from _roboticscape import _rcInitializeBarometer

# Meta definitions
class MyIntEnum(IntEnum):
    """ Add class method has_value to IntEnum to check whether a certain
        value exists in an enum.
    """
    @classmethod
    def has_value(cls, value):
        return (any(value == item.value for item in cls))


# Type definitions
class State(MyIntEnum):
    """ Enumeration of possible states from rcGetState(), and for
        rcSetState()
    """
    UNINITIALIZED   = 0
    RUNNING         = 1
    PAUSED          = 2
    EXITING         = 3


class PowerState(MyIntEnum):
    """ Enumeration of possible power states. """
    OFF             = 0
    ON              = 1


class LED(MyIntEnum):
    """ Enumeration of available LEDs. """
    GREEN           = 0
    RED             = 1


class Button(MyIntEnum):
    """ Enumeration of available buttons. """
    PAUSE           = 0
    MODE            = 1


class ButtonState(MyIntEnum):
    """ Enumeration of possible button states. """
    RELEASED        = 0
    PRESSED         = 1


class BMPOversample(MyIntEnum):
    """ Enumeration of BMP280 oversample settings. """
    BMP_OVERSAMPLE_1    = 4     # update rate 182 HZ
    BMP_OVERSAMPLE_2    = 8     # update rate 133 HZ
    BMP_OVERSAMPLE_4    = 12    # update rate 87 HZ
    BMP_OVERSAMPLE_8    = 16    # update rate 51 HZ
    BMP_OVERSAMPLE_16   = 20    # update rate 28 HZ


class BMPFilter(MyIntEnum):
    """ Enumeration of BMP280 filter settings. """
    BMP_FILTER_OFF      = 0
    BMP_FILTER_2        = 4
    BMP_FILTER_4        = 8
    BMP_FILTER_8        = 12
    BMP_FILTER_16       = 16


class CPUFreq(MyIntEnum):
    """ Enumeration of possible CPU frequencies. """
    FREQ_ONDEMAND   = 0
    FREQ_300MHZ     = 1
    FREQ_600MHZ     = 2
    FREQ_800MHZ     = 3
    FREQ_1000MHZ    = 4


class BBModel(MyIntEnum):
    UNKNOWN_MODEL   = 0
    BB_BLACK        = 1
    BB_BLACK_RC     = 2
    BB_BLACK_W      = 3
    BB_BLACK_W_RC   = 4
    BB_GREEN        = 5
    BB_GREEN_W      = 6
    BB_BLUE         = 7


# High level methods
def rcGetStateAsEnum():
    """ Get the current robot state as Python Enum. """
    state = rcGetState()
    return State(state)

def rcGetGreenLED():
    """ Get state of green LED as Enum. """
    return PowerState(rcGetLED(LED.GREEN.value))

def rcGetRedLED():
    """ Get state of red LED as Enum. """
    return PowerState(rcGetLED(LED.RED.value))

def rcSetGreenLEDOn():
    """ Turn green LED on. """
    return rcSetLED(LED.GREEN.value, PowerState.ON.value)

def rcSetGreenLEDOff():
    """ Turn green LED off. """
    return rcSetLED(LED.GREEN.value, PowerState.OFF.value)

def rcSetRedLEDOn():
    """ Turn red LED on. """
    return rcSetLED(LED.RED.value, PowerState.ON.value)

def rcSetRedLEDOff():
    """ Turn red LED off. """
    return rcSetLED(LED.RED.value, PowerState.OFF.value)

def rcGetModeButton():
    """ Get state of mode button as Enum. """
    return ButtonState(rcGetButton(Button.MODE.value))

def rcGetPauseButton():
    """ Get state of pause button as Enum. """
    return ButtonState(rcGetButton(Button.PAUSE.value))

def rcInitializeBarometer(
    bmpOversample = BMPOversample.BMP_OVERSAMPLE_1.value,
    bmpFilter = BMPFilter.BMP_FILTER_OFF.value):
    """ Initialize and power on barometer. """
    if not BMPOversample.has_value(bmpOversample):
        raise(ValueError('oversample value %d not allowed' % bmpOversample))
    if not BMPFilter.has_value(bmpFilter):
        raise(ValueError('filter value %d not allowed' % bmpFilter))
    return _rcInitializeBarometer(bmpOversample, bmpFilter)

def rcSetCPUFreqEnum(frequency):
    """ Set the CPU frequency of the BeagleBone using values provided by
        the CPUFreq Enum.
    """
    if isinstance(frequency, int):
        rcSetCPUFreq(frequency)
    if isinstance(frequency, CPUFreq):
        rcSetCPUFreq(frequency.value)

def rcGetCPUFreqEnum():
    """ Get the currently set BeagleBone CPU frequency as member of the
        CPUFreq Enum.
    """
    return CPUFreq(rcGetCPUFreq())

def rcGetBBModelEnum():
    """ Get the BeagleBone model as member of the BBModel Enum. """
    return BBModel(rcGetBBModel())


# Event handlers
""" Call the cleanup method on exit. """
atexit.register(rcCleanup)
