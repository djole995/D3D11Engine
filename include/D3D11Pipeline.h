#ifndef _D3D11_PIPELINE_H_
#define _D3D11_PIPELINE_H_

#include <D3D11.h>
#include <D3DX10.h>
#include <D3DX11.h>
#include <vector>

class D3D11Pipeline
{

public:

   /**
    * @brief D3D11 pipeline constructor
	*
	*/
	D3D11Pipeline() = default;

	/**
	* @brief D3D11 pipeline destructor
	*
	*/
	~D3D11Pipeline() = default;

  /**
	* @brief Load D3D11 custom pipeline (vertex shader, pixel shader and input layout).
	* 
	* @param vertexShaderSrc vertex shader source code path.
	* @param pixelShaderSrc pixel shader source code path.
	* @param inputLayoutDesc vertices attributes array.
	* @param dev Device interface used for pipeline components creation.
	*
	* @throws execption with description of its cause.
	*/
	void LoadPipeline(const char* vertexShaderSrc, const char* pixelShaderSrc, std::vector<D3D11_INPUT_ELEMENT_DESC>& inputLayoutDesc, ID3D11Device* dev) throw(std::exception);

   /**
	* @brief Set pipeline as active rendering pipeline over the used device context.
	* 
	* @param devCon Device context over which pipeline shall be set.
	*/
	void Activate(ID3D11DeviceContext* devCon);

   /**
   * @brief Clean pipeline (release all COM objects).
   *
   */
	void Clean();

	/**
	* @brief Get vertex shader COM object interface.
	*
	*/
	ID3D11VertexShader* GetVertexShader();

	/**
	* @brief Get vertex shader blob source.
	*
	*/
	ID3D10Blob* GetVertexShaderSrc();

	/**
	* @brief Get pixel shader COM object interface.
	*
	*/
	ID3D11PixelShader* GetPixelShader();

	/**
	* @brief Get input layout COM object interface.
	*
	*/
	ID3D11InputLayout* GetInputLayout();

private:
	ID3D11VertexShader* vertexShader_;  /**< vertex shader COM object interface */
	ID3D11PixelShader* pixelShader_;  /**< pixel shader COM object interface */
	ID3D11InputLayout* inputLayout_;   /**< input layout COM object interface */
	ID3D10Blob* vertexShaderSrc_;  /**< vertex shader source blob */
};

#endif
