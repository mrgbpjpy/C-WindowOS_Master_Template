#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif
#include <windows.h>  // Includes the Windows API header file, which declares the types, constants, and functions used in Win32 programming. URL: https://learn.microsoft.com/en-us/windows/win32/api/windows

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);  // Declares the window procedure callback function, which processes messages sent to the window. LRESULT is the return type for window procedures. URL for LRESULT: https://learn.microsoft.com/en-us/windows/win32/winprog/windows-data-types#lresult; URL for CALLBACK: https://learn.microsoft.com/en-us/cpp/cpp/callback-functions?view=msvc-170

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)  // The entry point for a Windows GUI application (Unicode version). hInstance is the handle to the current instance of the application. URL: https://learn.microsoft.com/en-us/windows/win32/learnwin32/winmain--the-application-entry-point; URL for HINSTANCE: https://learn.microsoft.com/en-us/windows/win32/winprog/windows-data-types#hinstance
{
    const wchar_t CLASS_NAME[] = L"HelloWorldWindowClass";  // Defines the name of the window class as a wide-character string. URL for wchar_t: https://learn.microsoft.com/en-us/cpp/cpp/data-type-ranges?view=msvc-170

    WNDCLASS wc = {};  // Declares and initializes a WNDCLASS structure to hold window class attributes. URL: https://learn.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-wndclassw
    wc.lpfnWndProc = WindowProc;  // Sets the pointer to the window procedure function in the WNDCLASS structure. URL for lpfnWndProc: https://learn.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-wndclassw#members
    wc.hInstance = hInstance;  // Sets the instance handle in the WNDCLASS structure. URL for hInstance: https://learn.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-wndclassw#members
    wc.lpszClassName = CLASS_NAME;  // Sets the class name in the WNDCLASS structure. URL for lpszClassName: https://learn.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-wndclassw#members

    RegisterClass(&wc);  // Registers the window class with the system for use in creating windows. URL: https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-registerclassw

    HWND hwnd = CreateWindowEx(  // Creates a new window with extended style and returns its handle (HWND). URL: https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-createwindowexw
        0,  // Extended window style (0 for none). URL for dwExStyle: https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-createwindowexw#parameters
        CLASS_NAME,  // The name of the registered window class. URL for lpClassName: https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-createwindowexw#parameters
        L"Hello, World Window",  // The title text for the window. URL for lpWindowName: https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-createwindowexw#parameters
        WS_OVERLAPPEDWINDOW,  // Window style that includes title bar, sizing border, and standard controls (close, maximize, minimize). URL: https://learn.microsoft.com/en-us/windows/win32/winmsg/window-styles
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,  // Uses default position and size for the window. URL for nWidth/nHeight: https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-createwindowexw#parameters
        NULL,  // No parent window. URL for hWndParent: https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-createwindowexw#parameters
        NULL,  // No menu. URL for hMenu: https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-createwindowexw#parameters
        hInstance,  // Instance handle. URL for hInstance: https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-createwindowexw#parameters
        NULL  // No additional creation data. URL for lpParam: https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-createwindowexw#parameters
    );

    if (hwnd == NULL)  // Checks if window creation failed. URL for HWND: https://learn.microsoft.com/en-us/windows/win32/winprog/windows-data-types#hwnd
    {
        return 0;  // Exits the application if window creation fails.
    }

    ShowWindow(hwnd, nCmdShow);  // Makes the window visible based on the startup info. URL: https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-showwindow

    MSG msg = {};  // Declares a MSG structure to hold message information. URL: https://learn.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-msg
    while (GetMessage(&msg, NULL, 0, 0))  // Retrieves messages from the thread's message queue until WM_QUIT is received. URL: https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getmessage
    {
        TranslateMessage(&msg);  // Translates virtual-key messages into character messages. URL: https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-translatemessage
        DispatchMessage(&msg);  // Dispatches the message to the appropriate window procedure. URL: https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-dispatchmessage
    }

    return 0;  // Exits the application successfully.
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)  // Defines the window procedure that handles messages for the window. URL for WindowProc: https://learn.microsoft.com/en-us/windows/win32/learnwin32/writing-the-window-procedure; URL for UINT: https://learn.microsoft.com/en-us/windows/win32/winprog/windows-data-types#uint; URL for WPARAM: https://learn.microsoft.com/en-us/windows/win32/winprog/windows-data-types#wparam; URL for LPARAM: https://learn.microsoft.com/en-us/windows/win32/winprog/windows-data-types#lparam
{
    switch (uMsg)  // Switches based on the message type (uMsg). URL for uMsg: https://learn.microsoft.com/en-us/windows/win32/winmsg/about-messages-and-message-queues
    {
        case WM_DESTROY:  // Handles the WM_DESTROY message, sent when the window is being destroyed. URL: https://learn.microsoft.com/en-us/windows/win32/winmsg/wm-destroy
            PostQuitMessage(0);  // Posts a WM_QUIT message to the message queue to end the message loop. URL: https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-postquitmessage
            return 0;  // Returns 0 to indicate the message was processed.

        case WM_PAINT:  // Handles the WM_PAINT message, sent when the window needs to be redrawn. URL: https://learn.microsoft.com/en-us/windows/win32/gdi/wm-paint
        {
            PAINTSTRUCT ps;  // Declares a PAINTSTRUCT to hold painting information. URL: https://learn.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-paintstruct
            HDC hdc = BeginPaint(hwnd, &ps);  // Begins the painting process and gets a device context (HDC) for drawing. URL for BeginPaint: https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-beginpaint; URL for HDC: https://learn.microsoft.com/en-us/windows/win32/gdi/device-contexts

            RECT clientRect;  // Declares a RECT structure to hold the client area coordinates. URL: https://learn.microsoft.com/en-us/windows/win32/api/windef/ns-windef-rect
            GetClientRect(hwnd, &clientRect);  // Retrieves the dimensions of the window's client area. URL: https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getclientrect
            FillRect(hdc, &clientRect, (HBRUSH)(COLOR_WINDOW + 1));  // Fills the client area with the system window background color. URL for FillRect: https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-fillrect; URL for COLOR_WINDOW: https://learn.microsoft.com/en-us/windows/win32/gdi/system-colors
            DrawText(hdc, L"Hello World", -1, &clientRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);  // Draws the text "Hello World" centered in the client area. URL for DrawText: https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-drawtextw; URL for DT_CENTER: https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-drawtextw#parameters; URL for DT_VCENTER: https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-drawtextw#parameters; URL for DT_SINGLELINE: https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-drawtextw#parameters

            EndPaint(hwnd, &ps);  // Ends the painting process and releases resources. URL: https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-endpaint
        }
        return 0;  // Returns 0 to indicate the message was processed.

    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);  // Calls the default window procedure for unhandled messages. URL: https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-defwindowprocw
}