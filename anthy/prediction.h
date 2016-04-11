#ifndef __prediction_h_included__
#define __prediction_h_included__

#include "xstr.h"

#ifndef EXPORT_API
#define EXPORT_API
#endif // EXPORT_API


struct prediction_t {
  int timestamp;
  /* �ɤ� */
  xstr *src_str;
  /* ��̤�ʸ���� */
  xstr *str;
};

/* ͽ¬���줿ʸ������Ǽ���� */
EXPORT_API int anthy_traverse_record_for_prediction(xstr*, struct prediction_t*);


#endif
