fn dpdyFine_d0a648() {
  var res : vec4<f32> = dpdyFine(vec4<f32>(1.0f));
}

@fragment
fn fragment_main() {
  dpdyFine_d0a648();
}
