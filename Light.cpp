#include "Light.h"
#include <cassert>

using namespace DirectX;

//静的メンバ変数の実態
ID3D12Device* Light::device = nullptr;

void Light::StaticInitialize(ID3D12Device* device)
{
	//再初期化チェック
	assert(!Light::device);
	//nullptrチェック
	assert(device);
	//静的メンバ変数のセット
	Light::device = device;
}

void Light::Initialize()
{
}
