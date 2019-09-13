.. Copyright 2019 RADAR, Inc. - All Rights Reserved
.. Proprietary and confidential

Boost.Build Full Example
========================

.. contents::

This example contains a larger example with several libraries,
executables, and unit tests defined. The structure is laid out as in
the Boost.Build examples to help live next to them, have commonality.

The full example requires Boost.Test from the Boost C++ Libraries is
installed on the system.

To build and run the tests for the example, run the following command
from the root directory.

.. code::

   bjam documentation
   bjam install --prefix=tmp
