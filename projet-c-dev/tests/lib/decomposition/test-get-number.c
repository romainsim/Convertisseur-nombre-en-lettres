#include <assert.h>
#include <stdlib.h>

#include <decomposition/decomposition.h>

#include <decomposition/decomposition.inc>

int main(void) {
  Decomposition *decomposition1 = decompose(23);
  Decomposition *decomposition2 = decompose(843);

  assert(decomposition1->number == decomposition_get_number(decomposition1));
  assert(decomposition2->number == decomposition_get_number(decomposition2));

  decomposition_destroy(decomposition1);
  decomposition_destroy(decomposition2);

  return EXIT_SUCCESS;
}
