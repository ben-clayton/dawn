fn abs_b96037() {
  var arg_0 = 1.0;
  var res : f32 = abs(arg_0);
}

@stage(vertex)
fn vertex_main() -> @builtin(position) vec4<f32> {
  abs_b96037();
  return vec4<f32>();
}

@stage(fragment)
fn fragment_main() {
  abs_b96037();
}

@stage(compute) @workgroup_size(1)
fn compute_main() {
  abs_b96037();
}