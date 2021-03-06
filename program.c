/* Copyright (c) 2013 Øyvind Kolås
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * Authors:  Øyvind Kolås    <pippin@gimp.org>
 */

#include "oi.h"
@generateheader

@trait Program
{
  var args;
} PACKED;

static void destroy ()
{
  this->args@ref:dec();
}

static void init (char **argv)
{
  this->args = @list:new();
  this->args@list:set_destroy (ref_dec, NULL);
  self@["name"string]=argv[0];
  argv++;
  while (*argv)
    {
      this->args@list:append (string_new (*argv));
      argv++;
    }
}

var get_args ()
{
  return this->args;
}

@end
