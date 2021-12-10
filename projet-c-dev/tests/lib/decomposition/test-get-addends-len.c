#include <assert.h>
#include <stdlib.h>

#include <decomposition/decomposition.h>

#include <decomposition/decomposition.inc>

int main(void) {
  Decomposition *decomposition1 = decompose(89);
  Decomposition *decomposition2 = decompose(429);

  assert(decomposition1->addends_len == decomposition_get_addends_len(decomposition1));
  assert(decomposition2->addends_len == decomposition_get_addends_len(decomposition2));

  decomposition_destroy(decomposition1);
  decomposition_destroy(decomposition2);

  return EXIT_SUCCESS;
}
