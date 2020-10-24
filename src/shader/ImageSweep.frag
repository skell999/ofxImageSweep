#version 330

out vec4 color;

uniform sampler2D image;
uniform vec2 resolution;
uniform float time;
uniform float width;
uniform float pos;

void main(){
	vec2 uv = gl_FragCoord.xy;

	float reverse = floor(mod((uv.x/width), 2));

	if(reverse == 0.0){
		uv.x = mod(uv.x,width) + pos;
	}else{
		uv.x = (width - mod(uv.x,width)) + pos;
	}


	color = texture(image,uv / resolution);
}