/*
 * ��¤��allocator
 * ��������������Ǥ�ator��ά���뤳�Ȥ�����
 */
#ifndef _alloc_h_included_
#define _alloc_h_included_

#ifndef EXPORT_API
#define EXPORT_API
#endif // EXPORT_API


/** ���������Υϥ�ɥ� */
typedef struct allocator_priv * allocator;

/*
 * allocator����
 * s: ��¤�Τ�size(�Х��ȿ�)
 * dtor: =destructor ���ݤ������֥������Ȥ����������Ȥ��˸ƤФ��ؿ�
 *  dtor�ΰ����ϲ�������륪�֥�������
 * �֤���: ��������allocator 
 */
EXPORT_API allocator anthy_create_allocator(int s, void (*dtor)(void *));

/*
 * allocator���������
 *  ���κݤˡ�����allocator������ݤ��줿���֥������Ȥ����Ʋ��������
 * a: ��������allocator
 */
EXPORT_API void anthy_free_allocator(allocator a);

/*
 * ���֥������Ȥ���ݤ���
 * a: allocator
 * �֤���: ���ݤ������֥������ȤΥ��ɥ쥹
 */
EXPORT_API void *anthy_smalloc(allocator a);
/*
 * ���֥������Ȥ��������
 * a: allocator
 * p: �������륪�֥������ȤΥ��ɥ쥹
 */
EXPORT_API void anthy_sfree(allocator a, void *p);

/* ���Ƥ�allocator���˴����� */
EXPORT_API void anthy_quit_allocator(void);

#endif
