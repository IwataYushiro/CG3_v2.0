#pragma once
#include <DirectXMath.h>
#include "DirectionalLight.h"

//ライト
class LightGroup
{
private: // エイリアス
	// Microsoft::WRL::を省略
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::を省略
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMVECTOR = DirectX::XMVECTOR;
	using XMMATRIX = DirectX::XMMATRIX;

public://定数
	static const int DirLightNum = 3;

public://サブクラス
	//定数バッファ用データ構造体
	struct ConstBufferData
	{
		//環境光の色
		XMFLOAT3 ambientColor;
		float pad1;
		//平行光源用
		DirectionalLight::ConstBufferData dirLights[DirLightNum];
	};

private://静的メンバ変数
	//デバイス
	static ID3D12Device* device;

public://静的メンバ関数

};

