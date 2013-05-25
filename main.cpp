#include <windows.h>

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
char szClassName[ ] = "CodeBlocksWindowsApp";

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
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = GetSysColorBrush(COLOR_3DDKSHADOW);

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "Code::Blocks Template Windows App",       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           600,                 /* The programs width */
           400,                 /* and height in pixels */
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
    switch (message)                  /* handle the messages */
    {
        case WM_CREATE :
           CreateWindow(TEXT("button"), TEXT("NAME"),
            WS_VISIBLE | WS_CHILD,
            240, 60, 80,30,
            hwnd, (HMENU) 1, NULL, NULL
            ) ;
            CreateWindow(TEXT("button"), TEXT("VERSITY"),
            WS_VISIBLE | WS_CHILD,
            240, 100, 80,30,
            hwnd, (HMENU) 2, NULL, NULL
            ) ;
             CreateWindow(TEXT("button"), TEXT("SUBJECT"),
            WS_VISIBLE | WS_CHILD,
            240, 140, 80,30,
            hwnd, (HMENU) 3, NULL, NULL
            ) ;
            CreateWindow(TEXT("button"), TEXT("ID NO."),
            WS_VISIBLE | WS_CHILD,
            240, 180, 80,30,
            hwnd, (HMENU) 4, NULL, NULL
            ) ;
            CreateWindow(TEXT("button"), TEXT("BATCH"),
            WS_VISIBLE | WS_CHILD,
            240, 220, 80,30,
            hwnd, (HMENU) 5, NULL, NULL
            ) ;
            CreateWindow(TEXT("button"), TEXT("COMMENT"),
            WS_VISIBLE | WS_CHILD,
            240, 260, 80,30,
            hwnd, (HMENU) 6, NULL, NULL
            ) ;


        break;
        case WM_COMMAND :
        if(LOWORD(wParam)==1){
        MessageBox(hwnd, "G.M.NAZMUL HOSSAIN SOMRAT", "SOMRAT", MB_OK | MB_ICONEXCLAMATION);
        }
        if(LOWORD(wParam)==2){
        MessageBox(hwnd, "NOAKHALI SCIENCE AND TECHNOLOGY UNIVERSITY", "SOMRAT", MB_OK | MB_ICONEXCLAMATION);
        }
         if(LOWORD(wParam)==3){
        MessageBox(hwnd, "COMPUTER SCIENCE AND TELECOMMUNICATION ENGINEERING", "SOMRAT", MB_OK | MB_ICONEXCLAMATION);
        }
         if(LOWORD(wParam)==4){
        MessageBox(hwnd, "ASH1201021M", "SOMRAT", MB_OK | MB_ICONEXCLAMATION);
        }
         if(LOWORD(wParam)==5){
        MessageBox(hwnd, "      7-TH.", "SOMRAT", MB_OK | MB_ICONEXCLAMATION);
        }
        if(LOWORD(wParam)==6){
        MessageBox(hwnd, "THANKS A LOT TO SEE MY WIN-APPS", "SOMRAT", MB_OK | MB_ICONEXCLAMATION);
        }


        break;
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
