#include <Arduino.h>
#include <unity.h>

void test_led_builtin_pin_number(void){
  TEST_ASSERT_EQUAL(13, LED_BUILTIN);
}

void test_led_state_high(void){
  digitalWrite(13, HIGH);
  TEST_ASSERT_EQUAL(HIGH, digitalRead(LED_BUILTIN));
}

void test_led_state_low(void){
  digitalWrite(13, LOW);
  TEST_ASSERT_EQUAL(LOW, digitalRead(LED_BUILTIN));
}
void setup() {
  // put your setup code here, to run once:
  delay(2000);
  UNITY_BEGIN();
  RUN_TEST(test_led_builtin_pin_number);
  pinMode(LED_BUILTIN, 1);
}
uint8_t i = 0;
uint8_t max_blinks = 5;

void loop() {
  // put your main code here, to run repeatedly:
  if (i< max_blinks)
  {
    RUN_TEST(test_led_state_high);
    delay(500);
    RUN_TEST(test_led_state_low);
    delay(500);
    i++;
  }else if(i== max_blinks){
    UNITY_END();
  }
}