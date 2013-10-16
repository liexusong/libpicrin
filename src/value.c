#include <stdlib.h>

#include "picrin.h"

enum pic_tt
pic_type(pic_value v)
{
  switch (v.type) {
  case PIC_VTYPE_NIL:
    return PIC_TT_NIL;
  case PIC_VTYPE_FLOAT:
    return PIC_TT_FLOAT;
  case PIC_VTYPE_UNDEF:
    return PIC_TT_UNDEF;
  case PIC_VTYPE_HEAP:
    return ((struct pic_object *)v.u.data)->tt;
  }
}

pic_value
pic_nil_value()
{
  pic_value v;

  v.type = PIC_VTYPE_NIL;
  v.u.data = NULL;
  return v;
}

pic_value
pic_obj_value(void *ptr)
{
  pic_value v;

  v.type = PIC_VTYPE_HEAP;
  v.u.data = ptr;
  return v;
}

pic_value
pic_float_value(double f)
{
  pic_value v;

  v.type = PIC_VTYPE_FLOAT;
  v.u.f = f;
  return v;
}

pic_value
pic_undef_value()
{
  pic_value v;

  v.type = PIC_VTYPE_UNDEF;
  v.u.data = NULL;
  return v;
}