#ifndef UTILS_COLORS_HELPERS_H
#define UTILS_COLORS_HELPERS_H

#include <string>
#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

#define Red glColor3f(1, 0, 0)
#define Green glColor3f(0, 1, 0)
#define Blue glColor3f(0, 0, 1)
#define Yellow glColor3f(1,1,0)
#define Cyan glColor3f(0, 1, 1)
#define Magenta glColor3f(1, 0, 1)
#define White glColor3f(1, 1, 1)
#define Black glColor3f(0, 0, 0)


// OTHER GRAYS
#define DimGray glColor3f(0.329412, 0.329412, 0.329412)
#define Gray glColor3f(0.752941, 0.752941, 0.752941)
#define LightGray glColor3f(0.658824, 0.658824, 0.658824)
#define VLightGray glColor3f(0.80, 0.80, 0.80)

#define Aquamarine glColor3f(0.439216, 0.858824, 0.576471)
#define BlueViolet glColor3f(0.62352, 0.372549, 0.623529)
#define Brown glColor3f(0.647059, 0.164706, 0.164706)
#define CadetBlue glColor3f(0.372549, 0.623529, 0.623529)
#define Coral glColor3f(1.0, 0.498039, 0.0)
#define CornflowerBlue glColor3f(0.258824, 0.258824, 0.435294)
#define DarkGreen glColor3f(0.184314, 0.309804, 0.184314)
#define DarkOliveGreen glColor3f(0.309804, 0.309804, 0.184314)
#define DarkOrchid glColor3f(0.6, 0.196078, 0.8)
#define DarkSlateBlue glColor3f(0.419608, 0.137255, 0.556863)
#define DarkSlateGray glColor3f(0.184314, 0.309804, 0.309804)
#define DarkSlateGrey glColor3f(0.184314, 0.309804, 0.309804)
#define DarkTurquoise glColor3f(0.439216, 0.576471, 0.858824)
#define Firebrick glColor3f(0.556863, 0.137255, 0.137255)
#define ForestGreen glColor3f(0.137255, 0.556863, 0.137255)
#define Gold glColor3f(0.8, 0.498039, 0.196078)
#define Goldenrod glColor3f(0.858824, 0.858824, 0.439216)
#define GreenYellow glColor3f(0.576471, 0.858824, 0.439216)
#define IndianRed glColor3f(0.309804, 0.184314, 0.184314)
#define Khaki glColor3f(0.623529, 0.623529, 0.372549)
#define LightBlue glColor3f(0.74902, 0.847059, 0.847059)
#define LightSteelBlue glColor3f(0.560784, 0.560784, 0.737255)
#define LimeGreen glColor3f(0.196078, 0.8, 0.196078)
#define Maroon glColor3f(0.556863, 0.137255, 0.419608)
#define MediumAquamarine glColor3f(0.196078, 0.8, 0.6)
#define MediumBlue glColor3f(0.196078, 0.196078, 0.8)
#define MediumForestGreen glColor3f(0.419608, 0.556863, 0.137255)
#define MediumGoldenrod glColor3f(0.917647, 0.917647, 0.678431)
#define MediumOrchid glColor3f(0.576471, 0.439216, 0.858824)
#define MediumSeaGreen glColor3f(0.258824, 0.435294, 0.258824)
#define MediumSlateBlue glColor3f(0.498039, 0, 1.0)
#define MediumSpringGreen glColor3f(0.498039, 0, 1.0)
#define MediumTurquoise glColor3f(0.439216, 0.858824, 0.858824)
#define MediumVioletRed glColor3f(0.858824, 0.439216, 0.576471)
#define MidnightBlue glColor3f(0.184314, 0.184314, 0.309804)
#define Navy glColor3f(0.137255, 0.137255, 0.556863)
#define NavyBlue glColor3f(0.137255, 0.137255, 0.556863)
#define Orange glColor3f(1, 0.5, 0.0)
#define OrangeRed glColor3f(1.0, 0, 0.25)
#define Orchid glColor3f(0.858824, 0.439216, 0.858824)
#define PaleGreen glColor3f(0.560784, 0.737255, 0.560784)
#define Pink glColor3f(0.737255, 0.560784, 0.560784)
#define Plum glColor3f(0.917647, 0.678431, 0.917647)
#define Salmon glColor3f(0.435294, 0.258824, 0.258824)
#define SeaGreen glColor3f(0.137255, 0.556863, 0.419608)
#define Sienna glColor3f(0.556863, 0.419608, 0.137255)
#define SkyBlue glColor3f(0.196078, 0.6, 0.8)
#define SteelBlue glColor3f(0.137255, 0.419608, 0.556863)
#define Tan glColor3f(0.858824, 0.576471, 0.439216)
#define Thistle glColor3f(0.847059, 0.74902, 0.847059)
#define Turquoise glColor3f(0.678431, 0.917647, 0.917647)
#define Violet glColor3f(0.309804, 0.184314, 0.309804)
#define VioletRed glColor3f(0.8, 0.196078, 0.6)
#define Wheat glColor3f(0.847059, 0.847059, 0.74902)
#define YellowGreen glColor3f(0.6, 0.8, 0.196078)
#define SummerSky glColor3f(0.22, 0.69, 0.87)
#define RichBlue glColor3f(0.35, 0.35, 0.67)
#define Brass glColor3f(0.71, 0.65, 0.26)
#define Copper glColor3f(0.72, 0.45, 0.20)
#define Bronze glColor3f(0.55, 0.47, 0.14)
#define Bronze2 glColor3f(0.65, 0.49, 0.24)
#define Silver glColor3f(0.90, 0.91, 0.98)
#define BrightGold glColor3f(0.85, 0.85, 0.10)
#define OldGold glColor3f(0.81, 0.71, 0.23)
#define Feldspar glColor3f(0.82, 0.57, 0.46)
#define Quartz glColor3f(0.85, 0.85, 0.95)
#define NeonPink glColor3f(1.00, 0.43, 0.78)
#define DarkPurple glColor3f(0.53, 0.12, 0.47)
#define NeonBlue glColor3f(0.30, 0.30, 1.00)
#define CoolCopper glColor3f(0.85, 0.53, 0.10)
#define MandarinOrange glColor3f(0.89, 0.47, 0.20)
#define LightWood glColor3f(0.91, 0.76, 0.65)
#define MediumWood glColor3f(0.65, 0.50, 0.39)
#define DarkWood glColor3f(0.52, 0.37, 0.26)
#define SpicyPink glColor3f(1.00, 0.11, 0.68)
#define SemiSweetChoc glColor3f(0.42, 0.26, 0.15)
#define BakersChoc glColor3f(0.36, 0.20, 0.09)
#define Flesh glColor3f(0.96, 0.80, 0.69)
#define NewTan glColor3f(0.92, 0.78, 0.62)
#define NewMidnightBlue glColor3f(0.00, 0.00, 0.61)
#define VeryDarkBrown glColor3f(0.35, 0.16, 0.14)
#define DarkBrown glColor3f(0.36, 0.25, 0.20)
#define DarkTan glColor3f(0.59, 0.41, 0.31)
#define GreenCopper glColor3f(0.32, 0.49, 0.46)
#define DkGreenCopper glColor3f(0.29, 0.46, 0.43)
#define DustyRose glColor3f(0.52, 0.39, 0.39)
#define HuntersGreen glColor3f(0.13, 0.37, 0.31)
#define Scarlet glColor3f(0.55, 0.09, 0.09)

#define Med_Purple glColor3f(0.73, 0.16, 0.96)
#define Light_Purple glColor3f(0.87, 0.58, 0.98)
#define Very_Light_Purple glColor3f(0.94f, 0.81f, 0.99f);

#define WHITE glColor3f(1,1,1);
#define SUN glColor3f(0.9f,1,0);
#define MERCURY glColor3f(0.4f,0.4f,0.4f);
#define VENUS glColor3f(0.9f,0.8f,0.4f);
#define EARTH glColor3f(0,0.6f,0);
#define MARS glColor3f(0.8f,0.3f,0);
#define JUPITER glColor3f(0.9f,0.6f,0.8f);
#define SATURN glColor3f(0.9f,0.8f,0.3f);
#define URANUS glColor3f(0.8f,0.8f,1.0f);
#define NEPTUNE glColor3f(0.5f,0.5f,1.0f);
#define PLUTO glColor3f(0.5f,0.3f,0.2f);

void set_glcolor3f(string color);

#endif