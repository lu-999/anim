
//! @file       TitreLib.h
//! @brief      Библиотека титров в фильме
//! @mainpage   Приветствую вас в справочной системе по библиотеке разработки титров для фильмов - TitreLib
//! - @ref      TitrStart
//! - @ref      DrawBonjour
//! - @ref      Background

//----------------------------------------------------------------------------

//! @ingroup Animation
//! @brief   Эта функция задает вертикальное перемещение титров по фону
//!
//! @param    x0         координата начальной позиции по горизонтали
//! @param    y0         координата центра фонового прямоугольника по вертикали
//! @param    size_font  размер используемого шрифта надписи в пикселях
//! @param    color      цвет заливки символов <i>(задается стандартной константой библиотеки TXLib.h)</i>
//! @param    delay      задержка времени между кадрами в анимации движения титров
//! @param    count_move количество смены кадров в анимации
//!
//! @see     txClear(), txSetFillColor(), Background(),
//!
//! @code
//!          Background(400, 300, TX_WHITE);
//! @endcode
void TitrStart(double x0, double y0, double dy, int size_font, COLORREF color, int delay, int count_move);

//! @ingroup Writing
//! @brief   Эта функция позволяет задать размеры и текст титров фильма
//!
//! @param    x          координата центра появления записи по горизонтали
//! @param    y          координата центра появления записи по вертикали
//! @param    font       тип используемого шрифта
//! @param    size_font  размер используемого шрифта надписи в пикселях
//! @param    text       задает текст титров
//! @param    color      цвет заливки символов <i>(задается стандартной константой библиотеки TXLib.h)</i>
//!
//! @see     txSetColor(), txSetFillColor(), txRectangle()
//!
//! @code
//!          DrawBonjour(400, 300, "Arial", 60, "Bonjour, mes amis", TX_ORANGE);
//! @endcode
void DrawBonjour(double x, double y, const char* font, int size_font, const char* text, COLORREF color);

//! @ingroup Drawing
//! @brief   Эта функция рисует фон, заливая его стандартным цветом по выбору пользователя
//!
//! @param    x0         координата центра фонового прямоугольника по горизонтали
//! @param    y0         координата центра фонового прямоугольника по вертикали
//! @param    color      цвет заливки фона <i>(задается стандартной константой библиотеки TXLib.h)</i>
//!
//! @see     txSetColor(), txSelectFont(), txSetTextAlign(), txTextOut()

//!
//! @code
//!          Background(400, 300, TX_WHITE);
//! @endcode
void Background(double x0, double y0, COLORREF color);

//-----------------------------------------------------------------------------

void TitrStart(double x0, double y0, double dy, int size_font, COLORREF color, int delay, int count_move)
    {
    txBegin();

    double t = 0;

    while (t <= count_move)
        {
        txSetFillColor(TX_BLACK);
        txClear();
        Background(400, 300, TX_WHITE);

        DrawBonjour(x0, y0, "Arial", size_font, "Bonjour, mes amis", color);

        y0 += dy;
        t++;

        txSleep(delay);
        }

    txEnd();
    }

//----------------------------------------------------------------------------

void DrawBonjour(double x, double y, const char* font, int size_font, const char* text, COLORREF color)
    {
    txSetColor(color);
    txSelectFont(font, size_font);
    txSetTextAlign(TA_CENTER);
    txTextOut(x, y, text);
    }

//-----------------------------------------------------------------------------

void Background(double x0, double y0, COLORREF color)
    {
    txSetColor(color);
    txSetFillColor(color);
    txRectangle(x0 - 390, y0 - 290, x0 + 390, y0 + 290);
    }
