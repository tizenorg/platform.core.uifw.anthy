/** ʸ��Υ��饹 */
#ifndef _segclass_h_included_
#define _segclass_h_included_

#ifndef EXPORT_API
#define EXPORT_API
#endif // EXPORT_API


enum dep_class {
  /* ��°��ʤ� */
  DEP_NONE,
  /* ��°����� */
  DEP_FUZOKUGO,
  /* �ʽ��� */
  DEP_KAKUJOSHI,
  /* Ϣ�� */
  DEP_RENYOU,
  /* Ϣ�� */
  DEP_RENTAI,
  /* ��ü */
  DEP_END,
  /* ̾��ñ�� */
  DEP_RAW
};


enum seg_class {
  /* 0 */
  SEG_HEAD,
  SEG_TAIL,
  SEG_BUNSETSU,
  SEG_SETSUZOKUGO,
  SEG_MEISHI_KAKUJOSHI,
  SEG_MEISHI_SHUTAN,
  SEG_DOUSHI_FUZOKUGO,
  SEG_DOUSHI_SHUTAN,
  SEG_KEIYOUSHI,
  SEG_KEIYOUDOUSHI,
  /* 10 */
  SEG_RENYOU_SHUSHOKU,
  SEG_RENTAI_SHUSHOKU,
  SEG_MEISHI,
  SEG_MEISHI_FUZOKUGO,
  SEG_MEISHI_RENYOU,
  SEG_DOUSHI_RENYOU,
  SEG_DOUSHI_RENTAI,
  SEG_SIZE
};

EXPORT_API const char* anthy_seg_class_name(enum seg_class sc);
EXPORT_API const char* anthy_seg_class_sym(enum seg_class sc);
EXPORT_API enum seg_class anthy_seg_class_by_name(const char *name);

#endif
