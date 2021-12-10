#include <assert.h>
#include <stdlib.h>

#include <decomposition/decomposition.h>

#include <decomposition/decomposition.inc>

int main(void) {
  // 4 => [4]
  Decomposition *decomposition1 = decompose_by_three(4);

  assert(decomposition1->number == 4);
  assert(decomposition1->addends_len == 1);
  assert(decomposition1->addends[0] == 4);

  decomposition_destroy(decomposition1);

  // 16 => [16]
  Decomposition *decomposition2 = decompose_by_three(16);

  assert(decomposition2->number == 16);
  assert(decomposition2->addends_len == 1);
  assert(decomposition2->addends[0] == 16);

  decomposition_destroy(decomposition2);

  // 336 => [336]
  Decomposition *decomposition3 = decompose_by_three(336);

  assert(decomposition3->number == 336);
  assert(decomposition3->addends_len == 1);
  assert(decomposition3->addends[0] == 336);

  decomposition_destroy(decomposition3);

  // 3002 => [2, 3]
  Decomposition *decomposition4 = decompose_by_three(3002);

  assert(decomposition4->number == 3002);
  assert(decomposition4->addends_len == 2);
  assert(decomposition4->addends[0] == 2);
  assert(decomposition4->addends[1] == 3);

  decomposition_destroy(decomposition4);

  // 3002484 => [484, 2, 3]
  Decomposition *decomposition5 = decompose_by_three(3002484);

  assert(decomposition5->number == 3002484);
  assert(decomposition5->addends_len == 3);
  assert(decomposition5->addends[0] == 484);
  assert(decomposition5->addends[1] == 2);
  assert(decomposition5->addends[2] == 3);

  decomposition_destroy(decomposition5);

  return EXIT_SUCCESS;
}
