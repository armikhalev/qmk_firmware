ifndef QUANTUM_DIR
	include ../../../../Makefile
endif

MOUSEKEY_ENABLE = yes        # Mouse keys(+4700)
STENO_ENABLE = yes          # Additional protocols for Stenography(+1700), requires VIRTSER
AUDIO_ENABLE = no           # Audio output on port C6
MIDI_ENABLE = no            # MIDI controls

BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration(+1000)
EXTRAKEY_ENABLE = no       # Audio control and System control(+450)
CONSOLE_ENABLE = no         # Console for debug(+400)
COMMAND_ENABLE = no        # Commands for debug and configuration
NKRO_ENABLE = yes            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE =  no           # Audio output on port C6
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.
API_SYSEX_ENABLE = no

TAP_DANCE_ENABLE = no 	    # Allow multiple repeated key presses to be interpret as a different key(s)
