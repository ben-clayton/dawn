#version 310 es

uniform highp samplerCube arg_1_arg_2;

void textureGather_11b2db() {
  vec4 res = textureGather(arg_1_arg_2, vec3(1.0f), int(1u));
}

vec4 vertex_main() {
  textureGather_11b2db();
  return vec4(0.0f);
}

void main() {
  gl_PointSize = 1.0;
  vec4 inner_result = vertex_main();
  gl_Position = inner_result;
  gl_Position.y = -(gl_Position.y);
  gl_Position.z = ((2.0f * gl_Position.z) - gl_Position.w);
  return;
}
#version 310 es
precision mediump float;

uniform highp samplerCube arg_1_arg_2;

void textureGather_11b2db() {
  vec4 res = textureGather(arg_1_arg_2, vec3(1.0f), int(1u));
}

void fragment_main() {
  textureGather_11b2db();
}

void main() {
  fragment_main();
  return;
}
#version 310 es

uniform highp samplerCube arg_1_arg_2;

void textureGather_11b2db() {
  vec4 res = textureGather(arg_1_arg_2, vec3(1.0f), int(1u));
}

void compute_main() {
  textureGather_11b2db();
}

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void main() {
  compute_main();
  return;
}
