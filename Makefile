#----------------------------------------------------------------------------
# File:		Makefile
# Author:	Tony Saveski, t_saveski@yahoo.com
#----------------------------------------------------------------------------
CROSS_COMPILE?=mips64r5900el-ps2-elf-
CC=$(CROSS_COMPILE)gcc
AS=$(CROSS_COMPILE)as
LD=$(CROSS_COMPILE)ld

OBJ_DIR = obj
CFLAGS = -Wall -W -nostdlib -DPS2_EE -O2

C_SRC = g2.c main.c
S_SRC = crt0.s ps2_asm.s dma_asm.s gs_asm.s hw.s

C_OBJ = $(addprefix $(OBJ_DIR)/, $(C_SRC:.c=.o))
S_OBJ = $(addprefix $(OBJ_DIR)/, $(S_SRC:.s=.o))

main.elf: $(C_OBJ) $(S_OBJ)
	@echo "-------------------------------------------------"
	$(CC) $(CFLAGS) -o main.elf $(C_OBJ) $(S_OBJ) -Wl,-Map,main.map -lgcc

$(OBJ_DIR)/%.o: %.c
	@echo "-------------------------------------------------"
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_DIR)/%.o: %.s
	@echo "-------------------------------------------------"
	@mkdir -p $(OBJ_DIR)
	$(CC) -xassembler-with-cpp -c $(CFLAGS) $< -o $@

clean:
	rm -f $(C_OBJ) $(S_OBJ) *.map *.elf
	rm -rf $(OBJ_DIR)
