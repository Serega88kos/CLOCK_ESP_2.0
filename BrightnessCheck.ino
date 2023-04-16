//////////// функция освещенности
void BrightnessCheck() {
  static uint32_t last_br = millis();
  if ((millis() - last_br) < o.brg) return;
  last_br = millis();
  if (o.auto_bright) {                                                                  // если включена автояркость
    if (millis() - bright_timer > 100) {                                                // каждые 100 мс
      bright_timer = millis();                                                          // сбросить таймер
      if (o.type_brg) {                                                                 // тип датчика цифра
        if (o.min_max) {                                                                // проверка инверсии
          new_bright = map(digitalRead(BRI_PIN), 0, 1023, o.min_bright, o.max_bright);  // считать показания с фоторезистора, перевести диапазон прямой
        } else {
          new_bright = map(digitalRead(BRI_PIN), 0, 1023, o.max_bright, o.min_bright);  // считать показания с фоторезистора, перевести диапазон обратный
        }
      } else {                                                                         // иначе тип датчика аналог
        if (o.min_max) {                                                               // проверка инверсии
          new_bright = map(analogRead(BRI_PIN), 0, 1023, o.min_bright, o.max_bright);  // считать показания с фоторезистора, перевести диапазон прямой
        } else {
          new_bright = map(analogRead(BRI_PIN), 0, 1023, o.max_bright, o.min_bright);  // считать показания с фоторезистора, перевести диапазон обратный
        }
      }
      LEDS.setBrightness(new_bright);       // устанавливаем яркость
    }
  } else LEDS.setBrightness(o.min_bright);  // если автояркость выключена, то в расчете минимальная
}