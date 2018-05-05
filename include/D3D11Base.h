#ifndef _D3D11_BASE_H_
#define _D3D11_BASE_H_

#include "ApplicationWindow.h"
#include "D3D11.h"
#include "D3DX11.h"
#include "D3DX10.h"

class D3D11Base : public ApplicationWindow
{
public:
   /** 
	* @brief D3D application object constructor, handles window subclass creation.
	*
	* @param hInstance Application instance handle which will be copied in internal instance handle.
	* @param appTitle Application window title.
	* @param wndClass optional parameter which contains user specific window class parameters.
	* (i.e. setting user custom window message procedure). If this parameter is not given, default
	* window class attributes are used.

	* @note If user calls constructor with non-null window class pointer, he is responsible for
	* all window class attributes proper setting.
	* @note appTitle and wndClass strings must not be greater than MAX_LOADSTRING value which is defined in ApplicationWindow subclass.
	*/
	D3D11Base(HINSTANCE hInstance, const TCHAR appTitle[], const WNDCLASSEX* wndClass = nullptr);

   /**
	* @brief D3D objects creation and initialization.
	*
	* Creates D3D device, device context, swapchain.
	* Back buffer is initialized as render target and view port is initiallized to window size.
	*
	* @note Viewport can be changed after D3D initialization with setViewport method.
	*
	* @param swapChainDesc optional swap chain descriptor parameter. 
	* If this parameter is not set, default swap chain attributes are used.   
	*/
	void InitD3D(DXGI_SWAP_CHAIN_DESC* swapChainDesc = nullptr);

   /**
    * @brief Set viewport dimensions and position.
	*
	* @param topLeftX top left corner X position.
	* @param topLeftY top lleft corner Y position.
	* @param width viewport width.
	* @param height viewport height.
	*
	*/
	void SetViewport(unsigned short topLeftX, unsigned short topLeftY, unsigned short width, unsigned short height);

   /**
    * @brief Cleans up Direct3D and its COM objects.
	*/
	void CleanD3D();

protected:
	/**
	* @brief Method which does graphic rendering.
	*
	*/
	virtual void Render();

	IDXGISwapChain* swapChain_;             /**< the pointer to the swap chain interface */
	ID3D11Device* dev_;                     /**< the pointer to Direct3D device interface */
	ID3D11DeviceContext* devCon_;           /**< the pointer to Direct3D device context */
	ID3D11RenderTargetView* backBuffer_;    /**< the pointer to main render target (backbuffer). */
	D3D11_VIEWPORT viewport_;               /**< render target viewport (translation model from normalized to screen coordinates). */

};

#endif  // _D3D11_BASE_H_