fn insertBits_87826b() {
  var res : vec3<u32> = insertBits(vec3<u32>(), vec3<u32>(), 1u, 1u);
}

@stage(vertex)
fn vertex_main() -> @builtin(position) vec4<f32> {
  insertBits_87826b();
  return vec4<f32>();
}

@stage(fragment)
fn fragment_main() {
  insertBits_87826b();
}

@stage(compute) @workgroup_size(1)
fn compute_main() {
  insertBits_87826b();
}