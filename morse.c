/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const uint PERIOD_MS = 100;
const uint DOT_UNITS = 1;
const uint DASH_UNITS = 3;
const uint INTER_UNITS = 1;
const uint LETTER_GAP_UNITS = 2; // 3 periods between letters, however, one period is already accounted for
const uint WORD_GAP_UNITS = 4; // 7 periods between words, however 3 periods have already been accounted for 

const uint INPUT_BUFFER_SIZE = 128;

const char *morse_letters[] = {
        ".-",    // A
        "-...",  // B
        "-.-.",  // C
        "-..",   // D
        ".",     // E
        "..-.",  // F
        "--.",   // G
        "....",  // H
        "..",    // I
        ".---",  // J
        "-.-",   // K
        ".-..",  // L
        "--",    // M
        "-.",    // N
        "---",   // O
        ".--.",  // P
        "--.-",  // Q
        ".-.",   // R
        "...",   // S
        "-",     // T
        "..-",   // U
        "...-",  // V
        ".--",   // W
        "-..-",  // X
        "-.--",  // Y
        "--.."   // Z
};

void sleep_units(uint units) {
    sleep_ms(PERIOD_MS * units);
}

void put_morse_letter(uint led_pin, const char *pattern) {
    for (; *pattern; ++pattern) {
        gpio_put(led_pin, 1);
        if (*pattern == '.')
            sleep_units(DOT_UNITS);
        else
            sleep_units(DASH_UNITS);
        gpio_put(led_pin, 0);
        sleep_units(INTER_UNITS);
    }
    sleep_units(LETTER_GAP_UNITS);
}

void put_morse_str(uint led_pin, const char *str) {
    for (; *str; ++str) {
        if (*str >= 'A' && *str < 'Z') {
            put_morse_letter(led_pin, morse_letters[*str - 'A']);
        } else if (*str >= 'a' && *str < 'z') {
            put_morse_letter(led_pin, morse_letters[*str - 'a']);
        } else if (*str == ' ') {
            sleep_units(WORD_GAP_UNITS);
        }
    }
}

int main() {
#ifndef PICO_DEFAULT_LED_PIN
#warning picoboard/blinky example requires a board with a regular LED
#else
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    put_morse_str(LED_PIN, "TEST");

    stdio_init_all();

    char buffer[INPUT_BUFFER_SIZE];
    while (fgets(buffer, INPUT_BUFFER_SIZE, stdin)) {
        put_morse_str(LED_PIN, buffer);
        printf(buffer);
    }
#endif
}
