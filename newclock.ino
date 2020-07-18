

#include <Arduino.h>
#include <U8g2lib.h>
#include <iarduino_RTC.h>
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

iarduino_RTC time(RTC_DS1307);
U8G2_SH1106_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
String rtrt  = "--:--";
String sec = "--";
String ampm = "  ";
String mmm= " ";
String dd= " ";
String DDD = " ";
// End of constructor list

void draw(void) {

  u8g2.setContrast(100);
// u8g2.setFont(u8g2_font_7Segments_26x42_mn);
u8g2.setFont(u8g2_font_logisoso42_tn);
//u8g2_font_inb38_mn
//u8g2_font_bubble_tn
//u8g2_font_michaelmouse_tu
//u8g2_font_fur42_tn X
//u8g2_font_fub35_tn
//u8g2_font_7Segments_26x42_mn
u8g2.setCursor(0, 42); //63
u8g2.print(rtrt);
//u8g2.setFont(u8g2_font_logisoso16_tr);

u8g2.setFont(u8g2_font_halftone_tr);
u8g2.setFont(u8g2_font_lastapprenticebold_tr);
//u8g2.setContrast(250);
//u8g2.setCursor(103, 63);
//u8g2.print(sec);
//u8g2.setCursor(0, 60);
//u8g2.print(ampm);
u8g2.setCursor(45, 63);
u8g2.print(mmm);
u8g2.setCursor(77, 63);
u8g2.print(dd);


//u8g2.setCursor(82, 63); 
u8g2.setCursor(7, 63);
u8g2.print(DDD);

u8g2.setFont(u8g2_font_halftone_tr);
//u8g2.setFont(u8g2_font_CursivePixel_tr);

//u8g2.setCursor(0, 62);
u8g2.setCursor(109, 63); 
u8g2.print(ampm);
}

void setup(void) {


  u8g2.begin();  
}



void loop(void) {
  rtrt = time.gettime("h:i");
  sec = time.gettime("s");
  ampm = time.gettime("A");
  mmm = time.gettime("M");
  dd = time.gettime("d");
  DDD = time.gettime("D");
  u8g2.firstPage();
  do {
    draw();
  } while ( u8g2.nextPage() );
delay(5);
}
