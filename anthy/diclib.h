#ifndef __diclib_h_included__
#define __diclib_h_included__

#ifndef EXPORT_API
#define EXPORT_API
#endif // EXPORT_API



/* 全体の初期化、解放 */
EXPORT_API int anthy_init_diclib(void);
EXPORT_API void anthy_quit_diclib(void);

EXPORT_API void* anthy_file_dic_get_section(const char* section_name);

/*
  utility
 */
EXPORT_API unsigned int anthy_dic_ntohl(unsigned int a);
EXPORT_API unsigned int anthy_dic_htonl(unsigned int a);


#endif
