#include <assert.h>
#include <stdlib.h>

#include <decomposition/decomposition.h>

#include <decomposition/decomposition.inc>

int main(void) {
  Decomposition *decomposition1 = decompose(29);
  Decomposition *decomposition2 = decompose(389);

  assert(decomposition1->addends == decomposition_get_addends(decomposition1));
  assert(decomposition2->addends == decomposition_get_addends(decomposition2));

  decomposition_destroy(decomposition1);
  decomposition_destroy(decomposition2);

  return EXIT_SUCCESS;
}
