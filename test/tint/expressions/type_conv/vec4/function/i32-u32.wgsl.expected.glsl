#version 310 es

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void unused_entry_point() {
  return;
}
int t = 0;
ivec4 m() {
  t = 1;
  return ivec4(t);
}

void f() {
  ivec4 tint_symbol = m();
  uvec4 v = uvec4(tint_symbol);
}
