#include <windows.h>
#include <String>
#include <stdlib.h>
#include <iostream>


// Identifiers
#define ID_MAIN_BUTTON	10
#define ID_EDIT_BOX 20
#define ID_LIST_BOX 30
#define ID_CLEAR_BUTTON 40
#define ID_FONT_BUTTON 50
#define ID_FONTDEFAULT_BUTTON 60
#define ID_CLOSE_BUTTON 70

#define BTN_WIDTH        (13 * cxChar)
#define BTN_HEIGHT       (1.3 * cyChar)
#define BTN_EditorWidth (65* cxChar)
#define BTN_EditorHeight (4 * cyChar)
#define BTN_ListWidth (65* cxChar)
#define BTN_ListHeight (9 * cyChar)

//Colors
#define MAGENTA    RGB(139, 0,139)
#define ORANGE  RGB(255,69,0)
#define WHEAT  RGB(245, 222, 179)
#define CADETBLUE RGB(142, 229, 238	)
#define DARKGREEN RGB(0, 100, 0)


    using namespace std;

    //Handles to different controls
    HWND hWndEditorLeft,hWndEditorRight,hWndButtonDelete,hWndButton,hWndButtonCustomFont,hWndButtonFontDefault,hWndCloseButton;

    //flag for checking .
    int font = 1;

    //  Declare Windows procedure
    LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

    //  Declare Windows procedure
    char szClassName[ ] = "CodeBlocksWindowsApp";


