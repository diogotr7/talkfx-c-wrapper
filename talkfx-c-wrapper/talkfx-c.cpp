// talkfx-c-wrapper.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "talkfx-c.h"

CROCCAT_Talk* newRoccatTalkHandle() {
  return new CROCCAT_Talk();
}

void destroyRoccatTalkHandle(CROCCAT_Talk* handle) {
  delete handle;
}

BOOL init_ryos_talk(CROCCAT_Talk* handle) {
  return handle->init_ryos_talk();
}

BOOL set_ryos_kb_SDKmode(CROCCAT_Talk* handle, BOOL state) {
  return handle->set_ryos_kb_SDKmode(state);
}

void turn_off_all_LEDS(CROCCAT_Talk* handle) {
  handle->turn_off_all_LEDS();
}

void turn_on_all_LEDS(CROCCAT_Talk* handle) {
  handle->turn_on_all_LEDS();
}

void set_LED_on(CROCCAT_Talk* handle, BYTE ucPos) {
  handle->set_LED_on(ucPos);
}

void set_LED_off(CROCCAT_Talk* handle, BYTE ucPos) {
  handle->set_LED_off(ucPos);
}

void Set_all_LEDS(CROCCAT_Talk* handle, BYTE *ucLED, BYTE layout) {
  handle->Set_all_LEDS(ucLED, layout);
}

void All_Key_Blinking(CROCCAT_Talk* handle, int DelayTime, int LoopTimes) {
  handle->All_Key_Blinking(DelayTime, LoopTimes);
}

void Set_LED_RGB(CROCCAT_Talk* handle, BYTE bZone, BYTE bEffect, BYTE bSpeed, BYTE colorR, BYTE colorG, BYTE colorB) {
  handle->Set_LED_RGB(bZone, bEffect, bSpeed, colorR, colorG, colorB);
}

void RestoreLEDRGB(CROCCAT_Talk* handle) {
  handle->RestoreLEDRGB();
}

void Set_all_LEDSFX(CROCCAT_Talk* handle, BYTE *ucLEDOnOff, BYTE *ucLEDRGB, BYTE layout) {
	handle->Set_all_LEDSFX(ucLEDOnOff, ucLEDRGB, layout);
}

void Set_all_LEDSFX_struct(CROCCAT_Talk* handle, BYTE *ucLEDOnOff, struct rgbstruct *strctLEDRGB, BYTE layout) {
	handle->Set_all_LEDSFX(ucLEDOnOff, strctLEDRGB, layout);
}

void Set_all_LEDSFX_individual(CROCCAT_Talk* handle, BYTE *ucLEDOnOff, BYTE *ucLEDRed, BYTE *ucLEDGreen, BYTE *ucLEDBlue, BYTE layout) {
	handle->Set_all_LEDSFX(ucLEDOnOff, ucLEDRed, ucLEDGreen, ucLEDBlue, layout);
}
