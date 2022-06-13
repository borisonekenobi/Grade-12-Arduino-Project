//#include <LiquidCrystal_I2C.h>

// LiquidCrystal_I2C lcd(0x27, 16, 2);

const int previousChar = 2; // Select previous character
const int upChar = 3;		// Set as previous character    (M => L)
const int downChar = 4;		// Set as next character        (M => N)
const int nextChar = 5;		// Select next character
const char chars[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
const char words[][3] = {{'A', 'A', 'H'}, {'A', 'A', 'L'}, {'A', 'A', 'S'}, {'A', 'B', 'A'}, {'A', 'B', 'S'}, {'A', 'B', 'Y'}, {'A', 'C', 'E'}, {'A', 'C', 'T'}, {'A', 'D', 'D'}, {'A', 'D', 'O'}, {'A', 'D', 'S'}, {'A', 'D', 'Z'}, {'A', 'F', 'F'}, {'A', 'F', 'T'}, {'A', 'G', 'A'}, {'A', 'G', 'E'}, {'A', 'G', 'O'}, {'A', 'G', 'S'}, {'A', 'H', 'A'}, {'A', 'H', 'I'}, {'A', 'H', 'S'}, {'A', 'I', 'D'}, {'A', 'I', 'L'}, {'A', 'I', 'M'}, {'A', 'I', 'N'}, {'A', 'I', 'R'}, {'A', 'I', 'S'}, {'A', 'I', 'T'}, {'A', 'J', 'I'}, {'A', 'L', 'A'}, {'A', 'L', 'B'}, {'A', 'L', 'E'}, {'A', 'L', 'L'}, {'A', 'L', 'P'}, {'A', 'L', 'S'}, {'A', 'L', 'T'}, {'A', 'M', 'A'}, {'A', 'M', 'I'}, {'A', 'M', 'P'}, {'A', 'M', 'U'}, {'A', 'N', 'A'}, {'A', 'N', 'D'}, {'A', 'N', 'E'}, {'A', 'N', 'I'}, {'A', 'N', 'T'}, {'A', 'N', 'Y'}, {'A', 'P', 'E'}, {'A', 'P', 'O'}, {'A', 'P', 'P'}, {'A', 'P', 'T'}, {'A', 'R', 'B'}, {'A', 'R', 'C'}, {'A', 'R', 'E'}, {'A', 'R', 'F'}, {'A', 'R', 'K'}, {'A', 'R', 'M'}, {'A', 'R', 'S'}, {'A', 'R', 'T'}, {'A', 'S', 'H'}, {'A', 'S', 'K'}, {'A', 'S', 'P'}, {'A', 'S', 'S'}, {'A', 'T', 'E'}, {'A', 'T', 'T'}, {'A', 'U', 'K'}, {'A', 'V', 'A'}, {'A', 'V', 'E'}, {'A', 'V', 'O'}, {'A', 'W', 'A'}, {'A', 'W', 'E'}, {'A', 'W', 'L'}, {'A', 'W', 'N'}, {'A', 'X', 'E'}, {'A', 'Y', 'E'}, {'A', 'Y', 'S'}, {'A', 'Z', 'O'}, {'B', 'A', 'A'}, {'B', 'A', 'D'}, {'B', 'A', 'G'}, {'B', 'A', 'H'}, {'B', 'A', 'L'}, {'B', 'A', 'M'}, {'B', 'A', 'N'}, {'B', 'A', 'P'}, {'B', 'A', 'R'}, {'B', 'A', 'S'}, {'B', 'A', 'T'}, {'B', 'A', 'Y'}, {'B', 'E', 'D'}, {'B', 'E', 'E'}, {'B', 'E', 'G'}, {'B', 'E', 'L'}, {'B', 'E', 'N'}, {'B', 'E', 'S'}, {'B', 'E', 'T'}, {'B', 'E', 'Y'}, {'B', 'I', 'B'}, {'B', 'I', 'D'}, {'B', 'I', 'G'}, {'B', 'I', 'N'}, {'B', 'I', 'O'}, {'B', 'I', 'S'}, {'B', 'I', 'T'}, {'B', 'I', 'Z'}, {'B', 'O', 'A'}, {'B', 'O', 'B'}, {'B', 'O', 'D'}, {'B', 'O', 'G'}, {'B', 'O', 'O'}, {'B', 'O', 'P'}, {'B', 'O', 'S'}, {'B', 'O', 'T'}, {'B', 'O', 'W'}, {'B', 'O', 'X'}, {'B', 'O', 'Y'}, {'B', 'R', 'A'}, {'B', 'R', 'O'}, {'B', 'R', 'R'}, {'B', 'U', 'B'}, {'B', 'U', 'D'}, {'B', 'U', 'G'}, {'B', 'U', 'M'}, {'B', 'U', 'N'}, {'B', 'U', 'R'}, {'B', 'U', 'S'}, {'B', 'U', 'T'}, {'B', 'U', 'Y'}, {'B', 'Y', 'E'}, {'B', 'Y', 'S'}, {'C', 'A', 'B'}, {'C', 'A', 'D'}, {'C', 'A', 'F'}, {'C', 'A', 'M'}, {'C', 'A', 'N'}, {'C', 'A', 'P'}, {'C', 'A', 'R'}, {'C', 'A', 'T'}, {'C', 'A', 'W'}, {'C', 'A', 'Y'}, {'C', 'E', 'E'}, {'C', 'E', 'L'}, {'C', 'E', 'P'}, {'C', 'H', 'I'}, {'C', 'I', 'G'}, {'C', 'I', 'S'}, {'C', 'O', 'B'}, {'C', 'O', 'D'}, {'C', 'O', 'G'}, {'C', 'O', 'L'}, {'C', 'O', 'N'}, {'C', 'O', 'O'}, {'C', 'O', 'P'}, {'C', 'O', 'R'}, {'C', 'O', 'S'}, {'C', 'O', 'T'}, {'C', 'O', 'W'}, {'C', 'O', 'X'}, {'C', 'O', 'Y'}, {'C', 'O', 'Z'}, {'C', 'R', 'U'}, {'C', 'R', 'Y'}, {'C', 'U', 'B'}, {'C', 'U', 'D'}, {'C', 'U', 'E'}, {'C', 'U', 'M'}, {'C', 'U', 'P'}, {'C', 'U', 'R'}, {'C', 'U', 'T'}, {'C', 'U', 'Z'}, {'C', 'W', 'M'}, {'D', 'A', 'B'}, {'D', 'A', 'D'}, {'D', 'A', 'G'}, {'D', 'A', 'H'}, {'D', 'A', 'K'}, {'D', 'A', 'L'}, {'D', 'A', 'M'}, {'D', 'A', 'N'}, {'D', 'A', 'P'}, {'D', 'A', 'S'}, {'D', 'A', 'W'}, {'D', 'A', 'Y'}, {'D', 'E', 'B'}, {'D', 'E', 'E'}, {'D', 'E', 'F'}, {'D', 'E', 'L'}, {'D', 'E', 'N'}, {'D', 'E', 'P'}, {'D', 'E', 'V'}, {'D', 'E', 'W'}, {'D', 'E', 'X'}, {'D', 'E', 'Y'}, {'D', 'I', 'B'}, {'D', 'I', 'D'}, {'D', 'I', 'E'}, {'D', 'I', 'F'}, {'D', 'I', 'G'}, {'D', 'I', 'M'}, {'D', 'I', 'N'}, {'D', 'I', 'P'}, {'D', 'I', 'S'}, {'D', 'I', 'T'}, {'D', 'O', 'C'}, {'D', 'O', 'E'}, {'D', 'O', 'G'}, {'D', 'O', 'H'}, {'D', 'O', 'L'}, {'D', 'O', 'M'}, {'D', 'O', 'N'}, {'D', 'O', 'R'}, {'D', 'O', 'S'}, {'D', 'O', 'T'}, {'D', 'O', 'W'}, {'D', 'R', 'Y'}, {'D', 'U', 'B'}, {'D', 'U', 'D'}, {'D', 'U', 'E'}, {'D', 'U', 'G'}, {'D', 'U', 'H'}, {'D', 'U', 'I'}, {'D', 'U', 'M'}, {'D', 'U', 'N'}, {'D', 'U', 'O'}, {'D', 'U', 'P'}, {'D', 'Y', 'E'}, {'E', 'A', 'R'}, {'E', 'A', 'T'}, {'E', 'A', 'U'}, {'E', 'B', 'B'}, {'E', 'C', 'O'}, {'E', 'C', 'U'}, {'E', 'D', 'H'}, {'E', 'D', 'S'}, {'E', 'E', 'K'}, {'E', 'E', 'L'}, {'E', 'E', 'W'}, {'E', 'F', 'F'}, {'E', 'F', 'S'}, {'E', 'F', 'T'}, {'E', 'G', 'G'}, {'E', 'G', 'O'}, {'E', 'K', 'E'}, {'E', 'L', 'D'}, {'E', 'L', 'F'}, {'E', 'L', 'K'}, {'E', 'L', 'L'}, {'E', 'L', 'M'}, {'E', 'L', 'S'}, {'E', 'M', 'E'}, {'E', 'M', 'O'}, {'E', 'M', 'S'}, {'E', 'M', 'U'}, {'E', 'N', 'D'}, {'E', 'N', 'G'}, {'E', 'N', 'S'}, {'E', 'O', 'N'}, {'E', 'R', 'A'}, {'E', 'R', 'E'}, {'E', 'R', 'G'}, {'E', 'R', 'N'}, {'E', 'R', 'R'}, {'E', 'R', 'S'}, {'E', 'S', 'S'}, {'E', 'S', 'T'}, {'E', 'T', 'A'}, {'E', 'T', 'H'}, {'E', 'V', 'E'}, {'E', 'W', 'E'}, {'E', 'Y', 'E'}, {'F', 'A', 'B'}, {'F', 'A', 'D'}, {'F', 'A', 'G'}, {'F', 'A', 'H'}, {'F', 'A', 'N'}, {'F', 'A', 'R'}, {'F', 'A', 'S'}, {'F', 'A', 'T'}, {'F', 'A', 'X'}, {'F', 'A', 'Y'}, {'F', 'E', 'D'}, {'F', 'E', 'E'}, {'F', 'E', 'H'}, {'F', 'E', 'M'}, {'F', 'E', 'N'}, {'F', 'E', 'R'}, {'F', 'E', 'S'}, {'F', 'E', 'T'}, {'F', 'E', 'U'}, {'F', 'E', 'W'}, {'F', 'E', 'Y'}, {'F', 'E', 'Z'}, {'F', 'I', 'B'}, {'F', 'I', 'D'}, {'F', 'I', 'E'}, {'F', 'I', 'G'}, {'F', 'I', 'L'}, {'F', 'I', 'N'}, {'F', 'I', 'R'}, {'F', 'I', 'T'}, {'F', 'I', 'X'}, {'F', 'I', 'Z'}, {'F', 'L', 'U'}, {'F', 'L', 'Y'}, {'F', 'O', 'B'}, {'F', 'O', 'E'}, {'F', 'O', 'G'}, {'F', 'O', 'H'}, {'F', 'O', 'N'}, {'F', 'O', 'O'}, {'F', 'O', 'P'}, {'F', 'O', 'R'}, {'F', 'O', 'U'}, {'F', 'O', 'X'}, {'F', 'O', 'Y'}, {'F', 'R', 'O'}, {'F', 'R', 'Y'}, {'F', 'U', 'B'}, {'F', 'U', 'D'}, {'F', 'U', 'G'}, {'F', 'U', 'N'}, {'F', 'U', 'R'}, {'G', 'A', 'B'}, {'G', 'A', 'D'}, {'G', 'A', 'E'}, {'G', 'A', 'G'}, {'G', 'A', 'L'}, {'G', 'A', 'M'}, {'G', 'A', 'N'}, {'G', 'A', 'P'}, {'G', 'A', 'R'}, {'G', 'A', 'S'}, {'G', 'A', 'T'}, {'G', 'A', 'Y'}, {'G', 'E', 'D'}, {'G', 'E', 'E'}, {'G', 'E', 'L'}, {'G', 'E', 'M'}, {'G', 'E', 'N'}, {'G', 'E', 'T'}, {'G', 'E', 'Y'}, {'G', 'H', 'I'}, {'G', 'I', 'B'}, {'G', 'I', 'D'}, {'G', 'I', 'E'}, {'G', 'I', 'F'}, {'G', 'I', 'G'}, {'G', 'I', 'N'}, {'G', 'I', 'P'}, {'G', 'I', 'S'}, {'G', 'I', 'T'}, {'G', 'N', 'U'}, {'G', 'O', 'A'}, {'G', 'O', 'B'}, {'G', 'O', 'D'}, {'G', 'O', 'O'}, {'G', 'O', 'R'}, {'G', 'O', 'S'}, {'G', 'O', 'T'}, {'G', 'O', 'X'}, {'G', 'R', 'R'}, {'G', 'U', 'L'}, {'G', 'U', 'M'}, {'G', 'U', 'N'}, {'G', 'U', 'T'}, {'G', 'U', 'V'}, {'G', 'U', 'Y'}, {'G', 'Y', 'M'}, {'G', 'Y', 'P'}, {'H', 'A', 'D'}, {'H', 'A', 'E'}, {'H', 'A', 'G'}, {'H', 'A', 'H'}, {'H', 'A', 'J'}, {'H', 'A', 'M'}, {'H', 'A', 'O'}, {'H', 'A', 'P'}, {'H', 'A', 'S'}, {'H', 'A', 'T'}, {'H', 'A', 'W'}, {'H', 'A', 'Y'}, {'H', 'E', 'H'}, {'H', 'E', 'M'}, {'H', 'E', 'N'}, {'H', 'E', 'P'}, {'H', 'E', 'R'}, {'H', 'E', 'S'}, {'H', 'E', 'T'}, {'H', 'E', 'W'}, {'H', 'E', 'X'}, {'H', 'E', 'Y'}, {'H', 'I', 'C'}, {'H', 'I', 'D'}, {'H', 'I', 'E'}, {'H', 'I', 'M'}, {'H', 'I', 'N'}, {'H', 'I', 'P'}, {'H', 'I', 'S'}, {'H', 'I', 'T'}, {'H', 'M', 'M'}, {'H', 'O', 'B'}, {'H', 'O', 'D'}, {'H', 'O', 'E'}, {'H', 'O', 'G'}, {'H', 'O', 'M'}, {'H', 'O', 'N'}, {'H', 'O', 'O'}, {'H', 'O', 'P'}, {'H', 'O', 'T'}, {'H', 'O', 'W'}, {'H', 'O', 'Y'}, {'H', 'U', 'B'}, {'H', 'U', 'E'}, {'H', 'U', 'G'}, {'H', 'U', 'H'}, {'H', 'U', 'M'}, {'H', 'U', 'N'}, {'H', 'U', 'P'}, {'H', 'U', 'T'}, {'H', 'Y', 'P'}, {'I', 'C', 'E'}, {'I', 'C', 'H'}, {'I', 'C', 'K'}, {'I', 'C', 'Y'}, {'I', 'D', 'S'}, {'I', 'F', 'F'}, {'I', 'F', 'S'}, {'I', 'G', 'G'}, {'I', 'L', 'K'}, {'I', 'L', 'L'}, {'I', 'M', 'P'}, {'I', 'N', 'K'}, {'I', 'N', 'N'}, {'I', 'N', 'S'}, {'I', 'O', 'N'}, {'I', 'R', 'E'}, {'I', 'R', 'K'}, {'I', 'S', 'M'}, {'I', 'T', 'S'}, {'I', 'V', 'Y'}, {'J', 'A', 'B'}, {'J', 'A', 'G'}, {'J', 'A', 'M'}, {'J', 'A', 'R'}, {'J', 'A', 'W'}, {'J', 'A', 'Y'}, {'J', 'E', 'E'}, {'J', 'E', 'T'}, {'J', 'E', 'U'}, {'J', 'I', 'B'}, {'J', 'I', 'G'}, {'J', 'I', 'N'}, {'J', 'O', 'B'}, {'J', 'O', 'E'}, {'J', 'O', 'G'}, {'J', 'O', 'T'}, {'J', 'O', 'W'}, {'J', 'O', 'Y'}, {'J', 'U', 'G'}, {'J', 'U', 'N'}, {'J', 'U', 'S'}, {'J', 'U', 'T'}, {'K', 'A', 'B'}, {'K', 'A', 'E'}, {'K', 'A', 'F'}, {'K', 'A', 'S'}, {'K', 'A', 'T'}, {'K', 'A', 'Y'}, {'K', 'E', 'A'}, {'K', 'E', 'F'}, {'K', 'E', 'G'}, {'K', 'E', 'N'}, {'K', 'E', 'P'}, {'K', 'E', 'X'}, {'K', 'E', 'Y'}, {'K', 'H', 'I'}, {'K', 'I', 'D'}, {'K', 'I', 'F'}, {'K', 'I', 'N'}, {'K', 'I', 'P'}, {'K', 'I', 'R'}, {'K', 'I', 'S'}, {'K', 'I', 'T'}, {'K', 'O', 'A'}, {'K', 'O', 'B'}, {'K', 'O', 'I'}, {'K', 'O', 'P'}, {'K', 'O', 'R'}, {'K', 'O', 'S'}, {'K', 'U', 'E'}, {'K', 'Y', 'E'}, {'L', 'A', 'B'}, {'L', 'A', 'C'}, {'L', 'A', 'D'}, {'L', 'A', 'G'}, {'L', 'A', 'H'}, {'L', 'A', 'M'}, {'L', 'A', 'P'}, {'L', 'A', 'R'}, {'L', 'A', 'S'}, {'L', 'A', 'T'}, {'L', 'A', 'V'}, {'L', 'A', 'W'}, {'L', 'A', 'X'}, {'L', 'A', 'Y'}, {'L', 'E', 'A'}, {'L', 'E', 'D'}, {'L', 'E', 'E'}, {'L', 'E', 'G'}, {'L', 'E', 'I'}, {'L', 'E', 'K'}, {'L', 'E', 'T'}, {'L', 'E', 'U'}, {'L', 'E', 'V'}, {'L', 'E', 'X'}, {'L', 'E', 'Y'}, {'L', 'I', 'B'}, {'L', 'I', 'D'}, {'L', 'I', 'E'}, {'L', 'I', 'N'}, {'L', 'I', 'P'}, {'L', 'I', 'S'}, {'L', 'I', 'T'}, {'L', 'O', 'B'}, {'L', 'O', 'G'}, {'L', 'O', 'O'}, {'L', 'O', 'P'}, {'L', 'O', 'T'}, {'L', 'O', 'W'}, {'L', 'O', 'X'}, {'L', 'U', 'D'}, {'L', 'U', 'G'}, {'L', 'U', 'M'}, {'L', 'U', 'N'}, {'L', 'U', 'V'}, {'L', 'U', 'X'}, {'L', 'Y', 'E'}, {'M', 'A', 'C'}, {'M', 'A', 'D'}, {'M', 'A', 'E'}, {'M', 'A', 'G'}, {'M', 'A', 'M'}, {'M', 'A', 'N'}, {'M', 'A', 'P'}, {'M', 'A', 'R'}, {'M', 'A', 'S'}, {'M', 'A', 'T'}, {'M', 'A', 'W'}, {'M', 'A', 'X'}, {'M', 'A', 'Y'}, {'M', 'E', 'D'}, {'M', 'E', 'G'}, {'M', 'E', 'H'}, {'M', 'E', 'L'}, {'M', 'E', 'M'}, {'M', 'E', 'N'}, {'M', 'E', 'T'}, {'M', 'E', 'W'}, {'M', 'H', 'O'}, {'M', 'I', 'B'}, {'M', 'I', 'C'}, {'M', 'I', 'D'}, {'M', 'I', 'G'}, {'M', 'I', 'L'}, {'M', 'I', 'M'}, {'M', 'I', 'R'}, {'M', 'I', 'S'}, {'M', 'I', 'X'}, {'M', 'M', 'M'}, {'M', 'O', 'A'}, {'M', 'O', 'B'}, {'M', 'O', 'C'}, {'M', 'O', 'D'}, {'M', 'O', 'G'}, {'M', 'O', 'I'}, {'M', 'O', 'L'}, {'M', 'O', 'M'}, {'M', 'O', 'N'}, {'M', 'O', 'O'}, {'M', 'O', 'P'}, {'M', 'O', 'R'}, {'M', 'O', 'S'}, {'M', 'O', 'T'}, {'M', 'O', 'W'}, {'M', 'U', 'D'}, {'M', 'U', 'G'}, {'M', 'U', 'M'}, {'M', 'U', 'N'}, {'M', 'U', 'S'}, {'M', 'U', 'T'}, {'M', 'U', 'X'}, {'M', 'Y', 'C'}, {'N', 'A', 'B'}, {'N', 'A', 'E'}, {'N', 'A', 'G'}, {'N', 'A', 'H'}, {'N', 'A', 'M'}, {'N', 'A', 'N'}, {'N', 'A', 'P'}, {'N', 'A', 'V'}, {'N', 'A', 'W'}, {'N', 'A', 'Y'}, {'N', 'E', 'B'}, {'N', 'E', 'E'}, {'N', 'E', 'G'}, {'N', 'E', 'T'}, {'N', 'E', 'W'}, {'N', 'I', 'B'}, {'N', 'I', 'L'}, {'N', 'I', 'M'}, {'N', 'I', 'P'}, {'N', 'I', 'T'}, {'N', 'I', 'X'}, {'N', 'O', 'B'}, {'N', 'O', 'D'}, {'N', 'O', 'G'}, {'N', 'O', 'H'}, {'N', 'O', 'M'}, {'N', 'O', 'O'}, {'N', 'O', 'R'}, {'N', 'O', 'S'}, {'N', 'O', 'T'}, {'N', 'O', 'W'}, {'N', 'T', 'H'}, {'N', 'U', 'B'}, {'N', 'U', 'G'}, {'N', 'U', 'N'}, {'N', 'U', 'S'}, {'N', 'U', 'T'}, {'O', 'A', 'F'}, {'O', 'A', 'K'}, {'O', 'A', 'R'}, {'O', 'A', 'T'}, {'O', 'B', 'A'}, {'O', 'B', 'E'}, {'O', 'B', 'I'}, {'O', 'C', 'A'}, {'O', 'C', 'H'}, {'O', 'D', 'A'}, {'O', 'D', 'D'}, {'O', 'D', 'E'}, {'O', 'D', 'S'}, {'O', 'E', 'S'}, {'O', 'F', 'F'}, {'O', 'F', 'T'}, {'O', 'H', 'M'}, {'O', 'H', 'O'}, {'O', 'H', 'S'}, {'O', 'I', 'K'}, {'O', 'I', 'L'}, {'O', 'K', 'A'}, {'O', 'K', 'E'}, {'O', 'L', 'D'}, {'O', 'L', 'E'}, {'O', 'M', 'A'}, {'O', 'M', 'S'}, {'O', 'N', 'E'}, {'O', 'N', 'O'}, {'O', 'N', 'S'}, {'O', 'O', 'F'}, {'O', 'O', 'H'}, {'O', 'O', 'T'}, {'O', 'P', 'A'}, {'O', 'P', 'E'}, {'O', 'P', 'S'}, {'O', 'P', 'T'}, {'O', 'R', 'A'}, {'O', 'R', 'B'}, {'O', 'R', 'C'}, {'O', 'R', 'E'}, {'O', 'R', 'G'}, {'O', 'R', 'S'}, {'O', 'R', 'T'}, {'O', 'S', 'E'}, {'O', 'U', 'D'}, {'O', 'U', 'R'}, {'O', 'U', 'T'}, {'O', 'V', 'A'}, {'O', 'W', 'E'}, {'O', 'W', 'L'}, {'O', 'W', 'N'}, {'O', 'W', 'T'}, {'O', 'X', 'O'}, {'O', 'X', 'Y'}, {'P', 'A', 'C'}, {'P', 'A', 'D'}, {'P', 'A', 'H'}, {'P', 'A', 'K'}, {'P', 'A', 'L'}, {'P', 'A', 'M'}, {'P', 'A', 'N'}, {'P', 'A', 'P'}, {'P', 'A', 'R'}, {'P', 'A', 'S'}, {'P', 'A', 'T'}, {'P', 'A', 'W'}, {'P', 'A', 'X'}, {'P', 'A', 'Y'}, {'P', 'E', 'A'}, {'P', 'E', 'C'}, {'P', 'E', 'D'}, {'P', 'E', 'E'}, {'P', 'E', 'G'}, {'P', 'E', 'H'}, {'P', 'E', 'N'}, {'P', 'E', 'P'}, {'P', 'E', 'R'}, {'P', 'E', 'S'}, {'P', 'E', 'T'}, {'P', 'E', 'W'}, {'P', 'H', 'I'}, {'P', 'H', 'O'}, {'P', 'H', 'T'}, {'P', 'I', 'A'}, {'P', 'I', 'C'}, {'P', 'I', 'E'}, {'P', 'I', 'G'}, {'P', 'I', 'N'}, {'P', 'I', 'P'}, {'P', 'I', 'S'}, {'P', 'I', 'T'}, {'P', 'I', 'U'}, {'P', 'I', 'X'}, {'P', 'L', 'Y'}, {'P', 'O', 'D'}, {'P', 'O', 'H'}, {'P', 'O', 'I'}, {'P', 'O', 'L'}, {'P', 'O', 'M'}, {'P', 'O', 'O'}, {'P', 'O', 'P'}, {'P', 'O', 'S'}, {'P', 'O', 'T'}, {'P', 'O', 'W'}, {'P', 'O', 'X'}, {'P', 'R', 'O'}, {'P', 'R', 'Y'}, {'P', 'S', 'I'}, {'P', 'S', 'T'}, {'P', 'U', 'B'}, {'P', 'U', 'D'}, {'P', 'U', 'G'}, {'P', 'U', 'L'}, {'P', 'U', 'N'}, {'P', 'U', 'P'}, {'P', 'U', 'R'}, {'P', 'U', 'S'}, {'P', 'U', 'T'}, {'P', 'Y', 'A'}, {'P', 'Y', 'E'}, {'P', 'Y', 'X'}, {'Q', 'A', 'T'}, {'Q', 'I', 'S'}, {'Q', 'U', 'A'}, {'R', 'A', 'D'}, {'R', 'A', 'G'}, {'R', 'A', 'H'}, {'R', 'A', 'I'}, {'R', 'A', 'J'}, {'R', 'A', 'M'}, {'R', 'A', 'N'}, {'R', 'A', 'P'}, {'R', 'A', 'S'}, {'R', 'A', 'T'}, {'R', 'A', 'W'}, {'R', 'A', 'X'}, {'R', 'A', 'Y'}, {'R', 'E', 'B'}, {'R', 'E', 'C'}, {'R', 'E', 'D'}, {'R', 'E', 'E'}, {'R', 'E', 'F'}, {'R', 'E', 'G'}, {'R', 'E', 'I'}, {'R', 'E', 'M'}, {'R', 'E', 'P'}, {'R', 'E', 'S'}, {'R', 'E', 'T'}, {'R', 'E', 'V'}, {'R', 'E', 'X'}, {'R', 'E', 'Z'}, {'R', 'H', 'O'}, {'R', 'I', 'A'}, {'R', 'I', 'B'}, {'R', 'I', 'D'}, {'R', 'I', 'F'}, {'R', 'I', 'G'}, {'R', 'I', 'M'}, {'R', 'I', 'N'}, {'R', 'I', 'P'}, {'R', 'O', 'B'}, {'R', 'O', 'C'}, {'R', 'O', 'D'}, {'R', 'O', 'E'}, {'R', 'O', 'M'}, {'R', 'O', 'O'}, {'R', 'O', 'T'}, {'R', 'O', 'W'}, {'R', 'U', 'B'}, {'R', 'U', 'E'}, {'R', 'U', 'G'}, {'R', 'U', 'M'}, {'R', 'U', 'N'}, {'R', 'U', 'T'}, {'R', 'Y', 'A'}, {'R', 'Y', 'E'}, {'R', 'Y', 'U'}, {'S', 'A', 'B'}, {'S', 'A', 'C'}, {'S', 'A', 'D'}, {'S', 'A', 'E'}, {'S', 'A', 'G'}, {'S', 'A', 'L'}, {'S', 'A', 'N'}, {'S', 'A', 'P'}, {'S', 'A', 'T'}, {'S', 'A', 'U'}, {'S', 'A', 'W'}, {'S', 'A', 'X'}, {'S', 'A', 'Y'}, {'S', 'E', 'A'}, {'S', 'E', 'C'}, {'S', 'E', 'E'}, {'S', 'E', 'G'}, {'S', 'E', 'I'}, {'S', 'E', 'L'}, {'S', 'E', 'N'}, {'S', 'E', 'R'}, {'S', 'E', 'T'}, {'S', 'E', 'V'}, {'S', 'E', 'W'}, {'S', 'E', 'X'}, {'S', 'H', 'A'}, {'S', 'H', 'E'}, {'S', 'H', 'H'}, {'S', 'H', 'O'}, {'S', 'H', 'Y'}, {'S', 'I', 'B'}, {'S', 'I', 'C'}, {'S', 'I', 'G'}, {'S', 'I', 'M'}, {'S', 'I', 'N'}, {'S', 'I', 'P'}, {'S', 'I', 'R'}, {'S', 'I', 'S'}, {'S', 'I', 'T'}, {'S', 'I', 'X'}, {'S', 'K', 'A'}, {'S', 'K', 'I'}, {'S', 'K', 'Y'}, {'S', 'L', 'Y'}, {'S', 'O', 'B'}, {'S', 'O', 'C'}, {'S', 'O', 'D'}, {'S', 'O', 'H'}, {'S', 'O', 'L'}, {'S', 'O', 'M'}, {'S', 'O', 'N'}, {'S', 'O', 'P'}, {'S', 'O', 'S'}, {'S', 'O', 'T'}, {'S', 'O', 'U'}, {'S', 'O', 'W'}, {'S', 'O', 'X'}, {'S', 'O', 'Y'}, {'S', 'P', 'A'}, {'S', 'P', 'Y'}, {'S', 'R', 'I'}, {'S', 'T', 'Y'}, {'S', 'U', 'B'}, {'S', 'U', 'E'}, {'S', 'U', 'K'}, {'S', 'U', 'M'}, {'S', 'U', 'N'}, {'S', 'U', 'P'}, {'S', 'U', 'Q'}, {'S', 'U', 'S'}, {'S', 'Y', 'N'}, {'T', 'A', 'B'}, {'T', 'A', 'D'}, {'T', 'A', 'E'}, {'T', 'A', 'G'}, {'T', 'A', 'J'}, {'T', 'A', 'M'}, {'T', 'A', 'N'}, {'T', 'A', 'O'}, {'T', 'A', 'P'}, {'T', 'A', 'R'}, {'T', 'A', 'S'}, {'T', 'A', 'T'}, {'T', 'A', 'U'}, {'T', 'A', 'V'}, {'T', 'A', 'W'}, {'T', 'A', 'X'}, {'T', 'E', 'A'}, {'T', 'E', 'C'}, {'T', 'E', 'D'}, {'T', 'E', 'E'}, {'T', 'E', 'G'}, {'T', 'E', 'L'}, {'T', 'E', 'N'}, {'T', 'E', 'S'}, {'T', 'E', 'T'}, {'T', 'E', 'W'}, {'T', 'H', 'E'}, {'T', 'H', 'O'}, {'T', 'H', 'Y'}, {'T', 'I', 'C'}, {'T', 'I', 'E'}, {'T', 'I', 'L'}, {'T', 'I', 'N'}, {'T', 'I', 'P'}, {'T', 'I', 'S'}, {'T', 'I', 'T'}, {'T', 'I', 'X'}, {'T', 'I', 'Z'}, {'T', 'O', 'D'}, {'T', 'O', 'E'}, {'T', 'O', 'G'}, {'T', 'O', 'M'}, {'T', 'O', 'N'}, {'T', 'O', 'O'}, {'T', 'O', 'P'}, {'T', 'O', 'R'}, {'T', 'O', 'T'}, {'T', 'O', 'W'}, {'T', 'O', 'Y'}, {'T', 'R', 'Y'}, {'T', 'S', 'K'}, {'T', 'U', 'B'}, {'T', 'U', 'G'}, {'T', 'U', 'I'}, {'T', 'U', 'M'}, {'T', 'U', 'N'}, {'T', 'U', 'P'}, {'T', 'U', 'T'}, {'T', 'U', 'X'}, {'T', 'W', 'A'}, {'T', 'W', 'O'}, {'T', 'Y', 'E'}, {'U', 'D', 'O'}, {'U', 'G', 'H'}, {'U', 'K', 'E'}, {'U', 'L', 'U'}, {'U', 'M', 'M'}, {'U', 'M', 'P'}, {'U', 'M', 'S'}, {'U', 'N', 'I'}, {'U', 'N', 'S'}, {'U', 'P', 'O'}, {'U', 'P', 'S'}, {'U', 'R', 'B'}, {'U', 'R', 'D'}, {'U', 'R', 'N'}, {'U', 'R', 'P'}, {'U', 'S', 'E'}, {'U', 'T', 'A'}, {'U', 'T', 'E'}, {'U', 'T', 'S'}, {'V', 'A', 'C'}, {'V', 'A', 'N'}, {'V', 'A', 'R'}, {'V', 'A', 'S'}, {'V', 'A', 'T'}, {'V', 'A', 'U'}, {'V', 'A', 'V'}, {'V', 'A', 'W'}, {'V', 'E', 'E'}, {'V', 'E', 'G'}, {'V', 'E', 'T'}, {'V', 'E', 'X'}, {'V', 'I', 'A'}, {'V', 'I', 'D'}, {'V', 'I', 'E'}, {'V', 'I', 'G'}, {'V', 'I', 'M'}, {'V', 'I', 'N'}, {'V', 'I', 'S'}, {'V', 'O', 'E'}, {'V', 'O', 'G'}, {'V', 'O', 'W'}, {'V', 'O', 'X'}, {'V', 'U', 'G'}, {'V', 'U', 'M'}, {'W', 'A', 'B'}, {'W', 'A', 'D'}, {'W', 'A', 'E'}, {'W', 'A', 'G'}, {'W', 'A', 'N'}, {'W', 'A', 'P'}, {'W', 'A', 'R'}, {'W', 'A', 'S'}, {'W', 'A', 'T'}, {'W', 'A', 'W'}, {'W', 'A', 'X'}, {'W', 'A', 'Y'}, {'W', 'E', 'B'}, {'W', 'E', 'D'}, {'W', 'E', 'E'}, {'W', 'E', 'N'}, {'W', 'E', 'T'}, {'W', 'H', 'A'}, {'W', 'H', 'O'}, {'W', 'H', 'Y'}, {'W', 'I', 'G'}, {'W', 'I', 'N'}, {'W', 'I', 'S'}, {'W', 'I', 'T'}, {'W', 'I', 'Z'}, {'W', 'O', 'E'}, {'W', 'O', 'K'}, {'W', 'O', 'N'}, {'W', 'O', 'O'}, {'W', 'O', 'S'}, {'W', 'O', 'T'}, {'W', 'O', 'W'}, {'W', 'R', 'Y'}, {'W', 'U', 'D'}, {'W', 'Y', 'E'}, {'W', 'Y', 'N'}, {'X', 'I', 'S'}, {'Y', 'A', 'G'}, {'Y', 'A', 'H'}, {'Y', 'A', 'K'}, {'Y', 'A', 'M'}, {'Y', 'A', 'P'}, {'Y', 'A', 'R'}, {'Y', 'A', 'S'}, {'Y', 'A', 'W'}, {'Y', 'A', 'Y'}, {'Y', 'E', 'A'}, {'Y', 'E', 'H'}, {'Y', 'E', 'N'}, {'Y', 'E', 'P'}, {'Y', 'E', 'S'}, {'Y', 'E', 'T'}, {'Y', 'E', 'W'}, {'Y', 'I', 'N'}, {'Y', 'I', 'P'}, {'Y', 'O', 'B'}, {'Y', 'O', 'D'}, {'Y', 'O', 'K'}, {'Y', 'O', 'M'}, {'Y', 'O', 'N'}, {'Y', 'O', 'U'}, {'Y', 'O', 'W'}, {'Y', 'U', 'K'}, {'Y', 'U', 'M'}, {'Y', 'U', 'P'}, {'Z', 'A', 'G'}, {'Z', 'A', 'P'}, {'Z', 'A', 'S'}, {'Z', 'A', 'X'}, {'Z', 'E', 'D'}, {'Z', 'E', 'E'}, {'Z', 'E', 'K'}, {'Z', 'E', 'N'}, {'Z', 'E', 'P'}, {'Z', 'I', 'G'}, {'Z', 'I', 'N'}, {'Z', 'I', 'P'}, {'Z', 'I', 'T'}, {'Z', 'O', 'A'}, {'Z', 'O', 'O'}, {'Z', 'U', 'Z'}, {'Z', 'Z', 'Z'}};
int numTries;
int typeIndex = 0;
int charIndex = 0;
char word[] = {'A', 'A', 'A'};
char randomWord[];

bool startGame = false;

void setup()
{
	// initialize the pushbutton pin as an input:
	pinMode(previousChar, INPUT);
	pinMode(upChar, INPUT);
	pinMode(downChar, INPUT);
	pinMode(nextChar, INPUT);
}

void loop()
{
	if (!startGame)
	{
		// TODO: choose random word:
		const int len = sizeof(words) / sizeof(words[0]);
		lcd.print(words[random(len)]);
		numTries = 5;
		startGame = true;
		return;
	}

	if (numTries <= 0)
	{
		loseSequence();
	}

	if (digitalRead(previousChar) == HIGH)
	{
		typeIndex--;
		if (typeIndex < 0)
			typeIndex = 0;
	}
	if (digitalRead(upChar) == HIGH)
	{
		charIndex--;
		if (charIndex < 0)
			charIndex = sizeof(chars) - 1;
	}
	if (digitalRead(downChar) == HIGH)
	{
		charIndex++;
		if (charIndex >= 26)
			charIndex = 0;
	}
	if (digitalRead(nextChar) == HIGH)
	{
		typeIndex++;
		if (typeIndex >= 3)
			checkWord();
	}

	Serial.println(chars[charIndex]);
	word[typeIndex] = chars[charIndex];

	delay(170);
}

void setup()
{
	pinMode(redPin, OUTPUT);
	pinMode(greenPin, OUTPUT);
	pinMode(bluePin, OUTPUT);
}

void checkWord()
{
	numTries--;
	int correctCounter = 0;

	for (int i = 0; i < sizeof(word); i++)
	{
		// light green led.
		if (word[i] == randomWord[i])
		{
			correctCounter++;
			if (i == 0)
			{
				int redPin = 13;
				int greenPin = 12;
				int bluePin = 11;
				setColor(0, 255, 0);
			}
			else if (i == 1)
			{
				int redPin = 10;
				int greenPin = 8;
				int bluePin = 7;
				setColor(0, 255, 0);
			}
			else
			{
				int redPin = 6;
				int greenPin = 5;
				int bluePin = 0;
				setColor(0, 255, 0);
			}
		}
		else if (isInArr(word[i], randomWord))
		{
			// light up yellow LED
			if (i == 0)
			{
				int redPin = 13;
				int greenPin = 12;
				int bluePin = 11;
				setColor(255, 215, 0);
			}
			else if (i == 1)
			{
				int redPin = 10;
				int greenPin = 8;
				int bluePin = 7;
				setColor(255, 215, 0);
			}
			else
			{
				int redPin = 6;
				int greenPin = 5;
				int bluePin = 0;
				setColor(255, 215, 0);
			}
		}
		else
		{
			// light up blue LED
			if (i == 0)
			{
				int redPin = 13;
				int greenPin = 12;
				int bluePin = 11;
				setColor(0, 0, 255);
			}
			else if (i == 1)
			{
				int redPin = 10;
				int greenPin = 8;
				int bluePin = 7;
				setColor(0, 0, 255);
			}
			else
			{
				int redPin = 6;
				int greenPin = 5;
				int bluePin = 0;
				setColor(0, 0, 255);
			}
		}
	}
	delay(1000);
	// TODO: turn off all LEDs
	setColor(0, 0, 0);

	if (correctCounter >= 3)
	{
		winSequence();
	}
}

bool isInArr(char element, char[] array)
{
	for (char a : array)
	{
		if (element == a)
			return true;
	}
	return false;
}

void winSequence()
{
	startGame = false;
	// TODO: make a win sequence
}

void loseSequence()
{
	startGame = false;
	// TODO: make a lose sequence
}