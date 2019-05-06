/////////////
// GLOBALS //
/////////////
cbuffer MatrixBuffer
{
	matrix worldMatrix;
	matrix viewMatrix;
	matrix projectionMatrix;
};


//////////////
// TYPEDEFS //
//////////////
struct VertexInputType
{
    float4 position : POSITION;
    float2 tex : TEXCOORD0;
	float3 normal : NORMAL;
};

struct PixelInputType
{
    float4 position : SV_POSITION;
    float4 color : COLOR;
};


////////////////////////////////////////////////////////////////////////////////
// Vertex Shader
////////////////////////////////////////////////////////////////////////////////
PixelInputType LightVertexShader(VertexInputType input)
{
    PixelInputType output;
    
	// Change the position vector to be 4 units for proper matrix calculations.
    input.position.w = 1.0f;

	float _Outline = 0.14f;

	output.position = input.position;
	output.position = mul(output.position, worldMatrix);
    output.position = mul(output.position, viewMatrix);

	input.normal = mul(input.normal, worldMatrix);
    input.normal = mul(input.normal, viewMatrix);
	input.normal.z = 0.1;

	output.position = output.position + float4(normalize(input.normal),0) *_Outline;

    output.position = mul(output.position, projectionMatrix);

	// black line
	output.color = float4(0.0f,0.0f,0.0f,0.0f);

    return output;
}