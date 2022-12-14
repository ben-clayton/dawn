#version 310 es

uint tint_insert_bits(uint v, uint n, uint offset, uint count) {
  uint s = min(offset, 32u);
  uint e = min(32u, (s + count));
  return bitfieldInsert(v, n, int(s), int((e - s)));
}

void f_1() {
  uint v = 0u;
  uint n = 0u;
  uint offset_1 = 0u;
  uint count = 0u;
  uint x_14 = v;
  uint x_15 = n;
  uint x_16 = offset_1;
  uint x_17 = count;
  uint x_12 = tint_insert_bits(x_14, x_15, x_16, x_17);
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
