#include "../include/D3D11Pipeline.h"

D3D11Pipeline::D3D11Pipeline(const char* vertexShaderSrc, const char* pixelShaderSrc, std::vector<D3D11_INPUT_ELEMENT_DESC>& inputLayoutDesc, ID3D11Device* dev)
{
	// compiled shader source
	ID3D10Blob *VS, *PS;

	// Compile pixel and vertex shader, with entry point "main" and HLSL 4.0 version
	D3DX11CompileFromFile(vertexShaderSrc, 0, 0, "VShader", "vs_4_0", 0, 0, 0, &VS, 0, 0);
	D3DX11CompileFromFile(pixelShaderSrc, 0, 0, "PShader", "ps_4_0", 0, 0, 0, &PS, 0, 0);

	// create shaders
	dev->CreateVertexShader(VS->GetBufferPointer(), VS->GetBufferSize(), NULL, &vertexShader_);
	dev->CreatePixelShader(PS->GetBufferPointer(), PS->GetBufferSize(), NULL, &pixelShader_);

	dev->CreateInputLayout(inputLayoutDesc.data(), inputLayoutDesc.size(), VS->GetBufferPointer(), VS->GetBufferSize(), &inputLayout_);
}

void D3D11Pipeline::Activate(ID3D11DeviceContext* devCon)
{
	devCon->VSSetShader(vertexShader_, 0, 0);
	devCon->PSSetShader(pixelShader_, 0, 0);
	devCon->IASetInputLayout(inputLayout_);
}

void D3D11Pipeline::SetVertexShader(const char* vertexShaderSrc)
{
}

void D3D11Pipeline::SetPixelShader(const char* pixelShaderSrc)
{
}

void D3D11Pipeline::SetInputLayout(D3D11_INPUT_ELEMENT_DESC* inputLayoutDesc)
{
}
