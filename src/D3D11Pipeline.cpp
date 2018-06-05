#include "../include/D3D11Pipeline.h"

void D3D11Pipeline::LoadPipeline(const char* vertexShaderSrc, const char* pixelShaderSrc, std::vector<D3D11_INPUT_ELEMENT_DESC>& inputLayoutDesc, ID3D11Device* dev)
{
	// compiled shader source
	ID3D10Blob* PS = nullptr;

	// Compile pixel and vertex shader and HLSL 4.0 version
	if (FAILED(D3DX11CompileFromFile(vertexShaderSrc, 0, 0, "VShader", "vs_4_0", 0, 0, 0, &vertexShaderSrc_, 0, 0)))
	{
		throw std::exception("Vertex shader source compilation failed!\nSource file does not exists or contains errors!");
	}

	if (FAILED(D3DX11CompileFromFile(pixelShaderSrc, 0, 0, "PShader", "ps_4_0", 0, 0, 0, &PS, 0, 0)))
	{
		throw std::exception("Pixel shader source compilation failed!\nSource file does not exists or contains errors!");
	}

	// create shaders and input layout
	if (FAILED(dev->CreateVertexShader(vertexShaderSrc_->GetBufferPointer(), vertexShaderSrc_->GetBufferSize(), NULL, &vertexShader_)))
	{
		throw std::exception("Vertex shader creation failed!");
	}
	
	if (FAILED(dev->CreatePixelShader(PS->GetBufferPointer(), PS->GetBufferSize(), NULL, &pixelShader_)))
	{
		throw std::exception("Pixel shader creation failed!");
	}

	if (FAILED(dev->CreateInputLayout(inputLayoutDesc.data(), inputLayoutDesc.size(), vertexShaderSrc_->GetBufferPointer(), vertexShaderSrc_->GetBufferSize(), &inputLayout_)))
	{
		throw std::exception("Input layout creation failed!\nProbably wrong format of input layout descriptor!");
	}
}

void D3D11Pipeline::Activate(ID3D11DeviceContext* devCon)
{
	devCon->VSSetShader(vertexShader_, 0, 0);
	devCon->PSSetShader(pixelShader_, 0, 0);
	devCon->IASetInputLayout(inputLayout_);
}

void D3D11Pipeline::Clean()
{
	vertexShader_->Release();
	pixelShader_->Release();
	inputLayout_->Release();
}

ID3D11VertexShader* D3D11Pipeline::GetVertexShader()
{
	return vertexShader_;
}

ID3D10Blob* D3D11Pipeline::GetVertexShaderSrc()
{
	return vertexShaderSrc_;
}

ID3D11PixelShader* D3D11Pipeline::GetPixelShader()
{
	return pixelShader_;
}

ID3D11InputLayout* D3D11Pipeline::GetInputLayout()
{
	return inputLayout_;
}
