#include "Ball.h"
#define ID_TIMER 101

//#include <WINMM.LIB>


LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
void ReDraw(HWND hwnd);
void DrawNyanCat(HDC hdc);
void DrawBubbles(HDC hdc);



static int TIMER = 28;//timer for nyan cat
int direction = 1;//direction of nyan cat
bool nyanActive = true;//nyan cat is active
int currentNyanPos = 0;//array nyan position



//int curX = 0;
//int tail = 0;
//bool flipped = false;
//int nyanXPos = 0;
HDC hdcMem;
int raynbowPos;
int globalIncrementor = 1;
//bool rainboxUp = false;

HBITMAP nyan[6];
HBITMAP rainbow;

char szClassName[ ] = "Walking cat";
HINSTANCE hInst;



int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;
    MSG messages;
    WNDCLASSEX wincl;

    hInst = hThisInstance;
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;
    wincl.style = CS_HREDRAW|CS_VREDRAW;;
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "Laboratory work nr 4",       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           800,                 /* The programs width */
           600,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );


    ShowWindow (hwnd, nCmdShow);
    SetActiveWindow(hwnd);
    UpdateWindow(hwnd);
    srand (time(NULL));
    SetTimer(hwnd,ID_TIMER,TIMER,NULL);

    while (GetMessage (&messages, NULL, 0, 0))
    {

        TranslateMessage(&messages);

        DispatchMessage(&messages);
    }


    return messages.wParam;
}




LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    PAINTSTRUCT ps;
    srand (time(NULL));
    static RECT updateCatRect = {0,2,1340,185};
    static RECT updateBallRect = {10,190,1340,690};
    static RECT updateRainbowRect = {0,700,3,176};
    HDC hdc = GetDC(hwnd);

    HPEN hPen;
    HBRUSH hBrush;



    switch (message)
    {

        case WM_CREATE:
        {
            PlaySoundW(L"nyanCat.wav",NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
            for(int i=0;i<6;i++)
            {
                char str[11];
                sprintf(str,"img/%d.bmp",i+1);

                nyan[i] = (HBITMAP)LoadImage(hInst,str,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);

            }
            rainbow = (HBITMAP)LoadImage(hInst,"img/rainbow.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
        }
        break;

        case WM_LBUTTONDOWN:
        {
            if(wParam & MK_LBUTTON)
            {
                Ball * ball = new Ball(TIMER);
                balls.push_back(ball);
            }
        }
        break;

        case WM_PAINT:{

            HDC hdc = BeginPaint(hwnd,&ps);
            hPen = CreatePen(PS_SOLID,1,RGB(0,0,0));
            hBrush = CreateSolidBrush(RGB(255,255,255));
            SelectObject(hdc,hPen);
            SelectObject(hdc,hBrush);
            Rectangle(hdc,updateCatRect.left,updateCatRect.top,updateCatRect.right,updateCatRect.bottom);
            Rectangle(hdc,updateBallRect.left,updateBallRect.top,updateBallRect.right,updateBallRect.bottom);
            DeleteObject(hPen);
            DeleteObject(hBrush);

            EndPaint(hwnd, &ps);
        }
        break;

        case WM_TIMER:{
            if(wParam == ID_TIMER)
            {
                if(nyanActive)
                {
                    HBRUSH brush = CreateSolidBrush(RGB(255,255,255));
                    SelectObject(hdc,brush);
                    FillRect(hdc,&updateRainbowRect,brush);
                    DeleteObject(brush);

                    HDC hdcMem = CreateCompatibleDC(hdc);
                    SelectObject(hdcMem,nyan[currentNyanPos]);
                    BitBlt(hdc,700,3,304,176,hdcMem,0,0,SRCCOPY);//transfer pixel color from one device cont to another

                    currentNyanPos ++;
                    if(currentNyanPos>5)
                        currentNyanPos = 0;

                    nyanActive = false;

                    //Rainbow draw

                    int startPos = raynbowPos;
                    int incrementor = 1;
                    int yCoord = 646;//length of the rainbow

                    SelectObject(hdcMem,rainbow);
                    for(int i=0;i<13;i++)
                    {
                        SelectObject(hdcMem,rainbow);
                        BitBlt(hdc,yCoord,45 + startPos * 5, 54, 96, hdcMem, 0, 0, SRCCOPY);
                        if (startPos >= 2 || startPos <= -2) {
                            incrementor = -incrementor;
                        }
                        startPos += incrementor;
                        yCoord -= 54;

                    }

                    if (raynbowPos >= 3 || raynbowPos <= -3) {
                        globalIncrementor = -globalIncrementor;
                    }
                    raynbowPos += globalIncrementor;

                    DeleteDC(hdcMem);

                }
                else
                {
                    nyanActive = true;
                    for(int i = 0; i < balls.size(); i++)
                    {

                        balls[i]->newPos();

                        for (int j = 0; j < balls.size(); j++)
                        {
                            if (j == i)
                                continue;
                            balls[i]->interactBall(*balls[j]);
                        }

                        balls[i]->reshapeBoundaries();
                        balls[i]->drawGhost(hdc);
                        balls[i]->drawBall(hdc);
                        if (balls[i]->_livingTime > 1000 * 10)
                        {
                            Ball* tempBall = balls[i];
                            balls.erase(balls.begin() + i);
                            tempBall->drawGhost(hdc);
                            delete tempBall;
                            i--;
                        }
                    }
                }
            }
        }
        break;

        case WM_MOUSEWHEEL:
        {
            if(GET_WHEEL_DELTA_WPARAM(wParam) < 0)
            {
                if(TIMER < 80)
                {
                    TIMER +=1;
                    for (int i = 0; i < balls.size(); i++) {
                        balls[i]->TIMER = TIMER;
                    }
                }

            }
            else
            {
                if(TIMER > 5)
                {
                    TIMER -= 1;
                    for (int i = 0; i < balls.size(); i++)
                    {
                        balls[i]->TIMER = TIMER;
                    }
                }
            }
            KillTimer(hwnd, ID_TIMER);
            SetTimer(hwnd, ID_TIMER, TIMER, NULL);

        }
        break;

        case WM_DESTROY:{
            PostQuitMessage (0);

        }
        break;

        //default:
          //  ReleaseDC(hwnd,hdc);
            //return DefWindowProc (hwnd, message, wParam, lParam);
    }

    ReleaseDC(hwnd, hdc);
    return DefWindowProc(hwnd,message,wParam,lParam);
}


