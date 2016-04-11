/*
 * Some comments are written in Japanese.
 *
 * Funded by IPA̤Ƨ���եȥ�������¤���� 2001
 *
 * Comments are in Japanese(EUC-JP)
 * doc/ILIB ����
 */

#ifndef INPUT_H_INCLUDE
#define INPUT_H_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif

#ifndef EXPORT_API
#define EXPORT_API
#endif // EXPORT_API


struct anthy_input_context;

EXPORT_API extern int anthy_input_errno;
#define AIE_NOMEM 1
#define AIE_INVAL 2
#define AIE_NOIMPL 3

#define ANTHY_INPUT_ST_OFF  0  /* ̵������ */ /* anthy agent does not use this state */
#define ANTHY_INPUT_ST_NONE 1  /* �Ե����� */
#define ANTHY_INPUT_ST_EDIT 2  /* �Խ����� */
#define ANTHY_INPUT_ST_CONV 3  /* �Ѵ����� */
#define ANTHY_INPUT_ST_CSEG 4  /* ʸ�῭�̾��� */

#define ANTHY_INPUT_MAP_ALPHABET  0
#define ANTHY_INPUT_MAP_WALPHABET 1
#define ANTHY_INPUT_MAP_HIRAGANA  2
#define ANTHY_INPUT_MAP_KATAKANA  3
#define ANTHY_INPUT_MAP_HANKAKU_KANA 4

#define ANTHY_INPUT_SF_NONE         0x00000000
#define ANTHY_INPUT_SF_CURSOR       0x00000001
#define ANTHY_INPUT_SF_ENUM         0x00000002
#define ANTHY_INPUT_SF_ENUM_REVERSE 0x00000004
#define ANTHY_INPUT_SF_EDITING      0x00000008
#define ANTHY_INPUT_SF_PENDING      0x00000010
#define ANTHY_INPUT_SF_FOLLOWING    0x00000020
  /* This have been in public API!*/
#define ANTHY_INPUT_SF_EDITTING     0x00000008

struct anthy_input_config;
struct anthy_input_context;

/*
 * anthy_input_get_preedit();
 * anthy_input_free_preedit();
 */
struct anthy_input_preedit {
  int state;

  char* commit;
  char* cut_buf;

  struct anthy_input_segment* segment;
  struct anthy_input_segment* cur_segment;
};

/*
 * anthy_input_get_candidate();
 * anthy_input_free_segment();
 */
struct anthy_input_segment {
  char* str;
  int cand_no;
  int noconv_len;
  int nr_cand;
  int flag;

  struct anthy_input_segment* next;
};

/* initialize ... */
EXPORT_API int anthy_input_init(void);

/* context management*/
EXPORT_API void anthy_input_set_personality(const char *);
EXPORT_API struct anthy_input_context*
anthy_input_create_context(struct anthy_input_config* cfg);
EXPORT_API void anthy_input_free_context(struct anthy_input_context* ictx);

/* pure function command */
EXPORT_API void anthy_input_str(struct anthy_input_context* ictx, const char* str);
EXPORT_API void anthy_input_next_candidate(struct anthy_input_context* ictx);
EXPORT_API void anthy_input_prev_candidate(struct anthy_input_context* ictx);
EXPORT_API void anthy_input_quit(struct anthy_input_context* ictx);
EXPORT_API void anthy_input_erase_prev(struct anthy_input_context* ictx);
EXPORT_API void anthy_input_erase_next(struct anthy_input_context* ictx);
EXPORT_API void anthy_input_commit(struct anthy_input_context* ictx);
EXPORT_API void anthy_input_move(struct anthy_input_context* ictx, int lr);
EXPORT_API void anthy_input_resize(struct anthy_input_context* ictx, int lr);
EXPORT_API void anthy_input_beginning_of_line(struct anthy_input_context* ictx);
EXPORT_API void anthy_input_end_of_line(struct anthy_input_context* ictx);
EXPORT_API void anthy_input_cut(struct anthy_input_context* ictx);

/* key oriented command */
EXPORT_API void anthy_input_key(struct anthy_input_context* ictx, int c);
EXPORT_API void anthy_input_space(struct anthy_input_context* ictx);

/* meta command */
EXPORT_API int anthy_input_get_state(struct anthy_input_context* ictx);
EXPORT_API struct anthy_input_preedit*
anthy_input_get_preedit(struct anthy_input_context* ictx);
EXPORT_API void anthy_input_free_preedit(struct anthy_input_preedit* pedit);
EXPORT_API int anthy_input_map_select(struct anthy_input_context* ictx, int map);
EXPORT_API int anthy_input_get_selected_map(struct anthy_input_context* ictx);
EXPORT_API struct anthy_input_segment* 
anthy_input_get_candidate(struct anthy_input_context* ictx, int cand_no);
EXPORT_API void anthy_input_free_segment(struct anthy_input_segment* cand);
EXPORT_API int anthy_input_select_candidate(struct anthy_input_context* ictx, int cand);

/* config */
EXPORT_API struct anthy_input_config* anthy_input_create_config(void);
EXPORT_API void anthy_input_free_config(struct anthy_input_config* cfg);
EXPORT_API int anthy_input_edit_toggle_config(struct anthy_input_config *cfg, char tg);
EXPORT_API int anthy_input_edit_rk_config(struct anthy_input_config *cfg, int map,
			       const char *from, const char *to, const char *follow);
EXPORT_API int anthy_input_clear_rk_config(struct anthy_input_config *cfg,
				int use_default);
EXPORT_API int anthy_input_break_into_roman_config(struct anthy_input_config* cfg, int f);
EXPORT_API int anthy_input_preedit_mode_config(struct anthy_input_config* cfg, int f);
EXPORT_API void anthy_input_change_config(struct anthy_input_config* cfg);

/* DEBUG API */
EXPORT_API anthy_context_t
anthy_input_get_anthy_context(struct anthy_input_context *ictx);

#ifdef __cplusplus
}
#endif

#endif /* INPUT_H_INCLUDE */
