/*
** init.c - initialize mruby core
**
** See Copyright Notice in mruby.h
*/

#include "mruby.h"

void mrb_init_symtbl(mrb_state*);
void mrb_init_class(mrb_state*);
void mrb_init_object(mrb_state*);
void mrb_init_kernel(mrb_state*);
void mrb_init_comparable(mrb_state*);
void mrb_init_enumerable(mrb_state*);
void mrb_init_symbol(mrb_state*);
void mrb_init_exception(mrb_state*);
void mrb_init_proc(mrb_state*);
void mrb_init_string(mrb_state*);
void mrb_init_array(mrb_state*);
void mrb_init_hash(mrb_state*);
void mrb_init_numeric(mrb_state*);
void mrb_init_range(mrb_state*);
void mrb_init_gc(mrb_state*);
void mrb_init_math(mrb_state*);
void mrb_init_mrblib(mrb_state*);
void mrb_init_mrbgems(mrb_state*);
void mrb_final_mrbgems(mrb_state*);

void mrb_mruby_math_gem_init(mrb_state* mrb);
void mrb_mruby_math_gem_final(mrb_state* mrb);

#define DONE mrb_gc_arena_restore(mrb, 0);
void
mrb_init_core(mrb_state *mrb)
{
  mrb_init_symtbl(mrb); DONE;

  mrb_init_class(mrb); DONE;
  mrb_init_object(mrb); DONE;
  mrb_init_kernel(mrb); DONE;
  mrb_init_comparable(mrb); DONE;
  mrb_init_enumerable(mrb); DONE;

  mrb_init_symbol(mrb); DONE;
  mrb_init_exception(mrb); DONE;
  mrb_init_proc(mrb); DONE;
  mrb_init_string(mrb); DONE;
  mrb_init_array(mrb); DONE;
  mrb_init_hash(mrb); DONE;
  mrb_init_numeric(mrb); DONE;
  mrb_init_range(mrb); DONE;
  mrb_init_gc(mrb); DONE;
  mrb_init_mrblib(mrb); DONE;

  mrb_mruby_math_gem_init(mrb); DONE;

// #ifndef DISABLE_GEMS
//   mrb_init_mrbgems(mrb); DONE;
// #endif
}

void
mrb_final_core(mrb_state *mrb)
{
  mrb_mruby_math_gem_final(mrb); DONE;

//#ifndef DISABLE_GEMS
//  mrb_final_mrbgems(mrb); DONE;
//#endif
}
