

#ifndef _BSP_IPC_H_
#define _BSP_IPC_H_
#ifdef __ASSEMBLY__
#include <bsp_memmap.h>
#define  IPC_CPU_RAW_INT_M3   0x420
/* c->m send ipc_int  addr & bit  */
#define  PM_C2M_IPC_ADDR       (HI_IPCM_REGBASE_ADDR+IPC_CPU_RAW_INT_M3)
#define  PM_C2M_IPC_BIT        (0x1<<17)
/* a->m send ipc_int  addr & bit  */
#define  PM_A2M_IPC_ADDR       (HI_IPCM_REGBASE_ADDR+IPC_CPU_RAW_INT_M3)
#define  PM_A2M_IPC_BIT        (0x1<<16)

#else

#include <product_config.h>
#include <osl_common.h>
#include <drv_ipc.h>
#ifdef __cplusplus
extern "C" {
#endif
typedef void  (*voidfuncptr)(u32);
#define IPC_ERR_MODEM_RESETING 1
#define MODEM_RESET_HWLOCK_ID 10

struct ipc_entry
{
 	voidfuncptr routine;
	u32	arg;
} ;

#ifdef CONFIG_MODULE_IPC
/*****************************************************************************
* �� �� ��     : bsp_ipc_init
*
* ��������  : IPCģ���ʼ��
*
* �������  : ��
* �������  : ��
*
* �� �� ֵ     : 
*
* �޸ļ�¼  : 2013��1��9��   lixiaojie     
                          
*****************************************************************************/
void bsp_ipc_init(void);
/*****************************************************************************
* �� �� ��     : bsp_ipc_sem_create
*
* ��������  : �����ź���
*
* �������  :   u32 u32SignalNum Ҫ�������ź������

* �������  : ��
*
* �� �� ֵ     : OK&ERROR
*
* �޸ļ�¼  : 2013��1��9�� lixiaojie 
*****************************************************************************/
s32 bsp_ipc_sem_create(u32 u32SignalNum);
/*****************************************************************************
* �� �� ��      : bsp_ipc_sem_delete
*
* ��������  : ɾ���ź���
*
* �������  :   u32 u32SignalNum Ҫɾ�����ź������

* �������  : ��
*
* �� �� ֵ     : OK&ERROR
*
* �޸ļ�¼  : 2013��1��9�� lixiaojie 
*****************************************************************************/

s32 bsp_ipc_sem_delete(u32 u32SignalNum);
/*****************************************************************************
* �� �� ��     :bsp_ipc_int_enable
*
* ��������  : ʹ��ĳ���ж�
*
* �������  :   u32 ulLvl Ҫʹ�ܵ��жϺţ�ȡֵ��Χ0��31  
* �������  : ��
*
* �� �� ֵ     : OK&ERROR
*
* �޸ļ�¼  : 2013��1��8��    lixiaojie 
*****************************************************************************/

s32 bsp_ipc_int_enable(IPC_INT_LEV_E ulLvl);
/*****************************************************************************
 * �� �� ��      : ipc_int_disable
 *
 * ��������  : ȥʹ��ĳ���ж�
 *
 * �������  : u32 ulLvl Ҫʹ�ܵ��жϺţ�ȡֵ��Χ0��31   
 * �������  : ��
 *
 * �� �� ֵ      : OK&ERROR
 *
 * �޸ļ�¼  :  2013��1��8�� lixiaojie  
 *****************************************************************************/

s32 bsp_ipc_int_disable(IPC_INT_LEV_E ulLvl);
/*****************************************************************************
 * �� �� ��     : bsp_ipc_int_connect
 *
 * ��������  : ע��ĳ���ж�
 *
 * �������  : u32 ulLvl Ҫʹ�ܵ��жϺţ�ȡֵ��Χ0��31 
                              routine �жϷ������
 *                            u32 parameter      �жϷ���������
 * �������  : ��
 *
 * �� �� ֵ      : OK&ERROR
 *
 * �޸ļ�¼  : 2013��1��9�� lixiaojie
 *****************************************************************************/

s32 bsp_ipc_int_connect(IPC_INT_LEV_E ulLvl, voidfuncptr routine, u32 parameter);
/*****************************************************************************
 * �� �� ��     : bsp_ipc_int_disconnect
 *
 * ��������  : ȡ��ע��ĳ���ж�
 *
 * �������  : u32 ulLvl Ҫʹ�ܵ��жϺţ�ȡֵ��Χ0��31 
 *                           voidfuncptr routine �жϷ������
 *                           u32 parameter      �жϷ���������
 * �������  : ��
 *
 * �� �� ֵ      : OK&ERROR
 *
 * �޸ļ�¼  : 2013��1��9�� lixiaojie 
 *****************************************************************************/   

s32 bsp_ipc_int_disconnect(IPC_INT_LEV_E ulLvl,voidfuncptr routine, u32 parameter);
/*****************************************************************************
* �� �� ��      : bsp_ipc_int_send
*
* ��������  : �����ж�
*
* �������  : ipc_int_core enDstore Ҫ�����жϵ�core
                             u32 ulLvl Ҫ���͵��жϺţ�ȡֵ��Χ0��31  
* �������  : ��
*
* �� �� ֵ      :  OK&ERROR
*
* �޸ļ�¼  :  2013��1��9�� lixiaojie 
*****************************************************************************/

s32 bsp_ipc_int_send(IPC_INT_CORE_E enDstCore, IPC_INT_LEV_E ulLvl);
/*****************************************************************************
 * �� �� ��     : bsp_ipc_sem_take
 *
 * ��������  : ��ȡ�ź���
 *
 * �������  : u32SignalNum Ҫ��ȡ���ź���ID
                                s32timeout  ��ʱʱ��,tickΪ��λ��һ��tickΪ10ms
 * �������  : ��
 *
 * �� �� ֵ      : OK&ERROR
 *
 * �޸ļ�¼  : 2013��1��9�� lixiaojie 
 *****************************************************************************/

s32 bsp_ipc_sem_take(u32 u32SignalNum,s32 s32timeout);
/*****************************************************************************
 * �� �� ��     : bsp_ipc_sem_give
 *
 * ��������  : �ͷ��ź���
 *
 * �������  : u32SignalNum Ҫ��ȡ���ź���
 					    s32timeout  ��10msΪ��λ�ĳ�ʱʱ��
 * �������  : ��
 *
 * �� �� ֵ      :OK&&ERROR
 *
 * �޸ļ�¼  : 2013��1��9�� lixiaojie 
 *****************************************************************************/

s32 bsp_ipc_sem_give(u32 u32SignalNum);
/*****************************************************************************
* �� �� ��     : bsp_ipc_spin_lock
*
* ��������  : ��ѯ�ȴ���ȡ�ź���,��ʹ�ñ�����ǰ��Ҫ���жϣ�
			����ʹ�ô����жϹ��ܵ�bsp_ipc_spin_lock_irqsave����
*
* �������  : u32SignalNum Ҫ��ȡ���ź���
* �������  : ��
*
* �� �� ֵ      :ERROR&OK
*
* �޸ļ�¼  :  2013��1��8�� lixiaojie 
*****************************************************************************/

s32 bsp_ipc_spin_lock (u32 u32SignalNum);
/*****************************************************************************
* �� �� ��      : bsp_ipc_spin_unlock
*
* ��������  : �ͷ��ź�������bsp_ipc_spin_lock����ʹ�ã��ú���Ҫ���жϣ�
			����ʹ�ô����жϹ��ܵ�bsp_ipc_spin_unlock_irqrestore����
*
* �������  : u32SignalNum  Ҫ�ͷŵ��ź���
* �������  : ��
*
* �� �� ֵ      : OK&ERROR
*
* �޸ļ�¼  :  2013��1��9�� lixiaojie
*****************************************************************************/

s32 bsp_ipc_spin_unlock (u32 u32SignalNum);
/*****************************************************************************
* �� �� ��     : bsp_ipc_spin_lock_irqsave
*
* ��������  : ���жϲ���ѯ�ȴ���ȡ�ź���
*
* �������  : u32SignalNum Ҫ��ȡ���ź���
						flags:���жϱ�־����bsp_ipc_spin_unlock_irqrestore���ʹ�ã�
						��������ֻ����ͬһ�������ڲ�ͬʱǰ�󱻵��ã�
						�ο�spin_lock_irqsave�÷�
* �������  : ��
*
* �� �� ֵ      :ERROR&OK
*
* �޸ļ�¼  :  2013��5��8�� lixiaojie 
*****************************************************************************/

#define bsp_ipc_spin_lock_irqsave(u32SignalNum,flags)  \
	do{local_irq_save(flags);(void)bsp_ipc_spin_lock(u32SignalNum);}while(0)
/*****************************************************************************
* �� �� ��     : bsp_ipc_spin_unlock_irqrestore
*
* ��������  :���жϲ��ͷŻ�õ��ź���
*
* �������  : u32SignalNum Ҫ��ȡ���ź���
					flags:���жϱ�־����bsp_ipc_spin_lock_irqsave���ʹ�ã�
						��������ֻ����ͬһ�������ڲ�ͬʱǰ�󱻵��ã�
						�ο�spin_unlock_irqrestore�÷�
* �������  : ��
*
* �� �� ֵ      :ERROR&OK
*
* �޸ļ�¼  :  2013��5��8�� lixiaojie 
*****************************************************************************/

#define bsp_ipc_spin_unlock_irqrestore(u32SignalNum,flags) \
	do{(void)bsp_ipc_spin_unlock(u32SignalNum);local_irq_restore(flags);}while(0)
#else
static inline s32 bsp_ipc_init(void) {return 0;}
static inline s32 bsp_ipc_sem_create(u32 u32SignalNum) {return 0;}
static inline s32 bsp_ipc_sem_delete(u32 u32SignalNum) {return 0;}
static inline s32 bsp_ipc_int_enable(IPC_INT_LEV_E ulLvl) {return 0;}
static inline s32 bsp_ipc_int_disable(IPC_INT_LEV_E ulLvl) {return 0;}
static inline s32 bsp_ipc_int_connect(IPC_INT_LEV_E ulLvl, voidfuncptr routine, u32 parameter) {return 0;}
static inline s32 bsp_ipc_int_disconnect(IPC_INT_LEV_E ulLvl,voidfuncptr routine, u32 parameter) {return 0;}
static inline s32 bsp_ipc_int_send(IPC_INT_CORE_E enDstCore, IPC_INT_LEV_E ulLvl) {return 0;}
static inline s32 bsp_ipc_sem_take(u32 u32SignalNum,s32 s32timeout) {return 0;}
static inline s32 bsp_ipc_sem_give(u32 u32SignalNum) {return 0;}
static inline s32 bsp_ipc_spin_lock (u32 u32SignalNum) {return 0;}
static inline s32 bsp_ipc_spin_unlock (u32 u32SignalNum) {return 0;}
#define bsp_ipc_spin_lock_irqsave(u32SignalNum,flags)  \
	do{}while(0)
#define bsp_ipc_spin_unlock_irqrestore(u32SignalNum,flags) \
	do{}while(0)

#endif
/*****************************************************************************
* �� �� ��     : bsp_int_send_info
*
* ��������  :�鿴��ÿ���˷���ÿ���жϴ���
*
* �������  : ��
* �������  : ��
*
* �� �� ֵ      :��
*
* �޸ļ�¼  :  2013��5��10�� lixiaojie 
*****************************************************************************/

void bsp_int_send_info(void);
#ifdef __CMSIS_RTOS
/*****************************************************************************
* �� �� ��	: bsp_ipc_suspend
*
* ��������	:IPC�豸�µ�ǰ����Ĵ���
*
* �������	: ��
* �������	: ��
*
* �� �� ֵ		:
*
* �޸ļ�¼	:  2013��6��14�� lixiaojie 
*****************************************************************************/
void bsp_ipc_suspend(void);
/*****************************************************************************
* �� �� ��	: bsp_ipc_resume
*
* ��������	:IPC�豸�ϵ��ָ��Ĵ���
*
* �������	: ��
* �������	: ��
*
* �� �� ֵ		:0: success
						 -1:fail
*
* �޸ļ�¼	:  2013��6��14�� lixiaojie 
*****************************************************************************/
void bsp_ipc_resume(void);
#endif

#ifdef __cplusplus
}
#endif

#endif /*#ifdef __ASSEMBLY__*/

#endif /* end #define _BSP_IPC_H_*/