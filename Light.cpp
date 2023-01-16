#include "Light.h"
#include <cassert>

using namespace DirectX;

//�ÓI�����o�ϐ��̎���
ID3D12Device* Light::device = nullptr;

void Light::StaticInitialize(ID3D12Device* device)
{
	//�ď������`�F�b�N
	assert(!Light::device);
	//nullptr�`�F�b�N
	assert(device);
	//�ÓI�����o�ϐ��̃Z�b�g
	Light::device = device;
}

void Light::Initialize()
{
}
