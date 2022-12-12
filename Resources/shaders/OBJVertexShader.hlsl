#include "OBJShaderHeader.hlsli"

VSOutput main(float4 pos : POSITION, float3 normal : NORMAL, float2 uv : TEXCOORD)
{
	
	//右、下、奥の方向を向いたライト
	float3 lightdir = float3(1.0f, -1.0f, 1.0f);
	lightdir = normalize(lightdir);
	//ライトの色
	float3 lightcolor = float3(1.0f, 1.0f, 1.0f);

	//環境反射光
	float3 ambient = m_ambient;
	//拡散反射光
	float3 diffuse = dot(-lightdir, normal) * m_diffuse;
	
	//視点座標
	const float3 eye = float3(0.0f, 0.0f, -20.0f);
	
	VSOutput output; // ピクセルシェーダーに渡す値
	output.svpos = mul(mat, pos);
	
	//ランバート反射の計算
	output.color.rgb = dot(-lightdir, normal) * m_diffuse * lightcolor;
	output.color.a = m_alpha;
	output.uv = uv;
	return output;
}