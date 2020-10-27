#version 330

out vec4 color;

uniform sampler2D image;
uniform sampler2D posMap;
uniform vec2 resolution;

uniform float divX;
uniform float posX;
uniform float divY;
uniform float posY;

uniform bool flipX;
uniform bool flipY;

uniform bool sliceX;
uniform bool sliceY;


uniform float pos;

void main(){
	vec2 uv = gl_FragCoord.xy;
	vec2 uvMod = uv / resolution;

	float widthX = resolution.x/divX;

	float reverse = 0.0;

	if(sliceX)
	{
		if(flipX){
			reverse = floor(mod((uv.x/widthX), 2));
		}

		float posMod = (texture(posMap,uvMod).r + texture(posMap,uvMod).g + texture(posMap,uvMod).b) / 3.0;

		if(reverse == 0.0){
			uv.x = mod(uv.x,widthX) + (posX + (posMod * 300));
		}else{
			uv.x = (widthX - mod(uv.x,widthX)) + (posX + (posMod * 300));
		}		
	}



	float widthY = resolution.y/divY;

	if(sliceY)
	{
		if(flipY){
			reverse = floor(mod((uv.y/widthY), 2));
		}else{
			reverse = 0.0;
		}

		if(reverse == 0.0){
			uv.y = mod(uv.y,widthY) + posY;
		}else{
			uv.y = (widthY - mod(uv.y,widthY)) + posY;
		}
	}



	color = texture(image,uv / resolution);
	//color = vec4(reverse,reverse,reverse,1.0);
}