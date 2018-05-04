#include "../include/D3D11Base.h"

D3D11Base::D3D11Base(HINSTANCE hInstance, const TCHAR appTitle[], const WNDCLASSEX* wndClass)
	: ApplicationWindow(hInstance, appTitle, wndClass) { }

void D3D11Base::initD3D(DXGI_SWAP_CHAIN_DESC* swapChainDesc)
{
	// if custom swap chain is not given as parameter, default is used
	if (!swapChainDesc)
	{
		// create a struct to hold information about the swap chain
		DXGI_SWAP_CHAIN_DESC scd;

		// clear out the struct for use
		ZeroMemory(&scd, sizeof(DXGI_SWAP_CHAIN_DESC));

		// fill the swap chain description struct
		scd.BufferCount = 1;                                    // one back buffer
		scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;     // use 32-bit color
		scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;      // how swap chain is to be used
		scd.OutputWindow = hAppMainWindow_;                                // the window to be used
		scd.SampleDesc.Count = 4;                               // how many multisamples
		scd.Windowed = TRUE;                                    // windowed/full-screen mode
																// create a device, device context and swap chain using the information in the scd struct
		D3D11CreateDeviceAndSwapChain(NULL,
			D3D_DRIVER_TYPE_HARDWARE,
			NULL,
			NULL,
			NULL,
			NULL,
			D3D11_SDK_VERSION,
			&scd,
			&swapChain_,
			&dev_,
			NULL,
			&devCon_);
	}
	else
	{
		D3D11CreateDeviceAndSwapChain(NULL,
			D3D_DRIVER_TYPE_HARDWARE,
			NULL,
			NULL,
			NULL,
			NULL,
			D3D11_SDK_VERSION,
			swapChainDesc,
			&swapChain_,
			&dev_,
			NULL,
			&devCon_);
	}
}

void D3D11Base::CleanD3D()
{
	// close and release all existing COM objects
	swapChain_->Release();
	dev_->Release();
	devCon_->Release();
}