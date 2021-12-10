#include <assert.h>
#include <stdlib.h>

#include <decomposition/decomposition.h>

#include <decomposition/decomposition.inc>

int main(void) {
  // 4 => [4]
  Decomposition *decomposition1 = decompose(4);

  assert(decomposition1->number == 4);
  assert(decomposition1->addends_len == 1);
  assert(decomposition1->addends[0] == 4);

  decomposition_destroy(decomposition1);

  // 16 => [10, 6]
  Decomposition *decomposition2 = decompose(16);

  assert(decomposition2->number == 16);
  assert(decomposition2->addends_len == 2);
  assert(decomposition2->addends[0] == 10);
  assert(decomposition2->addends[1] == 6);

  decomposition_destroy(decomposition2);

  // 336 => [300, 30, 6]
  Decomposition *decomposition3 = decompose(336);

  assert(decomposition3->number == 336);
  assert(decomposition3->addends_len == 3);
  assert(decomposition3->addends[0] == 300);
  assert(decomposition3->addends[1] == 30);
  assert(decomposition3->addends[2] == 6);

  decomposition_destroy(decomposition3);

  // 3002 => [3000, 2]
  Decomposition *decomposition4 = decompose(3002);

  assert(decomposition4->number == 3002);
  assert(decomposition4->addends_len == 2);
  assert(decomposition4->addends[0] == 3000);
  assert(decomposition4->addends[1] == 2);

  decomposition_destroy(decomposition4);

  return EXIT_SUCCESS;
}
