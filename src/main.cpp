#include "../include/D3D11Base.h"
#include "../include/D3D11Pipeline.h"
#include <memory>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10.h>
#include <vector>

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
	// create the input layout object
	std::vector<D3D11_INPUT_ELEMENT_DESC> ied =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 }
	};

	std::unique_ptr<D3D11Base> application = std::make_unique<D3D11Base>(D3D11Base(hInstance, appName));

	application->InitWindow(nCmdShow, 1280, 720);

	application->InitD3D();

	std::unique_ptr<D3D11Pipeline> D3DPipeline = std::make_unique<D3D11Pipeline>(D3D11Pipeline());
	
	try
	{
		D3DPipeline->LoadPipeline("../shaders/shaders.shader.txt", "../shaders/shaders.shader.txt"
			, ied, application->GetDevice());
	}
	catch (std::exception e)
	{
		MessageBox(NULL, e.what(), NULL, MB_OK);
		application->CleanD3D();
		return 0;
	}

	D3DPipeline->Activate(application->GetDeviceContext());

	application->Run();

	D3DPipeline->Clean();
	application->CleanD3D();

	return 0;
}