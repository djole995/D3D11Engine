#ifndef _D3D11_BASE_H_
#define _D3D11_BASE_H_

#include "ApplicationWindow.h"
#include "D3D11.h"
#include "D3DX11.h"
#include "D3DX10.h"

class D3D11Base : public ApplicationWindow
{
public:
	D3D11Base(HINSTANCE hInstance, const TCHAR appTitle[], const WNDCLASSEX* wndClass = nullptr);

	void initD3D(DXGI_SWAP_CHAIN_DESC* swapChainDesc = nullptr);

	// this is the function that cleans up Direct3D and COM
	void CleanD3D();

protected:
	IDXGISwapChain* swapChain_;             // the pointer to the swap chain interface
	ID3D11Device* dev_;                     // the pointer to our Direct3D device interface
	ID3D11DeviceContext* devCon_;           // the pointer to our Direct3D device context

};

#endif  // _D3D11_BASE_H_