#pragma once
#include <d3d12.h>
#include <DirectXMath.h>
#include <d3dx12.h>

class Light
{
private: // エイリアス
	// Microsoft::WRL::を省略
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::を省略
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

public://サブクラス
	//定数バッファ用データ構造体
	struct ConstBufferData
	{
		XMVECTOR lightV;		//ライトへの方向を表すベクトル
		XMFLOAT3 lightColor;	//ライトの色
	};

public:
	//静的初期化
	static void StaticInitialize(ID3D12Device* device);

private://静的メンバ変数
	//デバイス
	static ID3D12Device* device;

private://メンバ変数
	//定数バッファ
	ComPtr<ID3D12Resource> constBuff;
	//ライト光線方向(単位ベクトル)
	XMVECTOR lightDir = { 1.0f,0.0f,0.0f,0.0f };
	//ライト色
	XMFLOAT3 lightColor = { 1.0f,1.0f,1.0f };
	//ダーティフラグ
	bool dirty = false;

public://メンバ関数
	//初期化
	void Initialize();

};

