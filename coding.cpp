#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <algorithm>

#include "coding.h"

#define MAX_BUF_LENGTH 65535
static char gbuf[MAX_BUF_LENGTH];

/*
+---+-------------------+
|   | 1 | 2 | 3 | 4 | 5 |
+---+---+---+---+---+---+
| 1 | a | b | c | d | e |
+---+---+---+---+---+---+
| 2 | f | g | h | i | j |
+---+---+---+---+---+---+
| 3 | k | l | m | n | o |
+---+---+---+---+---+---+
| 4 | p | q | r | s | t |
+---+---+---+---+---+---+
| 5 | u | v | w | x | y |
+---+---+---+---+---+---+
| 6 | z | , | . |   | \n|
+-----------------------+
*/

static char c1[6][5] = {
    {'a', 'b', 'c', 'd', 'e'},
    {'f', 'g', 'h', 'i', 'j'},
    {'k', 'l', 'm', 'n', 'o'},
    {'p', 'q', 'r', 's', 't'},
    {'u', 'v', 'w', 'x', 'y'},
    {'z', ',', '.', ' ', '!'},
};

static char c2[128][3] = {
  //0  1   2  3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
  //30 31  32    33   34  35  36 37   38 39   40  41  42  43  44   45  46   47  48  49  50  51  52  53  54  55  56  57  58  59
  "", "", "64", "65", "", "", "", "", "", "", "", "", "", "", ",", "", ".", "", "", "", "", "", "", "", "", "", "", "", "", "",
  //60 ~ 89
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
  //90 ~ 96
  "", "", "", "", "", "", "",
  //a - z = 97 ... 122
  //{'a', 'b', 'c', 'd', 'e'},
  "11", "12", "13", "14", "15",
  //{'f', 'g', 'h', 'i', 'j'},
  "21", "22", "23", "24", "25",
  //{'k', 'l', 'm', 'n', 'o'},
  "31", "32", "33", "34", "35",
  //{'p', 'q', 'r', 's', 't'},
  "41", "42", "43", "44", "45",
  //{'u', 'v', 'w', 'x', 'y'},
  "51", "52", "53", "54", "55",
  //{'z'
  "61",
  "",
  //123 ~ 126
  "", "", "", "",
};

char* encode(const char* str)
{
    memset(gbuf, 0 , MAX_BUF_LENGTH);
    int len = std::min((int)strlen(str), MAX_BUF_LENGTH / 2 - 2);

    for (int i = 0; i < len; ++i) {
      if ((str[i] >= 'a' && str[i] <= 'z')
          || (str[i] == ',')
          || (str[i] == '.')
          || (str[i] == ' ')
          || (str[i] == '!'))
        strcat(gbuf, c2[str[i]]);
    }

    return gbuf;
}

char* decode(const char* str)
{
    memset(gbuf, 0 , MAX_BUF_LENGTH);

    if (!strcmp(str, "231141415564122443452364141155656424643235521564553551656421433533643211351211")) {
        strcpy(gbuf, "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">"
               "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">"
               "p, li { white-space: pre-wrap; }"
               "</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">"
               "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600; font-style:italic; color:#ff0000;\">happy </span><span style=\" font-size:16pt; font-weight:600; font-style:italic; color:#0000ff;\">birth</span><span style=\" font-size:16pt; font-weight:600; font-style:italic;\"> </span><span style=\" font-size:16pt; font-weight:600; font-style:italic; color:#aa55ff;\">day</span><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">! </span><span style=\" font-size:16pt; font-weight:600; font-style:italic; color:#55007f;\">i</span><span style=\" font-size:16pt; font-weight:600; font-style:italic;\"> </span><span style=\" font-size:16pt; font-weight:600; font-style:italic; color:#aaaa00;\">love</span><span style=\" font-size:16pt; font-weight:600; font-style:italic;\"> </span><span style=\" font-size:16pt; font-weight:600; font-style:italic; color:#ff0000;\">you</span><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">! </span><span style=\" font-size:16pt; font-weight:600; font-style:italic; color:#aa0000;\">from</span><span style=\" font-size:16pt; font-weight:600; font-style:italic;\"> </span><span style=\" font-size:16pt; font-weight:600; font-style:italic; color:#00007f;\">laoba</span></p></body></html>");
        return gbuf;
    }

    int len = std::min((int)strlen(str), MAX_BUF_LENGTH);
    if (len % 2) --len;
    char* ptr = gbuf;
    for (int i = 0; i < len; i += 2, ++ptr)
        *ptr = c1[str[i] - '0' - 1][str[i + 1] - '0' - 1];
    return gbuf;
}
