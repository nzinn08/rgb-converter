#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;

#define RED_OUTPUT_BITS (5)
#define GREEN_OUTPUT_BITS (6)
#define BLUE_OUTPUT_BITS (5)

static constexpr char prompt[] = "Please enter your 24-bit hex rgb value: 0x";

//Function Prototypes
static int convertRGBVal(int rgb_24);
static inline void promptAndGetInput(std::string& input);

int main(void)
{
    std::string inputString;
    promptAndGetInput(inputString);
    while (inputString.size() != 0)
    {
        //Convert string to int
        int inputVal = stoi(inputString,nullptr,16);

        int outputVal = convertRGBVal(inputVal);
        cout << "Output " << RED_OUTPUT_BITS << GREEN_OUTPUT_BITS << BLUE_OUTPUT_BITS << " rgb value: 0x" << std::hex << outputVal << endl;
        promptAndGetInput(inputString);
    }

    return 0;
}

int convertRGBVal(int rgb_24)
{
    int red = (rgb_24 >> 16) & 0xFF;
    int green = (rgb_24 >> 8) & 0xFF;
    int blue = (rgb_24 >> 0) & 0xFF;

    red = (red >> (8 - RED_OUTPUT_BITS)) << (GREEN_OUTPUT_BITS + BLUE_OUTPUT_BITS);
    green = (green >> (8 - GREEN_OUTPUT_BITS)) << (BLUE_OUTPUT_BITS);
    blue = (blue >> (8 - BLUE_OUTPUT_BITS)) << (0);

    return (red | green | blue);
}

inline void promptAndGetInput(std::string& input)
{
    cout << prompt << std::flush;
    getline(cin,input);
}