#include "Plotter.h"
#include "strlib.h"
using namespace std;

void runPlotterScript(istream& input) {
    /* TODO: Delete this line and the one after it, then implement this function. */
    PenStyle style= {1, "orange"};

    double x0, y0 = 0;
    bool penDown = false;
    for (string line; getline(input, line);) {
        Vector<string> commands = stringSplit(line, " ");
        if (toLowerCase(commands[0] == "penup")){
            penDown = false;
        } else if (toLowerCase(commands[0] == "pendown")) {
            penDown = true;
        } else if (toLowerCase(commands[0] == "moveabs")) {
            if (penDown == true) {
                drawLine(x0, y0, stringToReal(commands[1]), stringToReal(commands[2]), style);
            }
            x0 = stringToReal(commands[1]);
            y0 = stringToReal(commands[2]);

        } else if (toLowerCase(commands[0] == "moverel")) {
            if (penDown == true) {
                drawLine(x0, y0, stringToReal(commands[1]) + x0, stringToReal(commands[2]) + y0, style);
            }
            x0 += stringToReal(commands[1]);
            y0 += stringToReal(commands[2]);

        } else if (toLowerCase(commands[0] == "pencolor")) {
            style.color = commands[1];
        } else if (toLowerCase(commands[0] == "penwidth")) {
            style.width = stringToReal(commands[1]);
        }
    }
}
