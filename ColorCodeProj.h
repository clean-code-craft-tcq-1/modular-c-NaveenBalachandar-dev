/*Header file for project common functions */

#define MAX_COLORPAIR_NAME_CHARS  16 /*Max chars allowed for color pair*/
#define numberOfMinorColors 5
enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET}; /*Major colour enum*/
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE}; /*Minor colour enum*/
/*Major and Minor color names*/
const char* MajorColorNames[] = {
    "White", "Red", "Black", "Yellow", "Violet"
};
const char* MinorColorNames[] = {
    "Blue", "Orange", "Green", "Brown", "Slate"
};

/*Color pair struct */
typedef struct {
    enum MajorColor majorColor;
    enum MinorColor minorColor;
} ColorPair;
