#version 310 es

uint tint_extract_bits(uint v, uint offset, uint count) {
  uint s = min(offset, 32u);
  uint e = min(32u, (s + count));
  return bitfieldExtract(v, int(s), int((e - s)));
}

void f_1() {
  uint v = 0u;
  uint offset_1 = 0u;
  uint count = 0u;
  uint x_13 = v;
  uint x_14 = offset_1;
  uint x_15 = count;
  uint x_11 = tint_extract_bits(x_13, x_14, x_15);
  return;
}

void f() {
  f_1();
}

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void main() {
  f();
  return;
}
