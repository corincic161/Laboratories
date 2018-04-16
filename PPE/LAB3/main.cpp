#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include <string.h>
#include <iostream>
#include <stdio.h>
/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (hThisInstance, MAKEINTRESOURCE(IDI_ICON));
    wincl.hIconSm = LoadIcon (hThisInstance, MAKEINTRESOURCE(IDI_ICON));
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = MAKEINTRESOURCE(IDM_MENU);                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = CreateSolidBrush(RGB(153, 255, 102));

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Windows Programming #3"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           420,       /* Windows decides the position */
           300,       /* where the window ends up on the screen */
           650,                 /* The programs width */
           423,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    RECT rect = {10, 10, 450, 330};
    HPEN hpen;
    static HWND lineTool, penTool, polylineTool, rectTool, ellipseTool,
                clearButton, bezierTool, eraserTool, weightArea, okButton,
                colorButton;
    static BOOL isDrawing = FALSE;
    static int xStart, yStart, xEnd, yEnd;
    static int mouse_x, mouse_y;
    int cxCoord, cyCoord;
    char buffer[12] = "Set weight";
    char buffer2[12] = "Set color";
    char buffer3[12] = "Fill object";
    char textStore[50];
    POINT bez[4] = {{60, 80}, {88, 112}, {210, 67}, {160, 20}};
    static bool bezier = false;
    static int weight = 4;
    HINSTANCE hInstance = (HINSTANCE)GetWindowLong(hwnd, GWLP_HINSTANCE);
    HBITMAP bitmapHBmp;
    BITMAP bitmapBmp;
    bitmapHBmp = (HBITMAP)LoadImage(hInstance, "bitmap.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    GetObject(bitmapHBmp, sizeof(bitmapBmp), &bitmapBmp);
    mouse_x = LOWORD(lParam);
    mouse_y = HIWORD(lParam);
    COLORREF colour;
    HBRUSH hbrush;
    switch (message)                  /* handle the messages */
    {
        case WM_COMMAND:
        {
            switch(LOWORD(wParam))
            {
                case IDB_PEN:
                {
                    Button_SetCheck(lineTool, BST_UNCHECKED);
                    Button_SetCheck(polylineTool, BST_UNCHECKED);
                    Button_SetCheck(rectTool, BST_UNCHECKED);
                    Button_SetCheck(ellipseTool, BST_UNCHECKED);
                    Button_SetCheck(clearButton, BST_UNCHECKED);
                    Button_SetCheck(bezierTool, BST_UNCHECKED);
                    Button_SetCheck(eraserTool, BST_UNCHECKED);
                    break;
                }

                case IDB_LINE:
                {
                    Button_SetCheck(penTool, BST_UNCHECKED);
                    Button_SetCheck(polylineTool, BST_UNCHECKED);
                    Button_SetCheck(rectTool, BST_UNCHECKED);
                    Button_SetCheck(ellipseTool, BST_UNCHECKED);
                    Button_SetCheck(clearButton, BST_UNCHECKED);
                    Button_SetCheck(bezierTool, BST_UNCHECKED);
                    Button_SetCheck(eraserTool, BST_UNCHECKED);
                    break;
                }

                case IDB_POLYLINE:
                {
                    Button_SetCheck(lineTool, BST_UNCHECKED);
                    Button_SetCheck(penTool, BST_UNCHECKED);
                    Button_SetCheck(rectTool, BST_UNCHECKED);
                    Button_SetCheck(ellipseTool, BST_UNCHECKED);
                    Button_SetCheck(clearButton, BST_UNCHECKED);
                    Button_SetCheck(bezierTool, BST_UNCHECKED);
                    Button_SetCheck(eraserTool, BST_UNCHECKED);
                    break;

                }

                case IDB_ELLIPSE:
                {
                    Button_SetCheck(lineTool, BST_UNCHECKED);
                    Button_SetCheck(penTool, BST_UNCHECKED);
                    Button_SetCheck(rectTool, BST_UNCHECKED);
                    Button_SetCheck(polylineTool, BST_UNCHECKED);
                    Button_SetCheck(clearButton, BST_UNCHECKED);
                    Button_SetCheck(bezierTool, BST_UNCHECKED);
                    Button_SetCheck(eraserTool, BST_UNCHECKED);
                    break;

                }

                case IDB_RECT:
                {
                    Button_SetCheck(lineTool, BST_UNCHECKED);
                    Button_SetCheck(penTool, BST_UNCHECKED);
                    Button_SetCheck(polylineTool, BST_UNCHECKED);
                    Button_SetCheck(ellipseTool, BST_UNCHECKED);
                    Button_SetCheck(clearButton, BST_UNCHECKED);
                    Button_SetCheck(bezierTool, BST_UNCHECKED);
                    Button_SetCheck(eraserTool, BST_UNCHECKED);
                    break;
                }

                case IDB_BEZIER:
                {
                    Button_SetCheck(lineTool, BST_UNCHECKED);
                    Button_SetCheck(penTool, BST_UNCHECKED);
                    Button_SetCheck(polylineTool, BST_UNCHECKED);
                    Button_SetCheck(ellipseTool, BST_UNCHECKED);
                    Button_SetCheck(clearButton, BST_UNCHECKED);
                    Button_SetCheck(rectTool, BST_UNCHECKED);
                    Button_SetCheck(eraserTool, BST_UNCHECKED);
                    bezier = true;
                    InvalidateRect(hwnd, NULL, TRUE);
                    UpdateWindow(hwnd);
                    break;
                }

                case IDB_CLEAR:
                {
                    Button_SetCheck(lineTool, BST_UNCHECKED);
                    Button_SetCheck(penTool, BST_UNCHECKED);
                    Button_SetCheck(polylineTool, BST_UNCHECKED);
                    Button_SetCheck(ellipseTool, BST_UNCHECKED);
                    Button_SetCheck(rectTool, BST_UNCHECKED);
                    Button_SetCheck(bezierTool, BST_UNCHECKED);
                    Button_SetCheck(eraserTool, BST_UNCHECKED);
                    InvalidateRect(hwnd, &rect, FALSE);
                    InvalidateRect(hwnd, &rect, TRUE);
                    Button_SetCheck(clearButton, BST_UNCHECKED);
                    break;
                }

                case IDB_ERASER:
                {
                    Button_SetCheck(lineTool, BST_UNCHECKED);
                    Button_SetCheck(penTool, BST_UNCHECKED);
                    Button_SetCheck(polylineTool, BST_UNCHECKED);
                    Button_SetCheck(ellipseTool, BST_UNCHECKED);
                    Button_SetCheck(clearButton, BST_UNCHECKED);
                    Button_SetCheck(rectTool, BST_UNCHECKED);
                    Button_SetCheck(bezierTool, BST_UNCHECKED);
                    break;
                }

                case ID_CLEAR:
                {
                    SetFocus(hwnd);
                    InvalidateRect(hwnd, &rect, FALSE);
                    InvalidateRect(hwnd, &rect, TRUE);
                    break;

                }

                case IDB_OK:
                {
                    GetWindowText(weightArea, textStore, 50);
                    weight = atoi(textStore);
                    printf("%d", weight);
                    break;
                }

                case ID_EXIT:
                {
                    PostQuitMessage(0);
                    break;
                }
            }
            break;
        }

        case WM_CREATE:
        {
            lineTool = CreateWindowEx(NULL, "BUTTON", "Line",
                                      WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX | BS_PUSHLIKE,
                                      455, 35, 80, 20,
                                      hwnd, (HMENU)IDB_LINE, GetModuleHandle(NULL), NULL);
            penTool = CreateWindowEx(NULL, "BUTTON", "Pen",
                                      WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX | BS_PUSHLIKE,
                                      455, 10, 80, 20,
                                      hwnd, (HMENU)IDB_PEN, GetModuleHandle(NULL), NULL);
            polylineTool = CreateWindowEx(NULL, "BUTTON", "Polyline",
                                          WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX | BS_PUSHLIKE,
                                          455, 60, 80, 20,
                                          hwnd, (HMENU)IDB_POLYLINE, GetModuleHandle(NULL), NULL);
            rectTool = CreateWindowEx(NULL, "BUTTON", "Rectangle",
                                          WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX | BS_PUSHLIKE,
                                          455, 85, 80, 20,
                                          hwnd, (HMENU)IDB_RECT, GetModuleHandle(NULL), NULL);
            ellipseTool = CreateWindowEx(NULL, "BUTTON", "Ellipse",
                                         WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX | BS_PUSHLIKE,
                                         455, 110, 80, 20,
                                         hwnd, (HMENU)IDB_ELLIPSE, GetModuleHandle(NULL), NULL);
            clearButton = CreateWindowEx(NULL, "BUTTON", "Clear",
                                         WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX | BS_PUSHLIKE,
                                         10, 335, 441, 20,
                                         hwnd, (HMENU)IDB_CLEAR, GetModuleHandle(NULL), NULL);
            bezierTool = CreateWindowEx(NULL, "BUTTON", "Bezier",
                                         WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX | BS_PUSHLIKE,
                                         455, 135, 80, 20,
                                         hwnd, (HMENU)IDB_BEZIER, GetModuleHandle(NULL), NULL);
            eraserTool = CreateWindowEx(NULL, "BUTTON", "Eraser",
                                         WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX | BS_PUSHLIKE,
                                         455, 160, 80, 20,
                                         hwnd, (HMENU)IDB_ERASER, GetModuleHandle(NULL), NULL);
            weightArea = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "",
                                        WS_VISIBLE | WS_CHILD | ES_NUMBER,
                                        545, 200, 25, 20,
                                        hwnd, (HMENU)IDC_WEIGHT, GetModuleHandle(NULL), NULL);
            okButton = CreateWindowEx(NULL, "BUTTON", "OK",
                                         WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                         580, 200, 30, 20,
                                         hwnd, (HMENU)IDB_OK, GetModuleHandle(NULL), NULL);
            CreateWindowEx(NULL, "BUTTON", "Red",
                            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON | WS_GROUP,
                            543, 235, 60, 18,
                            hwnd, (HMENU)IDB_RED, GetModuleHandle(NULL), NULL);
            CreateWindowEx(NULL, "BUTTON", "Green",
                            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                            543, 255, 60, 18,
                            hwnd, (HMENU)IDB_GREEN, GetModuleHandle(NULL), NULL);
            CreateWindowEx(NULL, "BUTTON", "Blue",
                            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
                            543, 275, 60, 18,
                            hwnd, (HMENU)IDB_BLUE, GetModuleHandle(NULL), NULL);
            CreateWindowEx(NULL, "BUTTON", "Black",
                            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON | BST_CHECKED,
                            543, 295, 60, 18,
                            hwnd, (HMENU)IDB_BLACK, GetModuleHandle(NULL), NULL);
            CreateWindowEx(NULL, "BUTTON", "",
                            WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX,
                            543, 320, 60, 18,
                            hwnd, (HMENU)IDB_FILL, GetModuleHandle(NULL), NULL);
            Button_SetCheck(GetDlgItem(hwnd, IDB_BLACK), BST_CHECKED);
            RegisterHotKey(hwnd, HK_CLEAR, MOD_CONTROL, 0x4E);
            bitmapHBmp = (HBITMAP)LoadImage(hInstance, "bitmap.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            break;
        }

        case WM_LBUTTONDOWN:
        {
            if(mouse_x > 10 && mouse_x < 450 && mouse_y > 10 && mouse_y < 330)
            {
                if(Button_GetCheck(GetDlgItem(hwnd, IDB_RED)) == BST_CHECKED)
                {
                    colour = RGB(255, 0, 0);
                }
                else if(Button_GetCheck(GetDlgItem(hwnd, IDB_GREEN)) == BST_CHECKED)
                {
                    colour = RGB(0, 255, 0);
                }
                else if(Button_GetCheck(GetDlgItem(hwnd, IDB_BLUE)) == BST_CHECKED)
                {
                    colour = RGB(0, 0, 255);
                }
                else if(Button_GetCheck(GetDlgItem(hwnd, IDB_BLACK)) == BST_CHECKED)
                {
                    colour = RGB(0, 0, 0);
                }
                hpen = CreatePen(PS_SOLID, weight, colour);
                hdc = GetDC(hwnd);
                SelectObject(hdc, hpen);
                xStart = LOWORD(lParam);
                yStart = HIWORD(lParam);
                xEnd = LOWORD(lParam);
                yEnd = HIWORD(lParam);
                if(Button_GetCheck(lineTool) == BST_CHECKED)
                {
                    SetROP2(hdc, R2_XORPEN);
                    MoveToEx(hdc, xStart, yStart, NULL);
                    LineTo(hdc, xEnd, yEnd);
                    isDrawing = TRUE;
                }
                if(Button_GetCheck(penTool) == BST_CHECKED)
                {
                    xStart = LOWORD(lParam);
                    yStart = HIWORD(lParam);
                    isDrawing = TRUE;
                }
                if(Button_GetCheck(polylineTool) == BST_CHECKED)
                {
                    MoveToEx(hdc, xStart, yStart, NULL);
                    LineTo(hdc, xEnd, yEnd);
                    isDrawing = TRUE;
                }
                if(Button_GetCheck(rectTool) == BST_CHECKED)
                {
                    if(Button_GetCheck(GetDlgItem(hwnd, IDB_FILL)) == BST_CHECKED)
                    {
                        hbrush = CreateSolidBrush(colour);
                    }
                    else
                    {
                        hbrush = (HBRUSH)GetStockObject(NULL_BRUSH);
                    }
                    SelectObject(hdc, hbrush);
                    SetROP2(hdc, R2_XORPEN);
                    Rectangle(hdc, xStart, yStart, xEnd, yEnd);
                    isDrawing = TRUE;
                    DeleteObject(hbrush);
                }
                if(Button_GetCheck(ellipseTool) == BST_CHECKED)
                {
                    if(Button_GetCheck(GetDlgItem(hwnd, IDB_FILL)) == BST_CHECKED)
                    {
                        hbrush = CreateSolidBrush(colour);
                    }
                    else
                    {
                        hbrush = (HBRUSH)GetStockObject(NULL_BRUSH);
                    }
                    SetROP2(hdc, R2_XORPEN);
                    SelectObject(hdc, hbrush);
                    Ellipse(hdc, xStart, yStart, xEnd, yEnd);
                    isDrawing = TRUE;
                    DeleteObject(hbrush);
                }
                if(Button_GetCheck(bezierTool) == BST_CHECKED)
                {
                }
                DeleteObject(hpen);
                ReleaseDC(hwnd, hdc);
            }
            break;
        }

        case WM_MOUSEMOVE:
        {
            if( mouse_x > 10 && mouse_x < 450 && mouse_y > 10 && mouse_y < 330)
            {
                hdc = GetDC(hwnd);
                if(isDrawing == TRUE)
                {
                    if(Button_GetCheck(GetDlgItem(hwnd, IDB_RED)) == BST_CHECKED)
                    {
                        colour = RGB(255, 0, 0);
                    }
                    else if(Button_GetCheck(GetDlgItem(hwnd, IDB_GREEN)) == BST_CHECKED)
                    {
                        colour = RGB(0, 255, 0);
                    }
                    else if(Button_GetCheck(GetDlgItem(hwnd, IDB_BLUE)) == BST_CHECKED)
                    {
                        colour = RGB(0, 0, 255);
                    }
                    else if(Button_GetCheck(GetDlgItem(hwnd, IDB_BLACK)) == BST_CHECKED)
                    {
                        colour = RGB(0, 0, 0);
                    }
                    hpen = CreatePen(PS_SOLID, weight, colour);
                    SelectObject(hdc, hpen);
                    SetROP2(hdc, R2_NOTXORPEN);
                    if(Button_GetCheck(lineTool) == BST_CHECKED)
                    {
                        MoveToEx(hdc, xStart, yStart, NULL);
                        LineTo(hdc, xEnd, yEnd);
                        xEnd = LOWORD(lParam);
                        yEnd = HIWORD(lParam);
                        MoveToEx(hdc, xStart, yStart, NULL);
                        LineTo(hdc, xEnd, yEnd);
                    }
                    if(Button_GetCheck(penTool) == BST_CHECKED)
                    {
                        MoveToEx(hdc, xEnd, yEnd, NULL);
                        xEnd = LOWORD(lParam);
                        yEnd = HIWORD(lParam);
                        LineTo(hdc, xEnd, yEnd);
                    }
                    if(Button_GetCheck(polylineTool) == BST_CHECKED)
                    {
                        MoveToEx(hdc, xStart, yStart, NULL);
                        LineTo(hdc, xEnd, yEnd);
                        xEnd = LOWORD(lParam);
                        yEnd = HIWORD(lParam);
                        MoveToEx(hdc, xStart, yStart, NULL);
                        LineTo(hdc, xEnd, yEnd);
                    }
                    if(Button_GetCheck(rectTool) == BST_CHECKED)
                    {
                        if(Button_GetCheck(GetDlgItem(hwnd, IDB_FILL)) == BST_CHECKED)
                        {
                            hbrush = CreateSolidBrush(colour);
                        }
                        else
                        {
                            hbrush = (HBRUSH)GetStockObject(NULL_BRUSH);
                        }
                        SelectObject(hdc, hbrush);
                        SetROP2(hdc, R2_NOTXORPEN);
                        Rectangle(hdc, xStart, yStart, xEnd, yEnd);
                        xEnd = LOWORD(lParam);
                        yEnd = HIWORD(lParam);
                        Rectangle(hdc, xStart, yStart, xEnd, yEnd);
                        DeleteObject(hbrush);
                    }
                    if(Button_GetCheck(ellipseTool) == BST_CHECKED)
                    {
                        if(Button_GetCheck(GetDlgItem(hwnd, IDB_FILL)) == BST_CHECKED)
                        {
                            hbrush = CreateSolidBrush(colour);
                        }
                        else
                        {
                            hbrush = (HBRUSH)GetStockObject(NULL_BRUSH);
                        }
                        SelectObject(hdc, hbrush);
                        SetROP2(hdc, R2_NOTXORPEN);
                        Ellipse(hdc, xStart, yStart, xEnd, yEnd);
                        xEnd = LOWORD(lParam);
                        yEnd = HIWORD(lParam);
                        Ellipse(hdc, xStart, yStart, xEnd, yEnd);
                        DeleteObject(hbrush);
                    }
                    if(Button_GetCheck(bezierTool) == BST_CHECKED)
                    {

                    }
                }
                DeleteObject(hpen);
                ReleaseDC(hwnd, hdc);
            }
            break;
        }

        case WM_LBUTTONUP:
        {
            if( mouse_x > 10 && mouse_x < 450 && mouse_y > 10 && mouse_y < 330)
            {
                hdc = GetDC(hwnd);
                xEnd = LOWORD(lParam);
                yEnd = HIWORD(lParam);
                SetROP2(hdc, R2_XORPEN);
                MoveToEx(hdc, xStart, yStart, NULL);
                LineTo(hdc, xEnd, yEnd);
                ReleaseDC(hwnd, hdc);
                if(Button_GetCheck(lineTool) == BST_CHECKED)
                {
                    isDrawing = FALSE;
                }
                if(Button_GetCheck(penTool) == BST_CHECKED)
                {
                    isDrawing = FALSE;
                }
                if(Button_GetCheck(rectTool) == BST_CHECKED)
                {
                    isDrawing = FALSE;
                }
                if(Button_GetCheck(ellipseTool) == BST_CHECKED)
                {
                    isDrawing = FALSE;
                }
            break;
            }
        }

        case WM_RBUTTONDOWN:
        {
            if(Button_GetCheck(polylineTool) == BST_CHECKED)
            {
                isDrawing = FALSE;
            }
            break;
        }

        case WM_HOTKEY:
        {
            switch(wParam)
            {
                case HK_CLEAR:
                {
                    SendMessage(hwnd, WM_COMMAND, MAKEWPARAM(ID_CLEAR, 0), 0);
                    break;
                }
                default:
                    break;
            }
            break;
        }

        case WM_GETMINMAXINFO:
        {
            LPMINMAXINFO winSize = (LPMINMAXINFO)lParam;
            winSize->ptMinTrackSize.x = 650;
            winSize->ptMinTrackSize.y = 423;
            winSize->ptMaxTrackSize.x = 650;
            winSize->ptMaxTrackSize.y = 423;
            break;
        }


        case WM_PAINT:
        {
            hdc = BeginPaint(hwnd, &ps);
            FillRect(hdc, &rect, CreateSolidBrush(RGB(255, 255, 255)));
            HDC hdc_mem = CreateCompatibleDC(hdc);
            SelectObject(hdc_mem, bitmapHBmp);
            BitBlt(hdc, 550, 10, bitmapBmp.bmWidth, bitmapBmp.bmHeight, hdc_mem, 0, 0, SRCCOPY);
            DeleteObject(hdc_mem);
            SetBkMode(hdc, TRANSPARENT);
            TextOut(hdc, 460, 202, buffer, strlen(buffer));
            TextOut(hdc, 460, 235, buffer2, strlen(buffer2));
            TextOut(hdc, 460, 320, buffer3, strlen(buffer3));
            if(bezier == true)
            {
                HPEN localhpen = CreatePen(PS_SOLID, weight, colour);
                SelectObject(hdc, localhpen);
                SetFocus(hwnd);
                PolyBezier(hdc, bez, 4);
                bezier = false;
                DeleteObject(localhpen);
            }
            EndPaint(hwnd, &ps);
            break;
        }

        case WM_SIZE:
        {
            break;
        }

        case WM_CTLCOLORSTATIC:
        {
            SetBkColor((HDC)wParam, RGB(0, 0, 0));
            SetBkMode((HDC)wParam, TRANSPARENT);
            return (LRESULT)GetStockObject(HOLLOW_BRUSH);
        }

        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc(hwnd, message, wParam, lParam);
    }

    return TRUE;
}

