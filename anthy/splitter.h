/* splitter�⥸�塼��Υ��󥿡��ե����� */
#ifndef _splitter_h_included_
#define _splitter_h_included_

#include <anthy/dic.h>
#include <anthy/xstr.h>
#include <anthy/wtype.h>
#include <anthy/segclass.h>

/* �ѥ�᡼�� */
#define RATIO_BASE 256
#define OCHAIRE_SCORE 5000000

/** splitter�Υ���ƥ����ȡ�
 * �ǽ�ζ������꤫��anthy_context�β����ޤ�ͭ��
 */
 
 #ifndef EXPORT_API
 #define EXPORT_API
 #endif // EXPORT_API
 
struct splitter_context {
  /** splitter�����ǻ��Ѥ��빽¤�� */
  struct word_split_info_cache *word_split_info;
  int char_count;
  int is_reverse;
  struct char_ent {
    xchar *c;
    int seg_border;
    int initial_seg_len;/* �ǽ��ʸ��ʬ��κݤˤ�������Ϥޤä�ʸ�᤬
			   ����Ф���Ĺ�� */
    enum seg_class best_seg_class;
    struct meta_word* best_mw; /* ����ͥ�褷�ƻȤ�����metaword */
  }*ce;
};

/* ����Υ����å��ξ��� */
enum constraint_stat {
  unchecked, ok, ng
};

/* �Ȥꤢ������Ŭ�������䤷�Ƥߤ����꤬�Ф���ʬ�ह�� */
enum metaword_type {
  /* ���ߡ� : seginfo������ʤ� */
  MW_DUMMY,
  /* wordlist��0�� or ��Ĵޤ��� */
  MW_SINGLE,
  /* �̤�metaword��Ĥ�ޤ�: metaword + ������ �ʤ� :seginfo��mw1������ */
  MW_WRAP,
  /* ʣ�����Ƭ */
  MW_COMPOUND_HEAD,
  /* ʣ����� */
  MW_COMPOUND,
  /* ʣ���ΰ�ʸ�� */
  MW_COMPOUND_LEAF,
  /* ʣ������θġ���ʸ����礷�ư�Ĥ�ʸ��Ȥ��Ƥߤ���� */
  MW_COMPOUND_PART,
  /* ư���Ϣ�ѷ� + ���ƻ� */
  MW_V_RENYOU_A,
  /* ư���Ϣ�ѷ� + ̾�� */
  MW_V_RENYOU_NOUN,
  /* ���� */
  MW_NUMBER,
  /**/
  MW_OCHAIRE,
  /**/
  MW_END
};

#define MW_FEATURE_NONE 0
#define MW_FEATURE_SV 1
#define MW_FEATURE_WEAK_CONN 2
#define MW_FEATURE_SUFFIX 4
#define MW_FEATURE_NUM 16
#define MW_FEATURE_CORE1 32
#define MW_FEATURE_DEP_ONLY 64
#define MW_FEATURE_HIGH_FREQ 128
#define MW_FEATURE_WEAK_SEQ 256

/*
 * meta_word: �����θ������оݤȤʤ���
 * ñ���word_list��ޤ��Τ�¾�ˤ����Ĥ��μ��ब���롥
 * 
 */
struct meta_word {
  int from, len;
  /* ʸ�ᶭ���θ��Ф˻��Ѥ��륹���� */
  int score;
  /* ����������λ��˻��Ѥ��륹���� */
  int struct_score;
  /* �����ξ��� */
  int dep_word_hash;
  int mw_features;
  wtype_t core_wt;
  enum dep_class dep_class;
  /**/
  enum seg_class seg_class;
  enum constraint_stat can_use; /* �������ȶ����˸٤��äƤ��ʤ� */
  enum metaword_type type;
  struct word_list *wl;
  struct meta_word *mw1, *mw2;
  xstr cand_hint;

  int nr_parts;

  /* list�Υ�� */
  struct meta_word *next;
};

EXPORT_API int anthy_init_splitter(void);
EXPORT_API void anthy_quit_splitter(void);

EXPORT_API void anthy_init_split_context(xstr *xs, struct splitter_context *, int is_reverse);
/*
 * mark_border(context, l1, l2, r1);
 * l1��r1�δ֤�ʸ��򸡽Ф��롢������l1��l2�δ֤϶����ˤ��ʤ���
 */
EXPORT_API void anthy_mark_border(struct splitter_context *, int from, int from2, int to);
EXPORT_API void anthy_commit_border(struct splitter_context *, int nr,
		   struct meta_word **mw, int *len);
EXPORT_API void anthy_release_split_context(struct splitter_context *c);

/* ���Ф���ʸ��ξ����������� */
EXPORT_API int anthy_get_nr_metaword(struct splitter_context *, int from, int len);
EXPORT_API struct meta_word *anthy_get_nth_metaword(struct splitter_context *,
					 int from, int len, int nth);
/**/
EXPORT_API int anthy_dep_word_hash(xstr *xs);


#endif
