/*
 * ����⥸�塼��Υ��󥿡��ե�����
 */
#ifndef _dic_h_included_
#define _dic_h_included_

#include "xstr.h"
#include "wtype.h"

#ifndef EXPORT_API
#define EXPORT_API
#endif // EXPORT_API


/** ������ɤߤ��Ф���ϥ�ɥ�(sequence entry) */
typedef struct seq_ent *seq_ent_t;
/***/
typedef struct dic_ent *compound_ent_t;

/* ���Τν���������� */
EXPORT_API int anthy_init_dic(void);
EXPORT_API void anthy_quit_dic(void);

/* ¾�ץ������Ф�����¾���� */
EXPORT_API void anthy_lock_dic(void);
EXPORT_API void anthy_unlock_dic(void);

/**/
EXPORT_API void anthy_gang_load_dic(xstr *xs, int is_reverse);

/* ʸ����μ��� */
EXPORT_API seq_ent_t anthy_get_seq_ent_from_xstr(xstr *xs, int is_reverse);
/* ʸ����ξ��� */
EXPORT_API int anthy_get_nr_dic_ents(seq_ent_t se, xstr *xs);
EXPORT_API int anthy_has_compound_ents(seq_ent_t se);
EXPORT_API int anthy_has_non_compound_ents(seq_ent_t se);
EXPORT_API int anthy_get_nth_dic_ent_is_compound(seq_ent_t se, int nth);
/* ��ʣ��� */
/* caller should free @res */
EXPORT_API int anthy_get_nth_dic_ent_str(seq_ent_t, xstr *orig, int, xstr *res);
EXPORT_API int anthy_get_nth_dic_ent_freq(seq_ent_t, int nth);
EXPORT_API int anthy_get_nth_dic_ent_wtype(seq_ent_t, xstr *, int nth, wtype_t *w);
/*  �ʻ� */
EXPORT_API int anthy_get_seq_ent_pos(seq_ent_t, int pos);
EXPORT_API int anthy_get_seq_ent_ct(seq_ent_t, int pos, int ct);
EXPORT_API int anthy_get_seq_ent_wtype_freq(seq_ent_t, wtype_t);
EXPORT_API int anthy_get_seq_ent_indep(seq_ent_t se);
/* ʣ��� */
EXPORT_API compound_ent_t anthy_get_nth_compound_ent(seq_ent_t se, int nth);
EXPORT_API int anthy_get_seq_ent_wtype_compound_freq(seq_ent_t se, wtype_t wt);
/**/
EXPORT_API int anthy_compound_get_wtype(compound_ent_t, wtype_t *w);
EXPORT_API int anthy_compound_get_freq(compound_ent_t ce);
EXPORT_API int anthy_compound_get_nr_segments(compound_ent_t ce);
EXPORT_API int anthy_compound_get_nth_segment_len(compound_ent_t ce, int nth);
EXPORT_API int anthy_compound_get_nth_segment_xstr(compound_ent_t ce, int nth, xstr *xs);



/** ���񥻥å����
 *
 */
typedef struct mem_dic *dic_session_t;
/*typedef struct dic_session *dic_session_t;*/

EXPORT_API dic_session_t anthy_dic_create_session(void);
EXPORT_API void anthy_dic_activate_session(dic_session_t );
EXPORT_API void anthy_dic_release_session(dic_session_t);

/* personality */
EXPORT_API void anthy_dic_set_personality(const char *);
/**/
#define ANON_ID ""


/** ���㼭��
 */
EXPORT_API int anthy_dic_check_word_relation(int from, int to);

/** ̤�θ�γؽ�
 */
EXPORT_API void anthy_add_unknown_word(xstr *yomi, xstr *word);
EXPORT_API void anthy_forget_unused_unknown_word(xstr *xs);

#endif
