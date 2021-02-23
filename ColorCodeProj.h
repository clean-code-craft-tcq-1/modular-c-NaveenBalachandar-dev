/*Header file for project common functions */

#define MAX_COLORPAIR_NAME_CHARS  16 /*Max chars allowed for color pair*/

enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET}; /*Major colour enum*/
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE}; /*Minor colour enum*/
/*Color pair struct */
typedef struct {
    enum MajorColor majorColor;
    enum MinorColor minorColor;
} ColorPair;
