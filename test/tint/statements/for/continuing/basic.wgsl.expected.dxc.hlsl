[numthreads(1, 1, 1)]
void unused_entry_point() {
  return;
}

void f() {
  int i = 0;
  {
    [loop] for(; false; i = (i + 1)) {
    }
  }
}