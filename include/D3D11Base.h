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
	* @brief D3D swapchain, device and device context creation.
	* 
	* @param swapChainDesc optional swap chain descriptor parameter. 
	* If this parameter is not set, default swap chain attributes are used.   
	*/
	void initD3D(DXGI_SWAP_CHAIN_DESC* swapChainDesc = nullptr);

   /**
    * @brief Cleans up Direct3D and its COM objects.
	*/
	void CleanD3D();

protected:
	IDXGISwapChain* swapChain_;             /**< the pointer to the swap chain interface */
	ID3D11Device* dev_;                     /**< the pointer to Direct3D device interface */
	ID3D11DeviceContext* devCon_;           /**< the pointer to Direct3D device context */

};

#endif  // _D3D11_BASE_H_