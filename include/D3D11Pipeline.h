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
	* @brief D3D11 custom pipeline constructor (vertex shader, pixel shader and input layout).
	* 
	* @param vertexShaderSrc vertex shader source code path.
	* @param pixelShaderSrc pixel shader source code path.
	* @param inputLayoutDesc vertices attributes array.
	* @param dev Device interface used for pipeline components creation.
	*
	*/
	D3D11Pipeline(const char* vertexShaderSrc, const char* pixelShaderSrc, std::vector<D3D11_INPUT_ELEMENT_DESC>& inputLayoutDesc, ID3D11Device* dev);

	~D3D11Pipeline() = default;

   /**
	* @brief Set pipeline as active rendering pipeline over the used device context.
	* 
	* @param devCon Device context over which pipeline shall be set.
	*/
	void Activate(ID3D11DeviceContext* devCon);

   /**
    * @brief Load and set (change current) vertex shader.
	*
	* @param vertexShaderSrc vertex shader source code path.
	*/
	void SetVertexShader(const char* vertexShaderSrc);

	/**
	* @brief Load and set (change current) pixel shader.
	*
	* @param pixelShaderSrc pixel shader source code path.
	*/
	void SetPixelShader(const char* pixelShaderSrc);

	/**
	* @brief Set new input layout.
	*
	* @param inputLayoutDesc vertices format descriptor.
	*/
	void SetInputLayout(D3D11_INPUT_ELEMENT_DESC* inputLayoutDesc);

private:
	ID3D11VertexShader* vertexShader_; 
	ID3D11PixelShader* pixelShader_;
	ID3D11InputLayout* inputLayout_;
};

#endif
