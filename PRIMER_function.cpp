#include "TXLib.h"

//----------------------------------------------------------------------------

void DrawBonjour(double x, double y, const char* font, int size_font, const char* text, COLORREF color);
void DrawAdieu(double x, double y, const char* font, int size_font, const char* text, COLORREF color);
void DrawSoleil(double x0, double y0, double r_X, double r_Y, double zoom_X, double zoom_Y);
void DrawFunction(int x0, int dx, int delay, int sizeY);
void Background(double x0, double y0, COLORREF color);
void TitrStart(double x0, double y0, double dy, int size_font, COLORREF color, int delay, int count_move);
void TitrFinish(double x0, double y0, double dy, int size_font, COLORREF color, int delay, int count_move);

//----------------------------------------------------------------------------

int main()
    {
    txCreateWindow(800, 600);
    txTextCursor(false);

    TitrStart(400,  30,   3,  60, TX_BLACK,  10, 200);

    //DrawFunction( 0,  1,  50, 800);

    return 0;
    }

//----------------------------------------------------------------------------

void DrawFunction(int x, int dx, int delay, int sizeY)
    {
    txBegin();

    while (x <= sizeY)
        {
        txSetFillColor(TX_WHITE);  //  то-то хотел белый фон?
        txClear();
        Background(400, 300, TX_ORANGE);

        double y = sin(x) * 50 + 200;

        txSetColor(TX_BLACK, 5);
        txSetPixel(x, y, TX_BLACK);

        x += dx;

        txSleep(delay);
        }

    txEnd();
    }

//----------------------------------------------------------------------------

void DrawBonjour(double x, double y, const char* font, int size_font, const char* text, COLORREF color)
    {
    txSetColor (color);
    txSelectFont (font, size_font);
    txSetTextAlign (TA_CENTER);
    txTextOut (x, y, text);
    }

//----------------------------------------------------------------------------

void DrawSoleil(double x0, double y0, double r_X, double r_Y, double zoom_X, double zoom_Y)
    {
    txSetColor (TX_YELLOW);
    txSetFillColor (TX_YELLOW);
    txEllipse (x0 - r_X * zoom_X / 2, y0 - r_Y * zoom_Y / 2, x0 + r_X * zoom_X / 2, y0 + r_Y * zoom_Y / 2);
    //DrawSoleil(250, 250, 100, 200, 4, 2);
    }

//-----------------------------------------------------------------------------

void Background(double x0, double y0, COLORREF color)
    {
    txSetColor (color);
    txSetFillColor (color);
    txRectangle (x0 - 390, y0 - 290, x0 + 390, y0 + 290);
    }

//-----------------------------------------------------------------------------

void TitrStart(double x0, double y0, double dy, int size_font, COLORREF color, int delay, int count_move)
    {
    txBegin();

    double t = 0;

    while (t <= count_move)
        {
        txSetFillColor(TX_BLACK);  //  то-то хотел черный фон?
        txClear();
        Background(400, 300, TX_WHITE);

        DrawBonjour(x0, y0, "Arial", size_font, "Bonjour, mes amis", color);

        y0 += dy;
        t++;

        txSleep(delay);
        }

    txEnd();
    }
