#pragma once
#define TALKFX_ZONE_AMBIENT 0x00
#define TALKFX_ZONE_EVENT   0x01

#define TALKFX_EFFECT_OFF 0x00
#define TALKFX_EFFECT_ON  0x01
#define TALKFX_EFFECT_BLINKING  0x02
#define TALKFX_EFFECT_BREATHING 0x03
#define TALKFX_EFFECT_HEARTBEAT 0x04

#define TALKFX_SPEED_NOCHANGE 0x00
#define TALKFX_SPEED_SLOW     0x01
#define TALKFX_SPEED_NORMAL   0x02
#define TALKFX_SPEED_FAST     0x03

#define TALKFX_RYOS_LAYOUT_DE 0x00
#define TALKFX_RYOS_LAYOUT_ES 0x00
#define TALKFX_RYOS_LAYOUT_FR 0x00
#define TALKFX_RYOS_LAYOUT_HU 0x00
#define TALKFX_RYOS_LAYOUT_IT 0x00
#define TALKFX_RYOS_LAYOUT_LA 0x00
#define TALKFX_RYOS_LAYOUT_NO 0x00
#define TALKFX_RYOS_LAYOUT_PT 0x00
#define TALKFX_RYOS_LAYOUT_TR 0x00
#define TALKFX_RYOS_LAYOUT_SZ 0x00
#define TALKFX_RYOS_LAYOUT_CZ 0x00
#define TALKFX_RYOS_LAYOUT_BE 0x00
#define TALKFX_RYOS_LAYOUT_CH 0x00
#define TALKFX_RYOS_LAYOUT_UK 0x00

#define TALKFX_RYOS_LAYOUT_US 0x01
#define TALKFX_RYOS_LAYOUT_RU 0x01
#define TALKFX_RYOS_LAYOUT_KR 0x01

#define TALKFX_RYOS_LAYOUT_JP 0x02

#define TALKFX_RYOS_LAYOUT_QWERTZ 0x10
#define TALKFX_RYOS_LAYOUT_QWERTY 0x11
#define TALKFX_RYOS_LAYOUT_AZERTY 0x12

/* struct to store RGB value sfor the RyosFX */
typedef struct rgbstruct{
    rgbstruct()
    {
        this->red=0xFF;
        this->green=0xFF;
        this->blue=0xFF;
    }

    rgbstruct(const rgbstruct& other)
    {
        this->red = other.red;
        this->green = other.green;
        this->blue = other.blue;
    }

    BYTE red;
    BYTE green;
    BYTE blue;

	bool operator > (const rgbstruct& b) const{
		return ((red>b.red) && (green>b.green) && (blue>b.blue));
	}
	bool operator < (const rgbstruct& b) const{
		return ((red<b.red) && (green<b.green) && (blue<b.blue));
	}
	bool operator == (const rgbstruct& b) const{
		return ((red==b.red) && (green==b.green) && (blue==b.blue));
	}
	bool operator != (const rgbstruct& b) const{
		return ((red!=b.red) && (green!=b.green) && (blue!=b.blue));
	}
	bool operator <= (const rgbstruct& b) const{
		return ((red<=b.red) && (green<=b.green) && (blue<=b.blue));
	}
	bool operator >= (const rgbstruct& b) const{
		return ((red>=b.red) && (green>=b.green) && (blue>=b.blue));
	}
    rgbstruct& operator = (const rgbstruct& other){
        this->red = other.red;
        this->green = other.green;
        this->blue = other.blue;
        return *this;
    }
}rgbstruct;

class CROCCAT_Talk
{
public:
	/* General */
			CROCCAT_Talk(void);				// constructor
			~CROCCAT_Talk(void);		
	BOOL	init_ryos_talk(void);			// init talk
	void	RestoreLEDRGB();				// Reset talk
	/* Ryos MK Pro specific functions */
	BOOL	set_ryos_kb_SDKmode(BOOL state);	// set sdk mode on / off
	void	turn_off_all_LEDS(void);			// turn off all LEDs
	void	turn_on_all_LEDS(void);				// turn on all LEDs
	void	set_LED_on(BYTE ucPos);				// set single LED on
	void	set_LED_off(BYTE ucPos);			// Set single LED off
	void	Set_all_LEDS(BYTE *ucLED, BYTE country);	// set all LEDs with array
	void	All_Key_Blinking(int DelayTime, int LoopTimes);	// All keys blinking

	/* Single LED Devices like Isku FX, Kone XTD */
	void	Set_LED_RGB(BYTE bZone, BYTE bEffect, BYTE bSpeed,BYTE colorR, BYTE colorG, BYTE colorB);
	
	/*	Ryos MK FX specific functions
		Three different functions achieving the same thing.
		Layout is German per standard, the only three destinctive layouts are DE, US and JP as the have different Key-layouts
		All functions take one BYTE[120] for specifying which LEDs should be on or off, this can be all 1.
		Keys with the color "'lack' will be turned off automatically
	*/

	void    Set_all_LEDSFX(BYTE *ucLEDOnOff, BYTE *ucLEDRGB, BYTE layout = TALKFX_RYOS_LAYOUT_DE); // set LEDs using BYTE[360] for RGB, where BYTE[0] is red for key 0, BYTE [1] is green for key 0 and so on 
	void    Set_all_LEDSFX(BYTE *ucLEDOnOff, struct rgbstruct *strctLEDRGB, BYTE layout = TALKFX_RYOS_LAYOUT_DE);	// set all LEDs using rgbstruct[120]
	void    Set_all_LEDSFX(BYTE *ucLEDOnOff, BYTE *ucLEDRed, BYTE *ucLEDGreen, BYTE *ucLEDBlue, BYTE layout = TALKFX_RYOS_LAYOUT_DE);	// set all LEDs using three BYTE[120], one for each color

protected:
	void ComposeFXArray(rgbstruct str[110], BYTE rgb[330]);
    void ComposeFXArray(BYTE red[110], BYTE green[110], BYTE blue[110], BYTE rgb[330]);
	HWND	m_hwnd;
	UINT	m_uiMsgIDDiscover;

	BYTE	GetKeyNo(BYTE cMapKey);

	static HWND	m_hTalkWnd;
	static UINT m_uiMsgIDAttach, m_uiMsgIDControl,m_uiMsgIDRGBControlFX;
	static UINT m_uiMsgIDAttachForFX, m_uiMsgIDControlForFX;
	UINT	m_uiMsgIDDiscoverForFX;
	static BYTE	bLedOnOff[15];
	static LRESULT CALLBACK	SDKWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};
