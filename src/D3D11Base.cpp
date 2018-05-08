#include "../include/D3D11Base.h"

D3D11Base::D3D11Base(HINSTANCE hInstance, const TCHAR appTitle[], const WNDCLASSEX* wndClass)
	: ApplicationWindow(hInstance, appTitle, wndClass) { }

void D3D11Base::InitD3D(DXGI_SWAP_CHAIN_DESC* swapChainDesc)
{
	// render target address
	ID3D11Texture2D* pBackBuffer;

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

	// get back buffer address and create render target over it
	swapChain_->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&pBackBuffer);
	dev_->CreateRenderTargetView(pBackBuffer, nullptr, &backBuffer_);
	pBackBuffer->Release();

	devCon_->OMSetRenderTargets(1, &backBuffer_, nullptr);

	// initialize viewport to window size
	ZeroMemory(&viewport_, sizeof(D3D11_VIEWPORT));
	viewport_.TopLeftX = 0;
	viewport_.TopLeftY = 0;
	viewport_.Height = window_height_;
	viewport_.Width = window_width_;

	devCon_->RSSetViewports(1, &viewport_);
}

void D3D11Base::Render()
{
	devCon_->ClearRenderTargetView(backBuffer_, D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f));

	swapChain_->Present(0, 0);
}

void D3D11Base::SetViewport(unsigned short topLeftX, unsigned short topLeftY, unsigned short width, unsigned short height)
{
	viewport_.TopLeftX = topLeftX;
	viewport_.TopLeftY = topLeftY;
	viewport_.Height = height;
	viewport_.Width = width;
}

void D3D11Base::CleanD3D()
{
	// close and release all existing COM objects
	backBuffer_->Release();
	swapChain_->Release();
	dev_->Release();
	devCon_->Release();
}

ID3D11Device* D3D11Base::GetDevice()
{
	return dev_;
}

ID3D11DeviceContext* D3D11Base::GetDeviceContext()
{
	return devCon_;
}
