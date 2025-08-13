/*
 * SPDX-FileCopyrightText: 2023 Otto-von-Guericke-Universität Magdeburg
 * SPDX-License-Identifier: LGPL-2.1-only
 */

#include "board.h"
#include "periph/pio.h"

#include <stdio.h>

/* see blink.c */
pio_program_t pio_blink_export_program(void);

/* see blink.c */
int pio_blink_write_program(pio_t pio, pio_program_t *pro);

/* see blink.c */
int pio_blink_init(pio_t pio, pio_sm_t sm, const pio_program_t *pro,
                   gpio_t pin);

int main(void)
{
    pio_program_t blink = pio_blink_export_program();
    pio_t pio;
    pio_sm_t sm;
    if (pio_alloc_program_sm_lock_any(&pio, &sm, &blink)) {
        puts("No PIO resources available.");
        return 1;
    }
    if (pio_blink_write_program(pio, &blink)) {
        puts("Program could not be written.");
        return -1;
    }
    gpio_t blink_gpio = PIO_BLINK_PIN; /* see Makefile */
    if (blink_gpio == GPIO_UNDEF) {
#ifdef LED0_PIN
        blink_gpio = LED0_PIN;
#endif
    }
    if (pio_blink_init(pio, sm, &blink, blink_gpio)) {
        puts("PIO blink initialization failed");
        return 1;
    }
    pio_sm_start(pio, sm);
    return 0;
}
