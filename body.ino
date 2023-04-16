//////////// Тело программы
/*
   (с) Старик Похабыч, апрель, 2021 год.
*/
bool hasChange = false;
//uint8_t periodDisplay[] = {6,2,2,2,2,};      //сколько по времени выводить каждый режим, сек
//uint8_t orderDisplay[]  = {0,1,2,3,4};      //порядок вывода режимов
uint8_t mode = 0;
//bool showDot = false;

void body() {
  static uint32_t ch_tmr = millis();  //статическую переменную для хранения времени выполнения текущего режима,
  //а так же выбор того, что надо выводить
  if ((millis() - ch_tmr) < (c.periodDisplay[c.orderDisplay[mode]] * 1000)) {
    switch (c.orderDisplay[mode]) {  //вывод режимов
      case 0:
        timeToStringDots();
        timeToString();
        BrightnessCheck();
        break;
      case 1:
        TemperToString();
        break;
      case 2:
        TemperOutToString();
        break;
      case 3:
        PressToString();
        break;
      case 4:
        HumToString();
        break;
      case 5:
        DateToString();
        break;
      default:
        break;
    }
  } else {
    ch_tmr = millis();
    mode++;
    if (mode > 5) mode = 0;
    if (sizeof(c.orderDisplay) == mode) mode = 0;
  }
  static uint32_t Ftiming;
  if (millis() - Ftiming > 100) {
    Ftiming = millis();
    FastLED.show();
  }
}

void TemperToString() {
  static uint32_t tmr1 = millis() - c.periodDisplay[1] * 1000;
  if (millis() - tmr1 < (c.periodDisplay[1] * 1100)) return;
  tmr1 = millis();
  hasChange = true;
  if (!hasChange) return;
  hasChange = false;
  TempToArray();
}

void TemperOutToString() {
  static uint32_t tmr1 = millis() - c.periodDisplay[2] * 1000;
  if (millis() - tmr1 < (c.periodDisplay[2] * 1100)) return;
  tmr1 = millis();
  hasChange = true;
  if (!hasChange) return;
  hasChange = false;
  TempStreetToArray();
}

void PressToString() {
  static uint32_t tmr1 = millis() - c.periodDisplay[3] * 1000;
  if (millis() - tmr1 < (c.periodDisplay[3] * 1100)) return;
  tmr1 = millis();
  hasChange = true;
  if (!hasChange) return;
  hasChange = false;
  PressToArray();
}

void HumToString() {
  static uint32_t tmr1 = millis() - c.periodDisplay[4] * 1000;
  if (millis() - tmr1 < (c.periodDisplay[4] * 1100)) return;
  tmr1 = millis();
  hasChange = true;
  if (!hasChange) return;
  hasChange = false;
  HumToArray();
}

void timeToString() {
  static uint32_t tmr1 = millis();
  if (millis() - tmr1 < 500) return;
  tmr1 = millis();
  TimeToArray();
}

void timeToStringDots() {
  static unsigned int t_sec;
  static bool showDot = false;
  static uint32_t tmr1 = millis();
  switch (c.type_sec) {
    case 1:
      t_sec = 500;
      break;
    default:
      t_sec = 1000;
      break;
  }
  if ((millis() - tmr1) < t_sec) return;
  tmr1 = millis();
  showDot = !showDot;
  hasChange = true;
  if (showDot)
    Dots(Dot);
  else
    Dots(!Dot);
}

void DateToString() {
  static uint32_t tmr1 = millis() - c.periodDisplay[5] * 1000;
  if (millis() - tmr1 < (c.periodDisplay[5] * 1100)) return;
  tmr1 = millis();
  hasChange = true;
  if (!hasChange) return;
  hasChange = false;
  DateToArray();
}