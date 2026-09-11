#include "CppUTest/TestHarness.h"
#include "led.h"   /* o header ja tem extern "C" */

TEST_GROUP(Led)
{
    uint16_t virtualLeds; 

    void setup()
    {
        virtualLeds = 0xFFFF;
        led_init(&virtualLeds);
    }

    void teardown()
    {
        led_deinit();
    }
};

TEST(Led, AllLedsAreOffAfterInit)
{
    UNSIGNED_LONGS_EQUAL(0x0000, virtualLeds);
}

TEST(Led, TurnOnLedOne)
{
    LONGS_EQUAL(LED_OK, led_on(1));
    UNSIGNED_LONGS_EQUAL(0x0001, virtualLeds);
}

TEST(Led, TurnOffLedOne)
{
    led_on(1);
    LONGS_EQUAL(LED_OK, led_off(1));
    UNSIGNED_LONGS_EQUAL(0x0000, virtualLeds);
}

TEST(Led, TurnOnMultipleLeds)
{
    led_on(9);
    led_on(8);
    UNSIGNED_LONGS_EQUAL(0x0180, virtualLeds);
}

TEST(Led, TurnOffOnlyTheChosenLed)
{
    led_all_on();
    led_off(8);
    UNSIGNED_LONGS_EQUAL(0xFF7F, virtualLeds);
}

TEST(Led, ToggleLed)
{
    led_toggle(3);
    UNSIGNED_LONGS_EQUAL(0x0004, virtualLeds);
    led_toggle(3);
    UNSIGNED_LONGS_EQUAL(0x0000, virtualLeds);
}

TEST(Led, AllOnAndAllOff)
{
    led_all_on();
    UNSIGNED_LONGS_EQUAL(0xFFFF, virtualLeds);
    led_all_off();
    UNSIGNED_LONGS_EQUAL(0x0000, virtualLeds);
}

TEST(Led, UpperAndLowerBounds)
{
    led_on(1);
    led_on(16);
    UNSIGNED_LONGS_EQUAL(0x8001, virtualLeds);
}

TEST(Led, OutOfBoundsReturnsErrorAndChangesNothing)
{
    LONGS_EQUAL(LED_ERR_INVALID, led_on(0));
    LONGS_EQUAL(LED_ERR_INVALID, led_on(17));
    LONGS_EQUAL(LED_ERR_INVALID, led_off(17));
    UNSIGNED_LONGS_EQUAL(0x0000, virtualLeds);
}

TEST(Led, IsOnReflectsLedState)
{
    CHECK_FALSE(led_is_on(5));
    led_on(5);
    CHECK_TRUE(led_is_on(5));
    CHECK_FALSE(led_is_on(17));  
}

TEST(Led, OperationsFailWhenNotInitialized)
{
    led_deinit();
    LONGS_EQUAL(LED_ERR_NOT_INIT, led_on(1));
    LONGS_EQUAL(LED_ERR_NOT_INIT, led_toggle(1));
    CHECK_FALSE(led_is_on(1));
}