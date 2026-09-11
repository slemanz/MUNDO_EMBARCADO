#include "led.h"
#include <stddef.h>

#define ALL_LEDS_OFF 0x0000u
#define ALL_LEDS_ON  0xFFFFu

static uint16_t *leds_register = NULL;

static bool is_valid(uint8_t led)
{
    return (led >= LED_FIRST) && (led <= LED_LAST);
}

static uint16_t led_to_bit(uint8_t led)
{
    return (uint16_t)(1u << (led - 1u));
}

void led_init(uint16_t *register_address)
{
    leds_register = register_address;
    if (leds_register != NULL)
    {
        *leds_register = ALL_LEDS_OFF;
    }
}

void led_deinit(void)
{
    leds_register = NULL;
}

led_status_t led_on(uint8_t led)
{
    if(leds_register == NULL) return LED_ERR_NOT_INIT;
    if(!is_valid(led))        return LED_ERR_INVALID;

    *leds_register |= led_to_bit(led);
    return LED_OK;
}

led_status_t led_off(uint8_t led)
{
    if(leds_register == NULL) return LED_ERR_NOT_INIT;
    if(!is_valid(led))        return LED_ERR_INVALID;

    *leds_register &= (uint16_t)~led_to_bit(led);
    return LED_OK;
}

led_status_t led_toggle(uint8_t led)
{
    if(leds_register == NULL) return LED_ERR_NOT_INIT;
    if(!is_valid(led))        return LED_ERR_INVALID;

    *leds_register ^= led_to_bit(led);
    return LED_OK;
}

void led_all_on(void)
{
    if(leds_register != NULL) *leds_register = ALL_LEDS_ON;
}

void led_all_off(void)
{
    if(leds_register != NULL) *leds_register = ALL_LEDS_OFF;
}

bool led_is_on(uint8_t led)
{
    if(leds_register == NULL || !is_valid(led)) return false;
    return (*leds_register & led_to_bit(led)) != 0u;
}