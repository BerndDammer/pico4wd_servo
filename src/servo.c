#include <stdbool.h>
#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

#include "servo.h"

#define SERVO_PIN 18 //Pinout 24
#define SERVO_SLICE 1
#define SERVO_CHANNEL PWM_CHAN_A

#define SERVO_RIGHT 500
#define SERVO_CENTER 1500
#define SERVO_LEFT 2500

#define FPWM 50
#define PWM_CLK 1000000

void servo_init(void)
{
    pwm_config pc = pwm_get_default_config();
    // Tell GPIO they are allocated to the PWM
    gpio_init(SERVO_PIN);
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);

    pwm_config_set_clkdiv_mode(&pc, PWM_DIV_FREE_RUNNING);

    //int div;
    double d;
    {
        d = (double) clock_get_hz(clk_sys) / (double) PWM_CLK;
    }
    pwm_config_set_clkdiv(&pc, d);

    //s->pc.div = div;
    pc.top = PWM_CLK / FPWM - 1;

    pwm_init(SERVO_SLICE, &pc, false);

    pwm_set_chan_level(SERVO_SLICE, SERVO_CHANNEL, SERVO_OFF);

    pwm_set_enabled(SERVO_SLICE, true);
}

void servo_set(int angle)
{
    angle -= SERVO_MIN;
    angle *= SERVO_LEFT - SERVO_RIGHT;
    angle /= SERVO_MAX - SERVO_MIN;
    angle += SERVO_RIGHT;

    pwm_set_chan_level(SERVO_SLICE, SERVO_CHANNEL, angle);
}