int WINAPI WinMain (HINSTANCE hThisInstance,HINSTANCE hPrevInstance,LPSTR lpszArgument,int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_HREDRAW | CS_VREDRAW;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */

    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) CreateSolidBrush(WHEAT);

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    //Get the Width and Height of the User Laptop Screen.
    int nScreenWidth = GetSystemMetrics(SM_CXSCREEN);
    int nScreenHeight = GetSystemMetrics(SM_CYSCREEN);

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "Laboratory nr.1",       /* Title Text */
           WS_OVERLAPPEDWINDOW|WS_EX_RIGHT, /* default window */   // WS_OVERLAPPED | WS_MINIMIZEBOX | WS_SYSMENU  << this is for not resizing main Window
           nScreenWidth / 2 - 290,       /* Windows decides the position */
           nScreenHeight / 2 - 220,       /* where the window ends up on the screen */
           580,                 /* The programs width */
           460,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

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
    //Device Context Handle
    HDC hdc;
    RECT rect;
    PAINTSTRUCT ps;
    static char * buffer = new char [256];

    //Characters widht, height . Client width, height
    static short cxChar, cyChar,cxClient,cyClient;
    static int  font_button_pressed;
    //Text buffer;
    string text = "Giraffe write";


    //Font Handles
    static HFONT CustomFont,Signature,hFontOld,ListBoxFont,textFont,newFont,ButtonFont;

    //Default Font;
    HGDIOBJ hfDefault = GetStockObject(DEFAULT_GUI_FONT);

    //HBRUSH Variable for changing the color of brush on the text editor.
    HBRUSH color;

    switch (message)                  /* handle the messages */
    {
        case WM_CREATE:
            {
                //Getting information about the average height and width of a letter
                cxChar = LOWORD(GetDialogBaseUnits());
                cyChar = HIWORD(GetDialogBaseUnits());

                //Left Editor Window
                hWndEditorLeft=CreateWindowEx(WS_EX_CLIENTEDGE,
                                            "Edit","",
                                            WS_VISIBLE| WS_CHILD | WS_BORDER |LBS_NOINTEGRALHEIGHT|ES_MULTILINE,
                                            10,10,
                                            BTN_EditorWidth,
                                            BTN_EditorHeight,
                                            hwnd,
                                            (HMENU)ID_EDIT_BOX,
                                            GetModuleHandle(NULL),
                                            NULL);

                // Sets the default font to the left editor
                SendMessage(hWndEditorLeft,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0));

                //Sets the text to the left editor
                SendMessage(hWndEditorLeft,WM_SETTEXT,NULL,(LPARAM)"Help Giraffe to lern something new");

                //Rigth Editor Window
                hWndEditorRight=CreateWindowEx(WS_EX_CLIENTEDGE,
                                        "Listbox",
                                        "",
                                        WS_VISIBLE | WS_CHILD |WS_BORDER |LBS_NOINTEGRALHEIGHT |ES_READONLY ,  // Make it to handle multiline , make it be extendable on both direction verticl
                                        10,
                                        10,
                                        BTN_ListWidth,
                                        BTN_ListHeight,
                                        hwnd,
                                        (HMENU)ID_LIST_BOX,
                                        GetModuleHandle(NULL),
                                        NULL);

                //Set  Default Font
                SendMessage(hWndEditorRight,WM_SETFONT,(WPARAM)hfDefault, MAKELPARAM(FALSE,0));

                //Add An Welcome Text Message to the Right Editor
                SendDlgItemMessage(hwnd, ID_LIST_BOX, LB_ADDSTRING, 0, (LPARAM)"Let's go!");

                //Button for Sending the String from Left to Right Editor
                hWndButton = CreateWindowEx(NULL, //extended window style
                                            "Button", //Predifined class name
                                            "Send", //button text
                                            WS_CHILD|WS_VISIBLE, //The style of the window being created
                                            220, //The initial horizontal position of the window
                                            30, //The initial vertical position of the window
                                            BTN_WIDTH, //The width, in device units, of the windo
                                            BTN_HEIGHT, //The height, in device units, of the window
                                            hwnd, //A handle to the parent or owner window of the window being created
                                            (HMENU)ID_MAIN_BUTTON, // A handle to a menu, or specifies a child-window identifier, depending on the window style
                                            GetModuleHandle(NULL), //A handle to the instance of the module to be associated with the window.
                                            NULL); // Pointer not needed

                //Button for Setting Custom Font to the Text
                hWndButtonCustomFont = CreateWindowEx(NULL,
                                            "Button",
                                            "CustomFont",
                                            WS_CHILD|WS_VISIBLE,
                                            220,
                                            30,
                                            BTN_WIDTH,
                                            BTN_HEIGHT ,
                                            hwnd,
                                            (HMENU)ID_FONT_BUTTON,
                                            GetModuleHandle(NULL),
                                            NULL);

                //Button for Setting Default Font to the Text
                hWndButtonFontDefault = CreateWindowEx(NULL,
                                                    "Button",
                                                    "DefaultFont",
                                                    WS_CHILD|WS_VISIBLE,
                                                    220,
                                                    30,
                                                    BTN_WIDTH,
                                                    BTN_HEIGHT ,
                                                    hwnd,
                                                    (HMENU)ID_FONTDEFAULT_BUTTON,
                                                    GetModuleHandle(NULL),
                                                    NULL);

                // Button for Clossing the Window
                 hWndCloseButton = CreateWindowEx(NULL,
                                        "Button",
                                        "Close",
                                         WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
                                        220,
                                        100,
                                        BTN_WIDTH,
                                        BTN_HEIGHT,
                                        hwnd,
                                        (HMENU)ID_CLOSE_BUTTON ,
                                        GetModuleHandle(NULL),
                                        NULL);
                //
                hWndButtonDelete = CreateWindowEx(NULL,
                                                 "Button",
                                                 "DELETE",
                                                 WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
                                                 220,
                                                 100,
                                                 BTN_WIDTH,
                                                 BTN_HEIGHT,
                                                 hwnd,
                                                 (HMENU)ID_CLEAR_BUTTON ,
                                                 GetModuleHandle(NULL),
                                                 NULL);

            }
        break;

        case WM_SIZE:
            {
                //Width and Height of the Client Window
                cxClient = LOWORD(lParam);
                cyClient = HIWORD(lParam);

                //Moving buttons/editors to the new possition on resizing

                MoveWindow ( hWndButtonDelete,cxClient/2 +40  ,cyClient/2-80 ,BTN_WIDTH ,BTN_HEIGHT , TRUE);
                MoveWindow(hWndButton,cxClient/2 -130 , cyClient /2 - 80 , BTN_WIDTH , BTN_HEIGHT , TRUE);
                MoveWindow(hWndEditorLeft , cxClient/2  - 260, cyClient/2 - 160 , BTN_EditorWidth ,BTN_EditorHeight ,TRUE);
                MoveWindow(hWndEditorRight ,cxClient/2  - 260, cyClient/3 + 30 , BTN_ListWidth, BTN_ListHeight ,TRUE);
                MoveWindow(hWndButtonCustomFont , cxClient/2 +40 , cyClient/2+130,BTN_WIDTH,BTN_HEIGHT,TRUE);
                MoveWindow(hWndButtonFontDefault,cxClient/2 -130 , cyClient/2+130 , BTN_WIDTH ,BTN_HEIGHT,TRUE );
                MoveWindow(hWndCloseButton,cxClient/2-60 , cyClient/2+160, BTN_WIDTH+16,BTN_HEIGHT+20,TRUE);
            }
        break;

        case WM_COMMAND:
            {
                switch(LOWORD(wParam))
                {
                    //Delete Coammand
                    case ID_CLEAR_BUTTON:
                        {
                            SendMessage(hWndEditorRight,LB_RESETCONTENT,0,0);
                            cout<<"\nDelete Chat" ;
                        }
                    break;

                    //
                    case ID_MAIN_BUTTON:
                        {
                            if(font == 0)
                                {
                                     cout<<font;
                                    newFont = textFont;
                                    SendMessage(hWndEditorLeft,WM_GETTEXT,256,(LONG)buffer);
                                    SendMessage(hWndEditorRight ,WM_SETFONT,(WPARAM)newFont ,MAKELPARAM(true,0));
                                    SendDlgItemMessage(hwnd,ID_LIST_BOX,LB_ADDSTRING,0,(LPARAM)buffer);
                                    SendMessage(hWndEditorLeft, WM_SETTEXT,NULL,NULL);
                                }

                            if(font == 1)
                                {
                                    newFont = (HFONT)hfDefault;
                                    SendMessage(hWndEditorLeft,WM_GETTEXT,256,(LONG)buffer);
                                    SendMessage(hWndEditorRight ,WM_SETFONT,(WPARAM)newFont ,MAKELPARAM(true,0));
                                    SendDlgItemMessage(hwnd,ID_LIST_BOX,LB_ADDSTRING,0,(LPARAM)buffer);
                                    SendMessage(hWndEditorLeft, WM_SETTEXT,NULL,NULL);
                                }
                        }
                    break;

                    case ID_FONT_BUTTON:
                        {
                            font  = 0;
                            cout<<"\nCustom Font Activated";
                            textFont =CreateFont(-50,0,0,0,FW_DONTCARE,false,false,false,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,FF_DONTCARE,"Orion Pax");

                            if(textFont)
                                {
                                    SendMessage(hWndEditorRight ,WM_SETFONT,(WPARAM)textFont ,MAKELPARAM(true,0));
                                }
                        }
                    break;

                    case ID_FONTDEFAULT_BUTTON:
                        {
                            font = 1;
                            textFont = (HFONT)hfDefault;
                            SendMessage(hWndEditorRight ,WM_SETFONT,(WPARAM)textFont ,MAKELPARAM(true,0));
                            cout<<"\nDefault Font Activated.";
                        }
                    break;

                    case ID_CLOSE_BUTTON:
                        {
                            //Send a WM_QUIT to the message queue
                            PostQuitMessage (0);
                        }
                }

            }
         break;

        case WM_PAINT:
           {
                //creating 2 fonts.
                CustomFont = CreateFont(-50,0,0,0,FW_DONTCARE,false,false,false,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,FF_DONTCARE,"Rosewood Std Regular");
                Signature = CreateFont(-20,0,0,0,FW_DONTCARE,false,false,false,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,FF_DONTCARE,"Opificio");
                ButtonFont = CreateFont(-20,0,0,0,FW_DONTCARE,false,false,false,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,FF_DONTCARE,"Orion Pax");

                //Getting a handle on the window
                hdc = BeginPaint(hwnd , &ps);
                GetClientRect(hwnd , &rect);

                //Set background to transparent
                SetBkMode(hdc, TRANSPARENT);

                //Set the font,color and background for text
                hFontOld  = (HFONT)SelectObject(hdc, CustomFont);
                SetTextColor (hdc,MAGENTA);
                DrawText(hdc , text.c_str(),-1,&rect, DT_SINGLELINE | DT_CENTER);

                //Destroy font object
                DeleteObject(SelectObject(hdc,hFontOld));

                //Set the font,color and background for text
                hFontOld  = (HFONT)SelectObject(hdc, Signature);
                SetTextColor (hdc,MAGENTA);

                //Destroy font objecttext.c_str(),
                DeleteObject(SelectObject(hdc,hFontOld));

                // Change the font of Close Button
                hFontOld  = (HFONT)SelectObject(hdc,ButtonFont);
                SendMessage(hWndCloseButton,WM_SETFONT,WPARAM(ButtonFont),TRUE);

                //EndPaint
                EndPaint(hwnd , &ps);
            }
        break;

        //Setting the minimal size of the window
        case WM_GETMINMAXINFO:
            {

                    LPMINMAXINFO pInfo = (LPMINMAXINFO) lParam;
                    pInfo ->ptMinTrackSize.x = 580;
                    pInfo ->ptMinTrackSize.y = 440;
            }
        break;

         //Setting custom color for the edit box
         case WM_CTLCOLOREDIT:
             {
                if(ID_EDIT_BOX==GetDlgCtrlID((HWND)lParam))
                    {
                        hdc=(HDC)wParam;
                        color = CreateSolidBrush(CADETBLUE);
                        SetTextColor(hdc, ORANGE);  //setting text color
                        return (LONG)color;
                     }
             }
            break;

         case WM_CTLCOLORLISTBOX:
             {
                 if(ID_LIST_BOX==GetDlgCtrlID((HWND)lParam))
                     {
                         hdc=(HDC)wParam;
                        color = CreateSolidBrush(CADETBLUE);
                        SetTextColor(hdc, DARKGREEN);  //setting text color
                        return (LRESULT)color;
                     }
             }
         break;


        //Setting custom color for the button

   case WM_CTLCOLORBTN:
             if(ID_MAIN_BUTTON==GetDlgCtrlID((HWND)lParam))
             {
                hdc=(HDC)wParam;
                color = CreateSolidBrush(ORANGE);
                SetTextColor(hdc, WHEAT);  //setting text color
                SetBkMode(hdc, TRANSPARENT);            //setting background to transp
                SetBkColor(hdc,(LONG)color);            //setting background color
                return (LONG)color;
             }
             break;

        //Changing behavior of the Close Button
        case WM_CLOSE:
            {
                 system("cls");
                 int x_position = rand() % 800;
                 int y_position = rand() % 500 ;
                 cout <<"xPosition: "<<x_position<<endl;
                 cout<<"yPosition:"<<y_position<<endl;
                 SetWindowPos(hwnd,HWND_TOP,x_position,y_position,580,440,SWP_SHOWWINDOW);
                 MessageBoxA(NULL,"Release Rendering Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);

            }
         break;

        //Make minimize and maximize change with behaviors
         case WM_SYSCOMMAND:
             {
                switch(wParam)
                    {
                        case SC_MINIMIZE:
                            {
                                SetWindowPos(hwnd,HWND_TOP,0,0,500,500,SWP_SHOWWINDOW);
                            }
                        break;

                        case SC_MAXIMIZE:
                            {
                                //TODO...
                                SetWindowPos(hwnd,HWND_TOP,0,0,1100,1100,SWP_SHOWWINDOW);
                            }
                        break;


                        default: DefWindowProc (hwnd, message, wParam, lParam);
                    }
             }
           break;

        case WM_DESTROY:
            {
                DeleteObject(ListBoxFont);
                DeleteObject(textFont);
                DeleteObject(newFont);
                DeleteObject(ButtonFont);
            }
        break;

        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

