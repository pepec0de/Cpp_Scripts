#include <windows.h>
#include <iostream>

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

// GUI Vars
HMENU hmenu;
void createMenus(HWND);
HWND createButton(LPCWSTR str, int posx, int posy, int width, int height, HWND parentWnd, int action);
HWND createLabel(LPCWSTR str, int posx, int posy, int width, int height, HWND parentWnd);
HWND createTextField(LPCWSTR str, int posx, int posy, int width, int height, HWND parentWnd);
int actions[] = {};
void getIdAction(); // Load actions for buttons
bool isIdActionUsed(int action); // Check if id is already used in a button

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
    int width = 590;
    int height = 570;
    int posx = 0;
    int posy = 0;
    LPCWSTR title = L"Window";
    WNDCLASSW wndClass = {0};

    // Window init
    wndClass.hbrBackground = (HBRUSH) COLOR_WINDOW;
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.hInstance = hInst;
    wndClass.lpszClassName = L"myWndClass";
    wndClass.lpfnWndProc = WindowProcedure;

    if(!RegisterClassW(&wndClass))
    {
        return -1;
    }
    CreateWindowW(wndClass.lpszClassName, title, WS_OVERLAPPEDWINDOW | WS_VISIBLE, posx, posy, width, height,
                  NULL, NULL, NULL, NULL);

    MSG msg = {0};
    while( GetMessage(&msg, NULL, NULL, NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch(msg)
    {
        case WM_COMMAND: {
            switch(wp)
            {
                // Actions
            }
        }
        break;

        case WM_CREATE: {
            // Window ctor
            createMenus(hwnd);
        }break;

        case WM_DESTROY: {
            // Window dtor
            PostQuitMessage(0);
        }break;

        default:
            return DefWindowProcW(hwnd, msg, wp, lp);
    }
    return 0;
}

void createMenus(HWND hwnd)
{
    hmenu = CreateMenu();
    HMENU hSubMenu = CreateMenu();

    // Create File Menu
    AppendMenu(hmenu, MF_POPUP, (UINT_PTR) hSubMenu, "Menu");
    // Menu Structure
    AppendMenu(hSubMenu, MF_STRING, NULL /* action */, "Submenu");
    // Set Menu to UI
    SetMenu(hwnd, hmenu);
}

HWND createLabel(LPCWSTR str, int posx, int posy, int width, int height, HWND parentWnd)
{
    return CreateWindowW(L"static", str, WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, posx, posy, width, height, parentWnd,
                         NULL, NULL, NULL);
}

HWND createButton(LPCWSTR str, int posx, int posy, int width, int height, HWND parentWnd, int action)
{
    return CreateWindowW(L"button", str, WS_VISIBLE | WS_CHILD | BS_BITMAP, posx, posy, width, height, parentWnd,
                         (HMENU) action, NULL, NULL);
}

HWND createTextField(LPCWSTR str, int posx, int posy, int width, int height, HWND parentWnd)
{
    return CreateWindowW(L"edit", str, WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOHSCROLL | ES_AUTOVSCROLL,
                         posx, posy, width, height, parentWnd, NULL, NULL, NULL);
}

int getIdActions() { // Func to load id actions to all tiles
    // Tile grid loop
    for(int x = 0; x < 8; x++)
    {
        for (int y = 0; y < 8; y++)
        {
            // Give a random number from 10000 to 1
            int random = rand() % 1000000 + 1;
            if(!isIdActionUsed(random)) // Check if random id is used
            {
                return random;
            }
        }
    }
}

bool isIdActionUsed(int action) // Func to check if id is used by a tile
{
    // Tile grid loop
    for(int i = 0; i < sizeof(actions); i++)
    {
        // Check if its equal
        if(actions[i] == action)
        {
            return true;
        }

    }
    return false;
}
