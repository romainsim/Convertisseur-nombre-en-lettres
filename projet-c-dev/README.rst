SpellNumber
###########

Using the project
*****************

Create a build directory
========================

.. code:: bash

  $ mkdir build && cd build

Launch CMake
============

.. code:: bash

  $ cmake ../

Launch Make & Install packages
==============================

.. code:: bash

  $ make install

Launch tests
============

Prerequisites: Valgrind

.. code:: bash

  $ make test

Build the docs
==============

Prerequisites: Breathe, Doxygen, Sphinx

.. code:: bash

  $ make docs

Find library & program
======================

The library is into "build/src/lib/libspell-number.so".

The program is into "build/src/program/spell-number".
