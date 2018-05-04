#include "../include/D3D11Base.h"
#include <memory>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10.h>

// include the Direct3D Library file
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dx11.lib")
#pragma comment (lib, "d3dx10.lib")

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nCmdShow
)
{
	const TCHAR appName[] = "D3D11Engine";
	std::unique_ptr<D3D11Base> application = std::make_unique<D3D11Base>(D3D11Base(hInstance, appName));

	application->InitWindow(nCmdShow, 1280, 720);

	application->initD3D();

	application->Run();

	application->CleanD3D();

	return 0;
}