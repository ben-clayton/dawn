fn fwidth_5d1b39() {
  var res : vec3<f32> = fwidth(vec3<f32>(1.0f));
}

@fragment
fn fragment_main() {
  fwidth_5d1b39();
}
