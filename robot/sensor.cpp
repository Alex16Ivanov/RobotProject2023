#include "SENSOR.H"
//#include <Adafruit_TCS34725.h>

// black: r - (40;60), g- (50;70), ////b- (45;60), now- r- (45,60), g - (60;75), b-(40;65), ////before - r- (100,220), g - (100;270), b-(100;250)
// white:r- (100,220), g - (140;270), /////b-(140;240), now- r- (90,400), g - (100;450), b-(90;400). //// before r- (1000,1350), g - (1300;1700), b-(1100;1600)
// nothing: r- (15;25). g- (15:30).//// b-(15:30), now - r- (100,220), g - (140;270), b-(140;240). //// before r- (100,220), g - (140;270), b-(140;240)

int readColor(Adafruit_TCS34725 tcs){
  uint16_t r, g, b, c;
  tcs.getRawData(&r, &g, &b, &c);
  
if(r>=29 && r<=45 && g>= 35 && g<= 55 && b>=30 && b<=55){
//r>=40 && r<=100 && g>= 45 && g<= 100 && b>=35 && b<=100
  // true = 1 = black
  return 1;
  //r>=90 && r<=550 && g>= 100 && g<=650 && b>=90 && b<=600
} else if (r>=60 && r<=1200 && g>= 90 && g<=1210 && b>=80 && b<=1200){
  //r>=290 && r<=550 && g>= 400 && g<=550 && b>=400 && b<=500

  // false = 0 = white
  return 0;
} else if(r >= 20 && r<= 31 && g >= 20 && g<= 34 && b >= 20 && b<= 35){
  return -2;
}
 else {
  // other color
  return -1;
}


  delay(2000);
}

// int readRedFont(Adafruit_TCS34725 tcs){
//   uint16_t r, g, b, c;
//   tcs.getRawData(&r, &g, &b, &c);
//   //if(!(r>=90 && r<=450 && g>= 100 && g<=450 && b>=90 && b<=450) && !(r>=40 && r<=65 && g>= 45 && g<= 80 && b>=35 && b<=70)){
//     Serial.println(r);
//     return r;
    
     
//   //}
  
// }

// int readGreenFont(Adafruit_TCS34725 tcs){
//   uint16_t r, g, b, c;
//   tcs.getRawData(&r, &g, &b, &c);
//   //if(!(r>=90 && r<=450 && g>= 100 && g<=450 && b>=90 && b<=450) && !(r>=40 && r<=65 && g>= 45 && g<= 80 && b>=35 && b<=70)){
//     Serial.println(g);
//     return g;
//   //}
  
// }

// int readBlueFont(Adafruit_TCS34725 tcs){
//   uint16_t r, g, b, c;
//   tcs.getRawData(&r, &g, &b, &c);
//   //if(!(r>=90 && r<=450 && g>= 100 && g<=450 && b>=90 && b<=450) && !(r>=40 && r<=65 && g>= 45 && g<= 80 && b>=35 && b<=70)){
//     Serial.println(b);
//     return b;
//   //}
  
// }


// int readColor2(Adafruit_TCS34725 tcs, int rFont, int gFont, int bFont){
//   uint16_t r, g, b, c;
//   tcs.getRawData(&r, &g, &b, &c);
//   uint32_t sum = c;
//   r = (r*256)/sum;
//   g = (g*256)/sum;
//   b = (b*256)/sum;

//   if(r>=50 && r<=70 && g>= 10 && g<= 110 && b>=10 && b<=110){

//   // true = 1 = black
//   return 1;
  
// } else if (r>=10 && r<=40 && g>= 10 && g<=25 && b>=5 && b<=20){

//   // false = 0 = white
//   return 0;
// } else if(r >= rFont-50 && r<= rFont+50 && g >= rFont-50 && g<= gFont+50 && b >= bFont-50 && b<= bFont+50){
//   return -2;
// }
//  else {
//   // other color
//   return -1;
// }


//   delay(2000);
// }

