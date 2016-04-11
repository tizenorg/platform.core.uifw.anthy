/* �ؽ�������ʤɤ���¸����ǡ����١��� */
#ifndef _record_h_included_
#define _record_h_included_
/*
 * �ǡ����١�����̾������ʣ����section���鹽������ƥ���������
 * ʸ����򥭡��Ȥ��ƹ�®�˼��Ф����Ȥ��Ǥ���row����ʤ롣
 *
 * �ǡ����١����ϥ�����section�䥫����row�ʤɤξ��֤����
 * ���Ϥ�����Ф��ƹԤ��롣
 * section���row�Ͻ���ط����äƤ���
 * ���ν���ط��Ȥ��̤�LRU�ν�����äƤ���
 */

#include "xstr.h"

/*
 * ������section�����ꤹ��
 * name: section��̾��
 * create_if_not_exist: ����section���ʤ���к�뤫�ɤ����Υե饰
 * �֤���: ���� 0 ������ -1
 * ���Ԥλ��ˤϥ�����section��̵���ˤʤ�
 * ��˥�����row��̵���ˤʤ�
 */
 
 #ifndef EXPORT_API
 #define EXPORT_API
 #endif // EXPORT_API
 
EXPORT_API int anthy_select_section(const char *name, int create_if_not_exist);

/*
 * ������section�椫��name��row�򥫥���row�ˤ���
 * name: row��̾��
 * create_if_not_exist: ����row���ʤ���к�뤫�ɤ����Υե饰
 * �֤���: ���� 0 ������ -1
 * ���Ԥλ��ˤϥ�����row��̵���ˤʤ�
 */
EXPORT_API int anthy_select_row(xstr *name, int create_if_not_exist);

/*
 * ������section�椫��name�˺Ǥ�Ĺ��ʸ�����ǥޥå�����
 * ̾����row�򥫥���row�ˤ���
 * name: row��̾��
 * �֤���: ���� 0 ������ -1
 * ���Ԥλ��ˤϤ˥�����row��̵���ˤʤ�
 */
EXPORT_API int anthy_select_longest_row(xstr *name);

/*
 * ������section��κǽ��row�򥫥���row�ˤ���
 * �֤���: ���� 0 ������ -1
 * ���Ԥλ��ˤϥ�����row��̵���ˤʤ�
 */
EXPORT_API int anthy_select_first_row(void);

/*
 * ������row�μ���row�򥫥���row�ˤ���
 * �֤���: ���� 0 ������ -1
 * ������row���Ф����ѹ������äƤ⡢�ե�����ˤ���¸����ʤ�
 * ���Ԥλ��ˤϥ�����row��̵���ˤʤ�
 */
EXPORT_API int anthy_select_next_row(void);

/*
 * ������section���������
 * ��˥�����section,row��̵���ˤʤ�
 */
EXPORT_API void anthy_release_section(void);

/*
 * ������section��LRU�ꥹ�Ȥ���Ƭ����count�İʹߤ��������
 * ��˥�����row��̵���ˤʤ�
 */
EXPORT_API void anthy_truncate_section(int count);


/* ���ߤ�row���Ф������ */
EXPORT_API xstr *anthy_get_index_xstr(void);
EXPORT_API int anthy_get_nr_values(void);
EXPORT_API int anthy_get_nth_value(int );
EXPORT_API xstr *anthy_get_nth_xstr(int );/* intern����Ƥ���xstr���֤���� */

EXPORT_API void anthy_set_nth_value(int nth, int val);
EXPORT_API void anthy_set_nth_xstr(int nth, xstr *xs);/* �����ǥ��ԡ������ */

EXPORT_API void anthy_truncate_row(int nth);/* To Be Implemented */

/*
 * ������row��������롣��λ��Υ�����row������
 * ��˥�����row��̵���ˤʤ�
 */
EXPORT_API void anthy_release_row(void);

/*
 * ������row��LRU����Ƭ�����ؤ�äƤ���
 * ��˥�����row��̵���ˤʤ�
 */
EXPORT_API int anthy_mark_row_used(void);


EXPORT_API void anthy_reload_record(void);

#endif
