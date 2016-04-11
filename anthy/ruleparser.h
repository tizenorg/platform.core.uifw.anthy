/*
 * 汎用の設定ファイルパーザ
 */
#ifndef _ruleparser_h_included_
#define _ruleparser_h_included_

/*
 * ファイル名が'/'で始まっていれば絶対パス
 * ファイル名が'./'で始まっていればカレントディレクトリ
 * ファイル名がNULLならば標準入力
 * そうでなければ、ANTHYDIR中のファイルを開ける
 */
 
 #ifndef EXPORT_API
 #define EXPORT_API
 #endif // EXPORT_API
 
EXPORT_API int anthy_open_file(const char *fn);/* returns 0 on success */
EXPORT_API void anthy_close_file(void);
EXPORT_API int anthy_read_line(char ***tokens, int *nr);/* returns 0 on success */
EXPORT_API int anthy_get_line_number(void);
EXPORT_API void anthy_free_line(void);

#endif
