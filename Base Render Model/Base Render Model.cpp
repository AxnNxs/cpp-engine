
// Base Render Model.cpp : Defines the entry point for the application.

#include <Base Render Model.hpp>
#include <mylibraries/pixelManage.hpp>
#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>	//WinAPI
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam); //forward declaration of the window procedure function
#elif __linux__
#include <X11/Xlib.h>
#elif __APPLE__
#include <OpenGL/gl.h>
#endif

using namespace std;

#ifdef _WIN32
int WINAPI WinMain( _In_ HINSTANCE hInstance,     // Handle to the current instance of the application
                    _In_opt_ HINSTANCE hPrevInstance, // Handle to the previous instance (always NULL in modern Windows)
                    _In_ LPSTR lpCmdLine,         // Pointer to the command line string (ANSI)
                    _In_ int nCmdShow) {           // Controls how the window is to be shown (e.g., minimized, maximized, normal)
    

    const char* CLASS_NAME = "Sample Window Class";
    WNDCLASS wc = {};
    //wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    RegisterClass(&wc);

    //Create the window

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        "Cpp Engine",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd, SW_SHOWMAXIMIZED); //alternative to SW_something: nCmdShow
    UpdateWindow(hwnd);

    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    // Chiama la logica comune dopo il ciclo di messaggi o integrala nel ciclo
    // return runApplication(argc_placeholder, argv_placeholder); // Questo non ha senso con un message loop, dovrebbe essere gestito nel loop o dopo.
    // La pratica è che WinMain gestisce il message loop e chiama la logica di rendering/game update.
    // Quindi, runApplication dovrebbe essere il tuo motore di rendering / game loop che viene chiamato *da* WinMain.
    // Per ora, solo un return:
    return (int)msg.wParam; // Valore di uscita dal message loop

}


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_DESTROY: {
        // Messaggio inviato quando la finestra è stata distrutta.
        // Qui rilasci tutte le risorse allocate per questa finestra.
        // PostQuitMessage(0) invia un messaggio WM_QUIT alla coda dei messaggi,
        // che farà terminare il ciclo di messaggi in WinMain.
        PostQuitMessage(0);
        break;
    }
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        // Messaggio inviato quando una parte della finestra deve essere ridisegnata.
        // Questo è il luogo dove il tuo motore di rendering disegnerà.

        // --- Qui il tuo codice di disegno ---
        // Se usi GDI, disegneresti qui (es. TextOut, Rectangle, Ellipse)
        // Se usi OpenGL/DirectX, qui attiveresti il contesto grafico e chiameresti
        // le tue funzioni di rendering 3D.
        FillRect(hdc, &ps.rcPaint, (HBRUSH)GetStockObject(BLACK_BRUSH)); // Riempi l'area con un colore
        TextOut(hdc, 50, 50, "Hello, Windows!", 15); // Stampa testo

        EndPaint(hwnd, &ps); // Rilascia il contesto di device
        return 0;
    }
    case WM_CLOSE: {
        // X pressed
        DestroyWindow(hwnd);
        break;
    }
    case WM_SIZE: {
        // Messaggio inviato quando la finestra è ridimensionata.
        // wParam contiene il tipo di ridimensionamento (es. SIZE_RESTORED, SIZE_MINIMIZED).
        // lParam contiene la nuova larghezza (LOWORD) e altezza (HIWORD) della finestra.
        int newWidth = LOWORD(lParam);
        int newHeight = HIWORD(lParam);
        std::cout << "DEBUG: Window resized to " << newWidth << "x" << newHeight << std::endl;
        // Qui dovresti aggiornare le dimensioni della tua viewport OpenGL/DirectX
        break;
    }
    case WM_LBUTTONDOWN: {
        // Messaggio inviato quando il tasto sinistro del mouse viene premuto.
        // LOWORD(lParam) = X, HIWORD(lParam) = Y delle coordinate del mouse.
        int mouseX = LOWORD(lParam);
        int mouseY = HIWORD(lParam);
        std::cout << "DEBUG: Left mouse button down at (" << mouseX << ", " << mouseY << ")" << std::endl;
        break;
    }
    default:

        // È FONDAMENTALE chiamare DefWindowProc per tutti i messaggi che non gestisci.
        // Questo permette a Windows di eseguire la gestione predefinita della finestra
        // (es. ridimensionamento automatico del bordo, movimentazione della finestra, ecc.).

        return DefWindowProc(hwnd, uMsg, wParam, lParam);

    }

}




#elif __linux__

int main()
{

	return 0;
}

#elif __APPLE__
    //


#endif