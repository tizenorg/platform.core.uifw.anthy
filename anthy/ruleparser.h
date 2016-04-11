/*
 * ���Ѥ�����ե�����ѡ���
 */
#ifndef _ruleparser_h_included_
#define _ruleparser_h_included_

/*
 * �ե�����̾��'/'�ǻϤޤäƤ�������Хѥ�
 * �ե�����̾��'./'�ǻϤޤäƤ���Х����ȥǥ��쥯�ȥ�
 * �ե�����̾��NULL�ʤ��ɸ������
 * �����Ǥʤ���С�ANTHYDIR��Υե�����򳫤���
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
