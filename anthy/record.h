/* 学習の履歴などを保存するデータベース */
#ifndef _record_h_included_
#define _record_h_included_
/*
 * データベースは名前をもつ複数のsectionから構成され各セクションは
 * 文字列をキーとして高速に取り出すことができるrowからなる。
 *
 * データベースはカレントsectionやカレントrowなどの状態を持ち
 * 操作はそれに対して行われる。
 * section中のrowは順序関係をもっている
 * その順序関係とは別にLRUの順序をもっている
 */

#include "xstr.h"

/*
 * カレントsectionを設定する
 * name: sectionの名前
 * create_if_not_exist: そのsectionがなければ作るかどうかのフラグ
 * 返り値: 成功 0 、失敗 -1
 * 失敗の時にはカレントsectionは無効になる
 * 常にカレントrowは無効になる
 */
 
 #ifndef EXPORT_API
 #define EXPORT_API
 #endif // EXPORT_API
 
EXPORT_API int anthy_select_section(const char *name, int create_if_not_exist);

/*
 * カレントsection中からnameのrowをカレントrowにする
 * name: rowの名前
 * create_if_not_exist: そのrowがなければ作るかどうかのフラグ
 * 返り値: 成功 0 、失敗 -1
 * 失敗の時にはカレントrowは無効になる
 */
EXPORT_API int anthy_select_row(xstr *name, int create_if_not_exist);

/*
 * カレントsection中からnameに最も長い文字数でマッチする
 * 名前のrowをカレントrowにする
 * name: rowの名前
 * 返り値: 成功 0 、失敗 -1
 * 失敗の時にはにカレントrowは無効になる
 */
EXPORT_API int anthy_select_longest_row(xstr *name);

/*
 * カレントsection中の最初のrowをカレントrowにする
 * 返り値: 成功 0 、失敗 -1
 * 失敗の時にはカレントrowは無効になる
 */
EXPORT_API int anthy_select_first_row(void);

/*
 * カレントrowの次のrowをカレントrowにする
 * 返り値: 成功 0 、失敗 -1
 * カレントrowに対する変更があっても、ファイルには保存されない
 * 失敗の時にはカレントrowは無効になる
 */
EXPORT_API int anthy_select_next_row(void);

/*
 * カレントsectionを解放する
 * 常にカレントsection,rowは無効になる
 */
EXPORT_API void anthy_release_section(void);

/*
 * カレントsectionのLRUリストの先頭からcount個以降を解放する
 * 常にカレントrowは無効になる
 */
EXPORT_API void anthy_truncate_section(int count);


/* 現在のrowに対する操作 */
EXPORT_API xstr *anthy_get_index_xstr(void);
EXPORT_API int anthy_get_nr_values(void);
EXPORT_API int anthy_get_nth_value(int );
EXPORT_API xstr *anthy_get_nth_xstr(int );/* internされているxstrが返される */

EXPORT_API void anthy_set_nth_value(int nth, int val);
EXPORT_API void anthy_set_nth_xstr(int nth, xstr *xs);/* 内部でコピーされる */

EXPORT_API void anthy_truncate_row(int nth);/* To Be Implemented */

/*
 * カレントrowを解放する。終了後のカレントrowは不定
 * 常にカレントrowは無効になる
 */
EXPORT_API void anthy_release_row(void);

/*
 * カレントrowをLRUの先頭の方へもってくる
 * 常にカレントrowは無効になる
 */
EXPORT_API int anthy_mark_row_used(void);


EXPORT_API void anthy_reload_record(void);

#endif
