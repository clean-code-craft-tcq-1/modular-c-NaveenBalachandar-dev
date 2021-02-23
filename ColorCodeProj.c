/*********************************************/
/***File   : ColorCodeProj.c
/***Author : Naveen B 
/***brief  : Color code project project file
/*********************************************/
/*------ standard includes -------*/
#include <stdio.h>
#include <assert.h>

/*------ project spec includes --------*/
#include "ColorCodeProj.h"

void ColorPairToString(const ColorPair* colorPair, char* buffer) {
    sprintf(buffer, "%s %s",
        MajorColorNames[colorPair->majorColor],
        MinorColorNames[colorPair->minorColor]);
}

ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = 
        (enum MajorColor)(zeroBasedPairNumber / (int)NUM_OF_MINOR_COLOR);
    colorPair.minorColor =
        (enum MinorColor)(zeroBasedPairNumber % (int)NUM_OF_MINOR_COLOR);
    return colorPair;
}

int GetPairNumberFromColor(const ColorPair* colorPair) {
    return colorPair->majorColor * (int)NUM_OF_MINOR_COLOR +
            colorPair->minorColor + 1;
}

void testNumberToPair(int pairNumber,
    enum MajorColor expectedMajor_e,
    enum MinorColor expectedMinor_e)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
    ColorPairToString(&colorPair, colorPairNames);
    printf("Caluclated pair %s\n", colorPairNames);
    assert(colorPair.majorColor == expectedMajor_e);/*Validation of given and calculated color */
    assert(colorPair.minorColor == expectedMinor_e);
}

void testPairToNumber(
    enum MajorColor major_e,
    enum MinorColor minor_e,
    int expectedPairNum_i)
{
    ColorPair colorPair;
    colorPair.majorColor = major_e;
    colorPair.minorColor = minor_e;
    int actualPairNumber_i = GetPairNumberFromColor(&colorPair);
    printf("Actual pair num calc based on colors  %d\n", actualPairNumber_i); 
    assert(actualPairNumber_i == expectedPairNum_i); /*Validation of given and calculated number*/
}

void  main() {
    /*Unit testing*/
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);
    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);
}
