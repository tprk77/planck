# Copyright (c) 2018 Tim Perkins

# Use this Makefile to enable debug. You will also need `hid_listen`, a little
# utility by PJRC for Teensy 2.0. It dumps debug going over USB HID to a
# terminal. Remember to run it with permissions! See here for details:
# https://www.pjrc.com/teensy/hid_listen.html

# Note that you might need to use a "magic command" to enable debug. By default
# it is `Ctrl + Alt + D` and then `hid_listen` will print "debug: on". For more
# info, see here: https://docs.qmk.fm/#/faq_debug

BOOTMAGIC_ENABLE = no
MOUSEKEY_ENABLE  = no
EXTRAKEY_ENABLE  = yes
CONSOLE_ENABLE   = no
COMMAND_ENABLE   = no
NKRO_ENABLE      = no
BACKLIGHT_ENABLE = no
MIDI_ENABLE      = no
AUDIO_ENABLE     = no
UNICODE_ENABLE   = no

$(info )
$(info ============================================================)
$(info TPRK77 PLANCK CONFIGURATION)
$(info ============================================================)
$(info BOOTMAGIC_ENABLE: ... $(BOOTMAGIC_ENABLE))
$(info MOUSEKEY_ENABLE: .... $(MOUSEKEY_ENABLE))
$(info EXTRAKEY_ENABLE: .... $(EXTRAKEY_ENABLE))
$(info CONSOLE_ENABLE: ..... $(CONSOLE_ENABLE))
$(info COMMAND_ENABLE: ..... $(COMMAND_ENABLE))
$(info NKRO_ENABLE: ........ $(NKRO_ENABLE))
$(info BACKLIGHT_ENABLE: ... $(BACKLIGHT_ENABLE))
$(info MIDI_ENABLE: ........ $(MIDI_ENABLE))
$(info AUDIO_ENABLE: ....... $(AUDIO_ENABLE))
$(info UNICODE_ENABLE: ..... $(UNICODE_ENABLE))
$(info ============================================================)
$(info )

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
