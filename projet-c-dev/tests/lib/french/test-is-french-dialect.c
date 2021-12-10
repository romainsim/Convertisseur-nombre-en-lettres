#include <assert.h>
#include <stdlib.h>

#include <french/french.h>

int main(void) {
  assert(is_french_dialect("--fr_BE"));
  assert(is_french_dialect("--fr_FR"));
  assert(is_french_dialect("--fr_FR_african"));

  assert(!is_french_dialect("--fr_QE"));
  assert(!is_french_dialect("isdf"));
  assert(!is_french_dialect(""));

  return EXIT_SUCCESS;
}

