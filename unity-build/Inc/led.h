#ifndef LED_H
#define LED_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define LED_FIRST 1U
#define LED_LAST  16U

typedef enum {
    LED_OK             =  0,
    LED_ERR_INVALID    = -1,
    LED_ERR_NOT_INIT   = -2 
} led_status_t;

void         led_init(uint16_t *register_address);
void         led_deinit(void);

led_status_t led_on(uint8_t led);
led_status_t led_off(uint8_t led);
led_status_t led_toggle(uint8_t led);
void         led_all_on(void);
void         led_all_off(void);
bool         led_is_on(uint8_t led);

#ifdef __cplusplus
}
#endif

#endif /* LED_H */