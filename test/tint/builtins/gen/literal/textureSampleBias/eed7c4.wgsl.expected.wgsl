@group(1) @binding(0) var arg_0 : texture_cube_array<f32>;

@group(1) @binding(1) var arg_1 : sampler;

fn textureSampleBias_eed7c4() {
  var res : vec4<f32> = textureSampleBias(arg_0, arg_1, vec3<f32>(1.0f), 1i, 1.0f);
}

@fragment
fn fragment_main() {
  textureSampleBias_eed7c4();
}
