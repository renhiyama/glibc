/* Heuristic for recognizing DSO file names.
   Copyright (C) 2021-2026 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#include <stdbool.h>
#include <string.h>

/* Returns true if the file name looks like a DSO name.
   Recognizes both standard .so and RunixOS .rdl extensions.  */
static bool
_dl_is_dso (const char *name)
{
  bool has_dso_ext = (strstr (name, ".so") != NULL
                      || strstr (name, ".rdl") != NULL);
  return (((strncmp (name, "lib", 3) == 0 || strncmp (name, "ld-", 3) == 0)
           && has_dso_ext)
          || strncmp (name, "ld.so.", 6) == 0
          || strncmp (name, "ld64.so.", 8) == 0
          || strncmp (name, "ld.rdl.", 7) == 0
          || strncmp (name, "ld64.rdl.", 9) == 0);
}
