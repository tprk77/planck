# Copyright (c) 2018 Tim Perkins

QMK_DIR := qmk_firmware
QMK_TMP_DIR := build/qmk_tmp
BUILD_DIR := build

PLANCK_TARGET := planck/rev4:tprk77
PLANCK_FIRMWARE := planck_rev4_tprk77.hex

all:
	mkdir -p $(BUILD_DIR)
	mkdir -p $(QMK_TMP_DIR)
	mkdir -p $(QMK_TMP_DIR)/keyboards
	cp -R -f -t $(QMK_TMP_DIR) $(QMK_DIR)/Makefile
	cp -R -f -t $(QMK_TMP_DIR) $(QMK_DIR)/*.mk
	cp -R -f -t $(QMK_TMP_DIR) $(QMK_DIR)/lib
	cp -R -f -t $(QMK_TMP_DIR) $(QMK_DIR)/quantum
	cp -R -f -t $(QMK_TMP_DIR) $(QMK_DIR)/tmk_core
	cp -R -f -t $(QMK_TMP_DIR)/keyboards $(QMK_DIR)/keyboards/planck
	ln -r -f -T -s . $(QMK_TMP_DIR)/keyboards/planck/keymaps/tprk77
	make -C $(QMK_TMP_DIR) $(PLANCK_TARGET)
	cp -t $(BUILD_DIR) $(QMK_TMP_DIR)/$(PLANCK_FIRMWARE)

clean:
	-rm -rf build
