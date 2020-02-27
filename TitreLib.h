
//! @file       TitreLib.h
//! @brief      ���������� ������ � ������
//! @mainpage   ����������� ��� � ���������� ������� �� ���������� ���������� ������ ��� ������� - TitreLib
//! - @ref      TitrStart
//! - @ref      DrawBonjour
//! - @ref      Background

//----------------------------------------------------------------------------

//! @ingroup Animation
//! @brief   ��� ������� ������ ������������ ����������� ������ �� ����
//!
//! @param    x0         ���������� ��������� ������� �� �����������
//! @param    y0         ���������� ������ �������� �������������� �� ���������
//! @param    size_font  ������ ������������� ������ ������� � ��������
//! @param    color      ���� ������� �������� <i>(�������� ����������� ���������� ���������� TXLib.h)</i>
//! @param    delay      �������� ������� ����� ������� � �������� �������� ������
//! @param    count_move ���������� ����� ������ � ��������
//!
//! @see     txClear(), txSetFillColor(), Background(),
//!
//! @code
//!          Background(400, 300, TX_WHITE);
//! @endcode
void TitrStart(double x0, double y0, double dy, int size_font, COLORREF color, int delay, int count_move);

//! @ingroup Writing
//! @brief   ��� ������� ��������� ������ ������� � ����� ������ ������
//!
//! @param    x          ���������� ������ ��������� ������ �� �����������
//! @param    y          ���������� ������ ��������� ������ �� ���������
//! @param    font       ��� ������������� ������
//! @param    size_font  ������ ������������� ������ ������� � ��������
//! @param    text       ������ ����� ������
//! @param    color      ���� ������� �������� <i>(�������� ����������� ���������� ���������� TXLib.h)</i>
//!
//! @see     txSetColor(), txSetFillColor(), txRectangle()
//!
//! @code
//!          DrawBonjour(400, 300, "Arial", 60, "Bonjour, mes amis", TX_ORANGE);
//! @endcode
void DrawBonjour(double x, double y, const char* font, int size_font, const char* text, COLORREF color);

//! @ingroup Drawing
//! @brief   ��� ������� ������ ���, ������� ��� ����������� ������ �� ������ ������������
//!
//! @param    x0         ���������� ������ �������� �������������� �� �����������
//! @param    y0         ���������� ������ �������� �������������� �� ���������
//! @param    color      ���� ������� ���� <i>(�������� ����������� ���������� ���������� TXLib.h)</i>
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
