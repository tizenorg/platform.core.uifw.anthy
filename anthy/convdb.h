/* �Ѵ���̤Υǡ����١��� */
#ifndef _convdb_h_included_
#define _convdb_h_included_

#include <anthy/anthy.h>

/* ����, OK, ���Ѵ�, don't care��4�ĤΥ��ƥ��꡼��ʬ�ह�� */
#define CHK_UNKNOWN 0
#define CHK_OK 1
#define CHK_MISS 2
#define CHK_DONTCARE 3

/**/
#define CONV_OK 0
#define CONV_SIZE_MISS 1
#define CONV_CAND_MISS 2
#define CONV_INVALID 4

#ifndef EXPORT_API
#define EXPORT_API
#endif // EXPORT_API


/* �Ѵ������Ѵ����ʸ���󡢷�̤��Ф���Ƚ����Ǽ���� */
struct conv_res {
  /* �����Υ��� */
  char *src_str;
  char *res_str;
  /* ����������Ƥ���� */
  char *cand_str;
  /**/
  int *cand_check;
  /**/
  int check;
  int used;
  /**/
  struct conv_res *next;
};

/* �Ѵ���̤Υ������ */
struct res_stat {
  int unknown;
  int ok;
  int miss;
  int dontcare;
};

/* �Ѵ���̤Υǡ����١��� */
struct res_db {
  /**/
  struct conv_res res_list;
  struct conv_res *tail;
  /**/
  int total;
  struct res_stat res, split;
};

EXPORT_API struct res_db *create_db(void);
EXPORT_API void read_db(struct res_db *db, const char *fn);
EXPORT_API struct conv_res *find_conv_res(struct res_db *db, anthy_context_t ac,
			       const char *src, int conv);
EXPORT_API void print_size_miss_segment_info(anthy_context_t ac, int nth);
EXPORT_API void print_cand_miss_segment_info(anthy_context_t ac, int nth);
EXPORT_API void print_context_info(anthy_context_t ac, struct conv_res *cr);

#endif
