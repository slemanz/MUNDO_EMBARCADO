#include "unity_fixture.h"
#include "led.h"

TEST_GROUP(Led);

static uint16_t virtual_leds;

TEST_SETUP(Led)
{
    virtual_leds = 0xFFFF;
    led_init(&virtual_leds);
}

TEST_TEAR_DOWN(Led)
{
    led_deinit();
}

TEST(Led, test_all_leds_are_off_after_init)
{
    TEST_ASSERT_EQUAL_HEX16(0x0000, virtual_leds);
}

TEST(Led, test_turn_on_led_one)
{
    TEST_ASSERT_EQUAL_INT(LED_OK, led_on(1));
    TEST_ASSERT_EQUAL_HEX16(0x0001, virtual_leds);
}

TEST(Led, test_turn_off_led_one)
{
    led_on(1);
    TEST_ASSERT_EQUAL_INT(LED_OK, led_off(1));
    TEST_ASSERT_EQUAL_HEX16(0x0000, virtual_leds);
}

TEST(Led, test_turn_on_multiple_leds)
{
    led_on(9);
    led_on(8);
    TEST_ASSERT_EQUAL_HEX16(0x0180, virtual_leds);
}

TEST(Led, test_turn_off_only_the_chosen_led)
{
    led_all_on();
    led_off(8);
    TEST_ASSERT_EQUAL_HEX16(0xFF7F, virtual_leds);
}

TEST(Led, test_toggle_led)
{
    led_toggle(3);
    TEST_ASSERT_EQUAL_HEX16(0x0004, virtual_leds);
    led_toggle(3);
    TEST_ASSERT_EQUAL_HEX16(0x0000, virtual_leds);
}

TEST(Led, test_all_on_and_all_off)
{
    led_all_on();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtual_leds);
    led_all_off();
    TEST_ASSERT_EQUAL_HEX16(0x0000, virtual_leds);
}

TEST(Led, test_upper_and_lower_bounds)
{
    led_on(1);
    led_on(16);
    TEST_ASSERT_EQUAL_HEX16(0x8001, virtual_leds);
}

TEST(Led, test_out_of_bounds_returns_error_and_changes_nothing)
{
    TEST_ASSERT_EQUAL_INT(LED_ERR_INVALID, led_on(0));
    TEST_ASSERT_EQUAL_INT(LED_ERR_INVALID, led_on(17));
    TEST_ASSERT_EQUAL_INT(LED_ERR_INVALID, led_off(17));
    TEST_ASSERT_EQUAL_HEX16(0x0000, virtual_leds);
}

TEST(Led, test_is_on_reflects_led_state)
{
    TEST_ASSERT_FALSE(led_is_on(5));
    led_on(5);
    TEST_ASSERT_TRUE(led_is_on(5));
    TEST_ASSERT_FALSE(led_is_on(17));
}

TEST(Led, test_operations_fail_when_not_initialized)
{
    led_deinit();
    TEST_ASSERT_EQUAL_INT(LED_ERR_NOT_INIT, led_on(1));
    TEST_ASSERT_EQUAL_INT(LED_ERR_NOT_INIT, led_toggle(1));
    TEST_ASSERT_FALSE(led_is_on(1));
}

TEST_GROUP_RUNNER(Led)
{
    RUN_TEST_CASE(Led, test_all_leds_are_off_after_init);
    RUN_TEST_CASE(Led, test_turn_on_led_one);
    RUN_TEST_CASE(Led, test_turn_off_led_one);
    RUN_TEST_CASE(Led, test_turn_on_multiple_leds);
    RUN_TEST_CASE(Led, test_turn_off_only_the_chosen_led);
    RUN_TEST_CASE(Led, test_toggle_led);
    RUN_TEST_CASE(Led, test_all_on_and_all_off);
    RUN_TEST_CASE(Led, test_upper_and_lower_bounds);
    RUN_TEST_CASE(Led, test_out_of_bounds_returns_error_and_changes_nothing);
    RUN_TEST_CASE(Led, test_is_on_reflects_led_state);
    RUN_TEST_CASE(Led, test_operations_fail_when_not_initialized);
}