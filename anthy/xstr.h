/*
 * Anthy内部で使う文字列
 * 特に実装を隠蔽しようとしているわけでは無いので、
 * ここにある関数の使用は強制しない。
 */
#ifndef _xstr_h_included_
#define _xstr_h_included_

/** 文字型
 * UCS4が入っている */
 
 #ifndef EXPORT_API
 #define EXPORT_API
 #endif // EXPORT_API
 
typedef int xchar;

/** 文字列
 * xstrにtypedefされている
 */
typedef struct xstr_ {
  /** 文字列へのポインタ */
  xchar *str;
  /** xcharの数 */
  int len;
} xstr;

/* デバッグ用の出力関数 */
EXPORT_API void anthy_putxchar(xchar );
EXPORT_API void anthy_putxstr(xstr *);
EXPORT_API void anthy_putxstrln(xstr *);

/* Cの文字列への書き出し */
EXPORT_API int anthy_sputxchar(char *, xchar , int encoding);
EXPORT_API int anthy_sputxstr(char *, xstr *, int encoding);
EXPORT_API int anthy_snputxstr(char *, int , xstr *, int encoding);

/* xstrとstr共にmallocされる、freeで両方解放するかanthy_free_xstrで解放する */
EXPORT_API xstr *anthy_cstr_to_xstr(const char *, int );
/* 結果はmallocで確保される */
EXPORT_API char *anthy_xstr_to_cstr(xstr *, int);

/* xstrとstr共にmallocされる */
EXPORT_API xstr *anthy_xstr_dup(xstr *);
EXPORT_API void anthy_free_xstr(xstr *);

/* 結果はmallocで確保される */
EXPORT_API xchar *anthy_xstr_dup_str(xstr *);
EXPORT_API void anthy_free_xstr_str(xstr *);

/* 文字列をコピーする */
EXPORT_API xstr* anthy_xstrcpy(xstr *, xstr *);
/* 文字列を比較する。strcmpと同等の動作(返り値の符号に意味がある) */
EXPORT_API int anthy_xstrcmp(xstr *, xstr *);
/* n文字目まで文字列を比較する。strncmpと同等の動作(返り値の符号に意味がある) */
EXPORT_API int anthy_xstrncmp(xstr *, xstr *, int);
/* s->strをreallocする */
EXPORT_API xstr *anthy_xstrcat(xstr *s, xstr *d);
/* xs->strをreallocする */
EXPORT_API xstr *anthy_xstrappend(xstr *xs, xchar c);

/* strtollのxstr版 */
EXPORT_API long long anthy_xstrtoll(xstr *);
/* 全角数字から半角数字への変換 */
EXPORT_API xstr *anthy_xstr_wide_num_to_num(xstr *);
/* ひらがなからカタカナへの変換 */
EXPORT_API xstr *anthy_xstr_hira_to_kata(xstr *);
/**/
EXPORT_API xstr *anthy_xstr_hira_to_half_kata(xstr *);
EXPORT_API xstr *anthy_conv_half_wide(xstr *xs);

/*  xcharの型 */
#define XCT_ALL 0xffffffff
#define XCT_NONE 0
#define XCT_HIRA 1
#define XCT_KATA 2
#define XCT_ASCII 4
#define XCT_NUM 8
#define XCT_WIDENUM 16
#define XCT_OPEN 32
#define XCT_CLOSE 64
/* 直前の文字の一部 */
#define XCT_PART 128
/* 助詞 */
#define XCT_DEP 256
/* 記号 */
#define XCT_SYMBOL 1024
/* 漢字 */
#define XCT_KANJI 2048
/* 句読点 */
#define XCT_PUNCTUATION 4096

/** XCT_*が返ってくる */
EXPORT_API int anthy_get_xchar_type(const xchar );
/** 全ての文字に対してXCT_*の論理積をとったもの */
EXPORT_API int anthy_get_xstr_type(const xstr *);

/* hash */
EXPORT_API int anthy_xstr_hash(xstr *);

/* xstr.c */
EXPORT_API int anthy_init_xstr(void);
EXPORT_API void anthy_quit_xstr(void);
EXPORT_API void anthy_xstr_set_print_encoding(int );

EXPORT_API int anthy_euc_to_ucs(int ec);
EXPORT_API int anthy_ucs_to_euc(int uc);

EXPORT_API const char *anthy_utf8_to_ucs4_xchar(const char *s, xchar *res);
/**/
EXPORT_API char *anthy_conv_euc_to_utf8(const char *s);
EXPORT_API char *anthy_conv_utf8_to_euc(const char *s);

#endif
